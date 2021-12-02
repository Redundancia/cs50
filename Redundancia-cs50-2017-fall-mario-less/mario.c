#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = 0;
    int n;
    int j;
    // Prompt user to give us pyramid size
    do
    {
        n = get_int("Pyramid size: ");
    }
    while (n < 0 || n >= 24);

    // Print out this many rows
    for (i = 0; i < n; i++)
    {
        //Print out this many spaces
        for (int k = n-i-2; k >= 0; k--)
        {
            printf(" ");
        }

        //Print out this many columns
        for (j = -1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}