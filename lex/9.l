%{
#include<stdio.h>
#include<string.h>
char line[20];
FILE *out=NULL;
%}

%%

\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
(.*)  {fputs(yytext,out);}

%%

int main()
{
yyin=fopen("prog.c","r");
out=fopen("new.c","w");
yylex();
return 0;
}

int yywrap()
{
return 1;
}
