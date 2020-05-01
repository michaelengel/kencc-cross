#include	"l.h"

long	OFFSET;

#define	LPUT(c)\
	{\
		cbp[0] = (c);\
		cbp[1] = (c)>>8;\
		cbp[2] = (c)>>16;\
		cbp[3] = (c)>>24;\
		cbp += 4;\
		cbc -= 4;\
		if(cbc <= 0)\
			cflush();\
	}

#define	LBEPUT(c)\
	{\
		cbp[0] = (c)>>24;\
		cbp[1] = (c)>>16;\
		cbp[2] = (c)>>8;\
		cbp[3] = (c);\
		cbp += 4;\
		cbc -= 4;\
		if(cbc <= 0)\
			cflush();\
	}

#define	HPUT(c)\
	{\
		cbp[0] = (c);\
		cbp[1] = (c)>>8;\
		cbp += 2;\
		cbc -= 2;\
		if(cbc <= 0)\
			cflush();\
	}

#define	CPUT(c)\
	{\
		cbp[0] = (c);\
		cbp++;\
		cbc--;\
		if(cbc <= 0)\
			cflush();\
	}

void
objput(long l)	/* emit long in byte order appropriate to object machine */
{
	LPUT(l);
}

void
objhput(short s)
{
	HPUT(s);
}

void
lput(long l)		/* emit long in big-endian byte order */
{
	LBEPUT(l);
}

long
entryvalue(void)
{
	char *a;
	Sym *s;

	a = INITENTRY;
	if(*a >= '0' && *a <= '9')
		return atolwhex(a);
	s = lookup(a, 0);
	if(s->type == 0)
		return INITTEXT;
	if(s->type != STEXT && s->type != SLEAF)
		diag("entry not text: %s", s->name);
	return s->value;
}

void
asmb(void)
{
	Prog *p;
	long t, etext;
	Optab *o;

	if(debug['v'])
		Bprint(&bso, "%5.2f asm\n", cputime());
	Bflush(&bso);
	OFFSET = HEADR;
	seek(cout, OFFSET, 0);
	pc = INITTEXT;
	for(p = firstp; p != P; p = p->link) {
		if(p->as == ATEXT) {
			curtext = p;
			autosize = p->to.offset + 4;
		}
		if(p->pc != pc) {
			diag("phase error %lux sb %lux",
				p->pc, pc);
			if(!debug['a'])
				prasm(curp);
			pc = p->pc;
		}
		curp = p;
		o = oplook(p);	/* could probably avoid this call */
		if(asmout(p, o, 0)) {
			p = p->link;
			pc += 4;
		}
		pc += o->size;
	}
	if(debug['a'])
		Bprint(&bso, "\n");
	Bflush(&bso);
	cflush();

	etext = INITTEXT + textsize;
	for(t = pc; t < etext; t += sizeof(buf)-100) {
		if(etext-t > sizeof(buf)-100)
			datblk(t, sizeof(buf)-100, 1);
		else
			datblk(t, etext-t, 1);
	}

	Bflush(&bso);
	cflush();

	curtext = P;
	switch(HEADTYPE) {
	case 0:
	case 4:
		OFFSET = rnd(HEADR+textsize, 4096);
		seek(cout, OFFSET, 0);
		break;
	case 1:
	case 2:
	case 3:
	case 5:
	case 6:
		OFFSET = HEADR+textsize;
		seek(cout, OFFSET, 0);
		break;
	}
	for(t = 0; t < datsize; t += sizeof(buf)-100) {
		if(datsize-t > sizeof(buf)-100)
			datblk(t, sizeof(buf)-100, 0);
		else
			datblk(t, datsize-t, 0);
	}

	symsize = 0;
	lcsize = 0;
	if(!debug['s']) {
		if(debug['v'])
			Bprint(&bso, "%5.2f sym\n", cputime());
		Bflush(&bso);
		switch(HEADTYPE) {
		case 0:
		case 4:
			OFFSET = rnd(HEADR+textsize, 4096)+datsize;
			seek(cout, OFFSET, 0);
			break;
		case 3:
		case 2:
		case 1:
		case 5:
		case 6:
			OFFSET = HEADR+textsize+datsize;
			seek(cout, OFFSET, 0);
			break;
		}
		if(!debug['s'])
			asmsym();
		if(debug['v'])
			Bprint(&bso, "%5.2f pc\n", cputime());
		Bflush(&bso);
		if(!debug['s'])
			asmlc();
		cflush();
	}

	if(debug['v'])
		Bprint(&bso, "%5.2f header\n", cputime());
	Bflush(&bso);
	OFFSET = 0;
	seek(cout, OFFSET, 0);
	switch(HEADTYPE) {
	case 1:
		break;
	case 2:
		t = 29;
		lput(((((4*t)+0)*t)+7));	/* magic */
		lput(textsize);			/* sizes */
		lput(datsize);
		lput(bsssize);
		lput(symsize);			/* nsyms */
		lput(entryvalue());		/* va of entry */
		lput(0L);
		lput(lcsize);
		break;
	case 5:
		/* first part of ELF is byte-wide parts, thus no byte-order issues */
		strnput("\177ELF", 4);		/* e_ident */
		CPUT(1);			/* class = 32 bit */
		CPUT(1);			/* data: 1 = LSB, 2 = MSB */
		CPUT(1);			/* version = 1 */
		strnput("", 9);			/* reserved for expansion */
		/* entire remainder of ELF file is in target byte order */

		/* file header part of ELF header */
		objhput(2);			/* type = EXEC */
		objhput(243);		/* machine = RISC-V */
		objput(1L);			/* version = CURRENT */
		objput(entryvalue());		/* entry vaddr */
		objput(52L);			/* offset to first phdr */
		objput(0L);			/* offset to first shdr */
		objput(0L);			/* flags */
		objhput(52);			/* Ehdr size */
		objhput(32);			/* Phdr size */
		objhput(3);			/* # of Phdrs */
		objhput(0);			/* Shdr size */
		objhput(0);			/* # of Shdrs */
		objhput(0);			/* Shdr string size */

		/* "Program headers" - one per chunk of file to load */

		/*
		 * Don't include ELF headers in text
		 */
		objput(1L);			/* text: type = PT_LOAD */
		objput(HEADR);			/* file offset */
		objput(INITTEXT);		/* vaddr */
		objput(INITTEXT);		/* paddr */
		objput(textsize);		/* file size */
		objput(textsize);		/* memory size */
		objput(0x05L);			/* protections = RX */
		objput(0x1000L);		/* page-align text off's & vaddrs */

		objput(1L);			/* data: type = PT_LOAD */
		objput(HEADR+textsize);		/* file offset */
		objput(INITDAT);		/* vaddr */
		objput(INITDAT);		/* paddr */
		objput(datsize);		/* file size */
		objput(datsize+bsssize);	/* memory size */
		objput(0x06L);			/* protections = RW */
		if(INITDAT % 4096 == 0 && (HEADR + textsize) % 4096 == 0)
			objput(0x1000L);	/* page-align data off's & vaddrs */
		else
			objput(0L);		/* do not claim alignment */

		objput(0L);			/* P9 symbols: type = PT_NULL */
		objput(HEADR+textsize+datsize);	/* file offset */
		objput(0L);
		objput(0L);
		objput(symsize);		/* symbol table size */
		objput(lcsize);			/* line number size */
		objput(0x04L);			/* protections = R */
		objput(0L);			/* do not claim alignment */
		break;
	}
	cflush();
}

void
strnput(char *s, int n)
{
	for(; *s; s++){
		CPUT(*s);
		n--;
	}
	for(; n > 0; n--)
		CPUT(0);
}

void
cflush(void)
{
	int n;

	n = sizeof(buf.cbuf) - cbc;
	if(n)
		write(cout, buf.cbuf, n);
	cbp = buf.cbuf;
	cbc = sizeof(buf.cbuf);
}

void
nopstat(char *f, Count *c)
{
	if(c->outof)
	Bprint(&bso, "%s delay %ld/%ld (%.2f)\n", f,
		c->outof - c->count, c->outof,
		(double)(c->outof - c->count)/c->outof);
}

void
asmsym(void)
{
	Prog *p;
	Auto *a;
	Sym *s;
	int h;

	s = lookup("etext", 0);
	if(s->type == STEXT)
		putsymb(s->name, 'T', s->value, s->version);

	for(h=0; h<NHASH; h++)
		for(s=hash[h]; s!=S; s=s->link)
			switch(s->type) {
			case SCONST:
				putsymb(s->name, 'D', s->value, s->version);
				continue;

			case SSTRING:
				putsymb(s->name, 'T', s->value, s->version);
				continue;

			case SDATA:
				putsymb(s->name, 'D', s->value+INITDAT, s->version);
				continue;

			case SBSS:
				putsymb(s->name, 'B', s->value+INITDAT, s->version);
				continue;

			case SFILE:
				putsymb(s->name, 'f', s->value, s->version);
				continue;
			}

	for(p=textp; p!=P; p=p->cond) {
		s = p->from.sym;
		if(s->type != STEXT && s->type != SLEAF)
			continue;

		/* filenames first */
		for(a=p->to.autom; a; a=a->link)
			if(a->type == D_FILE)
				putsymb(a->asym->name, 'z', a->aoffset, 0);
			else
			if(a->type == D_FILE1)
				putsymb(a->asym->name, 'Z', a->aoffset, 0);

		if(s->type == STEXT)
			putsymb(s->name, 'T', s->value, s->version);
		else
			putsymb(s->name, 'L', s->value, s->version);

		/* frame, auto and param after */
		putsymb(".frame", 'm', p->to.offset+4, 0);
		for(a=p->to.autom; a; a=a->link)
			if(a->type == D_AUTO)
				putsymb(a->asym->name, 'a', -a->aoffset, 0);
			else
			if(a->type == D_PARAM)
				putsymb(a->asym->name, 'p', a->aoffset, 0);
	}
	if(debug['v'] || debug['n'])
		Bprint(&bso, "symsize = %lud\n", symsize);
	Bflush(&bso);
}

void
putsymb(char *s, int t, long v, int ver)
{
	int i, f;

	if(t == 'f')
		s++;
	LBEPUT(v);
	if(ver)
		t += 'a' - 'A';
	CPUT(t+0x80);			/* 0x80 is variable length */

	if(t == 'Z' || t == 'z') {
		CPUT(s[0]);
		for(i=1; s[i] != 0 || s[i+1] != 0; i += 2) {
			CPUT(s[i]);
			CPUT(s[i+1]);
		}
		CPUT(0);
		CPUT(0);
		i++;
	}
	else {
		for(i=0; s[i]; i++)
			CPUT(s[i]);
		CPUT(0);
	}
	symsize += 4 + 1 + i + 1;

	if(debug['n']) {
		if(t == 'z' || t == 'Z') {
			Bprint(&bso, "%c %.8lux ", t, v);
			for(i=1; s[i] != 0 || s[i+1] != 0; i+=2) {
				f = ((s[i]&0xff) << 8) | (s[i+1]&0xff);
				Bprint(&bso, "/%x", f);
			}
			Bprint(&bso, "\n");
			return;
		}
		if(ver)
			Bprint(&bso, "%c %.8lux %s<%d>\n", t, v, s, ver);
		else
			Bprint(&bso, "%c %.8lux %s\n", t, v, s);
	}
}

#define	MINLC	4
void
asmlc(void)
{
	long oldpc, oldlc;
	Prog *p;
	long v, s;

	oldpc = INITTEXT;
	oldlc = 0;
	for(p = firstp; p != P; p = p->link) {
		if(p->line == oldlc || p->as == ATEXT || p->as == ANOP) {
			if(p->as == ATEXT)
				curtext = p;
			if(debug['L'])
				Bprint(&bso, "%6lux %P\n",
					p->pc, p);
			continue;
		}
		if(debug['L'])
			Bprint(&bso, "\t\t%6ld", lcsize);
		v = (p->pc - oldpc) / MINLC;
		while(v) {
			s = 127;
			if(v < 127)
				s = v;
			CPUT(s+128);	/* 129-255 +pc */
			if(debug['L'])
				Bprint(&bso, " pc+%ld*%d(%ld)", s, MINLC, s+128);
			v -= s;
			lcsize++;
		}
		s = p->line - oldlc;
		oldlc = p->line;
		oldpc = p->pc + MINLC;
		if(s > 64 || s < -64) {
			CPUT(0);	/* 0 vv +lc */
			CPUT(s>>24);
			CPUT(s>>16);
			CPUT(s>>8);
			CPUT(s);
			if(debug['L']) {
				if(s > 0)
					Bprint(&bso, " lc+%ld(%d,%ld)\n",
						s, 0, s);
				else
					Bprint(&bso, " lc%ld(%d,%ld)\n",
						s, 0, s);
				Bprint(&bso, "%6lux %P\n",
					p->pc, p);
			}
			lcsize += 5;
			continue;
		}
		if(s > 0) {
			CPUT(0+s);	/* 1-64 +lc */
			if(debug['L']) {
				Bprint(&bso, " lc+%ld(%ld)\n", s, 0+s);
				Bprint(&bso, "%6lux %P\n",
					p->pc, p);
			}
		} else {
			CPUT(64-s);	/* 65-128 -lc */
			if(debug['L']) {
				Bprint(&bso, " lc%ld(%ld)\n", s, 64-s);
				Bprint(&bso, "%6lux %P\n",
					p->pc, p);
			}
		}
		lcsize++;
	}
	while(lcsize & 1) {
		s = 129;
		CPUT(s);
		lcsize++;
	}
	if(debug['v'] || debug['L'])
		Bprint(&bso, "lcsize = %ld\n", lcsize);
	Bflush(&bso);
}

void
datblk(long s, long n, int str)
{
	Prog *p;
	char *cast;
	long l, fl, j, d;
	int i, c;

	memset(buf.dbuf, 0, n+100);
	for(p = datap; p != P; p = p->link) {
		curp = p;
		if(str != (p->from.sym->type == SSTRING))
			continue;
		l = p->from.sym->value + p->from.offset - s;
		c = p->reg;
		i = 0;
		if(l < 0) {
			if(l+c <= 0)
				continue;
			while(l < 0) {
				l++;
				i++;
			}
		}
		if(l >= n)
			continue;
		if(p->as != AINIT && p->as != ADYNT) {
			for(j=l+(c-i)-1; j>=l; j--)
				if(buf.dbuf[j]) {
					print("%P\n", p);
					diag("multiple initialization");
					break;
				}
		}
		switch(p->to.type) {
		default:
			diag("unknown mode in initialization\n%P", p);
			break;

		case D_FCONST:
			switch(c) {
			default:
			case 4:
				fl = ieeedtof(p->to.ieee);
				cast = (char*)&fl;
				for(; i<c; i++) {
					buf.dbuf[l] = cast[fnuxi8[i+4]];
					l++;
				}
				break;
			case 8:
				cast = (char*)p->to.ieee;
				for(; i<c; i++) {
					buf.dbuf[l] = cast[fnuxi8[i]];
					l++;
				}
				break;
			}
			break;

		case D_SCONST:
			for(; i<c; i++) {
				buf.dbuf[l] = p->to.sval[i];
				l++;
			}
			break;

		case D_CONST:
			d = p->to.offset;
			if(p->to.sym) {
				switch(p->to.sym->type) {
				case STEXT:
				case SLEAF:
				case SSTRING:
					d += p->to.sym->value;
					break;
				case SDATA:
				case SBSS:
					d += p->to.sym->value + INITDAT;
					break;
				}
			}
			cast = (char*)&d;
			switch(c) {
			default:
				diag("bad nuxi %d %d\n%P", c, i, curp);
				break;
			case 1:
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi1[i]];
					l++;
				}
				break;
			case 2:
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi2[i]];
					l++;
				}
				break;
			case 4:
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi4[i]];
					l++;
				}
				break;
			}
			break;
		}
	}
	write(cout, buf.dbuf, n);
}

#define R(r) ((r)&0x1F)
#define OPU (0x3 | OLUI<<2)
#define OPX	(0x3 | o->op<<2)
#define OPF (OPX | o->func3<<12)
#define OPO	(0x3 | OOP<<2 | o->func3<<12)
#define OP_R(rs1,rs2,rd)\
	(OPO | rd<<7 | R(rs1)<<15 | R(rs2)<<20 | o->param<<25)
#define OP_ADD(rs1,rs2,rd)\
	(0x3 | OOP<<2 | rd<<7 | R(rs1)<<15 | R(rs2)<<20)
#define OP_I(rs1,rd,imm)\
	(OPF | rd<<7 | R(rs1)<<15 | imm<<20)
#define OP_FI(func3,rs1,rd,imm)\
	(OPX | func3<<12 | rd<<7 | R(rs1)<<15 | imm<<20)
#define OP_S(rs1,rs2,imm)\
	(OPF | (imm&0x1F)<<7 | R(rs1)<<15 | R(rs2)<<20 | (imm>>5)<<25)
#define OP_B(rs1,rs2,imm)\
	(OPF | R(rs1)<<15 | R(rs2)<<20 | (imm&0x800)>>4 | (imm&0x1E)<<7 | \
	 (imm&0x7E0)<<20 | (imm&0x1000)<<19)
#define OP_U(rd,imm)\
	(OPU | rd<<7 | (imm&0xFFFFF000))
#define OP_J(rd,imm)\
	(OPX | rd<<7 | (imm&0xff000) | (imm&0x800)<<9 | (imm&0x7FE)<<20 | (imm&0x100000)<<11)

int
asmout(Prog *p, Optab *o, int aflag)
{
	long o1, o2, o3, v;
	Prog *ct;
	int r;

	o1 = 0;
	o2 = 0;
	o3 = 0;
	r = p->reg;
	if(r == NREG)
		r = p->as == AMOVW || p->as == AJMP ? 0 : p->to.reg;
	switch(o->type) {
	default:
		diag("unknown type %d", o->type);
		if(!debug['a'])
			prasm(p);
		break;

	case 0:		/* add S,[R,]D */
		o1 = OP_R(r, (0x1f&p->from.reg), p->to.reg);
		break;

	case 1:		/* slli $I,[R,]D */
		v = p->from.offset & 0x1F;
		v |= (o->param<<5);
		o1 = OP_I(r, p->to.reg, v);
		break;

	case 2:		/* addi $I,[R,]D */
		v = p->from.offset;
		o1 = OP_I(r, p->to.reg, v);
		break;
	
	case 3:		/* beq S,[R,]L */
		if(r == NREG)
			r = REGZERO;
		if(p->cond == P)
			v = 0;
		else
			v = (p->cond->pc - pc);
		if(v < -0x1000 || v >= 0x1000)
			diag("branch out of range\n%P", p);
		o1 = OP_B(r, p->from.reg, v);
		break;

	case 4:		/* jal	[D,]L */
		if(p->cond == P)
			v = 0;
		else
			v = (p->cond->pc - pc);
		if(v < -0x200000 || v > 0x200000)
			diag("jump out of range\n%P", p);
		o1 = OP_J(o->param, v);
		break;

	case 5:		/* jalr [D,]I(S) */
		v = regoff(&p->to);
		o1 = OP_I(classreg(&p->to), o->param, v);
		break;

	case 6:		/* sb	R,I(S) */
		v = regoff(&p->to);
		r = classreg(&p->to);
		o1 = OP_S(r, p->from.reg, v);
		break;

	case 7:		/* lb	I(S),D */
		v = regoff(&p->from);
		r = classreg(&p->from);
		o1 = OP_I(r, p->to.reg, v);
		break;

	case 8:		/* lui	I,D */
		v = p->from.offset;
		o1 = OP_U(p->to.reg, v);
		break;

	case 9:		/* lui	I1,D; addi I0,D */
		v = regoff(&p->from);
		if(v & 0x800)
			v += 0x1000;
		o1 = OP_U(p->to.reg, v);
		v &= 0xFFF;
		o2 = OP_I(p->to.reg, p->to.reg, v);
		break;

	case 10:	/* sign extend */
		if(p->as == AMOVBU) {
			o1 = OP_I(p->from.reg, p->to.reg, o->param);
			break;
		}
		v = o->param & 0x1F;
		o1 = OP_FI(1, p->from.reg, p->to.reg, v);	/* slli */
		o2 = OP_I(p->to.reg, p->to.reg, o->param);	/* srli or srai */
		break;

	case 11:		/* addi $I,R,D */
		v = regoff(&p->from);
		o1 = OP_I(classreg(&p->from), p->to.reg, v);
		break;

	case 12:		/* mov r,lext => lui I1,T; sb r,I0(T) */
		v = regoff(&p->to);
		v += INITDAT + BIG;
		if(v & 0x800)
			v += 0x1000;
		o1 = OP_U(REGTMP, v);
		v &= 0xFFF;
		o2 = OP_S(REGTMP, p->from.reg, v);
		break;

	case 13:		/* mov lext, r => lui I1,T; lb r,I0(T) */
		v = regoff(&p->from);
		v += INITDAT + BIG;
		if(v & 0x800)
			v += 0x1000;
		o1 = OP_U(REGTMP, v);
		v &= 0xFFF;
		o2 = OP_I(REGTMP, p->to.reg, v);
		break;

	case 14:		/* add $lcon,d => lui I1,T; addi $L0,T,T; add T,d,d */
		v = regoff(&p->from);
		if(v & 0x800)
			v += 0x1000;
		o1 = OP_U(REGTMP, v);
		v &= 0xFFF;
		o2 = OP_I(REGTMP, REGTMP, v);
		o3 = OP_ADD(p->to.reg, REGTMP, p->to.reg);
		break;

	case 15:		/* mov r,L(s) => lui L1,T; add s,T,T; sb r,L0(T) */
		v = regoff(&p->to);
		r = classreg(&p->to);
		if(v & 0x800)
			v += 0x1000;
		o1 = OP_U(REGTMP, v);
		v &= 0xFFF;
		o2 = OP_ADD(r, REGTMP, REGTMP);
		o3 = OP_S(REGTMP, p->from.reg, v);
		break;

	case 16:		/* mov L(s),r => lui L1,T; add s,T,T; lb r,L0(T) */
		v = regoff(&p->from);
		r = classreg(&p->from);
		if(v & 0x800)
			v += 0x1000;
		o1 = OP_U(REGTMP, v);
		v &= 0xFFF;
		o2 = OP_ADD(r, REGTMP, REGTMP);
		o3 = OP_I(REGTMP, p->to.reg, v);
		break;

	case 24:		/* breakpoint */
		o1 = OP_I(0, 0, o->param);
		break;

	case 25:		/* word $x */
		o1 = regoff(&p->to);
		break;

	case 26:
	case 27:		/* pseudo ops */
		if(aflag) {
			if(p->link) {
				if(p->as == ATEXT) {
					ct = curtext;
					o2 = autosize;
					curtext = p;
					autosize = p->to.offset + 4;
					o1 = asmout(p->link, oplook(p->link), aflag);
					curtext = ct;
					autosize = o2;
				} else
					o1 = asmout(p->link, oplook(p->link), aflag);
			}
			return o1;
		}
		break;

	}
	if(aflag)
		return o1;
	v = p->pc;
	switch(o->size) {
	default:
		if(debug['a'])
			Bprint(&bso, " %.8lux:\t\t%P\n", v, p);
		break;
	case 4:
		if(debug['a'])
			Bprint(&bso, " %.8lux: %.8lux\t%P\n", v, o1, p);
		LPUT(o1);
		break;
	case 8:
		if(debug['a'])
			Bprint(&bso, " %.8lux: %.8lux %.8lux%P\n", v, o1, o2, p);
		LPUT(o1);
		LPUT(o2);
		break;
	case 12:
		if(debug['a'])
			Bprint(&bso, " %.8lux: %.8lux %.8lux %.8lux%P\n", v, o1, o2, o3, p);
		LPUT(o1);
		LPUT(o2);
		LPUT(o3);
		break;
	}
	return 0;
}

