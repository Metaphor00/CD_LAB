%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex(void);
    void yyerror(char *s);
    int flag=0;
%}

%token DIGIT LETTER ADDRESS
%token AT

%%
id:     LETTER AT LETTER ADDRESS
        |LETTER DIGIT AT LETTER ADDRESS
        |DIGIT AT LETTER ADDRESS
;
%%
int main()
{
    printf("enter an email:\n");
    yyparse();
    if(flag == 0){
        printf("valid email id\n");
    }
}
void yyerror(char *msg){
    flag =1;
    printf("invalid email id\n");

}
int yywrap()
{
    return 1;
}