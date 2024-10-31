%{
    #include<stdio.h>
%}

DIGIT [0-9]
KEYWORD "if"|"else"|"while"|"int"
ID [a-zA-Z][a-zA-Z0-9]*
OP "<"|"="|">"|">="|"<="|"+"|"-"|"*"|"/"
SPECIALCHARACTER "'"|";"|","|"("|")"|"{"|"}"

%%
{KEYWORD}            { printf("%s is a keyword\n", yytext); }
{DIGIT}+             { printf("%s is an integer\n", yytext); }
{ID}                 { printf("%s is an identifier\n", yytext); }
{OP}                 { printf("%s is an operator\n", yytext); }
{SPECIALCHARACTER}   { printf("%s is a special character\n", yytext); }
%%

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");

    if(fp == NULL){
        printf("Error while opening the file\n");
        exit(0);
    }

    yyin = fp;
    yylex();
    fclose(fp);
    return 0;
}

int yywrap() {
    return 1;
}