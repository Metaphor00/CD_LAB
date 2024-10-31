%{
    #include<stdio.h>
%}

ODD [0-9]*[1|3|5|7|9]
EVEN [0-9]*[0|2|4|6|8]

%%
{ODD}+         {printf("%s is an odd number\n",yytext);exit(0);}
{EVEN}+       {printf("%s is an even number\n",yytext);exit(0);}
%%

void main(){
    printf("enter a number to check:");
    yylex();
    
}
int yywrap(){
    return 1;
}