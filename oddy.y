%{
    #include <stdio.h>
    #include <stdlib.h> // Include for standard library functions
    void yyerror(char *s); // Prototype for the yyerror function
    int yylex(); // Prototype for yylex function
%}

%token ODD EVEN

%%
id:     ODD  { printf("odd number\n"); }
      | EVEN { printf("even number\n"); }
      ;
%%

int main(void)
{
    printf("enter a number:\n");
    yyparse();
    return 0;
}

void yyerror(char *msg)
{
     printf("error\n");
}

int yywrap()
{
    return 1;
}
