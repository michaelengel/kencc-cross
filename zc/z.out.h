#define	NSNAME	8
#define	NSYM	50
#define	NREG	32
#define NOPROF	(1<<0)
#define DUPOK	(1<<1)

enum
{
	REGZERO		= 0,	/* always zero */
	REGRET		= 1,	/* fn return value */
	REGARG		= 1,	/* fn arg value */
	REGEXT		= 24,	/* extern reg from here down */
	REGBPTMP	= 25,	/* breakpoint temporary */
	REGSB		= 26,	/* static base */
	REGSP		= 27,	/* stack pointer */
	REGTMP		= 28,	/* assembler temporary */
	REGEA		= 29,	/* exception return address */
	REGBA		= 30,	/* breakpoint return address */
	REGLINK		= 31,	/* call return address */

	FREGRET		= 0,	/* fn return value */
	FREGEXT		= 27,	/* extern reg from here down */
	FREGZERO	= 28,	/* always 0.0 */
	FREGHALF	= 29,
	FREGONE		= 30,
	FREGTWO		= 31,
};

enum	as
{
	AXXX = 0,

	/* processor instructions */
	AADD,
	AADDW,
	AAMO_D,
	AAMO_W,
	AAND,
	ABEQ,
	ABGE,
	ABGEU,
	ABLT,
	ABLTU,
	ABNE,
	ACSRRC,
	ACSRRCI,
	ACSRRS,
	ACSRRSI,
	ACSRRW,
	ACSRRWI,
	ADIV,
	ADIVU,
	ADIVUW,
	ADIVW,
	AFENCE,
	AFENCE_I,
	AJAL,
	AJALR,
	ALR_D,
	ALR_W,
	ALUI,
	AMOVB,
	AMOVBU,
	AMOVH,
	AMOVHU,
	AMOVL,
	AMOVW,
	AMOVWU,
	AMUL,
	AMULH,
	AMULHSU,
	AMULHU,
	AMULW,
	AOR,
	AREM,
	AREMU,
	AREMUW,
	AREMW,
	ASC_D,
	ASC_W,
	ASLL,
	ASLLW,
	ASLT,
	ASLTU,
	ASRA,
	ASRAW,
	ASRL,
	ASRLW,
	ASUB,
	ASUBW,
	ASWAP_D,
	ASWAP_W,
	ASYS,
	AXOR,

	/* floating point */
	AMOVF,
	AMOVD,
	AMOVFD,
	AMOVDF,
	AMOVWF,
	AMOVUF,
	AMOVFW,
	AMOVWD,
	AMOVUD,
	AMOVDW,
	AADDF,
	AADDD,
	ASUBF,
	ASUBD,
	AMULF,
	AMULD,
	ADIVF,
	ADIVD,
	ACMPLTF,
	ACMPLTD,
	ACMPEQF,
	ACMPEQD,
	ACMPLEF,
	ACMPLED,

	/* pseudo-ops */
	ABGT,
	ABGTU,
	ABLE,
	ABLEU,
	ASGT,
	ASGTU,
	AJMP,
	ARET,
	ANOP,

	/* C compiler pseudo-ops */
	ADATA,
	AGLOBL,
	AGOK,
	AHISTORY,
	ANAME,
	ATEXT,
	AWORD,
	AEND,
	ADYNT,
	AINIT,
	ASIGNAME,

	ALAST,
};

/* type/name */
enum
{
	D_GOK	= 0,
	D_NONE,

/* name */
	D_EXTERN,
	D_STATIC,
	D_AUTO,
	D_PARAM,

/* type */
	D_BRANCH,
	D_OREG,
	D_CONST,
	D_FCONST,
	D_SCONST,
	D_REG,
	D_CTLREG,
	D_FREG,
	D_FCREG,
	D_FILE,
	D_FILE1,
};

/*
 * this is the ranlib header
 */
#define	SYMDEF	"__.SYMDEF"

/*
 * this is the simulated IEEE floating point
 */
typedef	struct	ieee	Ieee;
struct	ieee
{
	long	l;	/* contains ls-man	0xffffffff */
	long	h;	/* contains sign	0x80000000
				    exp		0x7ff00000
				    ms-man	0x000fffff */
};
