%{
#include "a.h"
%}
%union
{
	Sym	*sym;
	long	lval;
	double	dval;
	char	sval[8];
	Gen	gen;
}
%left	'|'
%left	'^'
%left	'&'
%left	'<' '>'
%left	'+' '-'
%left	'*' '/' '%'
%token	<lval>	LADD LMUL LBEQ LBR LBRET LCALL
%token	<lval>	LMOVB LMOVBU LMOVW LLUI LSYS LSWAP LAMO
%token	<lval>	LCONST LSP LSB LFP LPC LREG LR LCTL
%token	<lval>	LDATA LTEXT LWORD
%token	<sval>	LSCONST
%token	<dval>	LFCONST
%token	<sym>	LNAME LLAB LVAR
%type	<lval>	con expr pointer offset sreg oprrr
%type	<gen>	rreg /*ctlreg*/
%type	<gen>	addr name oreg rel imm ximm fimm
%%
prog:
|	prog line

line:
	LLAB ':'
	{
		if($1->value != pc)
			yyerror("redeclaration of %s", $1->name);
		$1->value = pc;
	}
	line
|	LNAME ':'
	{
		$1->type = LLAB;
		$1->value = pc;
	}
	line
|	LNAME '=' expr ';'
	{
		$1->type = LVAR;
		$1->value = $3;
	}
|	LVAR '=' expr ';'
	{
		if($1->value != $3)
			yyerror("redeclaration of %s", $1->name);
		$1->value = $3;
	}
|	';'
|	inst ';'
|	error ';'

inst:
	LADD imm ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	oprrr rreg ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LADD imm ',' sreg ',' rreg
	{
		outcode($1, &$2, $4, &$6);
	}
|	oprrr rreg ',' sreg ',' rreg
	{
		outcode($1, &$2, $4, &$6);
	}

|	LBEQ rreg ',' sreg ',' rel
	{
		outcode($1, &$2, $4, &$6);
	}

|	LBEQ rreg ',' rel
	{
		Gen regzero;
		regzero = nullgen;
		regzero.type = D_REG;
		regzero.reg = 0;
		outcode($1, &regzero, $2.reg, &$4);
	}

|	LBR	rel
	{
		outcode($1, &nullgen, NREG, &$2);
	}

|	LBR oreg
	{
		outcode($1, &nullgen, NREG, &$2);
	}


|	LBRET
	{
		outcode($1, &nullgen, NREG, &nullgen);
	}

|	LCALL sreg ',' addr
	{
		outcode($1, &nullgen, $2, &$4);
	}
|	LCALL sreg ',' rel
	{
		outcode($1, &nullgen, $2, &$4);
	}

|	LMOVB addr ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LMOVBU addr ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LMOVB rreg ',' addr
	{
		outcode($1, &$2, NREG, &$4);
	}

|	LMOVW imm ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LMOVW ximm ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LMOVW rreg ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LMOVW addr ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LMOVW rreg ',' addr
	{
		outcode($1, &$2, NREG, &$4);
	}
/* control registers
|	LMOVW rreg ',' ctlreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LMOVW ctlreg ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
*/

|	LLUI name ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LLUI imm ',' rreg
	{
		outcode($1, &$2, NREG, &$4);
	}


|	LSYS imm
	{
		outcode($1, &nullgen, NREG, &$2);
	}

|	LSWAP rreg ',' sreg ',' rreg
	{
		outcode($1, &$2, $4, &$6);
	}

|	LAMO con ',' rreg ',' sreg ',' rreg
	{
		outcode($1, &$4, ($2<<16)|$6, &$8);
	}

|	LTEXT name ',' imm
	{
		outcode($1, &$2, NREG, &$4);
	}
|	LTEXT name ',' con ',' imm
	{
		outcode($1, &$2, $4, &$6);
	}

|	LDATA name '/' con ',' imm
	{
		outcode($1, &$2, $4, &$6);
	}
|	LDATA name '/' con ',' ximm
	{
		outcode($1, &$2, $4, &$6);
	}
|	LDATA name '/' con ',' fimm
	{
		outcode($1, &$2, $4, &$6);
	}

|	LWORD imm
	{
		outcode($1, &nullgen, NREG, &$2);
	}

rel:
	con '(' LPC ')'
	{
		$$ = nullgen;
		$$.type = D_BRANCH;
		$$.offset = $1 + pc;
	}
|	LNAME offset
	{
		$$ = nullgen;
		if(pass == 2)
			yyerror("undefined label: %s", $1->name);
		$$.type = D_BRANCH;
		$$.sym = $1;
		$$.offset = $2;
	}
|	LLAB offset
	{
		$$ = nullgen;
		$$.type = D_BRANCH;
		$$.sym = $1;
		$$.offset = $1->value + $2;
	}

oprrr:
	LADD
|	LMUL

addr:
	oreg
|	name

oreg:
	'(' sreg ')'
	{
		$$ = nullgen;
		$$.type = D_OREG;
		$$.reg = $2;
		$$.offset = 0;
	}
|	con '(' sreg ')'
	{
		$$ = nullgen;
		$$.type = D_OREG;
		$$.reg = $3;
		$$.offset = $1;
	}

name:
	con '(' pointer ')'
	{
		$$ = nullgen;
		$$.type = D_OREG;
		$$.name = $3;
		$$.sym = S;
		$$.offset = $1;
	}
|	LNAME offset '(' pointer ')'
	{
		$$ = nullgen;
		$$.type = D_OREG;
		$$.name = $4;
		$$.sym = $1;
		$$.offset = $2;
	}
|	LNAME '<' '>' offset '(' LSB ')'
	{
		$$ = nullgen;
		$$.type = D_OREG;
		$$.name = D_STATIC;
		$$.sym = $1;
		$$.offset = $4;
	}

offset:
	{
		$$ = 0;
	}
|	'+' con
	{
		$$ = $2;
	}
|	'-' con
	{
		$$ = -$2;
	}

pointer:
	LSB
|	LSP
|	LFP

rreg:
	sreg
	{
		$$ = nullgen;
		$$.type = D_REG;
		$$.reg = $1;
	}

sreg:
	LREG
|	LR '(' expr ')'
	{
		if($3 < 0 || $3 >= NREG)
			yyerror("register value out of range");
		$$ = $3;
	}

/* control registers
ctlreg:
	LCTL '(' expr ')'
	{
		if($3 < 0 || $3 >= NREG)
			yyerror("custom register value out of range");
		$$ = nullgen;
		$$.type = D_CTLREG;
		$$.reg = $3;
	}
*/

ximm:
	'$' addr
	{
		$$ = $2;
		$$.type = D_CONST;
	}
|	'$' LSCONST
	{
		$$ = nullgen;
		$$.type = D_SCONST;
		memcpy($$.sval, $2, sizeof($$.sval));
	}

fimm:
	'$' LFCONST
	{
		$$ = nullgen;
		$$.type = D_FCONST;
		$$.dval = $2;
	}
|	'$' '-' LFCONST
	{
		$$ = nullgen;
		$$.type = D_FCONST;
		$$.dval = -$3;
	}

imm:
	'$' con
	{
		$$ = nullgen;
		$$.type = D_CONST;
		$$.offset = $2;
	}

con:
	LCONST
|	LVAR
	{
		$$ = $1->value;
	}
|	'-' con
	{
		$$ = -$2;
	}
|	'+' con
	{
		$$ = $2;
	}
|	'~' con
	{
		$$ = ~$2;
	}
|	'(' expr ')'
	{
		$$ = $2;
	}

expr:
	con
|	expr '+' expr
	{
		$$ = $1 + $3;
	}
|	expr '-' expr
	{
		$$ = $1 - $3;
	}
|	expr '*' expr
	{
		$$ = $1 * $3;
	}
|	expr '/' expr
	{
		$$ = $1 / $3;
	}
|	expr '%' expr
	{
		$$ = $1 % $3;
	}
|	expr '<' '<' expr
	{
		$$ = $1 << $4;
	}
|	expr '>' '>' expr
	{
		$$ = $1 >> $4;
	}
|	expr '&' expr
	{
		$$ = $1 & $3;
	}
|	expr '^' expr
	{
		$$ = $1 ^ $3;
	}
|	expr '|' expr
	{
		$$ = $1 | $3;
	}
