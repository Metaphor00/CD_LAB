#include <stdio.h>
#include <string.h>

void main()
{

    char string[20], stack[20] = {'\0'}; // initialize stack with null characters
    printf("enter a string:\n");
    scanf("%s", string);

    int c = strlen(string);
    string[c] = '$';
    string[c + 1] = '\0';
    stack[0] = '$';
    printf("stack   input   action\n");
    char *strptr = string;
    int stackptr = 1; // we know index of 0 is $ so lets start with 1st position

    while (*strptr != '$')
    {
        if (*strptr == '+')
        {
            stack[stackptr] = '+';
            stackptr++;
            stack[stackptr] = '\0';
            strptr++; // for moving to the next character in the string
            printf("%s      %s      SHIFT\n", stack, strptr);
        }
        else if (*strptr == '*')
        {
            stack[stackptr] = '*';
            stackptr++;
            stack[stackptr] = '\0';
            strptr++; // for moving to the next character in the string
            printf("%s      %s      SHIFT\n", stack, strptr);
        }
        else if (*strptr == '/')
        {
            stack[stackptr] = '/';
            stackptr++;
            stack[stackptr] = '\0';
            strptr++; // for moving to the next character in the string
            printf("%s      %s      SHIFT\n", stack, strptr);
        }
        else if (*strptr == 'a')
        {
            stack[stackptr] = 'a';
            stack[stackptr + 1] = '\0';
            printf("%s      %s      SHIFT\n", stack, strptr);
            stack[stackptr] = 'E';
            stackptr++;
            stack[stackptr] = '\0';
            strptr++;
            printf("%s      %s      REDUCE E->a\n", stack, strptr);
        }
        else if (*strptr == 'b')
        {
            stack[stackptr] = 'b';
            stack[stackptr + 1] = '\0';
            printf("%s      %s      SHIFT\n", stack, strptr);
            stack[stackptr] = 'E';
            stackptr++;
            stack[stackptr] = '\0';
            strptr++;
            printf("%s      %s      REDUCE E->b\n", stack, strptr);
        }
        // checking patterns
        if (strcmp(stack, "$E/E") == 0)
        {
            // clearing the stack
            memset(stack, '\0', sizeof(stack));
            stack[0] = '$';
            stackptr = 1;
            stack[stackptr] = 'E';
            stackptr++;
            printf("%s      %s      REDUCE E->E/E\n", stack, strptr);
        }
        if (strcmp(stack, "$E*E") == 0)
        {
            // clearing the stack
            memset(stack, '\0', sizeof(stack));
            stack[0] = '$';
            stackptr = 1;
            stack[stackptr] = 'E';
            stackptr++;
            printf("%s      %s      REDUCE E->E*E\n", stack, strptr);
        }
        if (strcmp(stack, "$E+E") == 0)
        {
            // clearing the stack
            memset(stack, '\0', sizeof(stack));
            stack[0] = '$';
            stackptr = 1;
            stack[stackptr] = 'E';
            stackptr++;
            printf("%s      %s      REDUCE E->E+E\n", stack, strptr);
        }
    }
    if (strcmp(stack, "$E") == 0)
    {
        printf("string is accepted\n");
    }
    else
    {
        printf("string is not accepted\n");
    }
}