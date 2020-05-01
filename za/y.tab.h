
typedef union 
{
	Sym	*sym;
	long	lval;
	double	dval;
	char	sval[8];
	Gen	gen;
}	YYSTYPE;
extern	YYSTYPE	yylval;
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
