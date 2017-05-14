%{
%}
%s A
%s B
%s C
%%
<INITIAL>1  BEGIN C;
<INITIAL>0  BEGIN A;
<INITIAL>\n BEGIN INITIAL;printf("\nString Accepted\n");
<A>1  BEGIN B;
<A>0  BEGIN INITIAL;
<A>\n BEGIN INITIAL;printf("\nString Rejected\n");
<B>1  BEGIN A;
<B>0  BEGIN C;
<B>\n BEGIN INITIAL;printf("\nString Rejected\n");
<C>0  BEGIN B;
<C>1  BEGIN INITIAL;
<C>\n BEGIN INITIAL;printf("\nString Rejected\n");
%%
int main()
{
  yylex();
  return 0;
}
