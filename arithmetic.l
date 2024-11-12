%{
    #include"y.tab.h"
%}

%%
[0-9]+ {yylval =atoi(yytext);return DIGIT;}
[a-zA-Z] {return LETTER;}
"*"     {return MUL;}
"/"     {return DIV;}
"+"     {return PLUS;}  
"-"     {return MINUS;}
"("     {return LPARA;}
")"     {return RPARA;}
[\t\n]+ ;
.       ;
%%