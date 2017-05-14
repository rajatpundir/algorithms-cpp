%{
 int line=0, character=0, words=0;
%}
%%
[\n] line++;
[^ \t\n]+ {words++;character=character+yyleng;}
. character++;
%%
int yywrap()
{
return 1;
}

void main()
 {
  printf("INPUT :\n");
  yyin=fopen("prog.c","r");
  yylex();
  printf("No. of lines= %d\nNo. of words =%d\nNo. of characters = %d",line,words,character);
 }
