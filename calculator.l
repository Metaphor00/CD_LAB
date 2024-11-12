%{
    #include"y.tab.h"
%}

%%
[0-9]+  {yylval=atoi(yytext);return DIGIT;}
"+"     {return PLUS;}
"-"     {return MINUS;}
"*"     {return MUL;}
"/"     {return DIV;}
[\t\n]+ ;
.       ;
%%