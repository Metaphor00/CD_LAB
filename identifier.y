%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex(void);
    void yyerror(char *s);
%}
%token DIGIT LETTER

%%
id:     LETTER      {printf("valid identifier\n");exit(0);}
        |id LETTER  {printf("valid identifier\n");exit(0);}
        |id DIGIT   {printf("valid identifier\n");exit(0);}
;
%%
int main()
{
    printf("enter the variable:\n");
    yyparse();
}
void yyerror(char *msg)
{
    printf("invalid identifier\n");
}
int yywrap()
{
    return 1;
}