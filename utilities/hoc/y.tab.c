
#line	2	"hoc.y"
#include "hoc.h"
#define	code2(c1,c2)	code(c1); code(c2)
#define	code3(c1,c2,c3)	code(c1); code(c2); code(c3)

#line	6	"hoc.y"
typedef union  {
	Symbol	*sym;	/* symbol table pointer */
	Inst	*inst;	/* machine instruction */
	int	narg;	/* number of arguments */
	Formal	*formals;	/* list of formal parameters */
} YYSTYPE;
extern	int	yyerrflag;
#ifndef	YYMAXDEPTH
#define	YYMAXDEPTH	150
#endif
YYSTYPE	yylval;
YYSTYPE	yyval;
#define	NUMBER	57346
#define	STRING	57347
#define	PRINT	57348
#define	VAR	57349
#define	BLTIN	57350
#define	UNDEF	57351
#define	WHILE	57352
#define	FOR	57353
#define	IF	57354
#define	ELSE	57355
#define	FUNCTION	57356
#define	PROCEDURE	57357
#define	RETURN	57358
#define	FUNC	57359
#define	PROC	57360
#define	READ	57361
#define	ADDEQ	57362
#define	SUBEQ	57363
#define	MULEQ	57364
#define	DIVEQ	57365
#define	MODEQ	57366
#define	OR	57367
#define	AND	57368
#define	GT	57369
#define	GE	57370
#define	LT	57371
#define	LE	57372
#define	EQ	57373
#define	NE	57374
#define	UNARYMINUS	57375
#define	NOT	57376
#define	INC	57377
#define	DEC	57378
#define YYEOFCODE 1
#define YYERRCODE 2

#line	134	"hoc.y"

	/* end of grammar */
#include <lib9.h>
#include <bio.h>
#include <ctype.h>
char	*progname;
int	lineno = 1;
jmp_buf	begin;
int	indef;
char	*infile;	/* input file name */
Biobuf	*bin;		/* input file descriptor */
Biobuf	binbuf;
char	**gargv;	/* global argument list */
int	gargc;

int c = '\n';	/* global for use by warning() */

int	backslash(int), follow(int, int, int);
void	defnonly(char*), run(void);
void	warning(char*, char*);

yylex(void)		/* hoc6 */
{
	while ((c=Bgetc(bin)) == ' ' || c == '\t')
		;
	if (c < 0)
		return 0;
	if (c == '\\') {
		c = Bgetc(bin);
		if (c == '\n') {
			lineno++;
			return yylex();
		}
	}
	if (c == '#') {		/* comment */
		while ((c=Bgetc(bin)) != '\n' && c >= 0)
			;
		if (c == '\n')
			lineno++;
		return c;
	}
	if (c == '.' || isdigit(c)) {	/* number */
		double d;
		Bungetc(bin);
		Bgetd(bin, &d);
		yylval.sym = install("", NUMBER, d);
		return NUMBER;
	}
	if (isalpha(c) || c == '_' || c >= 0x80) {
		Symbol *s;
		char sbuf[100], *p = sbuf;
		do {
			if (p >= sbuf + sizeof(sbuf) - 1) {
				*p = '\0';
				execerror("name too long", sbuf);
			}
			*p++ = c;
		} while ((c=Bgetc(bin)) >= 0 && (isalnum(c) || c == '_' || c >= 0x80));
		Bungetc(bin);
		*p = '\0';
		if ((s=lookup(sbuf)) == 0)
			s = install(sbuf, UNDEF, 0.0);
		yylval.sym = s;
		return s->type == UNDEF ? VAR : s->type;
	}
	if (c == '"') {	/* quoted string */
		char sbuf[100], *p;
		for (p = sbuf; (c=Bgetc(bin)) != '"'; p++) {
			if (c == '\n' || c == Beof)
				execerror("missing quote", "");
			if (p >= sbuf + sizeof(sbuf) - 1) {
				*p = '\0';
				execerror("string too long", sbuf);
			}
			*p = backslash(c);
		}
		*p = 0;
		yylval.sym = (Symbol *)emalloc(strlen(sbuf)+1);
		strcpy((char*)yylval.sym, sbuf);
		return STRING;
	}
	switch (c) {
	case '+':	return follow('+', INC, follow('=', ADDEQ, '+'));
	case '-':	return follow('-', DEC, follow('=', SUBEQ, '-'));
	case '*':	return follow('=', MULEQ, '*');
	case '/':	return follow('=', DIVEQ, '/');
	case '%':	return follow('=', MODEQ, '%');
	case '>':	return follow('=', GE, GT);
	case '<':	return follow('=', LE, LT);
	case '=':	return follow('=', EQ, '=');
	case '!':	return follow('=', NE, NOT);
	case '|':	return follow('|', OR, '|');
	case '&':	return follow('&', AND, '&');
	case '\n':	lineno++; return '\n';
	default:	return c;
	}
}

backslash(int c)	/* get next char with \'s interpreted */
{
	static char transtab[] = "b\bf\fn\nr\rt\t";
	if (c != '\\')
		return c;
	c = Bgetc(bin);
	if (islower(c) && strchr(transtab, c))
		return strchr(transtab, c)[1];
	return c;
}

follow(int expect, int ifyes, int ifno)	/* look ahead for >=, etc. */
{
	int c = Bgetc(bin);

	if (c == expect)
		return ifyes;
	Bungetc(bin);
	return ifno;
}

void
yyerror(char* s)	/* report compile-time error */
{
/*rob
	warning(s, (char *)0);
	longjmp(begin, 0);
rob*/
	execerror(s, (char *)0);
}

void
execerror(char* s, char* t)	/* recover from run-time error */
{
	warning(s, t);
	Bseek(bin, 0L, 2);		/* flush rest of file */
	restoreall();
	longjmp(begin, 0);
}

void
fpecatch(void)	/* catch floating point exceptions */
{
	execerror("floating point exception", (char *) 0);
}

void
intcatch(void)	/* catch interrupts */
{
	execerror("interrupt", 0);
}

void
run(void)	/* execute until EOF */
{
	setjmp(begin);
	for (initcode(); yyparse(); initcode())
		execute(progbase);
}

void
main(int argc, char* argv[])	/* hoc6 */
{
	static int first = 1;
#ifdef YYDEBUG
	extern int yydebug;
	yydebug=3;
#endif
	progname = argv[0];
	init();
	if (argc == 1) {	/* fake an argument list */
		static char *stdinonly[] = { "-" };

		gargv = stdinonly;
		gargc = 1;
	} else if (first) {	/* for interrupts */
		first = 0;
		gargv = argv+1;
		gargc = argc-1;
	}
	Binit(&binbuf, 0, OREAD);
	bin = &binbuf;
	while (moreinput())
		run();
	exits(0);
}

moreinput(void)
{
	char *expr;
	static char buf[64];
	int fd;
	static Biobuf b;

	if (gargc-- <= 0)
		return 0;
	if (bin && bin != &binbuf)
		Bterm(bin);
	infile = *gargv++;
	lineno = 1;
	if (strcmp(infile, "-") == 0) {
		bin = &binbuf;
		infile = 0;
		return 1;
	}
	if(strncmp(infile, "-e", 2) == 0) {
		if(infile[2]==0){
			if(gargc == 0){
				fprint(2, "%s: no argument for -e\n", progname);
				return 0;
			}
			gargc--;
			expr = *gargv++;
		}else
			expr = infile+2;
		sprint(buf, "/tmp/hocXXXXXXX");
		infile = mktemp(buf);
		fd = create(infile, ORDWR|ORCLOSE, 0600);
		if(fd < 0){
			fprint(2, "%s: can't create temp. file: %r\n", progname);
			return 0;
		}
		fprint(fd, "%s\n", expr);
		/* leave fd around; file will be removed on exit */
		/* the following looks weird but is required for unix version */
		bin = &b;
		seek(fd, 0, 0);
		Binit(bin, fd, OREAD);
	} else {
		bin=Bopen(infile, OREAD);
		if (bin == 0) {
			fprint(2, "%s: can't open %s\n", progname, infile);
			return moreinput();
		}
	}
	return 1;
}

void
warning(char* s, char* t)	/* print warning message */
{
	fprint(2, "%s: %s", progname, s);
	if (t)
		fprint(2, " %s", t);
	if (infile)
		fprint(2, " in %s", infile);
	fprint(2, " near line %d\n", lineno);
	while (c != '\n' && c != Beof)
		if((c = Bgetc(bin)) == '\n')	/* flush rest of input line */
			lineno++;
}

void
defnonly(char *s)	/* warn if illegal definition */
{
	if (!indef)
		execerror(s, "used outside definition");
}
short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 0,
};
#define	YYNPROD	77
#define	YYPRIVATE 57344
#define	YYLAST	404
short	yyact[] =
{
 111, 128,   6, 118,   5, 141, 136, 104, 138, 131,
 132, 103,  62, 132,  66, 142, 123,  34,  35,  36,
  37,  38, 149,  75,  76,  77,  39, 139,  54,  55,
  56,  57,  58,  59, 137,  80,  81,  82,  83,  84,
  85,  86,  87,  88,  89,  90,  91,  92,  93,  60,
  61, 126, 124, 122, 117,  96,  97,  98,  99, 100,
 101,  36,  37,  38, 116, 112, 102,  74,  39, 105,
 105, 105,  73,  70,  69, 114, 110, 106, 107,  68,
  48,  32,  31,  30,  18,  39,  13,  10,  21,  64,
  27,  28,  29,  50,  19,  12,  11, 148,  49,  20,
  51,  52, 129, 119, 120, 113,  79,  78,  53,  72,
  63,  95,   4, 119,  94,  23, 125,   3,   1, 130,
  24,  25,  26,  16, 105,  22,  15, 133,  17, 135,
  14, 134,  71, 140,  65,   0,   0,   0,   0,   0,
 145, 143, 144, 105, 146,   0,   0,   0,   0,   0,
 147,   0,   0, 150, 151,   0, 152, 153,   7,   0,
  18,   0,  13,  10,  21,   0,  27,  28,  29,   0,
  19,  12,  11,   8,   9,  20,   0,  18,   0,  13,
  10,  21,   0,  27,  28,  29,   0,  19,  12,  11,
   0,  23,  20,   0,   0,   0,  24,  25,  26,   0,
   2,  22,   0,   0,  17,   0,   0,   0,  23,   0,
   0,   0,   0,  24,  25,  26,   0, 109,  22,   0,
   0,  17, 108,  47,  46,  40,  41,  42,  43,  44,
  45,  34,  35,  36,  37,  38,   0,   0,   0,   0,
  39,   0,   0, 127,  47,  46,  40,  41,  42,  43,
  44,  45,  34,  35,  36,  37,  38,   0,   0,   0,
   0,  39,   0,   0, 115,  47,  46,  40,  41,  42,
  43,  44,  45,  34,  35,  36,  37,  38,   0,   0,
   0,   0,  39,  33,  47,  46,  40,  41,  42,  43,
  44,  45,  34,  35,  36,  37,  38,   0,   0,  18,
 121,  39,  10,  21,   0,   0,   0,   0,   0,  19,
   0,   0,   0,   0,  20,  46,  40,  41,  42,  43,
  44,  45,  34,  35,  36,  37,  38,   0,   0,   0,
  23,  39,   0,   0,   0,  24,  25,  26,  18,  67,
  22,  10,  21,   0,   0,   0,  18,   0,  19,  10,
  21,   0,   0,  20,   0,   0,  19,   0,   0,   0,
   0,  20,   0,   0,   0,   0,   0,   0,   0,  23,
   0,   0,   0,   0,  24,  25,  26,  23,   0,  22,
   0,   0,  24,  25,  26,   0,   0,  22,  40,  41,
  42,  43,  44,  45,  34,  35,  36,  37,  38,   0,
   0,   0,   0,  39
};
short	yypact[] =
{
-1000, 156,-1000,  39,  38,  37, 239,  36,  86,  86,
   8, 342,-1000, 334,  34,  29,  28,-1000,-1000,-1000,
  27,  22, 342, 342, 342, 100,  99,-1000,-1000,-1000,
-1000,-1000,-1000,-1000, 342, 342, 342, 342, 342, 342,
 342, 342, 342, 342, 342, 342, 342, 342,-1000,-1000,
-1000,-1000,-1000,-1000, 342, 342, 342, 342, 342, 342,
-1000,-1000, 258,-1000,  21, -39, 258,-1000, 342, 342,
 342, 173,  20,  98, 342, 218,  42,  42,-1000,-1000,
  25,  25,  42,  42,  42,  42, -17, -17, -17, -17,
 -17, -17, 360, 288,  19,   9, 258, 258, 258, 258,
 258, 258, 342, 295,   7, 258, -31,   6,-1000,-1000,
-1000, 258, 342,   5, 197,-1000,  95,  95, -37, 258,
 258,-1000,  80, 342,  80, -40,-1000,-1000, -12, -42,
 -19,-1000, 342,-1000, -32,-1000,-1000,  80,  95,  80,
 258,-1000, 342,  84,-1000,-1000,-1000, -24,  80,  80,
-1000,-1000,-1000,-1000
};
short	yypgo[] =
{
   0,   1,   0,   4, 110, 134, 132,   7, 130, 126,
 123,  89,   5,  98,   3, 118, 117, 114, 111
};
short	yyr1[] =
{
   0,  15,  15,  15,  15,  15,  15,  15,   4,   4,
   4,   4,   4,   4,   3,   3,   3,   3,   3,   3,
   3,   3,   3,   3,   7,   8,   9,  10,  11,  12,
   6,   6,   6,   2,   2,   2,   2,   2,   2,   2,
   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
   5,   5,   5,   5,  17,  16,  18,  16,   1,   1,
   1,  13,  13,  13,  14,  14,  14
};
short	yyr2[] =
{
   0,   0,   2,   3,   3,   3,   3,   3,   3,   3,
   3,   3,   3,   3,   1,   1,   2,   5,   2,   6,
  10,   6,   9,   3,   1,   1,   1,   1,   0,   0,
   0,   2,   2,   1,   1,   1,   5,   4,   4,   3,
   3,   3,   3,   3,   3,   3,   2,   3,   3,   3,
   3,   3,   3,   3,   3,   2,   2,   2,   2,   2,
   1,   1,   3,   3,   0,   7,   0,   7,   0,   1,
   3,   1,   1,   1,   0,   1,   3
};
short	yychk[] =
{
-1000, -15,  44, -16,  -4,  -3,  -2,   2,  17,  18,
   7,  16,  15,   6,  -8,  -9, -10,  48,   4,  14,
  19,   8,  45,  35,  40,  41,  42,  10,  11,  12,
  44,  44,  44,  44,  34,  35,  36,  37,  38,  43,
  28,  29,  30,  31,  32,  33,  27,  26,  44, -13,
   7,  14,  15, -13,  20,  21,  22,  23,  24,  25,
  41,  42,  -2,  -4, -11,  -5,  -2,   5,  45,  45,
  45,  -6, -11,  45,  45,  -2,  -2,  -2,   7,   7,
  -2,  -2,  -2,  -2,  -2,  -2,  -2,  -2,  -2,  -2,
  -2,  -2,  -2,  -2, -17, -18,  -2,  -2,  -2,  -2,
  -2,  -2,  45,  50,  -7,  -2,  -7,  -7,  49,  44,
  -3,  -2,  45,   7,  -2,  46,  45,  45, -14,  -2,
  -2,   5,  46,  47,  46, -14,  46,  46,  -1,   7,
  -1,  46,  50,  -3,  -7,  -3,  46,  46,  50,  46,
  -2, -12,  47, -12,  -3,  -1,  -3,  -7,  13,  46,
  -3,  -3, -12, -12
};
short	yydef[] =
{
   1,  -2,   2,   0,  35,   0,   0,   0,   0,   0,
  34,  15,  28,   0,   0,   0,   0,  30,  33,  28,
   0,   0,   0,   0,   0,   0,   0,  25,  26,  27,
   3,   4,   5,   6,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   7,  64,
  71,  72,  73,  66,   0,   0,   0,   0,   0,   0,
  58,  59,  16,  35,   0,  18,  60,  61,   0,   0,
   0,   0,   0,   0,   0,   0,  46,  55,  56,  57,
  40,  41,  42,  43,  44,  45,  47,  48,  49,  50,
  51,  52,  53,  54,   0,   0,   8,   9,  10,  11,
  12,  13,  74,   0,   0,  24,   0,   0,  23,  31,
  32,  14,  74,   0,   0,  39,  68,  68,   0,  75,
  62,  63,   0,   0,   0,   0,  37,  38,   0,  69,
   0,  17,   0,  29,   0,  29,  36,   0,  68,   0,
  76,  19,   0,  21,  65,  70,  67,   0,   0,   0,
  29,  29,  22,  20
};
short	yytok1[] =
{
   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  44,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,  38,   0,   0,
  45,  46,  36,  34,  50,  35,   0,  37,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,  47,
   0,  20,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,  43,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,  48,   0,  49
};
short	yytok2[] =
{
   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,
  12,  13,  14,  15,  16,  17,  18,  19,  21,  22,
  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,
  33,  39,  40,  41,  42
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
		
case 4:
#line	31	"hoc.y"
{ code2(xpop, STOP); return 1; } break;
case 5:
#line	32	"hoc.y"
{ code(STOP); return 1; } break;
case 6:
#line	33	"hoc.y"
{ code2(printtop, STOP); return 1; } break;
case 7:
#line	34	"hoc.y"
{ yyerrok; } break;
case 8:
#line	36	"hoc.y"
{ code3(varpush,(Inst)yypt[-2].yyv.sym,assign); yyval.inst=yypt[-0].yyv.inst; } break;
case 9:
#line	37	"hoc.y"
{ code3(varpush,(Inst)yypt[-2].yyv.sym,addeq); yyval.inst=yypt[-0].yyv.inst; } break;
case 10:
#line	38	"hoc.y"
{ code3(varpush,(Inst)yypt[-2].yyv.sym,subeq); yyval.inst=yypt[-0].yyv.inst; } break;
case 11:
#line	39	"hoc.y"
{ code3(varpush,(Inst)yypt[-2].yyv.sym,muleq); yyval.inst=yypt[-0].yyv.inst; } break;
case 12:
#line	40	"hoc.y"
{ code3(varpush,(Inst)yypt[-2].yyv.sym,diveq); yyval.inst=yypt[-0].yyv.inst; } break;
case 13:
#line	41	"hoc.y"
{ code3(varpush,(Inst)yypt[-2].yyv.sym,modeq); yyval.inst=yypt[-0].yyv.inst; } break;
case 14:
#line	43	"hoc.y"
{ code(xpop); } break;
case 15:
#line	44	"hoc.y"
{ defnonly("return"); code(procret); } break;
case 16:
#line	46	"hoc.y"
{ defnonly("return"); yyval.inst=yypt[-0].yyv.inst; code(funcret); } break;
case 17:
#line	48	"hoc.y"
{ yyval.inst = yypt[-3].yyv.inst; code3(call, (Inst)yypt[-4].yyv.sym, (Inst)yypt[-1].yyv.narg); } break;
case 18:
#line	49	"hoc.y"
{ yyval.inst = yypt[-0].yyv.inst; } break;
case 19:
#line	50	"hoc.y"
{
		(yypt[-5].yyv.inst)[1] = (Inst)yypt[-1].yyv.inst;	/* body of loop */
		(yypt[-5].yyv.inst)[2] = (Inst)yypt[-0].yyv.inst; } break;
case 20:
#line	53	"hoc.y"
{
		(yypt[-9].yyv.inst)[1] = (Inst)yypt[-5].yyv.inst;	/* condition */
		(yypt[-9].yyv.inst)[2] = (Inst)yypt[-3].yyv.inst;	/* post loop */
		(yypt[-9].yyv.inst)[3] = (Inst)yypt[-1].yyv.inst;	/* body of loop */
		(yypt[-9].yyv.inst)[4] = (Inst)yypt[-0].yyv.inst; } break;
case 21:
#line	58	"hoc.y"
{	/* else-less if */
		(yypt[-5].yyv.inst)[1] = (Inst)yypt[-1].yyv.inst;	/* thenpart */
		(yypt[-5].yyv.inst)[3] = (Inst)yypt[-0].yyv.inst; } break;
case 22:
#line	61	"hoc.y"
{	/* if with else */
		(yypt[-8].yyv.inst)[1] = (Inst)yypt[-4].yyv.inst;	/* thenpart */
		(yypt[-8].yyv.inst)[2] = (Inst)yypt[-1].yyv.inst;	/* elsepart */
		(yypt[-8].yyv.inst)[3] = (Inst)yypt[-0].yyv.inst; } break;
case 23:
#line	65	"hoc.y"
{ yyval.inst = yypt[-1].yyv.inst; } break;
case 24:
#line	67	"hoc.y"
{ code(STOP); } break;
case 25:
#line	69	"hoc.y"
{ yyval.inst = code3(whilecode,STOP,STOP); } break;
case 26:
#line	71	"hoc.y"
{ yyval.inst = code(forcode); code3(STOP,STOP,STOP); code(STOP); } break;
case 27:
#line	73	"hoc.y"
{ yyval.inst = code(ifcode); code3(STOP,STOP,STOP); } break;
case 28:
#line	75	"hoc.y"
{ yyval.inst = progp; } break;
case 29:
#line	77	"hoc.y"
{ code(STOP); yyval.inst = progp; } break;
case 30:
#line	79	"hoc.y"
{ yyval.inst = progp; } break;
case 33:
#line	83	"hoc.y"
{ yyval.inst = code2(constpush, (Inst)yypt[-0].yyv.sym); } break;
case 34:
#line	84	"hoc.y"
{ yyval.inst = code3(varpush, (Inst)yypt[-0].yyv.sym, eval); } break;
case 36:
#line	87	"hoc.y"
{ yyval.inst = yypt[-3].yyv.inst; code3(call,(Inst)yypt[-4].yyv.sym,(Inst)yypt[-1].yyv.narg); } break;
case 37:
#line	88	"hoc.y"
{ yyval.inst = code2(varread, (Inst)yypt[-1].yyv.sym); } break;
case 38:
#line	89	"hoc.y"
{ yyval.inst=yypt[-1].yyv.inst; code2(bltin, (Inst)yypt[-3].yyv.sym->u.ptr); } break;
case 39:
#line	90	"hoc.y"
{ yyval.inst = yypt[-1].yyv.inst; } break;
case 40:
#line	91	"hoc.y"
{ code(add); } break;
case 41:
#line	92	"hoc.y"
{ code(sub); } break;
case 42:
#line	93	"hoc.y"
{ code(mul); } break;
case 43:
#line	94	"hoc.y"
{ code(div_); } break;
case 44:
#line	95	"hoc.y"
{ code(mod); } break;
case 45:
#line	96	"hoc.y"
{ code (power); } break;
case 46:
#line	97	"hoc.y"
{ yyval.inst=yypt[-0].yyv.inst; code(negate); } break;
case 47:
#line	98	"hoc.y"
{ code(gt); } break;
case 48:
#line	99	"hoc.y"
{ code(ge); } break;
case 49:
#line	100	"hoc.y"
{ code(lt); } break;
case 50:
#line	101	"hoc.y"
{ code(le); } break;
case 51:
#line	102	"hoc.y"
{ code(eq); } break;
case 52:
#line	103	"hoc.y"
{ code(ne); } break;
case 53:
#line	104	"hoc.y"
{ code(and); } break;
case 54:
#line	105	"hoc.y"
{ code(or); } break;
case 55:
#line	106	"hoc.y"
{ yyval.inst = yypt[-0].yyv.inst; code(not); } break;
case 56:
#line	107	"hoc.y"
{ yyval.inst = code2(preinc,(Inst)yypt[-0].yyv.sym); } break;
case 57:
#line	108	"hoc.y"
{ yyval.inst = code2(predec,(Inst)yypt[-0].yyv.sym); } break;
case 58:
#line	109	"hoc.y"
{ yyval.inst = code2(postinc,(Inst)yypt[-1].yyv.sym); } break;
case 59:
#line	110	"hoc.y"
{ yyval.inst = code2(postdec,(Inst)yypt[-1].yyv.sym); } break;
case 60:
#line	112	"hoc.y"
{ code(prexpr); } break;
case 61:
#line	113	"hoc.y"
{ yyval.inst = code2(prstr, (Inst)yypt[-0].yyv.sym); } break;
case 62:
#line	114	"hoc.y"
{ code(prexpr); } break;
case 63:
#line	115	"hoc.y"
{ code2(prstr, (Inst)yypt[-0].yyv.sym); } break;
case 64:
#line	117	"hoc.y"
{ yypt[-0].yyv.sym->type=FUNCTION; indef=1; } break;
case 65:
#line	118	"hoc.y"
{ code(procret); define(yypt[-5].yyv.sym, yypt[-2].yyv.formals); indef=0; } break;
case 66:
#line	119	"hoc.y"
{ yypt[-0].yyv.sym->type=PROCEDURE; indef=1; } break;
case 67:
#line	120	"hoc.y"
{ code(procret); define(yypt[-5].yyv.sym, yypt[-2].yyv.formals); indef=0; } break;
case 68:
#line	122	"hoc.y"
{ yyval.formals = 0; } break;
case 69:
#line	123	"hoc.y"
{ yyval.formals = formallist(yypt[-0].yyv.sym, 0); } break;
case 70:
#line	124	"hoc.y"
{ yyval.formals = formallist(yypt[-2].yyv.sym, yypt[-0].yyv.formals); } break;
case 74:
#line	130	"hoc.y"
{ yyval.narg = 0; } break;
case 75:
#line	131	"hoc.y"
{ yyval.narg = 1; } break;
case 76:
#line	132	"hoc.y"
{ yyval.narg = yypt[-2].yyv.narg + 1; } break;
	}
	goto yystack;  /* stack new state and value */
}
