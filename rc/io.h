#define	EOF	(-1)
#define	NBUF	512

#ifndef EXTERN
#define EXTERN extern
#endif

struct io{
	int	fd;
	uchar	*bufp, *ebuf, *strp;
	uchar	buf[NBUF];
};
EXTERN io *err;

EXTERN io *openfd(int), *openstr(void), *opencore(char *, int);
EXTERN int emptybuf(io*);
EXTERN void pchr(io*, int);
EXTERN int rchr(io*);
EXTERN int rutf(io*, char*, Rune*);
EXTERN void closeio(io*);
EXTERN void flush(io*);
EXTERN int fullbuf(io*, int);
EXTERN void pdec(io*, int);
EXTERN void poct(io*, unsigned);
EXTERN void pptr(io*, void*);
EXTERN void pquo(io*, char*);
EXTERN void pwrd(io*, char*);
EXTERN void pstr(io*, char*);
EXTERN void pcmd(io*, tree*);
EXTERN void pval(io*, word*);
EXTERN void pfnc(io*, thread*);
EXTERN void pfmt(io*, char*, ...);
