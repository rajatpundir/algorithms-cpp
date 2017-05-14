%{
int state = 0;
%}
%%
"0"	{if(state==0) state=1;else state=0; }
.	;
%%
int main()
{
// Design a DFA in lex, to accept even number of zeroes.
yylex();
if(state==0)
puts("Even no. of zeroes");
else 
puts("Odd no. of zeroes");
return 1;
}
