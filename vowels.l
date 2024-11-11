%{
    #include <stdio.h>
    int VOWELS = 0, CONSONANTS = 0; // Initialize counters for vowels and consonants
%}

%%
[a/A/e/E/i/I/o/O/u/U]    { VOWELS++; }
[a-zA-Z] { CONSONANTS++; }
%%

void main() {
    printf("Enter the input: ");
    yyin = stdin;
    yylex(); // Start lexical analysis

    // Display the total counts
    printf("\nTotal Vowels: %d\n", VOWELS);
    printf("Total Consonants: %d\n", CONSONANTS);

 
}

int yywrap() {
    return 1;
}
