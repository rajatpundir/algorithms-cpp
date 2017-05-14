%{
#include "stdio.h"
%}
%token NUM ID
%start s
%left '+' '-'
%left '*' '/'
%%
s: expr {printf("Valid Expression\n");}
:
expr: expr '+' expr
  |expr '-' expr
  |expr '*' expr
  |expr '/' expr
  |NUM
  |ID
  |'-' expr
  :
%%
main(){
  printf("Enter Expr : ");
  yyparse();
}
void yyerror(char *s)
{
  printf("\nInvalid Expression\n");
}
