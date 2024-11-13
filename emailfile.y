%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    //#include "lex.yy.c"  // Remove unnecessary include for lex.yy.c

    extern int yylex(void);
    void yyerror(char *s);
    extern FILE *yyin;
    int flag = 0;
%}

%token DIGIT LETTER ADDRESS AT

%%
id:     LETTER AT LETTER ADDRESS { /* No additional output here */ }
        | LETTER DIGIT AT LETTER ADDRESS { /* No additional output here */ }
        | DIGIT AT LETTER ADDRESS { /* No additional output here */ }
        ;
%%

int main() {
    FILE *f1, *validFile, *invalidFile;
    char line[1024];

    f1 = fopen("emailfile.txt", "r");
    if (f1 == NULL) {
        printf("Error opening emailfile.txt\n");
        return 1;
    }

    // Open files for valid and invalid emails
    validFile = fopen("valid_emails.txt", "w");
    if (validFile == NULL) {
        printf("Error creating valid_emails.txt\n");
        fclose(f1);
        return 1;
    }

    invalidFile = fopen("invalid_emails.txt", "w");
    if (invalidFile == NULL) {
        printf("Error creating invalid_emails.txt\n");
        fclose(f1);
        fclose(validFile);
        return 1;
    }

    // Process each line in emailfile.txt
    while (fgets(line, sizeof(line), f1)) {
        // Clear any previous flag value
        flag = 0;

        // Use yy_scan_string to parse the current line
        yy_scan_string(line);
        yyparse();

        // Check if the line was valid or invalid and write to the appropriate file
        if (flag == 0) {
            fprintf(validFile, "%s", line);
            printf("Valid email ID: %s", line);
        } else {
            fprintf(invalidFile, "%s", line);
            printf("Invalid email ID: %s", line);
        }
    }

    // Close all files
    fclose(f1);
    fclose(validFile);
    fclose(invalidFile);

    return 0;
}

void yyerror(char *msg) {
    flag = 1;  // Set flag to indicate an invalid email
}

int yywrap() {
    return 1;
}
