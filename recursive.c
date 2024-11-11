#include <stdio.h>
#include <string.h>
#define SUCCESS 1;
#define FAILED 0;
// function prototyping
int E(), Edash(), T(), Tdash(), F();
const char *cursor; // pointer for movin through the char array
char string[64];    // character array for storing the input

int main()
{
    printf("enter the string:\n");
    scanf("%s", string);
    cursor = string; // assigning pointer
    // printf(" ");
    printf("Input       Action\n");
    printf("-------------------------\n");

    if (E() && *cursor == '\0')
    {
        printf("-------------------------\n");
        printf("string successfully parsed\n");
        return 0;
    }
    else
    {
        printf("string is not parsed\n");
        return 1;
    }
}
int E()
{
    printf("%-16s E -> T E'\n", cursor);
    if (T())
    {
        if (Edash())
        {
            return SUCCESS;
        }
        else
        {
            return FAILED;
        }
    }
    else
    {
        return FAILED;
    }
}

int Edash()
{
    if (*cursor == '+')
    {
        printf("%-16s E' -> + T E'\n", cursor);
        cursor++;
        if (T())
        {
            if (Edash())
            {
                return SUCCESS;
            }
            else
                return FAILED;
        }
        else
            return FAILED
    }
    else
    {
        printf("%-16s E' -> $\n", cursor);
        return SUCCESS;
    }
}

// function for T->Ft'
int T()
{
    printf("%-16s T -> F T'\n", cursor);
    if (F())
    {
        if (Tdash())
        {

            return SUCCESS;
        }

        else
        {
            return FAILED;
        }
    }
    else
    {
        return FAILED;
    }
}
// function for T'->*Ft'|$
int Tdash()
{
    if (*cursor == '*')
    {
        printf("%-16s T' -> * F T'\n", cursor);
        cursor++;
        if (F())
        {
            if (Tdash())
            {
                return SUCCESS;
            }
            else
                return FAILED;
        }
        else
        {
            return FAILED;
        }
    }
    else
    {
        printf("%-16s T' -> $\n", cursor);
        return SUCCESS;
    }
}
// function for F->(E)|i
int F()
{
    if (*cursor == '(')
    {
        printf("%-16s F -> (E)\n", cursor);
        cursor++;
        if (E())
        {
            if (*cursor == ')')
            {
                cursor++;
                return SUCCESS;
            }
            else
                return FAILED;
        }
        else
        {
            return FAILED;
        }
    }
    else if (*cursor >= 'a' && *cursor <= 'z')
    {
        printf("%-16s F -> i\n", cursor);
        cursor++;
        return SUCCESS;
    }
    else
    {
        return FAILED;
    }
}
