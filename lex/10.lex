%{

%}
%%
"<"[^>]+">"	puts(yytext);
.	;
%%
int main()
{
// Design a lex code to print HTML tags.
yyin = fopen( "input.txt", "r" );
yyout = fopen( "output.txt", "w" );
yylex();
return 1;
}
