%{
%}
%s	A
%%
<INITIAL>1	BEGIN INITIAL;
<INITIAL>0	BEGIN A;
<INITIAL>\n	BEGIN INITIAL;puts("Accepted");
<A>1	BEGIN A;
<A>0	BEGIN INITIAL;
<A>\n	BEGIN INITIAL;puts("Not Accepted");
%%
int main()
{
// Design a DFA in lex, to accept even number of zeroes.
yylex();
return 1;
}
