
#line	2	"a.y"
#include "a.h"

#line	4	"a.y"
typedef union 
{
	Sym	*sym;
	long	lval;
	double	dval;
	char	sval[8];
	Gen	gen;
} YYSTYPE;
extern	int	yyerrflag;
#ifndef	YYMAXDEPTH
#define	YYMAXDEPTH	150
#endif
YYSTYPE	yylval;
YYSTYPE	yyval;
#define	LADD	57346
#define	LMUL	57347
#define	LBEQ	57348
#define	LBR	57349
#define	LBRET	57350
#define	LCALL	57351
#define	LMOVB	57352
#define	LMOVBU	57353
#define	LMOVW	57354
#define	LLUI	57355
#define	LSYS	57356
#define	LSWAP	57357
#define	LAMO	57358
#define	LCONST	57359
#define	LSP	57360
#define	LSB	57361
#define	LFP	57362
#define	LPC	57363
#define	LREG	57364
#define	LR	57365
#define	LCTL	57366
#define	LDATA	57367
#define	LTEXT	57368
#define	LWORD	57369
#define	LSCONST	57370
#define	LFCONST	57371
#define	LNAME	57372
#define	LLAB	57373
#define	LVAR	57374
#define YYEOFCODE 1
#define YYERRCODE 2
short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 0,
};
#define	YYNPROD	85
#define	YYPRIVATE 57344
#define	yydebug	1
#define	YYLAST	512
short	yyact[] =
{
  76,  59,  84,   2, 148, 206,  39,  33, 211, 198,
 186, 183, 182,  41, 140,  89,  55,  55,  55,  65,
  34, 199,  69,  65,  65, 152, 184, 181,  35,  48,
  47,  96,  38,  32,  79, 109,  52,  83,  60,  81,
 208,  68, 192,  50,  75,  77,  87,  45,  90,  91,
  92,  58,  64,  67, 191, 190, 189, 180,  72,  97,
  42,  43,  46, 106, 104, 178,  31,  66, 177, 112,
  49, 111, 110,  88, 108, 107, 103, 114, 115, 102,
  51,  57,  61, 135, 101, 100, 138, 139,  99, 134,
  95,  94,  93,  82, 144,  80,  55, 132,  78, 128,
 143, 130,  30,  55,  27,  28,  29, 129,  26, 131,
 136, 133, 137, 165, 166, 146, 136,  36,  37, 207,
 154, 155, 156, 157, 159, 137,  36,  37, 160, 161,
 113,  54, 163, 167, 168, 169, 170, 171,  53, 162,
 174, 175, 176, 150, 149, 151, 164, 173, 185, 153,
  63,  40,  48,  47,  70,  71, 188, 187, 142, 172,
 147, 119, 120, 121,  48,  47,   7, 158,  48,  47,
  45,  98,  74,  85,  86,  36,  37,  85,  86,  73,
   1, 135,  45,  42,  43,  46,  45, 197, 193, 194,
  66,  36,  37,  49, 204, 145,  43,  46, 195, 196,
 205,  46,  44,  10,   0,  49,  66, 106,   0,  49,
 200,  90,   0, 137,   0,   0,   0,   0,   8, 201,
 117, 118, 119, 120, 121, 202, 203,   0,   0, 212,
   9,  25,  11,  12,  13,  14,  15,  16,  17,  18,
  19,  20,  21,   0,  48,  47,   0,   0,   0,   0,
   0,  23,  22,  24,   0,   0,   4,   3,   5,   0,
   0,   6,  45,  48, 210,   0,   0,  36,  37, 150,
 149, 151, 136,  36,  37,  56,   0,  46,   0,   0,
   0,  45,  44,   0,  62,  49, 150, 149, 151,   0,
  36,  37, 105, 209,  56,   0,  46,  48,  47,   0,
   0,  44,   0,   0,  49, 126, 125, 124, 122, 123,
 117, 118, 119, 120, 121,  45,   0,   0,   0,   0,
  36,  37,   0,   0,   0,   0,   0,   0,  56,   0,
  46,   0,  48,  47,   0,  44,  48,  47,  49, 126,
 125, 124, 122, 123, 117, 118, 119, 120, 121, 179,
  45,   0,   0,   0,  45,   0,   0,  48,  47,   0,
   0, 105,   0,  56,   0,  46,   0,  56,   0,  46,
  44,   0,   0,  49,  66,  45,  33,  49,  48,  47,
   0,   0,   0, 141,  48,  47,   0,   0,  42,  43,
  46,   0,   0,   0,   0,  44,  45,   0,  49,   0,
  48,  47,  45,   0,   0,   0,   0,   0, 213,  48,
  47,  46,   0,   0,   0,   0,  66,  46,  45,  49,
   0,   0,  66,   0,  33,  49,   0,  45,  48,  47,
   0,  56,   0,  46,   0,   0,   0,   0,  44,   0,
  56,  49,  46,   0,   0,   0,  45,  66,   0,   0,
  49, 126, 125, 124, 122, 123, 117, 118, 119, 120,
 121,  46,   0,   0,   0,   0,  66,   0,   0,  49,
 126, 125, 124, 122, 123, 117, 118, 119, 120, 121,
 125, 124, 122, 123, 117, 118, 119, 120, 121,   0,
   0,   0, 127, 124, 122, 123, 117, 118, 119, 120,
 121, 122, 123, 117, 118, 119, 120, 121,   0,   0,
   0, 116
};
short	yypact[] =
{
-1000, 216,-1000,  65,  61,  62,-1000,  57,  21, -42,
  94,  94, 348,-1000,  94, 288, 391, 235, 327, -42,
  94, 419, 400, 400, -42,-1000,-1000,-1000, 419, 419,
-1000,-1000,  52, 419,  49,-1000,-1000,  -8,  47,-1000,
-1000, -10, 168, 168, 159,-1000,-1000, 419, 419, 419,
  46,  45,  44,-1000,-1000, -16, 164,  42,  39,  38,
  33,  30, 323,  29,  28, -12, 419,-1000,  26,  25,
  23, 118,-1000, 216, 216, 466,-1000, 447,  94,-1000,
  94, 419, 143,  85,-1000, 419, 419,-1000, -34, 335,
-1000,-1000,-1000, 155,  94, 391, 258, -22, 141,  94,
  94,  94, 288,  94,-1000,-1000, -16,  94,  94, 115,
  94,  94, 375, 419,-1000,-1000,-1000, 419, 419, 419,
 419, 419, 152, 139, 419, 419, 419,-1000,-1000,  22,
-1000,  19, 301,  11,-1000, -20, -36, -37,-1000,-1000,
-1000,-1000,-1000,-1000, -21, 164,-1000,-1000, -38,-1000,
-1000,-1000, 115, 168,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,  10,   9,-1000,   8,  -4, 150, 150,-1000,
-1000,-1000, 419, 419, 494, 487, 475,  94,  94,-1000,
  20,  79,-1000,-1000, 241, -22,-1000, -39, -26,  94,
  94, -42, -44, 211, 211,-1000,-1000,-1000,-1000,  90,
-1000,  -6,-1000,-1000,-1000,-1000, 254, -40,  94,-1000,
 369,-1000,-1000,-1000
};
short	yypgo[] =
{
   0,   0,  15,   4,   2,  28, 203,  20,  64, 131,
 138,   6,  33,   1, 200, 180,   3, 179, 172, 166
};
short	yyr1[] =
{
   0,  15,  15,  17,  16,  18,  16,  16,  16,  16,
  16,  16,  19,  19,  19,  19,  19,  19,  19,  19,
  19,  19,  19,  19,  19,  19,  19,  19,  19,  19,
  19,  19,  19,  19,  19,  19,  19,  19,  19,  19,
  19,  19,  11,  11,  11,   6,   6,   8,   8,  10,
  10,   9,   9,   9,   4,   4,   4,   3,   3,   3,
   7,   5,   5,  13,  13,  14,  14,  12,   1,   1,
   1,   1,   1,   1,   2,   2,   2,   2,   2,   2,
   2,   2,   2,   2,   2
};
short	yyr2[] =
{
   0,   0,   2,   0,   4,   0,   4,   4,   4,   1,
   2,   2,   4,   4,   6,   6,   6,   4,   2,   2,
   1,   4,   4,   4,   4,   4,   4,   4,   4,   4,
   4,   4,   4,   2,   6,   8,   4,   6,   6,   6,
   6,   2,   4,   2,   2,   1,   1,   1,   1,   3,
   4,   4,   5,   7,   0,   2,   2,   1,   1,   1,
   1,   1,   4,   2,   2,   2,   3,   2,   1,   1,
   2,   2,   2,   3,   1,   3,   3,   3,   3,   3,
   4,   4,   3,   3,   3
};
short	yychk[] =
{
-1000, -15, -16,  41,  40,  42,  45, -19,   2,  14,
  -6,  16,  17,  18,  19,  20,  21,  22,  23,  24,
  25,  26,  36,  35,  37,  15,  43,  43,  44,  44,
  45,  45, -12,  49,  -7,  -5,  32,  33,  -7, -11,
 -10,  -1,  40,  41,  47,  27,  42,  10,   9,  50,
  -5,  -8,  -7, -10,  -9,  -1,  40,  -8, -12, -13,
  -7,  -8,  49,  -9, -12,  -1,  47, -12,  -7,  -1,
  -9,  -9, -12, -17, -18,  -2,  -1,  -2,  46,  -1,
  46,  47,  46,  47,  -4,   9,  10,  -4,  -5,  -2,
  -1,  -1,  -1,  46,  46,  46,  47,  -4,   7,  46,
  46,  46,  46,  46,  -8,  38,  -1,  46,  46,  47,
  46,  46,  46,  12, -16, -16,  45,   9,  10,  11,
  12,  13,   7,   8,   6,   5,   4,  45,  -7,  -5,
  -7,  -5,  -2,  -5, -11,  -1,  31,  -5,  -1,  -1,
  48,  48,  -8, -11,  -1,  40,  -7,  -8,  -3,  29,
  28,  30,  47,   8,  -7,  -7,  -7,  -7,  -8,  -7,
  -7,  -7,  -5,  -7, -12,  -1,  -1,  -2,  -2,  -2,
  -2,  -2,   7,   8,  -2,  -2,  -2,  46,  46,  48,
  46,  47,  48,  48,  47,  -4,  48,  -3,  -4,  46,
  46,  46,  46,  -2,  -2,  -7,  -7, -11,  48,  47,
  -7,  -5, -12, -12, -13, -14,  49,  29,  46,  39,
  10,  48,  -7,  39
};
short	yydef[] =
{
   1,  -2,   2,   0,   0,   0,   9,   0,   0,  45,
   0,   0,   0,  20,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,  46,   3,   5,   0,   0,
  10,  11,   0,   0,   0,  60,  61,   0,   0,  18,
  19,   0,  54,  54,   0,  68,  69,   0,   0,   0,
   0,   0,   0,  47,  48,   0,  54,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,  33,   0,   0,
   0,   0,  41,   0,   0,   0,  74,   0,   0,  67,
   0,   0,   0,   0,  43,   0,   0,  44,   0,   0,
  70,  71,  72,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,  63,  64,  67,   0,   0,   0,
   0,   0,   0,   0,   4,   6,   7,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   8,  12,  60,
  13,  60,   0,   0,  17,   0,   0,   0,  55,  56,
  49,  73,  21,  22,   0,  54,  23,  25,   0,  57,
  58,  59,   0,  54,  24,  26,  27,  28,  30,  29,
  31,  32,   0,   0,  36,   0,   0,  75,  76,  77,
  78,  79,   0,   0,  82,  83,  84,   0,   0,  62,
   0,   0,  42,  50,   0,  43,  51,   0,   0,   0,
   0,   0,   0,  80,  81,  14,  15,  16,  52,   0,
  34,   0,  37,  38,  39,  40,   0,   0,   0,  65,
   0,  53,  35,  66
};
short	yytok1[] =
{
   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  49,  13,   6,   0,
  47,  48,  11,   9,  46,  10,   0,  12,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,  43,  45,
   7,  44,   8,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   5,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   4,   0,  50
};
short	yytok2[] =
{
   2,   3,  14,  15,  16,  17,  18,  19,  20,  21,
  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,
  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,
  42
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
		
case 3:
#line	34	"a.y"
{
		if(yypt[-1].yyv.sym->value != pc)
			yyerror("redeclaration of %s", yypt[-1].yyv.sym->name);
		yypt[-1].yyv.sym->value = pc;
	} break;
case 5:
#line	41	"a.y"
{
		yypt[-1].yyv.sym->type = LLAB;
		yypt[-1].yyv.sym->value = pc;
	} break;
case 7:
#line	47	"a.y"
{
		yypt[-3].yyv.sym->type = LVAR;
		yypt[-3].yyv.sym->value = yypt[-1].yyv.lval;
	} break;
case 8:
#line	52	"a.y"
{
		if(yypt[-3].yyv.sym->value != yypt[-1].yyv.lval)
			yyerror("redeclaration of %s", yypt[-3].yyv.sym->name);
		yypt[-3].yyv.sym->value = yypt[-1].yyv.lval;
	} break;
case 12:
#line	63	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 13:
#line	67	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 14:
#line	71	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 15:
#line	75	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 16:
#line	80	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 17:
#line	85	"a.y"
{
		Gen regzero;
		regzero = nullgen;
		regzero.type = D_REG;
		regzero.reg = 0;
		outcode(yypt[-3].yyv.lval, &regzero, yypt[-2].yyv.gen.reg, &yypt[-0].yyv.gen);
	} break;
case 18:
#line	94	"a.y"
{
		outcode(yypt[-1].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 19:
#line	99	"a.y"
{
		outcode(yypt[-1].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 20:
#line	105	"a.y"
{
		outcode(yypt[-0].yyv.lval, &nullgen, NREG, &nullgen);
	} break;
case 21:
#line	110	"a.y"
{
		outcode(yypt[-3].yyv.lval, &nullgen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 22:
#line	114	"a.y"
{
		outcode(yypt[-3].yyv.lval, &nullgen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 23:
#line	119	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 24:
#line	123	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 25:
#line	127	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 26:
#line	132	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 27:
#line	136	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 28:
#line	140	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 29:
#line	144	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 30:
#line	148	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 31:
#line	163	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 32:
#line	167	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 33:
#line	173	"a.y"
{
		outcode(yypt[-1].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 34:
#line	178	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 35:
#line	183	"a.y"
{
		outcode(yypt[-7].yyv.lval, &yypt[-4].yyv.gen, (yypt[-6].yyv.lval<<16)|yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 36:
#line	188	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 37:
#line	192	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 38:
#line	197	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 39:
#line	201	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 40:
#line	205	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 41:
#line	210	"a.y"
{
		outcode(yypt[-1].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 42:
#line	216	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_BRANCH;
		yyval.gen.offset = yypt[-3].yyv.lval + pc;
	} break;
case 43:
#line	222	"a.y"
{
		yyval.gen = nullgen;
		if(pass == 2)
			yyerror("undefined label: %s", yypt[-1].yyv.sym->name);
		yyval.gen.type = D_BRANCH;
		yyval.gen.sym = yypt[-1].yyv.sym;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 44:
#line	231	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_BRANCH;
		yyval.gen.sym = yypt[-1].yyv.sym;
		yyval.gen.offset = yypt[-1].yyv.sym->value + yypt[-0].yyv.lval;
	} break;
case 49:
#line	248	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.reg = yypt[-1].yyv.lval;
		yyval.gen.offset = 0;
	} break;
case 50:
#line	255	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.reg = yypt[-1].yyv.lval;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 51:
#line	264	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.name = yypt[-1].yyv.lval;
		yyval.gen.sym = S;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 52:
#line	272	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.name = yypt[-1].yyv.lval;
		yyval.gen.sym = yypt[-4].yyv.sym;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 53:
#line	280	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.name = D_STATIC;
		yyval.gen.sym = yypt[-6].yyv.sym;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 54:
#line	289	"a.y"
{
		yyval.lval = 0;
	} break;
case 55:
#line	293	"a.y"
{
		yyval.lval = yypt[-0].yyv.lval;
	} break;
case 56:
#line	297	"a.y"
{
		yyval.lval = -yypt[-0].yyv.lval;
	} break;
case 60:
#line	308	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_REG;
		yyval.gen.reg = yypt[-0].yyv.lval;
	} break;
case 62:
#line	317	"a.y"
{
		if(yypt[-1].yyv.lval < 0 || yypt[-1].yyv.lval >= NREG)
			yyerror("register value out of range");
		yyval.lval = yypt[-1].yyv.lval;
	} break;
case 63:
#line	337	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
		yyval.gen.type = D_CONST;
	} break;
case 64:
#line	342	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SCONST;
		memcpy(yyval.gen.sval, yypt[-0].yyv.sval, sizeof(yyval.gen.sval));
	} break;
case 65:
#line	350	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = yypt[-0].yyv.dval;
	} break;
case 66:
#line	356	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = -yypt[-0].yyv.dval;
	} break;
case 67:
#line	364	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_CONST;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 69:
#line	373	"a.y"
{
		yyval.lval = yypt[-0].yyv.sym->value;
	} break;
case 70:
#line	377	"a.y"
{
		yyval.lval = -yypt[-0].yyv.lval;
	} break;
case 71:
#line	381	"a.y"
{
		yyval.lval = yypt[-0].yyv.lval;
	} break;
case 72:
#line	385	"a.y"
{
		yyval.lval = ~yypt[-0].yyv.lval;
	} break;
case 73:
#line	389	"a.y"
{
		yyval.lval = yypt[-1].yyv.lval;
	} break;
case 75:
#line	396	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval + yypt[-0].yyv.lval;
	} break;
case 76:
#line	400	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval - yypt[-0].yyv.lval;
	} break;
case 77:
#line	404	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval * yypt[-0].yyv.lval;
	} break;
case 78:
#line	408	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval / yypt[-0].yyv.lval;
	} break;
case 79:
#line	412	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval % yypt[-0].yyv.lval;
	} break;
case 80:
#line	416	"a.y"
{
		yyval.lval = yypt[-3].yyv.lval << yypt[-0].yyv.lval;
	} break;
case 81:
#line	420	"a.y"
{
		yyval.lval = yypt[-3].yyv.lval >> yypt[-0].yyv.lval;
	} break;
case 82:
#line	424	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval & yypt[-0].yyv.lval;
	} break;
case 83:
#line	428	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval ^ yypt[-0].yyv.lval;
	} break;
case 84:
#line	432	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval | yypt[-0].yyv.lval;
	} break;
	}
	goto yystack;  /* stack new state and value */
}
