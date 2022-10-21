%{
// bison --report=all exp.y
#include <stdio.h>

extern char *yytext;

void yyerror() {
  printf("syntax error before %s\n",yytext);
}
int yylex();
%}

%union {
   int intconst;
   char *stringconst;
}

%token <stringconst> tID
%token tWHILE "while"
%token tDO "do"
%token tASSIGN ":="
%token '+'

/*
%precedence WHILEPREC
%precedence ":="
%left '+'
*/

%start S


%%
S: E { };

E
: "while" E "do" E %prec WHILEPREC {}
| tID ":=" E {}
| E '+' E {}
| tID {}
;
%%
