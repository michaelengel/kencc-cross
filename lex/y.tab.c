#define	CHAR	57346
#define	CCL	57347
#define	NCCL	57348
#define	STR	57349
#define	DELIM	57350
#define	SCON	57351
#define	ITER	57352
#define	NEWE	57353
#define	NULLS	57354
#define	CAT	57355

#line	11	"parser.y"
# include "ldefs.h"
#define YYSTYPE union _yystype_
union _yystype_
{
	int	i;
	uchar	*cp;
};
extern	int	yyerrflag;
#ifndef	YYMAXDEPTH
#define	YYMAXDEPTH	150
#endif
#ifndef	YYSTYPE
#define	YYSTYPE	int
#endif
YYSTYPE	yylval;
YYSTYPE	yyval;

#line	21	"parser.y"
int i;
int j,k;
int g;
uchar *p;
#define YYEOFCODE 1
#define YYERRCODE 2

#line	217	"parser.y"

int
yylex(void)
{
	uchar *p;
	int c, i;
	uchar  *t, *xp;
	int n, j, k, x;
	static int sectbegin;
	static uchar token[TOKENSIZE];
	static int iter;

# ifdef DEBUG
	yylval.i = 0;
# endif

	if(sect == DEFSECTION) {		/* definitions section */
		while(!eof) {
			if(prev == '\n'){		/* next char is at beginning of line */
				getl(p=buf);
				switch(*p){
				case '%':
					switch(*(p+1)){
					case '%':
						lgate();
						Bprint(&fout,"#define YYNEWLINE %d\n",'\n');
						Bprint(&fout,"int\nyylex(void){\nint nstr; extern int yyprevious;\nif(yyprevious){}\n");
						sectbegin = TRUE;
						i = treesize*(sizeof(*name)+sizeof(*left)+
							sizeof(*right)+sizeof(*nullstr)+sizeof(*parent))+ALITTLEEXTRA;
						p = myalloc(i,1);
						if(p == 0)
							error("Too little core for parse tree");
						free(p);
						name = myalloc(treesize,sizeof(*name));
						left = myalloc(treesize,sizeof(*left));
						right = myalloc(treesize,sizeof(*right));
						nullstr = myalloc(treesize,sizeof(*nullstr));
						parent = myalloc(treesize,sizeof(*parent));
						ptr = myalloc(treesize,sizeof(*ptr));
						if(name == 0 || left == 0 || right == 0 || parent == 0 || nullstr == 0 || ptr == 0)
							error("Too little core for parse tree");
						return(freturn(DELIM));
					case 'p': case 'P':	/* has overridden number of positions */
						while(*p && !isdigit(*p))p++;
						maxpos = atol((char*)p);
# ifdef DEBUG
						if (debug) print("positions (%%p) now %d\n",maxpos);
# endif
						if(report == 2)report = 1;
						continue;
					case 'n': case 'N':	/* has overridden number of states */
						while(*p && !isdigit(*p))p++;
						nstates = atol((char*)p);
# ifdef DEBUG
						if(debug)print( " no. states (%%n) now %d\n",nstates);
# endif
						if(report == 2)report = 1;
						continue;
					case 'e': case 'E':		/* has overridden number of tree nodes */
						while(*p && !isdigit(*p))p++;
						treesize = atol((char*)p);
# ifdef DEBUG
						if (debug) print("treesize (%%e) now %d\n",treesize);
# endif
						if(report == 2)report = 1;
						continue;
					case 'o': case 'O':
						while (*p && !isdigit(*p))p++;
						outsize = atol((char*)p);
						if (report ==2) report=1;
						continue;
					case 'a': case 'A':		/* has overridden number of transitions */
						while(*p && !isdigit(*p))p++;
						if(report == 2)report = 1;
						ntrans = atol((char*)p);
# ifdef DEBUG
						if (debug)print("N. trans (%%a) now %d\n",ntrans);
# endif
						continue;
					case 'k': case 'K': /* overriden packed char classes */
						while (*p && !isdigit(*p))p++;
						if (report==2) report=1;
						free(pchar);
						pchlen = atol((char*)p);
# ifdef DEBUG
						if (debug) print( "Size classes (%%k) now %d\n",pchlen);
# endif
						pchar=pcptr=myalloc(pchlen, sizeof(*pchar));
						continue;
					case '{':
						lgate();
						while(getl(p) && strcmp((char*)p,"%}") != 0)
							Bprint(&fout, "%s\n",(char*)p);
						if(p[0] == '%') continue;
						error("Premature eof");
					case 's': case 'S':		/* start conditions */
						lgate();
						while(*p && strchr(" \t,", *p) == 0) p++;
						n = TRUE;
						while(n){
							while(*p && strchr(" \t,", *p)) p++;
							t = p;
							while(*p && strchr(" \t,", *p) == 0)p++;
							if(!*p) n = FALSE;
							*p++ = 0;
							if (*t == 0) continue;
							i = sptr*2;
							Bprint(&fout,"#define %s %d\n",(char*)t,i);
							strcpy((char*)sp, (char*)t);
							sname[sptr++] = sp;
							sname[sptr] = 0;	/* required by lookup */
							if(sptr >= STARTSIZE)
								error("Too many start conditions");
							sp += strlen((char*)sp) + 1;
							if(sp >= stchar+STARTCHAR)
								error("Start conditions too long");
						}
						continue;
					default:
						warning("Invalid request %s",p);
						continue;
					}	/* end of switch after seeing '%' */
				case ' ': case '\t':		/* must be code */
					lgate();
					Bprint(&fout, "%s\n",(char*)p);
					continue;
				default:		/* definition */
					while(*p && !isspace(*p)) p++;
					if(*p == 0)
						continue;
					prev = *p;
					*p = 0;
					bptr = p+1;
					yylval.cp = buf;
					if(isdigit(buf[0]))
						warning("Substitution strings may not begin with digits");
					return(freturn(STR));
				}
			}
			/* still sect 1, but prev != '\n' */
			else {
				p = bptr;
				while(*p && isspace(*p)) p++;
				if(*p == 0)
					warning("No translation given - null string assumed");
				strcpy((char*)token, (char*)p);
				yylval.cp = token;
				prev = '\n';
				return(freturn(STR));
			}
		}
		/* end of section one processing */
	} else if(sect == RULESECTION){		/* rules and actions */
		while(!eof){
			switch(c=gch()){
			case '\0':
				return(freturn(0));
			case '\n':
				if(prev == '\n') continue;
				x = NEWE;
				break;
			case ' ':
			case '\t':
				if(sectbegin == TRUE){
					cpyact();
					while((c=gch()) && c != '\n');
					continue;
				}
				if(!funcflag)phead2();
				funcflag = TRUE;
				Bprint(&fout,"case %d:\n",casecount);
				if(cpyact())
					Bprint(&fout,"break;\n");
				while((c=gch()) && c != '\n');
				if(peek == ' ' || peek == '\t' || sectbegin == TRUE){
					warning("Executable statements should occur right after %%");
					continue;
				}
				x = NEWE;
				break;
			case '%':
				if(prev != '\n') goto character;
				if(peek == '{'){	/* included code */
					getl(buf);
					while(!eof && getl(buf) && strcmp("%}",(char*)buf) != 0)
						Bprint(&fout,"%s\n",(char*)buf);
					continue;
				}
				if(peek == '%'){
					gch();
					gch();
					x = DELIM;
					break;
				}
				goto character;
			case '|':
				if(peek == ' ' || peek == '\t' || peek == '\n'){
					Bprint(&fout,"%d\n",30000+casecount++);
					continue;
				}
				x = '|';
				break;
			case '$':
				if(peek == '\n' || peek == ' ' || peek == '\t' || peek == '|' || peek == '/'){
					x = c;
					break;
				}
				goto character;
			case '^':
				if(prev != '\n' && scon != TRUE) goto character;	/* valid only at line begin */
				x = c;
				break;
			case '?':
			case '+':
			case '.':
			case '*':
			case '(':
			case ')':
			case ',':
			case '/':
				x = c;
				break;
			case '}':
				iter = FALSE;
				x = c;
				break;
			case '{':	/* either iteration or definition */
				if(isdigit(c=gch())){	/* iteration */
					iter = TRUE;
				ieval:
					i = 0;
					while(isdigit(c)){
						token[i++] = c;
						c = gch();
					}
					token[i] = 0;
					yylval.i = atol((char*)token);
					munputc(c);
					x = ITER;
					break;
				} else {		/* definition */
					i = 0;
					while(c && c!='}'){
						token[i++] = c;
						c = gch();
					}
					token[i] = 0;
					i = lookup(token,def);
					if(i < 0)
						warning("Definition %s not found",token);
					else
						munputs(subs[i]);
					continue;
				}
			case '<':		/* start condition ? */
				if(prev != '\n')		/* not at line begin, not start */
					goto character;
				t = slptr;
				do {
					i = 0;
					c = gch();
					while(c != ',' && c && c != '>'){
						token[i++] = c;
						c = gch();
					}
					token[i] = 0;
					if(i == 0)
						goto character;
					i = lookup(token,sname);
					if(i < 0) {
						warning("Undefined start condition %s",token);
						continue;
					}
					*slptr++ = i+1;
				} while(c && c != '>');
				*slptr++ = 0;
				/* check if previous value re-usable */
				for (xp=slist; xp<t; ){
					if (strcmp((char*)xp, (char*)t)==0)
						break;
					while (*xp++);
				}
				if (xp<t){
					/* re-use previous pointer to string */
					slptr=t;
					t=xp;
				}
				if(slptr > slist+STARTSIZE)		/* note not packed ! */
					error("Too many start conditions used");
				yylval.cp = t;
				x = SCON;
				break;
			case '"':
				i = 0;
				while((c=gch()) && c != '"' && c != '\n'){
					if(c == '\\') c = usescape(gch());
					token[i++] = c;
					if(i > TOKENSIZE){
						warning("String too long");
						i = TOKENSIZE-1;
						break;
					}
				}
				if(c == '\n') {
					yyline--;
					warning("Non-terminated string");
					yyline++;
				}
				token[i] = 0;
				if(i == 0)x = NULLS;
				else if(i == 1){
					yylval.i = token[0];
					x = CHAR;
				} else {
					yylval.cp = token;
					x = STR;
				}
				break;
			case '[':
				for(i=1;i<NCH;i++) symbol[i] = 0;
				x = CCL;
				if((c = gch()) == '^'){
					x = NCCL;
					c = gch();
				}
				while(c != ']' && c){
					if(c == '\\') c = usescape(gch());
					symbol[c] = 1;
					j = c;
					if((c=gch()) == '-' && peek != ']'){		/* range specified */
						c = gch();
						if(c == '\\') c = usescape(gch());
						k = c;
						if(j > k) {
							n = j;
							j = k;
							k = n;
						}
						if(!(('A' <= j && k <= 'Z') ||
						     ('a' <= j && k <= 'z') ||
						     ('0' <= j && k <= '9')))
							warning("Non-portable Character Class");
						for(n=j+1;n<=k;n++)
							symbol[n] = 1;		/* implementation dependent */
						c = gch();
					}
				}
				/* try to pack ccl's */
				i = 0;
				for(j=0;j<NCH;j++)
					if(symbol[j])token[i++] = j;
				token[i] = 0;
				p = ccl;
				while(p <ccptr && strcmp((char*)token,(char*)p) != 0)p++;
				if(p < ccptr)	/* found it */
					yylval.cp = p;
				else {
					yylval.cp = ccptr;
					strcpy((char*)ccptr,(char*)token);
					ccptr += strlen((char*)token) + 1;
					if(ccptr >= ccl+CCLSIZE)
						error("Too many large character classes");
				}
				cclinter(x==CCL);
				break;
			case '\\':
				c = usescape(gch());
			default:
			character:
				if(iter){	/* second part of an iteration */
					iter = FALSE;
					if('0' <= c && c <= '9')
						goto ieval;
				}
				if(isalpha(peek)){
					i = 0;
					yylval.cp = token;
					token[i++] = c;
					while(isalpha(peek))
						token[i++] = gch();
					if(peek == '?' || peek == '*' || peek == '+')
						munputc(token[--i]);
					token[i] = 0;
					if(i == 1){
						yylval.i = token[0];
						x = CHAR;
					}
					else x = STR;
				} else {
					yylval.i = c;
					x = CHAR;
				}
			}
			scon = FALSE;
			if(x == SCON)scon = TRUE;
			sectbegin = FALSE;
			return(freturn(x));
		}
	}
	/* section three */
	ptail();
# ifdef DEBUG
	if(debug)
		Bprint(&fout,"\n/*this comes from section three - debug */\n");
# endif
	while(getl(buf) && !eof)
		Bprint(&fout,"%s\n",(char*)buf);
	return(freturn(0));
}
/* end of yylex */
# ifdef DEBUG
int
freturn(int i)
{
	if(yydebug) {
		print("now return ");
		if(i < NCH) allprint(i);
		else print("%d",i);
		printf("   yylval = ");
		switch(i){
			case STR: case CCL: case NCCL:
				strpt(yylval.cp);
				break;
			case CHAR:
				allprint(yylval.i);
				break;
			default:
				print("%d",yylval.i);
				break;
		}
		print("\n");
	}
	return(i);
}
# endif
short	yyexca[] =
{-1, 0,
	7, 8,
	8, 8,
	-2, 0,
-1, 1,
	1, -1,
	-2, 0,
-1, 5,
	1, 6,
	-2, 0,
-1, 8,
	1, 6,
	-2, 0,
};
#define	YYNPROD	33
#define	YYPRIVATE 57344
#define	YYLAST	142
short	yyact[] =
{
  14,  17,  18,  15,  46,  19,  33,  23,  22,  32,
  30,  34,  20,  21,  16,  35,  27,  28,  29,  31,
  44,  43,  41,  42,  10,  12,   6,   7,  12,  14,
  17,  18,  15,  25,  45,  33,   4,  22,   8,  36,
  37,  38,  21,  16,   3,  27,  28,  29,   9,   2,
  39,   1,  40,  14,  17,  18,  15,  24,  19,  33,
  26,  22,  32,  30,  34,  20,  21,  16,   0,  27,
  28,  29,  14,  17,  18,  15,   0,  11,  33,   0,
  22,   5,  30,  34,  20,  21,  16,   0,  27,  28,
  29,  14,  17,  18,  15,   0,   0,  33,   0,  22,
   0,   0,  34,  20,  21,  16,   0,  27,  28,  29,
  13,   0,  14,  17,  18,  15,   7,  19,   0,   0,
  22,  27,  28,  29,  20,  21,  16,  14,  17,  18,
  15,   0,  19,   0,   0,  22,   0,   0,   0,  20,
  21,  16
};
short	yypact[] =
{
  34,-1000,-1000,  19,-1000, 108,   0,-1000, 108,-1000,
-1000,-1000,  49,   4,-1000,-1000,-1000,-1000,-1000, 123,
 123, 123,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
 123, 101, 123,  -1,-1000,-1000,  68,  25,  -4,  87,
  68,  10,-1000,-1000, -20,-1000,-1000
};
short	yypgo[] =
{
   0,  51,  49,  44,  77,  38,  48,  24,  19
};
short	yyr1[] =
{
   0,   1,   2,   2,   2,   6,   6,   3,   3,   4,
   5,   5,   7,   7,   8,   8,   8,   8,   8,   8,
   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,
   8,   8,   8
};
short	yyr2[] =
{
   0,   1,   4,   3,   1,   1,   0,   3,   0,   1,
   2,   1,   2,   2,   1,   1,   1,   1,   1,   2,
   2,   2,   3,   2,   3,   5,   3,   4,   2,   2,
   2,   3,   1
};
short	yychk[] =
{
-1000,  -1,  -2,  -3,   2,  -4,   7,   8,  -5,  -6,
  -7,  -4,  -8,   2,   4,   7,  18,   5,   6,   9,
  16,  17,  12,   7,  -6,  -7,  11,  20,  21,  22,
  14,  -8,  13,  10,  15,  11,  -8,  -8,  -8,  -8,
  -8,  23,  24,  25,  10,  24,  24
};
short	yydef[] =
{
  -2,  -2,   1,   0,   4,  -2,   0,   9,  -2,   3,
  11,   5,   0,   0,  14,  15,  16,  17,  18,   0,
   0,   0,  32,   7,   2,  10,  12,  19,  20,  21,
   0,  23,   0,   0,  30,  13,  28,  29,   0,  22,
  24,   0,  26,  31,   0,  27,  25
};
short	yytok1[] =
{
   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  15,   0,   0,   0,
  17,  25,  20,  21,  23,   0,  18,  13,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,  22,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,  16,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,  14,  24
};
short	yytok2[] =
{
   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,
  12,  19
};
long	yytok3[] =
{
   0
};
#define YYFLAG 		-1000
#define	yyclearin	yychar = -1
#define	yyerrok		yyerrflag = 0

#ifdef	yydebug
#include	"y.debug"
#else
#define	yydebug		0
char*	yytoknames[1];		/* for debugging */
char*	yystates[1];		/* for debugging */
#endif

/*	parser for yacc output	*/

int	yynerrs = 0;		/* number of errors */
int	yyerrflag = 0;		/* error recovery flag */

extern	int	fprint(int, char*, ...);
extern	int	sprint(char*, char*, ...);

char*
yytokname(int yyc)
{
	static char x[16];

	if(yyc > 0 && yyc <= sizeof(yytoknames)/sizeof(yytoknames[0]))
	if(yytoknames[yyc-1])
		return yytoknames[yyc-1];
	sprint(x, "<%d>", yyc);
	return x;
}

char*
yystatname(int yys)
{
	static char x[16];

	if(yys >= 0 && yys < sizeof(yystates)/sizeof(yystates[0]))
	if(yystates[yys])
		return yystates[yys];
	sprint(x, "<%d>\n", yys);
	return x;
}

long
yylex1(void)
{
	long yychar;
	long *t3p;
	int c;

	yychar = yylex();
	if(yychar <= 0) {
		c = yytok1[0];
		goto out;
	}
	if(yychar < sizeof(yytok1)/sizeof(yytok1[0])) {
		c = yytok1[yychar];
		goto out;
	}
	if(yychar >= YYPRIVATE)
		if(yychar < YYPRIVATE+sizeof(yytok2)/sizeof(yytok2[0])) {
			c = yytok2[yychar-YYPRIVATE];
			goto out;
		}
	for(t3p=yytok3;; t3p+=2) {
		c = t3p[0];
		if(c == yychar) {
			c = t3p[1];
			goto out;
		}
		if(c == 0)
			break;
	}
	c = 0;

out:
	if(c == 0)
		c = yytok2[1];	/* unknown char */
	if(yydebug >= 3)
		fprint(2, "lex %.4lux %s\n", yychar, yytokname(c));
	return c;
}

int
yyparse(void)
{
	struct
	{
		YYSTYPE	yyv;
		int	yys;
	} yys[YYMAXDEPTH], *yyp, *yypt;
	short *yyxi;
	int yyj, yym, yystate, yyn, yyg;
	long yychar;
	YYSTYPE save1, save2;
	int save3, save4;

	save1 = yylval;
	save2 = yyval;
	save3 = yynerrs;
	save4 = yyerrflag;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyp = &yys[-1];
	goto yystack;

ret0:
	yyn = 0;
	goto ret;

ret1:
	yyn = 1;
	goto ret;

ret:
	yylval = save1;
	yyval = save2;
	yynerrs = save3;
	yyerrflag = save4;
	return yyn;

yystack:
	/* put a state and value onto the stack */
	if(yydebug >= 4)
		fprint(2, "char %s in %s", yytokname(yychar), yystatname(yystate));

	yyp++;
	if(yyp >= &yys[YYMAXDEPTH]) {
		yyerror("yacc stack overflow");
		goto ret1;
	}
	yyp->yys = yystate;
	yyp->yyv = yyval;

yynewstate:
	yyn = yypact[yystate];
	if(yyn <= YYFLAG)
		goto yydefault; /* simple state */
	if(yychar < 0)
		yychar = yylex1();
	yyn += yychar;
	if(yyn < 0 || yyn >= YYLAST)
		goto yydefault;
	yyn = yyact[yyn];
	if(yychk[yyn] == yychar) { /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if(yyerrflag > 0)
			yyerrflag--;
		goto yystack;
	}

yydefault:
	/* default state action */
	yyn = yydef[yystate];
	if(yyn == -2) {
		if(yychar < 0)
			yychar = yylex1();

		/* look through exception table */
		for(yyxi=yyexca;; yyxi+=2)
			if(yyxi[0] == -1 && yyxi[1] == yystate)
				break;
		for(yyxi += 2;; yyxi += 2) {
			yyn = yyxi[0];
			if(yyn < 0 || yyn == yychar)
				break;
		}
		yyn = yyxi[1];
		if(yyn < 0)
			goto ret0;
	}
	if(yyn == 0) {
		/* error ... attempt to resume parsing */
		switch(yyerrflag) {
		case 0:   /* brand new error */
			yyerror("syntax error");
			yynerrs++;
			if(yydebug >= 1) {
				fprint(2, "%s", yystatname(yystate));
				fprint(2, "saw %s\n", yytokname(yychar));
			}

		case 1:
		case 2: /* incompletely recovered error ... try again */
			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */
			while(yyp >= yys) {
				yyn = yypact[yyp->yys] + YYERRCODE;
				if(yyn >= 0 && yyn < YYLAST) {
					yystate = yyact[yyn];  /* simulate a shift of "error" */
					if(yychk[yystate] == YYERRCODE)
						goto yystack;
				}

				/* the current yyp has no shift onn "error", pop stack */
				if(yydebug >= 2)
					fprint(2, "error recovery pops state %d, uncovers %d\n",
						yyp->yys, (yyp-1)->yys );
				yyp--;
			}
			/* there is no state on the stack with an error shift ... abort */
			goto ret1;

		case 3:  /* no shift yet; clobber input char */
			if(yydebug >= 2)
				fprint(2, "error recovery discards %s\n", yytokname(yychar));
			if(yychar == YYEOFCODE)
				goto ret1;
			yychar = -1;
			goto yynewstate;   /* try again in the same state */
		}
	}

	/* reduction by production yyn */
	if(yydebug >= 2)
		fprint(2, "reduce %d in:\n\t%s", yyn, yystatname(yystate));

	yypt = yyp;
	yyp -= yyr2[yyn];
	yyval = (yyp+1)->yyv;
	yym = yyn;

	/* consult goto table to find next state */
	yyn = yyr1[yyn];
	yyg = yypgo[yyn];
	yyj = yyg + yyp->yys + 1;

	if(yyj >= YYLAST || yychk[yystate=yyact[yyj]] != -yyn)
		yystate = yyact[yyg];
	switch(yym) {
		
case 1:
#line	27	"parser.y"
{	
# ifdef DEBUG
		if(debug) sect2dump();
# endif
	} break;
case 3:
#line	35	"parser.y"
{
		if(!funcflag)phead2();
		funcflag = TRUE;
	} break;
case 4:
#line	40	"parser.y"
{
# ifdef DEBUG
		if(debug) {
			sect1dump();
			sect2dump();
			}
# endif
		} break;
case 7:
#line	51	"parser.y"
{	strcpy((char*)dp,(char*)yypt[-1].yyv.cp);
		def[dptr] = dp;
		dp += strlen((char*)yypt[-1].yyv.cp) + 1;
		strcpy((char*)dp,(char*)yypt[-0].yyv.cp);
		subs[dptr++] = dp;
		if(dptr >= DEFSIZE)
			error("Too many definitions");
		dp += strlen((char*)yypt[-0].yyv.cp) + 1;
		if(dp >= dchar+DEFCHAR)
			error("Definitions too long");
		subs[dptr]=def[dptr]=0;	/* for lookup - require ending null */
	} break;
case 9:
#line	66	"parser.y"
{
# ifdef DEBUG
		if(sect == DEFSECTION && debug) sect1dump();
# endif
		sect++;
		} break;
case 10:
#line	74	"parser.y"
{	yyval.i = mn2(RNEWE,yypt[-1].yyv.i,yypt[-0].yyv.i);
		} break;
case 11:
#line	77	"parser.y"
{	yyval.i = yypt[-0].yyv.i;} break;
case 12:
#line	80	"parser.y"
{
		if(divflg == TRUE)
			i = mn1(S1FINAL,casecount);
		else i = mn1(FINAL,casecount);
		yyval.i = mn2(RCAT,yypt[-1].yyv.i,i);
		divflg = FALSE;
		casecount++;
		} break;
case 13:
#line	89	"parser.y"
{
# ifdef DEBUG
		if(debug) sect2dump();
# endif
		} break;
case 14:
#line	95	"parser.y"
{	yyval.i = mn0(yypt[-0].yyv.i); } break;
case 15:
#line	97	"parser.y"
{
		p = yypt[-0].yyv.cp;
		i = mn0(*p++);
		while(*p)
			i = mn2(RSTR,i,*p++);
		yyval.i = i;
		} break;
case 16:
#line	105	"parser.y"
{	symbol['\n'] = 0;
		if(psave == FALSE){
			p = ccptr;
			psave = ccptr;
			for(i=1;i<'\n';i++){
				symbol[i] = 1;
				*ccptr++ = i;
				}
			for(i='\n'+1;i<NCH;i++){
				symbol[i] = 1;
				*ccptr++ = i;
				}
			*ccptr++ = 0;
			if(ccptr > ccl+CCLSIZE)
				error("Too many large character classes");
			}
		else
			p = psave;
		yyval.i = mnp(RCCL,p);
		cclinter(1);
		} break;
case 17:
#line	127	"parser.y"
{	yyval.i = mnp(RCCL,yypt[-0].yyv.cp); } break;
case 18:
#line	129	"parser.y"
{	yyval.i = mnp(RNCCL,yypt[-0].yyv.cp); } break;
case 19:
#line	131	"parser.y"
{	yyval.i = mn1(STAR,yypt[-1].yyv.i); } break;
case 20:
#line	133	"parser.y"
{	yyval.i = mn1(PLUS,yypt[-1].yyv.i); } break;
case 21:
#line	135	"parser.y"
{	yyval.i = mn1(QUEST,yypt[-1].yyv.i); } break;
case 22:
#line	137	"parser.y"
{	yyval.i = mn2(BAR,yypt[-2].yyv.i,yypt[-0].yyv.i); } break;
case 23:
#line	139	"parser.y"
{	yyval.i = mn2(RCAT,yypt[-1].yyv.i,yypt[-0].yyv.i); } break;
case 24:
#line	141	"parser.y"
{	if(!divflg){
			j = mn1(S2FINAL,-casecount);
			i = mn2(RCAT,yypt[-2].yyv.i,j);
			yyval.i = mn2(DIV,i,yypt[-0].yyv.i);
			}
		else {
			yyval.i = mn2(RCAT,yypt[-2].yyv.i,yypt[-0].yyv.i);
			warning("Extra slash removed");
			}
		divflg = TRUE;
		} break;
case 25:
#line	153	"parser.y"
{	if(yypt[-3].yyv.i > yypt[-1].yyv.i){
			i = yypt[-3].yyv.i;
			yypt[-3].yyv.i = yypt[-1].yyv.i;
			yypt[-1].yyv.i = i;
			}
		if(yypt[-1].yyv.i <= 0)
			warning("Iteration range must be positive");
		else {
			j = yypt[-4].yyv.i;
			for(k = 2; k<=yypt[-3].yyv.i;k++)
				j = mn2(RCAT,j,dupl(yypt[-4].yyv.i));
			for(i = yypt[-3].yyv.i+1; i<=yypt[-1].yyv.i; i++){
				g = dupl(yypt[-4].yyv.i);
				for(k=2;k<=i;k++)
					g = mn2(RCAT,g,dupl(yypt[-4].yyv.i));
				j = mn2(BAR,j,g);
				}
			yyval.i = j;
			}
	} break;
case 26:
#line	174	"parser.y"
{
		if(yypt[-1].yyv.i < 0)warning("Can't have negative iteration");
		else if(yypt[-1].yyv.i == 0) yyval.i = mn0(RNULLS);
		else {
			j = yypt[-2].yyv.i;
			for(k=2;k<=yypt[-1].yyv.i;k++)
				j = mn2(RCAT,j,dupl(yypt[-2].yyv.i));
			yyval.i = j;
			}
		} break;
case 27:
#line	185	"parser.y"
{
				/* from n to infinity */
		if(yypt[-2].yyv.i < 0)warning("Can't have negative iteration");
		else if(yypt[-2].yyv.i == 0) yyval.i = mn1(STAR,yypt[-3].yyv.i);
		else if(yypt[-2].yyv.i == 1)yyval.i = mn1(PLUS,yypt[-3].yyv.i);
		else {		/* >= 2 iterations minimum */
			j = yypt[-3].yyv.i;
			for(k=2;k<yypt[-2].yyv.i;k++)
				j = mn2(RCAT,j,dupl(yypt[-3].yyv.i));
			k = mn1(PLUS,dupl(yypt[-3].yyv.i));
			yyval.i = mn2(RCAT,j,k);
			}
		} break;
case 28:
#line	199	"parser.y"
{	yyval.i = mn2(RSCON,yypt[-0].yyv.i,yypt[-1].yyv.i); } break;
case 29:
#line	201	"parser.y"
{	yyval.i = mn1(CARAT,yypt[-0].yyv.i); } break;
case 30:
#line	203	"parser.y"
{	i = mn0('\n');
		if(!divflg){
			j = mn1(S2FINAL,-casecount);
			k = mn2(RCAT,yypt[-1].yyv.i,j);
			yyval.i = mn2(DIV,k,i);
			}
		else yyval.i = mn2(RCAT,yypt[-1].yyv.i,i);
		divflg = TRUE;
		} break;
case 31:
#line	213	"parser.y"
{	yyval.i = yypt[-1].yyv.i; } break;
case 32:
#line	215	"parser.y"
{	yyval.i = mn0(RNULLS); } break;
	}
	goto yystack;  /* stack new state and value */
}
