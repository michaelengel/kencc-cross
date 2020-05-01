
#line	2	"a.y"
#include "a.h"

#line	4	"a.y"
typedef union 	{
	Sym	*sym;
	long	lval;
	double	dval;
	char	sval[8];
	Gen	gen;
	Gen2	gen2;
} YYSTYPE;
extern	int	yyerrflag;
#ifndef	YYMAXDEPTH
#define	YYMAXDEPTH	150
#endif
YYSTYPE	yylval;
YYSTYPE	yyval;
#define	LTYPE0	57346
#define	LTYPE1	57347
#define	LTYPE2	57348
#define	LTYPE3	57349
#define	LTYPE4	57350
#define	LTYPEC	57351
#define	LTYPED	57352
#define	LTYPEN	57353
#define	LTYPER	57354
#define	LTYPET	57355
#define	LTYPES	57356
#define	LTYPEM	57357
#define	LTYPEI	57358
#define	LCONST	57359
#define	LFP	57360
#define	LPC	57361
#define	LSB	57362
#define	LBREG	57363
#define	LLREG	57364
#define	LSREG	57365
#define	LFREG	57366
#define	LFCONST	57367
#define	LSCONST	57368
#define	LSP	57369
#define	LNAME	57370
#define	LLAB	57371
#define	LVAR	57372
#define YYEOFCODE 1
#define YYERRCODE 2
short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 0,
};
#define	YYNPROD	111
#define	YYPRIVATE 57344
#define	yydebug	1
#define	YYLAST	494
short	yyact[] =
{
  42,  54,   2,  40,  73,  33, 105,  55,  41,  52,
 216, 215,  74, 213, 100,  63,  48,  47,  79,  44,
 209,  78,  57,  77, 177,  94,  75,  62,  94,  86,
  88,  90, 207, 147,  45,  68, 200, 198, 188,  93,
 187, 178,  95, 148,  94,  64,  65,  46, 102, 103,
 104,  61,  66, 201, 195,  49, 110, 179, 190, 176,
 151, 127,  63, 119, 101,  97,  27,  94, 146, 189,
 131, 120, 121,  79, 118, 111,  78, 124,  77, 130,
 126,  75, 125,  48,  47,  53, 129, 128, 123, 117,
 116, 109,  29,  26, 132, 133,  32,  25,  23,  59,
  24,  45, 192, 191,  32,  22,  50, 206, 153, 154,
 205, 204,  64,  65,  46,  94, 102,  96, 159,  66,
 197, 144,  49, 160, 162, 161, 145, 158, 150,  48,
  47, 185, 210, 183, 159,  94,  94,  94,  94,  94,
 184, 144,  94,  94,  94,  30, 145,  45, 180, 166,
 167, 168, 169, 170,  34,  28, 173, 174, 175, 186,
  46, 136, 137, 138,  83,  66, 122,  55,  49, 211,
  96,  70,  94,  94,  82,  48,  47,  76, 196, 208,
 181, 106, 199, 107, 108, 172, 193, 194, 107, 108,
 152, 202, 203,  45, 171,   6,  92,  35,  37,  39,
  36,  91, 157,  38,  80,  65,  46,   1,  89, 212,
  72,  43, 214,  87,  49, 163, 164, 165,  48,  47,
  76,  85,  81,  71,  69, 143, 142, 141, 139, 140,
 134, 135, 136, 137, 138,  67,  45,  48,  47,  58,
  35,  37,  39,  36,  56,  51,  38,  80,  65,  46,
  60, 182,   0,   0,  43,  45,   0,  49,   0,  35,
  37,  39,  36,  48,  47,  38,  50, 149,  46,   0,
   0,   0,   0,  43,   0,  55,  49,   0,   0,   0,
   0,  45,  48,  47,   0,  35,  37,  39,  36,   0,
   0,  38,  50,   0,  46,   0,   0,   0,  84,  43,
  45,   0,  49,   0,  35,  37,  39,  36,  48,  47,
  38,  50,   0,  46,   0,   0,   0,  31,  43,   0,
   0,  49,   0,   0,   0,   0,  45,   0,   0,   0,
  35,  37,  39,  36,   0,   0,  38,  50,   7,  46,
   0,   0,   0,   0,  43,   0,   0,  49,   0,   0,
   9,  10,  11,  12,  13,  17,  15,  18,  14,  16,
  19,  20,  21,  48,  47, 142, 141, 139, 140, 134,
 135, 136, 137, 138,   4,   3,   8,   0,   5,  48,
 115,  45,   0,  48,  47,  35,  37,  39,  36,  48,
  47,  38,   0,   0,  46,  48,  47,  45,   0,  43,
   0,  45,  49,   0,   0, 113, 112,  45,  50, 156,
  46,   0,  98,  45,  46, 114,   0,  99,  49,  66,
  46, 155,  49,  48,  47,  66,  46,   0,  49,  48,
  47,  66,   0,   0,  49, 134, 135, 136, 137, 138,
   0,  45,   0,   0,   0,   0,   0,  45,   0,   0,
   0,   0,  50,   0,  46,   0,   0,   0,   0,  43,
  46,   0,  49,   0,   0,  66,   0,   0,  49, 143,
 142, 141, 139, 140, 134, 135, 136, 137, 138, 141,
 139, 140, 134, 135, 136, 137, 138, 139, 140, 134,
 135, 136, 137, 138
};
short	yypact[] =
{
-1000, 336,-1000,  64,  57,-1000,  55,  51,  23,  48,
 273, 228, 228, 299,   7,  68, 414, 166, 254, 228,
 228, 228,-1000,-1000, 420,-1000,-1000, 420,-1000,-1000,
-1000, 299,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,  20, 380,  19,-1000,-1000, 420, 420, 420,
 174,-1000,  47,-1000,-1000, 370,-1000,  46,-1000,  45,
-1000,  74,-1000,  18, 179, 179, 420,-1000, 154,-1000,
  44,-1000, 209,-1000,-1000,-1000, 354,-1000,-1000,  16,
 174,-1000,-1000,-1000, 299,-1000,  42,-1000,  35,-1000,
  26, 336, 336, 465,-1000, 465,-1000, 109,  22,  -3,
 221,  96,-1000,-1000,-1000,  15, 182, 420, 420,-1000,
-1000,-1000,-1000,-1000, 386, 374, 299, 228,-1000, 105,
-1000,-1000, 420, 120,-1000,-1000,-1000,  89,  15, 299,
 299, 299,-1000,-1000, 420, 420, 420, 420, 420, 187,
 177, 420, 420, 420,  13,  -5,  12, 420,-1000,-1000,
 169, 103, 179,-1000,-1000,  -6,-1000,-1000,-1000,  -8,
  25,-1000,  14,  62,  61,-1000, 150, 150,-1000,-1000,
-1000, 420, 420, 480, 473, 360,   9, 420,-1000,  88,
  -9, 420, -10,-1000,-1000,-1000,   8,-1000,-1000, -40,
 -40,  79,  77, 426, 426,  75, -14, 168,-1000, -26,
-1000, 102,-1000,-1000,-1000,-1000, 158,-1000, 420,-1000,
 -33, 420, -35,-1000, -36,-1000,-1000
};
short	yypgo[] =
{
   0,   0,  14, 251,   6, 154,   1,   5,  19,  12,
  85,   9,   4,   3,   8, 155, 250, 145, 245, 244,
 239, 235, 224, 223, 222, 221, 213, 208, 207,   2,
 201, 196, 195
};
short	yyr1[] =
{
   0,  28,  28,  30,  29,  31,  29,  29,  29,  29,
  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
  32,  32,  32,  32,  32,  15,  15,  19,  20,  18,
  18,  17,  17,  16,  16,  21,  22,  22,  23,  23,
  24,  24,  25,  25,  26,  26,  27,  27,  27,  10,
  10,  12,  12,  12,  12,  12,  12,  11,  11,   9,
   9,   9,   7,   7,   7,   7,   7,   6,   6,   6,
   6,   6,   6,   5,   5,  13,  13,  13,  13,  13,
  13,  13,  13,  13,  14,  14,   8,   8,   4,   4,
   4,   3,   3,   3,   1,   1,   1,   1,   1,   1,
   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
   2
};
short	yyr2[] =
{
   0,   0,   2,   0,   4,   0,   4,   1,   2,   2,
   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,
   2,   2,   2,   2,   2,   0,   1,   3,   3,   2,
   1,   2,   1,   2,   1,   5,   3,   5,   2,   1,
   1,   1,   3,   5,   3,   5,   2,   1,   3,   1,
   1,   1,   1,   2,   2,   1,   1,   1,   1,   4,
   2,   2,   1,   1,   1,   1,   1,   2,   2,   2,
   2,   4,   3,   1,   1,   1,   4,   4,   6,   9,
   3,   3,   5,   8,   1,   6,   5,   7,   0,   2,
   2,   1,   1,   1,   1,   1,   2,   2,   2,   3,
   1,   3,   3,   3,   3,   3,   4,   4,   3,   3,
   3
};
short	yychk[] =
{
-1000, -28, -29,  39,  38,  42, -32,   2,  40,  14,
  15,  16,  17,  18,  22,  20,  23,  19,  21,  24,
  25,  26,  41,  41,  43,  42,  42,  43, -15,  44,
 -17,  44, -10,  -7,  -5,  31,  34,  32,  37,  33,
 -13, -14,  -1,  45,  -8,  27,  40,  10,   9,  48,
  38, -18, -11, -10,  -6,  47, -19, -11, -20, -10,
 -16,  44,  -9,  -1,  38,  39,  45, -21,  -8, -22,
  -5, -23,  44, -12,  -9, -14,  11,  -7, -13,  -1,
  38, -24, -15, -17,  44, -25, -11, -26, -11, -27,
 -11, -30, -31,  -2,  -1,  -2, -10,  45,  32,  37,
  -2,  45,  -1,  -1,  -1,  -4,   7,   9,  10,  44,
  -1,  -8,  36,  35,  45,  10,  44,  44,  -9,  45,
  -4,  -4,  12,  44, -12,  -7, -13,  45,  -4,  44,
  44,  44, -29, -29,   9,  10,  11,  12,  13,   7,
   8,   6,   5,   4,  32,  37,  46,  11,  46,  46,
  32,  45,   8,  -1,  -1,  35,  35, -10, -11,  29,
  -1,  -6,  -1, -10, -10, -10,  -2,  -2,  -2,  -2,
  -2,   7,   8,  -2,  -2,  -2,  46,  11,  46,  45,
  -1,  11,  -3,  30,  37,  28,  -4,  46,  46,  44,
  44,  41,  41,  -2,  -2,  45,  -1,  32,  46,  -1,
  46,  45,  -6,  -6,  32,  33,  32,  46,  11,  46,
  30,  11,  -1,  46,  -1,  46,  46
};
short	yydef[] =
{
   1,  -2,   2,   0,   0,   7,   0,   0,   0,  25,
   0,   0,   0,   0,   0,   0,   0,   0,  25,   0,
   0,   0,   3,   5,   0,   8,   9,   0,  12,  26,
  13,   0,  32,  49,  50,  62,  63,  64,  65,  66,
  73,  74,  75,   0,  84,  94,  95,   0,   0,   0,
  88,  14,  30,  57,  58,   0,  15,   0,  16,   0,
  17,   0,  34,   0,  88,  88,   0,  18,   0,  19,
   0,  20,   0,  39,  51,  52,   0,  55,  56,  75,
  88,  21,  40,  41,  26,  22,   0,  23,   0,  24,
  47,   0,   0,  10, 100,  11,  31,   0,   0,   0,
   0,   0,  96,  97,  98,   0,   0,   0,   0,  29,
  67,  68,  69,  70,   0,   0,   0,   0,  33,   0,
  60,  61,   0,   0,  38,  53,  54,   0,  60,   0,
   0,  46,   4,   6,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  80,   0,  81,  99,
   0,   0,  88,  89,  90,   0,  72,  27,  28,   0,
   0,  36,   0,  42,  44,  48, 101, 102, 103, 104,
 105,   0,   0, 108, 109, 110,  76,   0,  77,   0,
   0,   0,   0,  91,  92,  93,   0,  71,  59,   0,
   0,   0,   0, 106, 107,   0,   0,   0,  82,   0,
  86,   0,  35,  37,  43,  45,   0,  78,   0,  85,
   0,   0,   0,  87,   0,  83,  79
};
short	yytok1[] =
{
   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  47,  13,   6,   0,
  45,  46,  11,   9,  44,  10,   0,  12,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,  41,  42,
   7,  43,   8,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   5,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   4,   0,  48
};
short	yytok2[] =
{
   2,   3,  14,  15,  16,  17,  18,  19,  20,  21,
  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,
  32,  33,  34,  35,  36,  37,  38,  39,  40
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
#line	35	"a.y"
{
		if(yypt[-1].yyv.sym->value != pc)
			yyerror("redeclaration of %s", yypt[-1].yyv.sym->name);
		yypt[-1].yyv.sym->value = pc;
	} break;
case 5:
#line	42	"a.y"
{
		yypt[-1].yyv.sym->type = LLAB;
		yypt[-1].yyv.sym->value = pc;
	} break;
case 10:
#line	53	"a.y"
{
		yypt[-2].yyv.sym->type = LVAR;
		yypt[-2].yyv.sym->value = yypt[-0].yyv.lval;
	} break;
case 11:
#line	58	"a.y"
{
		if(yypt[-2].yyv.sym->value != yypt[-0].yyv.lval)
			yyerror("redeclaration of %s", yypt[-2].yyv.sym->name);
		yypt[-2].yyv.sym->value = yypt[-0].yyv.lval;
	} break;
case 12:
#line	63	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 13:
#line	64	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 14:
#line	65	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 15:
#line	66	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 16:
#line	67	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 17:
#line	68	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 18:
#line	69	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 19:
#line	70	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 20:
#line	71	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 21:
#line	72	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 22:
#line	73	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 23:
#line	74	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 24:
#line	75	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 25:
#line	78	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = nullgen;
	} break;
case 26:
#line	83	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = nullgen;
	} break;
case 27:
#line	90	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 28:
#line	97	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 29:
#line	104	"a.y"
{
		yyval.gen2.from = yypt[-1].yyv.gen;
		yyval.gen2.to = nullgen;
	} break;
case 30:
#line	109	"a.y"
{
		yyval.gen2.from = yypt[-0].yyv.gen;
		yyval.gen2.to = nullgen;
	} break;
case 31:
#line	116	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 32:
#line	121	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 33:
#line	128	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 34:
#line	133	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 35:
#line	140	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.from.scale = yypt[-2].yyv.lval;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 36:
#line	148	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 37:
#line	153	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.from.scale = yypt[-2].yyv.lval;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 38:
#line	161	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 39:
#line	166	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 42:
#line	177	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 43:
#line	182	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.to = yypt[-2].yyv.gen;
		if(yyval.gen2.from.index != D_NONE)
			yyerror("dp shift with lhs index");
		yyval.gen2.from.index = yypt[-0].yyv.lval;
	} break;
case 44:
#line	192	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 45:
#line	197	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.to = yypt[-2].yyv.gen;
		if(yyval.gen2.to.index != D_NONE)
			yyerror("dp move with lhs index");
		yyval.gen2.to.index = yypt[-0].yyv.lval;
	} break;
case 46:
#line	207	"a.y"
{
		yyval.gen2.from = yypt[-1].yyv.gen;
		yyval.gen2.to = nullgen;
	} break;
case 47:
#line	212	"a.y"
{
		yyval.gen2.from = yypt[-0].yyv.gen;
		yyval.gen2.to = nullgen;
	} break;
case 48:
#line	217	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 53:
#line	230	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
	} break;
case 54:
#line	234	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
	} break;
case 59:
#line	246	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_BRANCH;
		yyval.gen.offset = yypt[-3].yyv.lval + pc;
	} break;
case 60:
#line	252	"a.y"
{
		yyval.gen = nullgen;
		if(pass == 2)
			yyerror("undefined label: %s", yypt[-1].yyv.sym->name);
		yyval.gen.type = D_BRANCH;
		yyval.gen.sym = yypt[-1].yyv.sym;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 61:
#line	261	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_BRANCH;
		yyval.gen.sym = yypt[-1].yyv.sym;
		yyval.gen.offset = yypt[-1].yyv.sym->value + yypt[-0].yyv.lval;
	} break;
case 62:
#line	270	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 63:
#line	275	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 64:
#line	280	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 65:
#line	285	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SP;
	} break;
case 66:
#line	290	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 67:
#line	297	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_CONST;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 68:
#line	303	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
		yyval.gen.index = yypt[-0].yyv.gen.type;
		yyval.gen.type = D_ADDR;
		/*
		if($2.type == D_AUTO || $2.type == D_PARAM)
			yyerror("constant cannot be automatic: %s",
				$2.sym->name);
		 */
	} break;
case 69:
#line	314	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SCONST;
		memcpy(yyval.gen.sval, yypt[-0].yyv.sval, sizeof(yyval.gen.sval));
	} break;
case 70:
#line	320	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = yypt[-0].yyv.dval;
	} break;
case 71:
#line	326	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = yypt[-1].yyv.dval;
	} break;
case 72:
#line	332	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = -yypt[-0].yyv.dval;
	} break;
case 75:
#line	344	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_NONE;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 76:
#line	350	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+yypt[-1].yyv.lval;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 77:
#line	356	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_SP;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 78:
#line	362	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_NONE;
		yyval.gen.offset = yypt[-5].yyv.lval;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 79:
#line	371	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+yypt[-6].yyv.lval;
		yyval.gen.offset = yypt[-8].yyv.lval;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 80:
#line	380	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+yypt[-1].yyv.lval;
	} break;
case 81:
#line	385	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_SP;
	} break;
case 82:
#line	390	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_NONE;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 83:
#line	398	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+yypt[-6].yyv.lval;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 84:
#line	408	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
	} break;
case 85:
#line	412	"a.y"
{
		yyval.gen = yypt[-5].yyv.gen;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 86:
#line	421	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-1].yyv.lval;
		yyval.gen.sym = yypt[-4].yyv.sym;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 87:
#line	428	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_STATIC;
		yyval.gen.sym = yypt[-6].yyv.sym;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 88:
#line	436	"a.y"
{
		yyval.lval = 0;
	} break;
case 89:
#line	440	"a.y"
{
		yyval.lval = yypt[-0].yyv.lval;
	} break;
case 90:
#line	444	"a.y"
{
		yyval.lval = -yypt[-0].yyv.lval;
	} break;
case 92:
#line	451	"a.y"
{
		yyval.lval = D_AUTO;
	} break;
case 95:
#line	459	"a.y"
{
		yyval.lval = yypt[-0].yyv.sym->value;
	} break;
case 96:
#line	463	"a.y"
{
		yyval.lval = -yypt[-0].yyv.lval;
	} break;
case 97:
#line	467	"a.y"
{
		yyval.lval = yypt[-0].yyv.lval;
	} break;
case 98:
#line	471	"a.y"
{
		yyval.lval = ~yypt[-0].yyv.lval;
	} break;
case 99:
#line	475	"a.y"
{
		yyval.lval = yypt[-1].yyv.lval;
	} break;
case 101:
#line	482	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval + yypt[-0].yyv.lval;
	} break;
case 102:
#line	486	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval - yypt[-0].yyv.lval;
	} break;
case 103:
#line	490	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval * yypt[-0].yyv.lval;
	} break;
case 104:
#line	494	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval / yypt[-0].yyv.lval;
	} break;
case 105:
#line	498	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval % yypt[-0].yyv.lval;
	} break;
case 106:
#line	502	"a.y"
{
		yyval.lval = yypt[-3].yyv.lval << yypt[-0].yyv.lval;
	} break;
case 107:
#line	506	"a.y"
{
		yyval.lval = yypt[-3].yyv.lval >> yypt[-0].yyv.lval;
	} break;
case 108:
#line	510	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval & yypt[-0].yyv.lval;
	} break;
case 109:
#line	514	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval ^ yypt[-0].yyv.lval;
	} break;
case 110:
#line	518	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval | yypt[-0].yyv.lval;
	} break;
	}
	goto yystack;  /* stack new state and value */
}
