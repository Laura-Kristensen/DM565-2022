%{
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern EXP *theexpression;

int yylex();

void yyerror() {
   printf("syntax error before %s\n",yytext);
}
%}

%union {
   int intconst;
   char *stringconst;
   struct EXP *exp;
}

%token <intconst> tINTCONST
%token <stringconst> tIDENTIFIER
%token tAND "&&"
%token tOR  "||"
%token tLEQ "<="
%token tLES "<"
%token tEQ  "=="
%token '!'

%type <exp> program exp

%start program

%left "||"
%left "&&"
%nonassoc "<=" "==" "<"
%left '+' '-'
%left '*' '/'
%right NOT

%%
program: exp
         { theexpression = $1;}
;

exp : tIDENTIFIER
      {$$ = makeEXPid($1);}
    | tINTCONST
      {$$ = makeEXPintconst($1);}
    | exp '*' exp
      {$$ = makeEXPtimes($1,$3);}
    | exp '/' exp
      {$$ = makeEXPdiv($1,$3);}
    | exp '+' exp
      {$$ = makeEXPplus($1,$3);}
    | exp '-' exp
      {$$ = makeEXPminus($1,$3);}
    | exp "||" exp
      {$$ = makeEXPor($1,$3);}
    | exp "&&" exp
      {$$ = makeEXPand($1,$3);}
    | exp "<=" exp
      {$$ = makeEXPleq($1,$3);}
    | exp "==" exp
      {$$ = makeEXPeq($1,$3);}
    | exp "<" exp
      {$$ = makeEXPles($1,$3);}
    | '!' exp %prec NOT
      {$$ = makeEXPnot($2);}
    | '(' exp ')'
      {$$ = $2;}
;

%%
