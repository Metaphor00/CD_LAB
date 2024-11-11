#include <stdio.h>
#include <string.h>

void main()
{
    int state = 0;
    char string[20];
    printf("enter the string:");
    scanf("%s", string);

    for (int i = 0; i < strlen(string); i++)
    {
        char c = string[i];

        switch (state)
        {
        case 0:
            if (c == '1')
                state = 0;

            else if (c == '0')
                state = 1;
            break;
        case 1:
            if (c == '0')
                state = 1;

            else if (c == '1')
                state = 2;
            break;
        case 2:
            if (c == '0')
                state = 1;

            else if (c == '1')
                state = 0;
            break;
        }
    }
    if (state == 2)
    {
        printf("\nThe string is accepted");
    }
    else
    {
        printf("\n The string is not accepted");
    }
}