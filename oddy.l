%{
    #include "y.tab.h"
    #include <stdlib.h>
%}

%%

[1-9]*[13579]  { yylval = atoi(yytext); return ODD; }
[1-9]*[02468]  { yylval = atoi(yytext); return EVEN; }
[ \t\n]+       ;  /* Ignore whitespace */
.              { return yytext[0]; }

%%
