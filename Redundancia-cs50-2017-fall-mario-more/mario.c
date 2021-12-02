#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int n;

  // Prompt user to set pyramid size
  do
  {
    n = get_int("Pyramid size: ");
  }
  while (n < 0 || n > 23);

  //Print out this many rows
  for (int i = 0; i < n; i++)
  {

    //Print out this many spaces
    for (int k = n-i-2; k >= 0; k--)
    {
      printf(" ");
    }

    //Print out this many columns
    for (int j = 0; j <= i; j++)
    {
      printf("#");
    }

    //Print out 2 spaces
    printf("  ");

    //Print out this many columns
    for (int l = 0; l <= i; l++)
    {
      printf("#");
    }

    printf("\n");
  }
}

