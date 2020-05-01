
#line	2	"a.y"
#include "a.h"

#line	4	"a.y"
typedef union 
{
	Sym	*sym;
	vlong	lval;
	double	dval;
	char	sval[NSNAME];
	Gen	gen;
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
#define	LTYPE5	57351
#define	LTYPE6	57352
#define	LTYPE7	57353
#define	LTYPE8	57354
#define	LTYPE9	57355
#define	LTYPEA	57356
#define	LTYPEB	57357
#define	LTYPEC	57358
#define	LTYPED	57359
#define	LTYPEE	57360
#define	LTYPEF	57361
#define	LTYPEG	57362
#define	LTYPEH	57363
#define	LTYPEI	57364
#define	LTYPEJ	57365
#define	LTYPEK	57366
#define	LTYPEL	57367
#define	LTYPEM	57368
#define	LTYPEN	57369
#define	LTYPEO	57370
#define	LTYPEP	57371
#define	LTYPEQ	57372
#define	LTYPER	57373
#define	LTYPES	57374
#define	LTYPET	57375
#define	LTYPEU	57376
#define	LTYPEV	57377
#define	LTYPEW	57378
#define	LTYPEX	57379
#define	LTYPEY	57380
#define	LTYPEZ	57381
#define	LMOVK	57382
#define	LDMB	57383
#define	LSTXR	57384
#define	LCONST	57385
#define	LSP	57386
#define	LSB	57387
#define	LFP	57388
#define	LPC	57389
#define	LR	57390
#define	LREG	57391
#define	LF	57392
#define	LFREG	57393
#define	LV	57394
#define	LVREG	57395
#define	LC	57396
#define	LCREG	57397
#define	LFCR	57398
#define	LFCSEL	57399
#define	LCOND	57400
#define	LS	57401
#define	LAT	57402
#define	LEXT	57403
#define	LSPR	57404
#define	LSPREG	57405
#define	LVTYPE	57406
#define	LFCONST	57407
#define	LSCONST	57408
#define	LNAME	57409
#define	LLAB	57410
#define	LVAR	57411
#define YYEOFCODE 1
#define YYERRCODE 2
short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 0,
-1, 16,
	82, 24,
	-2, 66,
-1, 226,
	92, 132,
	-2, 66,
-1, 249,
	83, 117,
	-2, 103,
-1, 250,
	83, 118,
	-2, 104,
};
#define	YYNPROD	163
#define	YYPRIVATE 57344
#define	yydebug	1
#define	YYLAST	754
short	yyact[] =
{
 150,  63,  65, 130, 378, 152, 247, 102, 225, 179,
   2, 260, 307,  67,  68,  52,  70, 327, 139, 402,
  92,  93,  94, 365, 104, 364, 224, 223,  82, 117,
 117, 377, 110, 112, 376, 414,  54, 120, 400, 136,
  67, 137, 141, 141, 381,  64, 353, 347,  62, 343,
 342, 146, 341, 131,  95, 132, 340, 116, 118, 154,
 335, 143,  73, 334,  96, 266,  61,  60,  85,  84,
 382, 272, 111, 113,  69, 164, 119,  61,  60, 170,
 171, 172, 278, 163, 211, 201, 138, 140, 178, 165,
 145,  53,  55, 187, 104,  67, 192,  79,  78, 177,
 185, 191, 114,  58, 117, 361,  91, 121, 123, 123,
 176, 128, 175, 160, 100, 202, 203, 108, 109, 206,
 207, 190,  73, 214,  85,  84,  61,  60,  85,  84,
  58,  74, 200, 264, 142, 142, 144, 308,  72, 184,
  53,  76,  73, 413, 174, 412,  61,  60, 125,  59,
  59, 115, 226, 411, 410, 409,  59, 408, 233, 234,
 407, 208, 406,  67, 258, 405, 383,  77, 371, 370,
 170,  51,  58, 369, 107, 368, 363, 269, 270, 271,
  73,  80, 274, 275,  61,  60, 362, 360, 358, 357,
 209, 356, 355, 149, 151, 104,  79,  78, 279, 248,
 281, 354, 284, 351, 350,  79,  78, 257, 349,  53,
  53, 295, 326, 296, 290, 183, 232, 231, 230, 229,
 173, 228, 227, 136, 305, 306, 304, 222, 221, 276,
 141, 313, 309,  67, 315, 288, 220, 131, 219, 132,
  76, 285, 286, 287, 218, 289, 216, 215, 312,  76,
 213, 293, 328, 328, 328, 328, 210,  79,  78, 297,
 205, 204, 199, 198, 197, 136,  77, 337,  79,  78,
 329, 330, 331, 338, 311,  77, 339, 314, 346, 336,
  80, 196, 107, 345, 344, 195, 194, 348, 193,  80,
 298, 299, 249, 300, 301, 302, 303, 292, 162, 161,
 153,  76, 259, 294,  50, 256, 359,  47,  48,  79,
 169, 166,  76,  49, 268,  46, 265, 401, 367,  98,
  87,  86, 142, 265, 291, 366, 226,  77, 280, 217,
  85,  84, 282, 375, 107, 403, 352,  59,  77, 155,
 156,  80, 157,  58, 380, 107, 212,  79,  78, 322,
  73, 104,  80,  76,  61,  60,  61,  60, 385, 273,
 390, 387, 388, 122, 136, 254, 310, 395, 253,  67,
 396, 398, 374, 252, 332, 168, 167,  90, 131,  77,
 132, 316, 317, 318, 319, 320,  81, 321, 323, 324,
 325,  76, 277,  80, 168, 384, 283, 386, 126, 255,
  61,  60, 158, 159, 250, 251,  79,  78,  61,  60,
 181, 182,  79,  78, 423, 105, 106,  77, 262, 261,
 263, 291, 424,   7, 107, 425, 426,  79,  78, 404,
  75,  80, 148, 391,  97, 392, 393, 394, 262, 261,
 263, 147,  61,  60, 262, 261, 263,   1,  71, 389,
  76, 415,  83, 417, 418,  99,  76, 101, 422,  87,
  86, 238, 239, 240, 124, 124, 372, 373, 186, 133,
 127,  76, 129,  57,  90,  56,  77, 379, 379, 134,
 105, 106,  77,  81,   0, 420, 421, 103, 135, 107,
  80,   0,   0, 282, 282,  90,  80,  77,   0, 416,
   8,   0, 419, 180,  81, 181, 182,   0, 397,   0,
 399,  80,   9,  10,  11,  12,  14,  15,  16,  17,
  18,  36,  26,  28,  29,  30,  45,  35,   0,  31,
  32,  39,  33,  34,  40,  41,  42,  25,  27,  19,
  20,  21,  22,  23,  38,   0,  24,   0,  13,  43,
  44,  79,  78,   0,  79,  78, 236, 237, 238, 239,
 240,   0,  79,  78,   0,  37,  79,  78, 241, 242,
 236, 237, 238, 239, 240,   4,   3,   5,   0,   0,
   6, 245, 244, 243, 241, 242, 236, 237, 238, 239,
 240,   0,   0,   0,   0,  76,  73,   0,  76,   0,
  61,  60,  85,  84,  87,  86,  76,   0,  66,   0,
  76,  61,  60,   0,  89,  88,   0,   0,   0,  90,
   0,  77, 188, 106,  77,   0,  74,   0,  81,   0,
   0, 189,  77,   0,  90,  80,  77,   0,  80, 107,
   0,   0,   0, 107,   0,   0,  80,   0,   0,   0,
  80, 245, 244, 243, 241, 242, 236, 237, 238, 239,
 240,   0,   0,   0, 333, 245, 244, 243, 241, 242,
 236, 237, 238, 239, 240, 245, 244, 243, 241, 242,
 236, 237, 238, 239, 240, 244, 243, 241, 242, 236,
 237, 238, 239, 240, 243, 241, 242, 236, 237, 238,
 239, 240,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0, 267,   0,   0,   0,   0,   0,
   0,   0,   0, 246,   0,   0,   0,   0,   0,   0,
   0,   0,   0, 235
};
short	yypact[] =
{
-1000, 498,-1000, 235, 227, 232,-1000, 222,  89,  57,
  19,  19, 542,  46,  57,  57,  57,  19, 296, 251,
 251,  46, 251, 403,  46,  46, 126,  68, 557, 557,
 296,  57, 270,  64,  64, 251, 270, 251, 397, 542,
 296,  88, 259,  46, 296,  57,-1000,-1000, 196, 196,
-1000,-1000,-1000,  57, 217,-1000,-1000,-1000, 196, 332,
-1000,  27, 216, 215,-1000,-1000,-1000,  -3,-1000,-1000,
-1000,-1000,-1000,-1000, 300,-1000,-1000,-1000, 196, 196,
 196, 553,  26,-1000,-1000,  24,-1000,  13,-1000,   2,
 496, 132, 545, 338, 542, 205, 203, 202,-1000, 198,
 181, 180, 179, 557,  -1, 401, 401, 196, 178, 177,
-1000,-1000,-1000,  57,  57,   8, 173,  -2, 334, 167,
  47, 164, 163,-1000,-1000, 319, 161, 155, 153, 145,
 144,-1000, -62,-1000, -63, 258,  -3, 139, 138,-1000,
 136, 135,-1000, 134,-1000, 133,-1000, 498, 498, 671,
-1000, 661,-1000, 350,-1000, 398, 365, 360, 357, 392,
 196, 296, 542, 384,  -3,-1000,  49,-1000,-1000, 248,
-1000,-1000,-1000, -22, 647, 298, 196, 196, 196, -15,
 351, 196, 196, 296, 385,-1000,-1000,  -4, 496, 553,
-1000,-1000,-1000, 342, 338, 296, 296, 296,  19, 296,
 131, 267,-1000,-1000,  46, 296,-1000,-1000,-1000,-1000,
 259, 390, 196, 296,-1000, 270, 270, 241, 270, 270,
 270, 270, 397, 196, 196, -80, 127, 298, 296, 259,
 196, 296, 542,-1000,-1000,-1000, 196, 196, 196, 196,
 196, 380, 341, 196, 196, 196,-1000, 129,-1000,-1000,
-1000, 196, 196, 196, 196, 367, 577,-1000,-1000, -24,
 -27,-1000,-1000,-1000, 418,-1000, 187,-1000, -31, -35,
 -37, -38, 390, 401,-1000,-1000,-1000, 196, 364, -15,
 -40,  57,-1000,-1000,-1000,-1000, 125, 121, 120,-1000,
 296, -41, 118, 109,-1000, 108, 106,-1000,-1000, 105,
  57, 104,  20, 103,  93, -65, -67,-1000, 258, 258,
  92,  90,-1000,  86,-1000,  85, 450, 450,-1000,-1000,
-1000, 196, 196, 561, 688, 680, 296,-1000,-1000,-1000,
-1000,-1000, 196,-1000, -54,-1000,-1000, -57, 553, 298,
-1000,-1000,-1000,-1000, -43, -16,  83,-1000,-1000, 296,
 338, 296,-1000,-1000, 342, 342,  46,  47, 270,-1000,
 270, 270, 270, 397,-1000,-1000,-1000,-1000, 542, 298,
 196, 298, 547, 547,-1000,-1000,-1000,-1000, -49, 246,
 -71,-1000, 280, 296,  82,-1000,  79,  77,  74,-1000,
-1000,-1000,  72,  71,  70,-1000,-1000,  62,  60,-1000,
-1000,-1000,-1000, -52,-1000, 296,  46, 296, 296,  46,
 270, 270, 296, 196,-1000,-1000,  57,-1000,-1000,  57,
  57,-1000,-1000,-1000,-1000,-1000,-1000
};
short	yypgo[] =
{
   0,   0, 144,  11,   9, 138,   6,  17,   4, 479,
   8,   1,   7,  45,  74,  16, 475, 430, 363, 473,
 469,   3,  92,   2,  28,  14, 468, 452,  36, 448,
 434,  18, 447,  10, 441, 432, 423,   5
};
short	yyr1[] =
{
   0,  32,  32,  34,  33,  35,  33,  33,  33,  33,
  33,  33,  36,  36,  36,  36,  36,  36,  36,  36,
  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,
  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,
  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,
  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,
  36,  36,  36,  36,  36,  30,  37,  37,  31,  31,
  12,  12,  12,  23,  23,  23,  23,  23,  17,  17,
  11,  11,  11,  11,  11,  11,  11,  11,  26,  26,
  25,  25,  25,  27,  27,  27,  27,  27,  27,  28,
  28,  28,  22,  13,  13,  16,  16,  16,  16,  19,
  19,  19,   8,   8,   7,   5,   5,   6,   6,  29,
  29,  18,  18,  14,  14,  21,  21,  21,  21,  20,
  20,   9,  10,  10,  10,  15,  15,  24,  24,  24,
   4,   4,   4,   3,   3,   3,   1,   1,   1,   1,
   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,
   2,   2,   2
};
short	yyr2[] =
{
   0,   0,   2,   0,   4,   0,   4,   4,   4,   1,
   2,   2,   2,   6,   5,   4,   4,   4,   4,   7,
   3,   3,   3,   3,   1,   5,   4,   4,   8,   6,
   6,   9,   4,   5,   8,   8,   2,   2,   2,   3,
   3,   3,   3,   4,   6,   6,   4,   3,   4,   4,
   6,   5,   9,   9,   8,   4,   6,   6,   8,   2,
   4,   4,   2,   6,   2,   1,   0,   2,   7,   1,
   4,   2,   2,   2,   2,   4,   2,   1,   2,   3,
   1,   1,   1,   1,   1,   1,   1,   1,   3,   1,
   1,   4,   1,   3,   4,   5,   5,   6,   6,   1,
   1,   1,   2,   1,   1,   4,   4,   4,   4,   1,
   2,   5,   1,   2,   1,   1,   4,   1,   1,   1,
   4,   1,   1,   1,   4,   1,   1,   1,   1,   4,
   4,   3,   1,   3,   3,   1,   4,   4,   5,   7,
   0,   2,   2,   1,   1,   1,   1,   1,   2,   2,
   2,   3,   1,   3,   3,   3,   3,   3,   4,   4,
   3,   3,   3
};
short	yychk[] =
{
-1000, -32, -33,  78,  77,  79,  82, -36,   2,  14,
  15,  16,  17,  50,  18,  19,  20,  21,  22,  41,
  42,  43,  44,  45,  48,  39,  24,  40,  25,  26,
  27,  31,  32,  34,  35,  29,  23,  67,  46,  33,
  36,  37,  38,  51,  52,  28,  80,  80,  81,  81,
  82,  82, -37,  83, -28, -22, -16, -19,  84,  -5,
  59,  58, -28, -11, -13, -23,  66,  -1, -25, -14,
 -15, -29,  -5,  54,  84, -17,  53,  79,  10,   9,
  93,  86, -24, -27,  61,  60,  63,  62,  73,  72,
  77, -22, -37, -37, -37, -28, -13, -30,  68, -30,
 -22, -30, -12,  84,  -1,  77,  78,  86, -22, -22,
 -37, -13, -37, -13, -14,  83, -24,  -1, -24, -13,
 -37, -14, -18, -14, -17,  84, -18, -30, -14, -30,
 -21, -25, -15, -20,  -9,  91,  -1, -11, -13, -31,
 -13,  -1, -22, -31, -22, -13, -37, -34, -35,  -2,
  -1,  -2, -37,  83,  -1,   7,   8,  10,  70,  71,
  86,  83,  83,  86,  -1, -25,  11,  76,  75,  10,
  -1,  -1,  -1,  -5,  -2,  86,  86,  86,  86,  -4,
   7,   9,  10,  83,   7, -12, -26,  -1,  77,  86,
 -24, -12, -11,  83,  83,  83,  83,  83,  83,  83,
 -24,  86,  -4,  -4,  83,  83, -37, -37, -13, -14,
  83,  86,  12,  83, -23,  83,  83,  10,  83,  83,
  83,  83,  83,  89,  89, -10, -15,  83,  83,  83,
  83,  83,  83, -33, -33,  82,   9,  10,  11,  12,
  13,   7,   8,   6,   5,   4,  82,  -6, -13,  -5,
  54,   7,   8,   8,   8,   7,  -2, -13, -11,  -5,
  -3,  55,  54,  56,  84,  75,  87,  87,  -5,  -1,
  -1,  -1,  86,   8,  -1,  -1, -13,   7,  86,  -4,
  -5,  -6,  -5,  54, -12, -13, -13, -13, -28, -13,
  83,  57, -22, -13, -22,  -1,  -1, -13, -14, -14,
 -14, -14, -14, -14, -21,  -1,  -1,  92,  10, -37,
  -5, -13, -31,  -1, -13, -11,  -2,  -2,  -2,  -2,
  -2,   7,   8,  -2,  -2,  -2,  83,  -7,  -1,  -7,
  -7,  -7,   7,  87,  87,  87, -25,  -1,  86,  89,
  87,  87,  87,  87,  -3,  -4,  -1,  87, -37,  83,
  83,  83, -13,  87,  83,  83,  83,  83,  83, -37,
  83,  85,  83,  83,  90,  90, -15, -10,  83,  83,
  83,  83,  -2,  -2, -13,  -1,  88,  88,  -8,  -5,
  -8,  87,  86,  83, -13, -12, -13,  -6,  -6, -22,
 -23, -14, -14, -14, -14, -21, -11,  -5,  -1,  -5,
  87,  71,  90,  55, -13,  83,  83,  83,  83,  83,
  83,  83,  83,  83,  87, -13, -22, -13, -13, -22,
 -14, -14, -13,  -1, -37, -37, -37
};
short	yydef[] =
{
   1,  -2,   2,   0,   0,   0,   9,   0,   0,  66,
   0,   0,   0,   0,  66,  66,  -2,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  66,  66,   0,   0,
   0,  66,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,  66,   3,   5,   0,   0,
  10,  11,  12,  66,   0,  99, 100, 101,   0, 109,
 115,   0,   0,   0,  80,  81,  82,  83,  84,  85,
  86,  87, 103, 104,   0,  77, 146, 147,   0,   0,
   0,   0,  90,  92, 123,   0, 135,   0, 119,   0,
 140,   0,   0,   0,   0,   0,   0,   0,  65,   0,
   0,   0,   0,   0,   0, 140, 140,   0,   0,   0,
  36,  37,  38,  66,  66,  66,   0,   0,   0,   0,
   0,   0,   0, 121, 122,   0,   0,   0,   0,   0,
   0, 125, 126, 127, 128,   0,   0,   0,   0,  59,
   0,   0,  69,   0,  62,   0,  64,   0,   0,   0,
 152,   0,  67,   0, 102,   0,   0,   0,   0, 110,
   0,   0,   0,   0,  73,  74,   0,  76,  78,   0,
 148, 149, 150,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,  20,  21,   0, 140,   0,
  89,  22,  23,   0,   0,   0,   0,   0,   0,   0,
   0,   0,  71,  72,   0,   0,  39,  40,  41,  42,
   0,   0,   0,   0,  47,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  -2,   0,   0,   0,
   0,   0,   0,   4,   6,   7,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   8,   0,  15,  -2,
  -2,   0,   0,   0,   0,   0,   0,  16,  17,   0,
   0, 143, 144, 145,   0,  79,  93, 151,   0,   0,
   0,   0,   0, 140, 141, 142,  18,   0,   0,  71,
   0,  66, 117, 118,  26,  27,   0,   0,   0,  32,
   0,   0,   0,   0,  43,   0,   0,  46,  48,  49,
  66,   0,   0,   0,  55,   0,   0, 131,   0,   0,
   0,   0,  60,   0,  61,   0, 153, 154, 155, 156,
 157,   0,   0, 160, 161, 162,  14, 105, 114, 106,
 107, 108,   0, 116,  94, 137,  75,   0,   0,   0,
  91, 124, 136, 120,   0,   0,   0,  88,  25,   0,
   0,   0,  33,  70,   0,   0,   0,   0,   0,  51,
   0,   0,   0,   0, 129, 130, 133, 134,   0,   0,
   0,   0, 158, 159,  13, 111,  95,  96,   0, 112,
   0, 138,   0,   0,  29,  30,   0,   0,   0,  44,
  45,  50,   0,   0,   0,  56,  57,   0,   0,  63,
  97, 113,  98,   0,  19,   0,   0,   0,   0,   0,
   0,   0,   0,   0, 139,  28,  66,  34,  35,  66,
  66,  54,  58,  68,  31,  52,  53
};
short	yytok1[] =
{
   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,  88,   0,   0,  84,  13,   6,   0,
  86,  87,  11,   9,  83,  10,   0,  12,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,  80,  82,
   7,  81,   8,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,  89,   0,  90,   5,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,  91,   4,  92,  93
};
short	yytok2[] =
{
   2,   3,  14,  15,  16,  17,  18,  19,  20,  21,
  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,
  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,
  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,
  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,
  62,  63,  64,  65,  66,  67,  68,  69,  70,  71,
  72,  73,  74,  75,  76,  77,  78,  79,  85
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
#line	41	"a.y"
{
		if(yypt[-1].yyv.sym->value != pc)
			yyerror("redeclaration of %s", yypt[-1].yyv.sym->name);
		yypt[-1].yyv.sym->value = pc;
	} break;
case 5:
#line	48	"a.y"
{
		yypt[-1].yyv.sym->type = LLAB;
		yypt[-1].yyv.sym->value = pc;
	} break;
case 7:
#line	54	"a.y"
{
		yypt[-3].yyv.sym->type = LVAR;
		yypt[-3].yyv.sym->value = yypt[-1].yyv.lval;
	} break;
case 8:
#line	59	"a.y"
{
		if(yypt[-3].yyv.sym->value != yypt[-1].yyv.lval)
			yyerror("redeclaration of %s", yypt[-3].yyv.sym->name);
		yypt[-3].yyv.sym->value = yypt[-1].yyv.lval;
	} break;
case 12:
#line	73	"a.y"
{
		outcode(yypt[-1].yyv.lval, &nullgen, NREG, &nullgen);
	} break;
case 13:
#line	80	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 14:
#line	84	"a.y"
{
		outcode(yypt[-4].yyv.lval, &yypt[-3].yyv.gen, yypt[-1].yyv.lval, &nullgen);
	} break;
case 15:
#line	88	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 16:
#line	95	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 17:
#line	102	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 18:
#line	109	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 19:
#line	113	"a.y"
{
		Gen g;
		g = nullgen;
		g.type = D_CONST;
		g.offset = yypt[-2].yyv.lval;
		outcode4(yypt[-6].yyv.lval, &yypt[-5].yyv.gen, NREG, &g, &yypt[-0].yyv.gen);
	} break;
case 20:
#line	124	"a.y"
{
		outcode(yypt[-2].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 21:
#line	128	"a.y"
{
		outcode(yypt[-2].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 22:
#line	135	"a.y"
{
		outcode(yypt[-2].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 23:
#line	142	"a.y"
{
		outcode(yypt[-2].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 24:
#line	146	"a.y"
{
		outcode(yypt[-0].yyv.lval, &nullgen, NREG, &nullgen);
	} break;
case 25:
#line	153	"a.y"
{
		outcode(yypt[-4].yyv.lval, &yypt[-3].yyv.gen, yypt[-1].yyv.lval, &nullgen);
	} break;
case 26:
#line	160	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 27:
#line	167	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 28:
#line	174	"a.y"
{
		outcode4(yypt[-7].yyv.lval, &yypt[-6].yyv.gen, yypt[-2].yyv.gen.reg, &yypt[-4].yyv.gen, &yypt[-0].yyv.gen);
	} break;
case 29:
#line	178	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.gen.reg, &yypt[-0].yyv.gen);
	} break;
case 30:
#line	185	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.gen.reg, &yypt[-0].yyv.gen);
	} break;
case 31:
#line	192	"a.y"
{
		outcode4(yypt[-8].yyv.lval, &yypt[-7].yyv.gen, yypt[-3].yyv.gen.reg, &yypt[-5].yyv.gen, &yypt[-1].yyv.gen);
	} break;
case 32:
#line	199	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 33:
#line	203	"a.y"
{
		outcode(yypt[-4].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 34:
#line	210	"a.y"
{
		outcode4(yypt[-7].yyv.lval, &yypt[-6].yyv.gen, yypt[-2].yyv.lval, &yypt[-4].yyv.gen, &yypt[-0].yyv.gen);
	} break;
case 35:
#line	217	"a.y"
{
		outcode4(yypt[-7].yyv.lval, &yypt[-6].yyv.gen, yypt[-2].yyv.lval, &yypt[-4].yyv.gen, &yypt[-0].yyv.gen);
	} break;
case 36:
#line	224	"a.y"
{
		outcode(yypt[-1].yyv.lval, &nullgen, NREG, &nullgen);
	} break;
case 37:
#line	228	"a.y"
{
		outcode(yypt[-1].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 38:
#line	235	"a.y"
{
		outcode(yypt[-1].yyv.lval, &nullgen, NREG, &nullgen);
	} break;
case 39:
#line	239	"a.y"
{
		outcode(yypt[-2].yyv.lval, &yypt[-1].yyv.gen, NREG, &nullgen);
	} break;
case 40:
#line	243	"a.y"
{
		outcode(yypt[-2].yyv.lval, &yypt[-1].yyv.gen, NREG, &nullgen);
	} break;
case 41:
#line	247	"a.y"
{
		outcode(yypt[-2].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 42:
#line	251	"a.y"
{
		outcode(yypt[-2].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 43:
#line	258	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 44:
#line	262	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 45:
#line	269	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 46:
#line	276	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 47:
#line	283	"a.y"
{
		outcode(yypt[-2].yyv.lval, &nullgen, NREG, &yypt[-0].yyv.gen);
	} break;
case 48:
#line	290	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 49:
#line	297	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 50:
#line	301	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.gen.reg, &yypt[-0].yyv.gen);
	} break;
case 51:
#line	308	"a.y"
{
		outcode(yypt[-4].yyv.lval, &yypt[-3].yyv.gen, yypt[-1].yyv.gen.reg, &nullgen);
	} break;
case 52:
#line	315	"a.y"
{
		outcode4(yypt[-8].yyv.lval, &yypt[-7].yyv.gen, yypt[-3].yyv.gen.reg, &yypt[-5].yyv.gen, &yypt[-1].yyv.gen);
	} break;
case 53:
#line	322	"a.y"
{
		outcode4(yypt[-8].yyv.lval, &yypt[-7].yyv.gen, yypt[-5].yyv.gen.reg, &yypt[-3].yyv.gen, &yypt[-1].yyv.gen);
	} break;
case 54:
#line	329	"a.y"
{
		outcode4(yypt[-7].yyv.lval, &yypt[-6].yyv.gen, yypt[-2].yyv.gen.reg, &yypt[-4].yyv.gen, &yypt[-0].yyv.gen);
	} break;
case 55:
#line	336	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 56:
#line	340	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.gen.reg, &yypt[-0].yyv.gen);
	} break;
case 57:
#line	347	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-2].yyv.lval, &yypt[-0].yyv.gen);
	} break;
case 58:
#line	354	"a.y"
{
		outcode4(yypt[-7].yyv.lval, &yypt[-6].yyv.gen, yypt[-2].yyv.lval, &yypt[-4].yyv.gen, &yypt[-0].yyv.gen);
	} break;
case 59:
#line	361	"a.y"
{
		outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen, NREG, &nullgen);
	} break;
case 60:
#line	365	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-0].yyv.gen, yypt[-2].yyv.gen.reg, &nullgen);
	} break;
case 61:
#line	369	"a.y"
{
		outcode(yypt[-3].yyv.lval, &yypt[-2].yyv.gen, NREG, &yypt[-0].yyv.gen);
	} break;
case 62:
#line	376	"a.y"
{
		outcode(yypt[-1].yyv.lval, &yypt[-0].yyv.gen, NREG, &nullgen);
	} break;
case 63:
#line	383	"a.y"
{
		outcode(yypt[-5].yyv.lval, &yypt[-4].yyv.gen, yypt[-0].yyv.lval, &yypt[-2].yyv.gen);
	} break;
case 64:
#line	390	"a.y"
{
		outcode(yypt[-1].yyv.lval, &nullgen, NREG, &nullgen);
	} break;
case 65:
#line	396	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_COND;
		yyval.gen.reg = yypt[-0].yyv.lval;
	} break;
case 68:
#line	407	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_CONST;
		yyval.gen.offset = SYSARG4(yypt[-6].yyv.lval, yypt[-4].yyv.lval, yypt[-2].yyv.lval, yypt[-0].yyv.lval);
	} break;
case 70:
#line	416	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_BRANCH;
		yyval.gen.offset = yypt[-3].yyv.lval + pc;
	} break;
case 71:
#line	422	"a.y"
{
		yyval.gen = nullgen;
		if(pass == 2)
			yyerror("undefined label: %s", yypt[-1].yyv.sym->name);
		yyval.gen.type = D_BRANCH;
		yyval.gen.sym = yypt[-1].yyv.sym;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 72:
#line	431	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_BRANCH;
		yyval.gen.sym = yypt[-1].yyv.sym;
		yyval.gen.offset = yypt[-1].yyv.sym->value + yypt[-0].yyv.lval;
	} break;
case 73:
#line	439	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_CONST;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 74:
#line	445	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
		yyval.gen.type = D_CONST;
	} break;
case 75:
#line	450	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
		yyval.gen.type = D_OCONST;
	} break;
case 76:
#line	455	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SCONST;
		memmove(yyval.gen.sval, yypt[-0].yyv.sval, sizeof(yyval.gen.sval));
	} break;
case 78:
#line	464	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = yypt[-0].yyv.dval;
	} break;
case 79:
#line	470	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FCONST;
		yyval.gen.dval = -yypt[-0].yyv.dval;
	} break;
case 82:
#line	480	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SPR;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 83:
#line	486	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 88:
#line	498	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.reg = yypt[-1].yyv.lval;
		yyval.gen.offset = 0;
	} break;
case 89:
#line	505	"a.y"
{
		yyval.gen = yypt[-0].yyv.gen;
		if(yypt[-0].yyv.gen.name != D_EXTERN && yypt[-0].yyv.gen.name != D_STATIC) {
		}
	} break;
case 91:
#line	514	"a.y"
{
		yyval.gen = yypt[-3].yyv.gen;
		yyval.gen.type = D_OREG;
		yyval.gen.reg = yypt[-1].yyv.lval;
	} break;
case 93:
#line	523	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.reg = yypt[-1].yyv.lval;
		yyval.gen.offset = 0;
	} break;
case 94:
#line	530	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.reg = yypt[-1].yyv.lval;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 95:
#line	537	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_XPRE;
		yyval.gen.reg = yypt[-2].yyv.lval;
		yyval.gen.offset = yypt[-4].yyv.lval;
	} break;
case 96:
#line	544	"a.y"
{
		yyval.gen.type = D_XPOST;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 97:
#line	549	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_ROFF;
		yyval.gen.reg = yypt[-4].yyv.lval;
		yyval.gen.xreg = yypt[-1].yyv.lval & 0x1f;
		yyval.gen.offset = yypt[-1].yyv.lval;
	} break;
case 98:
#line	557	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_ROFF;
		yyval.gen.reg = yypt[-4].yyv.lval;
		yyval.gen.xreg = yypt[-1].yyv.lval & 0x1f;
		yyval.gen.offset = yypt[-1].yyv.lval | (1<<16);
	} break;
case 102:
#line	571	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_CONST;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 103:
#line	579	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_REG;
		yyval.gen.reg = yypt[-0].yyv.lval;
	} break;
case 104:
#line	585	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SP;
		yyval.gen.reg = REGSP;
	} break;
case 105:
#line	593	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SHIFT;
		yyval.gen.offset = (yypt[-3].yyv.lval << 16) | (yypt[-0].yyv.lval << 10) | (0 << 22);
	} break;
case 106:
#line	599	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SHIFT;
		yyval.gen.offset = ((yypt[-3].yyv.lval&0x1F) << 16) | (yypt[-0].yyv.lval << 10) | (1 << 22);
	} break;
case 107:
#line	605	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SHIFT;
		yyval.gen.offset = (yypt[-3].yyv.lval << 16) | (yypt[-0].yyv.lval << 10) | (2 << 22);
	} break;
case 108:
#line	611	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SHIFT;
		yyval.gen.offset = (yypt[-3].yyv.lval << 16) | (yypt[-0].yyv.lval << 10) | (3 << 22);
	} break;
case 109:
#line	619	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_REG;
		yyval.gen.reg = yypt[-0].yyv.lval;
	} break;
case 110:
#line	625	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_EXTREG;
		yyval.gen.reg = yypt[-1].yyv.lval;
		yyval.gen.offset = (yypt[-1].yyv.lval << 16) | (yypt[-0].yyv.lval << 13);
	} break;
case 111:
#line	632	"a.y"
{
		if(yypt[-0].yyv.lval < 0 || yypt[-0].yyv.lval > 4)
			yyerror("shift value out of range");
		yyval.gen = nullgen;
		yyval.gen.type = D_EXTREG;
		yyval.gen.reg = yypt[-4].yyv.lval;
		yyval.gen.offset = (yypt[-4].yyv.lval << 16) | (yypt[-3].yyv.lval << 13) | (yypt[-0].yyv.lval << 10);
	} break;
case 112:
#line	643	"a.y"
{
		yyval.lval = (3 << 8) | yypt[-0].yyv.lval;
	} break;
case 113:
#line	647	"a.y"
{
		yyval.lval = (yypt[-0].yyv.lval << 8) | yypt[-1].yyv.lval;
	} break;
case 114:
#line	653	"a.y"
{
		if(yyval.lval < 0 || yyval.lval >= 64)
			yyerror("shift value out of range");
		yyval.lval = yypt[-0].yyv.lval&0x3F;
	} break;
case 116:
#line	662	"a.y"
{
		if(yypt[-1].yyv.lval < 0 || yypt[-1].yyv.lval >= NREG)
			print("register value out of range\n");
		yyval.lval = yypt[-1].yyv.lval;
	} break;
case 118:
#line	671	"a.y"
{
		yyval.lval = REGSP;
	} break;
case 119:
#line	677	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_SPR;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 120:
#line	683	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = yypt[-3].yyv.lval;
		yyval.gen.offset = yypt[-1].yyv.lval;
	} break;
case 123:
#line	695	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FREG;
		yyval.gen.reg = yypt[-0].yyv.lval;
	} break;
case 124:
#line	701	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_FREG;
		yyval.gen.reg = yypt[-1].yyv.lval;
	} break;
case 128:
#line	712	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_VSET;
		yyval.gen.offset = yypt[-0].yyv.lval;
	} break;
case 129:
#line	720	"a.y"
{
		yyval.gen.type = D_VLANE;
		yyval.gen.offset = yypt[-1].yyv.lval;
	} break;
case 130:
#line	725	"a.y"
{
		yyval.gen.type = D_VLANE;
		yyval.gen.offset = yypt[-1].yyv.lval;
	} break;
case 131:
#line	732	"a.y"
{
		yyval.lval = yypt[-1].yyv.lval;
	} break;
case 132:
#line	738	"a.y"
{
		yyval.lval = 1 << yypt[-0].yyv.gen.reg;
	} break;
case 133:
#line	742	"a.y"
{
		int i;
		yyval.lval=0;
		for(i=yypt[-2].yyv.gen.reg; i<=yypt[-0].yyv.gen.reg; i++)
			yyval.lval |= 1<<i;
		for(i=yypt[-0].yyv.gen.reg; i<=yypt[-2].yyv.gen.reg; i++)
			yyval.lval |= 1<<i;
	} break;
case 134:
#line	751	"a.y"
{
		yyval.lval = (1<<yypt[-2].yyv.gen.reg) | yypt[-0].yyv.lval;
	} break;
case 135:
#line	757	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_VREG;
		yyval.gen.reg = yypt[-0].yyv.lval;
		/* TO DO: slice */
	} break;
case 136:
#line	764	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_VREG;
		yyval.gen.reg = yypt[-1].yyv.lval;
	} break;
case 137:
#line	772	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.name = yypt[-1].yyv.lval;
		yyval.gen.sym = S;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 138:
#line	780	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.name = yypt[-1].yyv.lval;
		yyval.gen.sym = yypt[-4].yyv.sym;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 139:
#line	788	"a.y"
{
		yyval.gen = nullgen;
		yyval.gen.type = D_OREG;
		yyval.gen.name = D_STATIC;
		yyval.gen.sym = yypt[-6].yyv.sym;
		yyval.gen.offset = yypt[-3].yyv.lval;
	} break;
case 140:
#line	797	"a.y"
{
		yyval.lval = 0;
	} break;
case 141:
#line	801	"a.y"
{
		yyval.lval = yypt[-0].yyv.lval;
	} break;
case 142:
#line	805	"a.y"
{
		yyval.lval = -yypt[-0].yyv.lval;
	} break;
case 147:
#line	817	"a.y"
{
		yyval.lval = yypt[-0].yyv.sym->value;
	} break;
case 148:
#line	821	"a.y"
{
		yyval.lval = -yypt[-0].yyv.lval;
	} break;
case 149:
#line	825	"a.y"
{
		yyval.lval = yypt[-0].yyv.lval;
	} break;
case 150:
#line	829	"a.y"
{
		yyval.lval = ~yypt[-0].yyv.lval;
	} break;
case 151:
#line	833	"a.y"
{
		yyval.lval = yypt[-1].yyv.lval;
	} break;
case 153:
#line	840	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval + yypt[-0].yyv.lval;
	} break;
case 154:
#line	844	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval - yypt[-0].yyv.lval;
	} break;
case 155:
#line	848	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval * yypt[-0].yyv.lval;
	} break;
case 156:
#line	852	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval / yypt[-0].yyv.lval;
	} break;
case 157:
#line	856	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval % yypt[-0].yyv.lval;
	} break;
case 158:
#line	860	"a.y"
{
		yyval.lval = yypt[-3].yyv.lval << yypt[-0].yyv.lval;
	} break;
case 159:
#line	864	"a.y"
{
		yyval.lval = yypt[-3].yyv.lval >> yypt[-0].yyv.lval;
	} break;
case 160:
#line	868	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval & yypt[-0].yyv.lval;
	} break;
case 161:
#line	872	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval ^ yypt[-0].yyv.lval;
	} break;
case 162:
#line	876	"a.y"
{
		yyval.lval = yypt[-2].yyv.lval | yypt[-0].yyv.lval;
	} break;
	}
	goto yystack;  /* stack new state and value */
}
