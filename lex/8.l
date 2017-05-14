%{
int keywd,identifier,separator,operator;
%}
keyword printf|scanf|if|else
%%
{keyword}   {keywd++;}
[$_a-zA-Z]*[0-9a-zA-Z]* {identifier++;}
[;,]    {separator++;}
[+*]  {operator++;}
%%
int yywrap()
{
return 1;
}
int main()
{
  yyin=fopen("prog.c","r");
  yylex();
  printf("identifier %d,keywd %d,operator %d,separator %d",identifier,keywd,operator,separator);
  return 0;
}

