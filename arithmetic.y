%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex(void);
    void yyerror(char *s);
    int flag=0;
%}

%token DIGIT LETTER MUL DIV PLUS MINUS LPARA RPARA
%left   PLUS MINUS
%left   MUL DIV

%%

expr:     expr PLUS expr       
        | expr MINUS expr      
        | expr MUL expr         
        | expr DIV expr        
        | LPARA expr RPARA     
        | DIGIT                  
        | LETTER               
        ;

%%

int main() {
    printf("Enter the expression:\n");
    yyparse();
    if(flag==0){
        printf("valid arithmetic expression\n");
    }
}

void yyerror(char *msg) {
    printf("Invalid arithmetic expression\n");
    flag=1;
}

int yywrap() {
    return 1;
}
