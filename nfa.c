#include <stdio.h>
#include <string.h>

// declaring the required arrays
char result[20][3]; // for storing the results
char copy[3];       // for storing the copies
char states[20][3]; // for getting the input

// function for adding the states
void add_state(char a[20], int i)
{
    strcpy(result[i], a);
}
// function for printing
void display(int n)
{
    int k = 0;
    printf("\n Epsilon Closure of %s = {", copy);
    while (k < n)
    {
        printf("%s", result[k]);
        k++;
    }
    printf("}\n");
}

int main()
{
    FILE *INPUT;
    INPUT = fopen("input.dat", "r");
    if (INPUT == NULL)
    {
        printf("error opening file\n");
        return 1;
    }
    char state[20];
    int end, i = 0, n, k = 0;
    char state1[20], input[20], state2[20];

    printf("\nEnter the no of states:\n");
    scanf("%d", &n);
    printf("enter the states\n");
    for (k = 0; k < n; k++)
    {
        scanf("%s", states[k]);
    }
    // we will consider the first state, then we will check the transitons upon e
    for (k = 0; k < n; k++)
    {
        i = 0;
        strcpy(state, states[k]);
        strcpy(copy, state);
        add_state(state, i++);

        while (1)
        {
            end = fscanf(INPUT, "%s%s%s", state1, input, state2);
            if (end == EOF)
            {
                break;
            }
            if (strcmp(state, state1) == 0)
            {
                if (strcmp(input, "e") == 0)
                {
                    add_state(state2, i++);
                    strcpy(state, state2);
                }
            }
        }
        display(i);
        rewind(INPUT);
    }
    fclose(INPUT);
    return 0;
}