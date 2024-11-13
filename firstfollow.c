#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, i = 0, m = 0, j = 0;
char a[10][10], f[10]; // f is used for finding the first and follow
void follow(char c);
void first(char c);
int main()
{
    char c;
    int z;
    printf("enter the no of productions:\n");
    scanf("%d", &n);
    printf("enter the productions:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    do
    {
        m = 0;
        printf("enter the element whose first and follow is to be found:\n");
        scanf("%c", &c);
        first(c);
        // printing the first set
        printf("First(%c)={", c);
        for (i = 0; i < n; i++)
        {
            printf("%c", f[i]);
        }
        printf("}\n");
        strcpy(f, ""); // clearing the f so that it can be reused for findinf the follow too
        m = 0;
        follow(c);
        // printing the follow set
        printf("Follow(%c)={", c);
        for (i = 0; i < n; i++)
        {
            printf("%c", f[i]);
        }
        printf("}\n");
        printf("continue(0/1)?");
        scanf("%d", &z);
    } while (z == 1);
    return 0;
}
// function for finding first
void first(char c)
{
    int k;
    if (!isupper(c))
    {
        // if c is a terminal directly add it to the first set
        f[m++] = c;
        return;
    }
    for (k = 0; k < n; k++)
    {
        // check if the rules lhs matches c
        if (a[k][0] == c)
        {
            // check if rhs is epsilon
            if (a[k][2] == '$')
            {
                f[m++] = '$';
            }
            else if (islower(a[k][2]))
            {
                f[m++] = a[k][2];
            }
            else
            {
                // if its a non terminal just find its first
                first(a[k][2]);
            }
        }
    }
}
// function for finding the follow
void follow(char c)
{
    if (a[0][0] == c)
    {
        f[m++] = '$';
    }

    for (i = 0; i < n; i++) // iterate through all productions
    {
        for (j = 2; j < strlen(a[i]); j++) // check each symbol in the rhs
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                {
                    first(a[i][j + 1]); // find the first of the next symbol
                }
                if (a[i][j + 1] == '\0' && c != a[i][0])
                {
                    follow(a[i][0]); // find the follow of the non terminal
                }
            }
        }
    }
}