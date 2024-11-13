%{
    #include<stdio.h>
%}

%%
[0-9]*[1|3|5|7|9]   {printf("%s is an odd number\n",yytext);}
[0-9]*[2|4|6|8|0]   {printf("%s is an even number\n",yytext);}
%%

int main()
{
    printf("enter a number to check:\n");
    yylex();
    exit(0);
}
int yywrap()
{
    return 1;
}