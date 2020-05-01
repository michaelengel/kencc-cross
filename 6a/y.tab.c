
#line	2	"a.y"
#include "a.h"

#line	4	"a.y"
typedef union 	{
	Sym	*sym;
	vlong	lval;
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
#define	LTYPEG	57359
#define	LTYPEXC	57360
#define	LTYPEX	57361
#define	LTYPEY	57362
#define	LTYPERT	57363
#define	LCONST	57364
#define	LFP	57365
#define	LPC	57366
#define	LSB	57367
#define	LBREG	57368
#define	LLREG	57369
#define	LSREG	57370
#define	LFREG	57371
#define	LMREG	57372
#define	LXREG	57373
#define	LYREG	57374
#define	LFCONST	57375
#define	LSCONST	57376
#define	LSP	57377
#define	LNAME	57378
#define	LLAB	57379
#define	LVAR	57380
#define YYEOFCODE 1
#define YYERRCODE 2
short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 0,
};
#define	YYNPROD	131
#define	YYPRIVATE 57344
#define	yydebug	1
#define	YYLAST	600
short	yyact[] =
{
  50,  62,   2,  48,  49, 125,  81,  52,  63, 262,
 208, 261, 172, 257, 251,  71,  38, 249,  88,  87,
  82,  86,  83,  76, 237, 103, 235, 220, 110, 219,
 114, 210, 209, 114,  85,  70, 173, 238, 232, 101,
  61, 211, 176, 147, 139, 121, 117,  60, 254, 253,
 229,  37, 114, 207,  67, 171, 122, 123, 124,  37,
  65, 228, 227, 226, 130, 225, 222,  95,  97,  99,
  71, 131, 120, 108, 221, 114, 155, 116, 140, 141,
 154,  88,  87, 153,  86,  83, 152, 144, 146, 151,
 138, 150, 149, 143, 137, 148, 136,  85, 129,  34,
  32, 145, 113,  56, 135, 115,  31,  56,  55,  28,
 224,  29,  30, 223, 156, 157,  40,  42,  45,  41,
  43,  46,  47,  27,  58,  44,  53, 242, 178, 179,
  53, 184, 248, 241, 116, 114, 122, 133, 132, 234,
  58, 175,  54, 185, 187, 186,  54, 134, 252, 142,
  57,  74,  64,  63,  57, 195, 194, 168, 170, 114,
 114, 114, 114, 114,  39, 169, 114, 114, 114, 192,
 255, 250, 196, 212,  56,  55, 184, 182, 107, 168,
 170,  78,  35, 218, 213, 183, 217, 169, 215, 105,
 188, 189, 190, 191, 193, 203, 182,  53, 216, 177,
  33,  92, 202, 114, 114,   6,  56,  55, 112, 233,
 111,  72,  73,  54, 236, 127, 128,  69,  74,  91,
   1,  57, 109, 239, 240, 126, 243, 127, 128,  53,
 246, 197, 198, 199, 200, 201, 106, 104, 204, 205,
 206, 102, 100,  58, 245,  54, 160, 161, 162,  98,
  51, 256,  96,  57, 258,  94, 260,  56,  55,  84,
 163, 164, 158, 159, 160, 161, 162, 244,  56,  55,
 247, 259,  90,  79,  77, 230, 231,  75,  66,  59,
  53,  68, 214,   0,  40,  42,  45,  41,  43,  46,
  47,  53,   0,  44,  89,  73,  54,  56,  55,  84,
  80,  51,   0,  63,  57,  72,  73,  54,   0,   0,
   0,   0,  74,   0,   0,  57,   0,   0,   0,   0,
  53,   0,   0,   0,  40,  42,  45,  41,  43,  46,
  47,   0,   0,  44,  89,  73,  54,   7,   0,   0,
   0,  51,   0,  63,  57,   0,   0,   0,   0,   9,
  10,  11,  12,  13,  17,  15,  18,  14,  16,  19,
  20,  21,  24,  22,  23,  25,  26,  56,  55, 167,
 166, 165, 163, 164, 158, 159, 160, 161, 162,   0,
   0,   4,   3,   8,   0,   5,   0,   0,   0,   0,
  53,   0,  56,  55,  40,  42,  45,  41,  43,  46,
  47,   0,   0,  44,  58,   0,  54,   0,   0,   0,
   0,  51,   0,  63,  57,  53,   0,  56,  55,  40,
  42,  45,  41,  43,  46,  47,   0,   0,  44,  58,
   0,  54,   0,   0,   0,  93,  51,   0,   0,  57,
  53,   0,  56,  55,  40,  42,  45,  41,  43,  46,
  47,   0,   0,  44,  58,   0,  54,   0,   0,   0,
  36,  51,   0,   0,  57,  53,   0,  56,  55,  40,
  42,  45,  41,  43,  46,  47,   0,   0,  44,  58,
   0,  54,   0,   0,   0,   0,  51,   0,   0,  57,
  53,   0,   0,   0,  40,  42,  45,  41,  43,  46,
  47,   0,   0,  44,  56,  55,  54,   0,  56,  55,
   0,  51,   0,   0,  57, 167, 166, 165, 163, 164,
 158, 159, 160, 161, 162,   0,   0,  53,   0,   0,
   0,  53, 118,  56,  55,  56,  55,   0,   0,   0,
 119,   0, 181,  54,   0,   0,   0,  54,  74,   0,
   0,  57,  74,   0,   0,  57,  53,   0,  53, 158,
 159, 160, 161, 162,   0, 174,   0, 180,   0,   0,
   0,   0,  54,   0,  54,   0,   0,  74,   0,  74,
  57,   0,  57, 166, 165, 163, 164, 158, 159, 160,
 161, 162, 165, 163, 164, 158, 159, 160, 161, 162
};
short	yypact[] =
{
-1000, 335,-1000,  74,  60,-1000,  62,  56,  49,  47,
 408, 358, 358, 433, 165,  78, 197, 248, 383, 358,
 358, 358,  80, -47, 197, 358, -47,-1000,-1000, 526,
-1000,-1000, 526,-1000,-1000,-1000, 433,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
  -7, 495,  -8,-1000,-1000, 526, 526, 526, 218,-1000,
  46,-1000,-1000,  94,-1000,  44,-1000,  42,-1000, 259,
-1000,  -9, 206, 206, 526,-1000, 137,-1000,  41,-1000,
 288,-1000,-1000,-1000, 458,-1000,-1000,-1000, -10, 218,
-1000,-1000,-1000, 433,-1000,  40,-1000,  39,-1000,  37,
-1000,  34,-1000,  31,-1000,  28,-1000,-1000,  24,-1000,
-1000, 335, 335, 365,-1000, 365,-1000, 120,   1, -18,
 511, 104,-1000,-1000,-1000, -11, 191, 526, 526,-1000,
-1000,-1000,-1000,-1000, 524, 499, 433, 358,-1000,  97,
-1000,-1000, 526,  98,-1000,-1000,-1000, 142, -11, 433,
 433, 433, 433, 433,  98, 433,-1000,-1000, 526, 526,
 526, 526, 526, 195, 187, 526, 526, 526,  -1, -22,
 -23, -12, 526,-1000,-1000, 173, 153, 206,-1000,-1000,
 -25,-1000,-1000,-1000, -27,  22,-1000,  14,  64,  61,
-1000,  13,  11,  10,-1000,   9,  -2, 235, 235,-1000,
-1000,-1000, 526, 526, 253, 586, 578, -15, 526,-1000,
-1000, 102, -28, 526, -30,-1000,-1000,-1000, -16,-1000,
-1000, -47, -47,  96,  89, 526, 433,  80, -47, 433,
 550, 550,  95, -37, 160,-1000, -40,-1000, 113,-1000,
-1000,-1000,-1000,-1000,  -3,  -4,-1000,-1000, 159,-1000,
 526,-1000, -41, 526,  80, 526, -43,-1000,-1000,-1000,
 -45,-1000,-1000
};
short	yypgo[] =
{
   0,   0,  72, 282,   5, 164,   1,  16,   7,  20,
  40,  47,   6,   3,   4, 200, 281, 182, 279, 152,
 278, 277, 274, 273, 272, 255, 252, 249, 242, 241,
 237, 236, 222, 220,   2, 210, 208, 205
};
short	yyr1[] =
{
   0,  33,  33,  35,  34,  36,  34,  34,  34,  34,
  37,  37,  37,  37,  37,  37,  37,  37,  37,  37,
  37,  37,  37,  37,  37,  37,  37,  37,  37,  37,
  15,  15,  19,  20,  18,  18,  17,  17,  16,  16,
  21,  22,  22,  23,  23,  24,  24,  25,  25,  26,
  26,  27,  27,  27,  28,  28,  29,  29,  30,  30,
  31,  31,  32,  32,  10,  10,  12,  12,  12,  12,
  12,  12,  12,  11,  11,   9,   9,   9,   7,   7,
   7,   7,   7,   7,   7,   7,   6,   6,   6,   6,
   6,   6,   5,   5,  13,  13,  13,  13,  13,  13,
  13,  13,  13,  13,  14,  14,   8,   8,   4,   4,
   4,   3,   3,   3,   1,   1,   1,   1,   1,   1,
   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
   2
};
short	yyr2[] =
{
   0,   0,   2,   0,   4,   0,   4,   1,   2,   2,
   3,   3,   2,   2,   2,   2,   2,   2,   2,   2,
   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
   0,   1,   3,   3,   2,   1,   2,   1,   2,   1,
   5,   3,   5,   2,   1,   1,   1,   3,   5,   3,
   5,   2,   1,   3,   5,   7,   5,   7,   3,   5,
   1,   5,   0,   1,   1,   1,   1,   1,   2,   2,
   1,   1,   1,   1,   1,   4,   2,   2,   1,   1,
   1,   1,   1,   1,   1,   1,   2,   2,   2,   2,
   4,   3,   1,   1,   1,   4,   4,   6,   9,   3,
   3,   4,   5,   8,   1,   6,   5,   7,   0,   2,
   2,   1,   1,   1,   1,   1,   2,   2,   2,   3,
   1,   3,   3,   3,   3,   3,   4,   4,   3,   3,
   3
};
short	yychk[] =
{
-1000, -33, -34,  47,  46,  50, -37,   2,  48,  14,
  15,  16,  17,  18,  22,  20,  23,  19,  21,  24,
  25,  26,  28,  29,  27,  30,  31,  49,  49,  51,
  50,  50,  51, -15,  52, -17,  52, -10,  -7,  -5,
  36,  39,  37,  40,  45,  38,  41,  42, -13, -14,
  -1,  53,  -8,  32,  48,  10,   9,  56,  46, -18,
 -11, -10,  -6,  55, -19, -11, -20, -10, -16,  52,
  -9,  -1,  46,  47,  53, -21,  -8, -22,  -5, -23,
  52, -12,  -9, -14,  11,  -7, -13,  -6,  -1,  46,
 -24, -15, -17,  52, -25, -11, -26, -11, -27, -11,
 -28,  -7, -29,  -6, -30,  -5, -31, -19, -11, -32,
  -6, -35, -36,  -2,  -1,  -2, -10,  53,  37,  45,
  -2,  53,  -1,  -1,  -1,  -4,   7,   9,  10,  52,
  -1,  -8,  44,  43,  53,  10,  52,  52,  -9,  53,
  -4,  -4,  12,  52, -12,  -7, -13,  53,  -4,  52,
  52,  52,  52,  52,  52,  52, -34, -34,   9,  10,
  11,  12,  13,   7,   8,   6,   5,   4,  37,  45,
  38,  54,  11,  54,  54,  37,  53,   8,  -1,  -1,
  43,  43, -10, -11,  34,  -1,  -6,  -1, -10, -10,
 -10, -10,  -7, -10,  -6,  -1,  -7,  -2,  -2,  -2,
  -2,  -2,   7,   8,  -2,  -2,  -2,  54,  11,  54,
  54,  53,  -1,  11,  -3,  35,  45,  33,  -4,  54,
  54,  52,  52,  49,  49,  52,  52,  52,  52,  52,
  -2,  -2,  53,  -1,  37,  54,  -1,  54,  53,  -6,
  -6,  37,  38,  -1, -10,  -7,  -6, -10,  37,  54,
  11,  54,  35,  52,  52,  11,  -1,  54,  -1,  -7,
  -1,  54,  54
};
short	yydef[] =
{
   1,  -2,   2,   0,   0,   7,   0,   0,   0,  30,
   0,   0,   0,   0,   0,   0,   0,   0,  30,   0,
   0,   0,   0,   0,   0,   0,  62,   3,   5,   0,
   8,   9,   0,  12,  31,  13,   0,  37,  64,  65,
  78,  79,  80,  81,  82,  83,  84,  85,  92,  93,
  94,   0, 104, 114, 115,   0,   0,   0, 108,  14,
  35,  73,  74,   0,  15,   0,  16,   0,  17,   0,
  39,   0, 108, 108,   0,  18,   0,  19,   0,  20,
   0,  44,  66,  67,   0,  70,  71,  72,  94, 108,
  21,  45,  46,  31,  22,   0,  23,   0,  24,  52,
  25,   0,  26,   0,  27,   0,  28,  60,   0,  29,
  63,   0,   0,  10, 120,  11,  36,   0,   0,   0,
   0,   0, 116, 117, 118,   0,   0,   0,   0,  34,
  86,  87,  88,  89,   0,   0,   0,   0,  38,   0,
  76,  77,   0,   0,  43,  68,  69,   0,  76,   0,
   0,  51,   0,   0,   0,   0,   4,   6,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,  99,   0, 100, 119,   0,   0, 108, 109, 110,
   0,  91,  32,  33,   0,   0,  41,   0,  47,  49,
  53,   0,   0,   0,  58,   0,  64, 121, 122, 123,
 124, 125,   0,   0, 128, 129, 130,  95,   0,  96,
 101,   0,   0,   0,   0, 111, 112, 113,   0,  90,
  75,   0,   0,   0,   0,   0,   0,   0,   0,   0,
 126, 127,   0,   0,   0, 102,   0, 106,   0,  40,
  42,  48,  50,  54,   0,  56,  59,  61,   0,  97,
   0, 105,   0,   0,   0,   0,   0, 107,  55,  57,
   0, 103,  98
};
short	yytok1[] =
{
   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  55,  13,   6,   0,
  53,  54,  11,   9,  52,  10,   0,  12,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,  49,  50,
   7,  51,   8,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   5,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   4,   0,  56
};
short	yytok2[] =
{
   2,   3,  14,  15,  16,  17,  18,  19,  20,  21,
  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,
  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,
  42,  43,  44,  45,  46,  47,  48
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
#line	76	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 26:
#line	77	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 27:
#line	78	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 28:
#line	79	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 29:
#line	80	"a.y"
{ outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen2); } break;
case 30:
#line	83	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = nullgen;
	} break;
case 31:
#line	88	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = nullgen;
	} break;
case 32:
#line	95	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 33:
#line	102	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 34:
#line	109	"a.y"
{
		yyval.gen2.from = yypt[-1].yyv.gen;
		yyval.gen2.to = nullgen;
	} break;
case 35:
#line	114	"a.y"
{
		yyval.gen2.from = yypt[-0].yyv.gen;
		yyval.gen2.to = nullgen;
	} break;
case 36:
#line	121	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 37:
#line	126	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 38:
#line	133	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 39:
#line	138	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 40:
#line	145	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.from.scale = yypt[-2].yyv.lval;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 41:
#line	153	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 42:
#line	158	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.from.scale = yypt[-2].yyv.lval;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 43:
#line	166	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 44:
#line	171	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 47:
#line	182	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 48:
#line	187	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.to = yypt[-2].yyv.gen;
		if(yyval.gen2.from.index != D_NONE)
			yyerror("dp shift with lhs index");
		yyval.gen2.from.index = yypt[-0].yyv.lval;
	} break;
case 49:
#line	197	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 50:
#line	202	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.to = yypt[-2].yyv.gen;
		if(yyval.gen2.to.index != D_NONE)
			yyerror("dp move with lhs index");
		yyval.gen2.to.index = yypt[-0].yyv.lval;
	} break;
case 51:
#line	212	"a.y"
{
		yyval.gen2.from = yypt[-1].yyv.gen;
		yyval.gen2.to = nullgen;
	} break;
case 52:
#line	217	"a.y"
{
		yyval.gen2.from = yypt[-0].yyv.gen;
		yyval.gen2.to = nullgen;
	} break;
case 53:
#line	222	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 54:
#line	229	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.to = yypt[-2].yyv.gen;
		yyval.gen2.from.offset = yypt[-0].yyv.lval;
	} break;
case 55:
#line	235	"a.y"
{
		yyval.gen2.from = yypt[-6].yyv.gen;
		if(!isxyreg(yypt[-4].yyv.gen.type))
			yyerror("second source operand must be X/Y register");
		yyval.gen2.from.index = yypt[-4].yyv.gen.type;
		yyval.gen2.to = yypt[-2].yyv.gen;
		yyval.gen2.from.offset = yypt[-0].yyv.lval;
	} break;
case 56:
#line	246	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
		if(yypt[-4].yyv.gen.type != D_CONST)
			yyerror("illegal constant");
		yyval.gen2.to.offset = yypt[-4].yyv.gen.offset;
	} break;
case 57:
#line	254	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
		if(yypt[-6].yyv.gen.type != D_CONST)
			yyerror("illegal constant");
		yyval.gen2.to.offset = yypt[-6].yyv.gen.offset;
		if(!isxyreg(yypt[-2].yyv.gen.type))
			yyerror("second source operand must be X/Y register");
		yyval.gen2.to.index = yypt[-2].yyv.gen.type;
	} break;
case 58:
#line	267	"a.y"
{
		yyval.gen2.from = yypt[-2].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 59:
#line	272	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.from.scale = yypt[-2].yyv.lval;
		yyval.gen2.to = yypt[-0].yyv.gen;
	} break;
case 61:
#line	281	"a.y"
{
		yyval.gen2.from = yypt[-4].yyv.gen;
		yyval.gen2.to = yypt[-0].yyv.gen;
		if(isxyreg(yypt[-2].yyv.gen.type)) {
			if(isxyreg(yypt[-4].yyv.gen.type))
				yyval.gen2.from.index = yypt[-2].yyv.gen.type;
			else if(isxyreg(yypt[-0].yyv.gen.type))
				yyval.gen2.to.index = yypt[-2].yyv.gen.type;
		} else
			yyerror("second source operand must be X or Y register");
	} break;
case 62:
#line	294	"a.y"
{
		yyval.gen2.from = nullgen;
		yyval.gen2.to = nullgen;
	} break;
case 63:
#line	299	"a.y"
{
		yyval.gen2.from = yypt[-0].yyv.gen;
		yyval.gen2.to = nullgen;
	} break;
case 68:
#line	312	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
	} break;
case 69:
#line	316	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
	} break;
case 75:
#line	329	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_BRANCH;
		yyval.gen.offset = yypt[-3].yyv.lval + pc;
	} break;
case 76:
#line	335	"a.y"
{
		yyval.gen = nullgen;
		if(pass == 2)
			yyerror("undefined label: %s", yypt[-1].yyv.sym->name);
		yyval.gen.type = D_BRANCH;
		yyval.gen.sym = yypt[-1].yyv.sym;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 77:
#line	344	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_BRANCH;
		yyval.gen.sym = yypt[-1].yyv.sym;
		yyval.gen.offset = yypt[-1].yyv.sym->value + yypt[-0].yyv.lval;
	} break;
case 78:
#line	353	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 79:
#line	358	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 80:
#line	363	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 81:
#line	368	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 82:
#line	373	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SP;
	} break;
case 83:
#line	378	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 84:
#line	383	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 85:
#line	388	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-0].yyv.lval;
	} break;
case 86:
#line	395	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_CONST;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 87:
#line	401	"a.y"
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
case 88:
#line	412	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SCONST;
		memcpy(yyval.gen.sval, yypt[-0].yyv.sval, sizeof(yyval.gen.sval));
	} break;
case 89:
#line	418	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = yypt[-0].yyv.dval;
	} break;
case 90:
#line	424	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = yypt[-1].yyv.dval;
	} break;
case 91:
#line	430	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = -yypt[-0].yyv.dval;
	} break;
case 94:
#line	442	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_NONE;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 95:
#line	448	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+yypt[-1].yyv.lval;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 96:
#line	454	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_SP;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 97:
#line	460	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_NONE;
		yyval.gen.offset = yypt[-5].yyv.lval;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 98:
#line	469	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+yypt[-6].yyv.lval;
		yyval.gen.offset = yypt[-8].yyv.lval;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 99:
#line	478	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+yypt[-1].yyv.lval;
	} break;
case 100:
#line	483	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_SP;
	} break;
case 101:
#line	488	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+yypt[-1].yyv.lval;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 102:
#line	494	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+D_NONE;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 103:
#line	502	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_INDIR+yypt[-6].yyv.lval;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 104:
#line	512	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
	} break;
case 105:
#line	516	"a.y"
{
		yyval.gen = yypt[-5].yyv.gen;
		yyval.gen.index = yypt[-3].yyv.lval;
		yyval.gen.scale = yypt[-1].yyv.lval;
		checkscale(yyval.gen.scale);
	} break;
case 106:
#line	525	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-1].yyv.lval;
		yyval.gen.sym = yypt[-4].yyv.sym;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 107:
#line	532	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_STATIC;
		yyval.gen.sym = yypt[-6].yyv.sym;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 108:
#line	540	"a.y"
{
		yyval.lval = 0;
	} break;
case 109:
#line	544	"a.y"
{
		yyval.lval = yypt[-0].yyv.lval;
	} break;
case 110:
#line	548	"a.y"
{
		yyval.lval = -yypt[-0].yyv.lval;
	} break;
case 112:
#line	555	"a.y"
{
		yyval.lval = D_AUTO;
	} break;
case 115:
#line	563	"a.y"
{
		yyval.lval = yypt[-0].yyv.sym->value;
	} break;
case 116:
#line	567	"a.y"
{
		yyval.lval = -yypt[-0].yyv.lval;
	} break;
case 117:
#line	571	"a.y"
{
		yyval.lval = yypt[-0].yyv.lval;
	} break;
case 118:
#line	575	"a.y"
{
		yyval.lval = ~yypt[-0].yyv.lval;
	} break;
case 119:
#line	579	"a.y"
{
		yyval.lval = yypt[-1].yyv.lval;
	} break;
case 121:
#line	586	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval + yypt[-0].yyv.lval;
	} break;
case 122:
#line	590	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval - yypt[-0].yyv.lval;
	} break;
case 123:
#line	594	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval * yypt[-0].yyv.lval;
	} break;
case 124:
#line	598	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval / yypt[-0].yyv.lval;
	} break;
case 125:
#line	602	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval % yypt[-0].yyv.lval;
	} break;
case 126:
#line	606	"a.y"
{
		yyval.lval = yypt[-3].yyv.lval << yypt[-0].yyv.lval;
	} break;
case 127:
#line	610	"a.y"
{
		yyval.lval = yypt[-3].yyv.lval >> yypt[-0].yyv.lval;
	} break;
case 128:
#line	614	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval & yypt[-0].yyv.lval;
	} break;
case 129:
#line	618	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval ^ yypt[-0].yyv.lval;
	} break;
case 130:
#line	622	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval | yypt[-0].yyv.lval;
	} break;
	}
	goto yystack;  /* stack new state and value */
}
