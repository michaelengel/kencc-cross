#include	<lib9.h>
#include	<ctype.h>
#include	<bio.h>

extern	Biobuf*	yyout;

int
printable(int c)
{
	return 040 < c && c < 0177;
}

void
allprint(char c)
{

	switch(c) {
	case '\n':
		Bprint(yyout,"\\n");
		break;
	case '\t':
		Bprint(yyout,"\\t");
		break;
	case '\b':
		Bprint(yyout,"\\b");
		break;
	case ' ':
		Bprint(yyout,"\\\bb");
		break;
	default:
		if(!printable(c))
			Bprint(yyout,"\\%-3o",c);
		else
			c = Bputc(yyout,c);
			USED(c);
		break;
	}
	return;
}
