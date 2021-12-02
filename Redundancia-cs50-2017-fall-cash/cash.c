#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
  int change_in_cents;
  float dollar;
  int coin = 0;
  //Prompt user to input change
  do
    {
      dollar = get_float("Your change in dollar: ");
    }
  while(dollar < 0);

  //Change value to cents
  change_in_cents = roundf(dollar * 100);

  //Count number of coins needed
  while (change_in_cents >= 25)
  {
    coin++;
    change_in_cents = change_in_cents-25;
  }

  while (change_in_cents >= 10)
  {
    coin++;
    change_in_cents = change_in_cents-10;
  }

  while (change_in_cents >= 5)
  {
    coin++;
    change_in_cents = change_in_cents-5;
  }

  while (change_in_cents >= 1)
  {
    coin++;
    change_in_cents = change_in_cents-1;
  }

  printf("%i\n", coin);
}



