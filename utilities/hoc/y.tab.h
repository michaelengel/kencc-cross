
typedef union  {
	Symbol	*sym;	/* symbol table pointer */
	Inst	*inst;	/* machine instruction */
	int	narg;	/* number of arguments */
	Formal	*formals;	/* list of formal parameters */
}	YYSTYPE;
extern	YYSTYPE	yylval;
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
