%{
int count = 0, state = 0;
%}
%%
[0-9]   {if(state == 0) state = 2; printf("%s", yytext); }
[a-zA-Z]    {if(state == 0) state = 1; printf("%s", yytext);}
"\n"    {if(state == 1) {count++; printf(" is valid. \n");} else if(state == 2) printf(" is invalid. \n"); state = 0;}
.   {if(state == 1) {count++; printf(" is valid. \n");} else if(state == 2) printf(" is invalid. \n"); state = 0;}
%%
void main()
{
    yylex();
    printf("\nTotal valid identifiers= %d \n", count);
}
