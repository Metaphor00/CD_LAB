%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%%
[0-9]+  {printf("%s is an integer\n",yytext);}
"if"|"else"|"while"|"int"   {printf("%s is a keyword\n",yytext);}
[a-zA-Z][a-zA-Z0-9]*    {printf("%s is an identifier\n",yytext);}
"<"|"="|">"|">="|"<="|"+"|"-"|"*"|"/"   {printf("%s is an operator\n",yytext);}
"'"|";"|","|"("|")"|"{"|"}"    {printf("%s is a special character\n",yytext);}
%%

 int main()
 {
    FILE *f1;
    f1=fopen("input.txt","r");
    if(f1==NULL){
        printf("error while opening the file\n");
        exit(0);
    }
    yyin = f1;
    yylex();
    fclose(f1);
 }

 int yywrap()
 {
    return 1;
 }