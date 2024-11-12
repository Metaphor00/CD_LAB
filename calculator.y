%{
   #include<stdio.h>
   #include<stdlib.h>
   int yylex(void);
   void yyerror(char *s); 
  
%}

%token DIGIT PLUS MINUS MUL DIV
%left PLUS MINUS
%left MUL DIV

%%
A:expr{printf("result=%d\n",$$);return 0;}
expr:   expr PLUS expr {$$=$1+$3;}
        |expr MINUS expr {$$=$1-$3;}
        |expr MUL expr {$$=$1*$3;}
        |expr DIV expr {$$=$1/$3;}
        |DIGIT{$$=$1;}
;

%%
int main() {
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}

void yyerror(char *msg)
{
    printf("error/n");
    
}
int yywrap()
{
    return 1;
}
