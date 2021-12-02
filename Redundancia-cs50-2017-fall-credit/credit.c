#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
  long long card_number;
  int digits = 0;
  int CC_sum = 0;

  //Prompt user to give us credit card number
  do
  {
    card_number = get_long_long("Number: ");
  }
  while (card_number < 0);

  //Count the digits
  long long card_number1 = card_number;

  while (card_number1 > 0)
  {
    digits++;
    card_number1 = card_number1 / 10;
  }

  long long card_number2 = roundl(card_number / 10);

  //Get every second digit starting from behind, *2 them and sum the DIGITS
  while (card_number2 > 0)
  {
    if ((card_number2 % 10) * 2 >= 10)
    {
      CC_sum += (((card_number2 % 10) * 2) % 10) + 1;
    }
    else
    {
      CC_sum += (card_number2 % 10) * 2;
    }
    card_number2 = card_number2 / 100;
  }

  //Add left out numbers to the sum
  long long card_number3 = card_number;

  while (card_number3 > 0)
  {
    CC_sum += roundl(card_number3 % 10);
    card_number3 =  card_number3 / 100;
  }

  long long n_n = 10;

  //Check if CC number sum mod 10 is 0
  if (CC_sum % 10 == 0)
  {
    //Check if card is 15 digits long
    if (digits == 15)
    {
      //Check if it starts with 34 or 37
      //Implement int^n
      for (int codestart1 = 3 ; codestart1 < digits; codestart1++ )
      {
        n_n = n_n * 10;
      }
      if (card_number / n_n == 34 || card_number / n_n == 37)
      {
        printf("AMEX\n");
      }
      else
      {
        //Check if it starts with 4
        n_n = 10;
        for (int codestart1 = 2 ; codestart1 < digits; codestart1++ )
        {
          n_n = n_n * 10;
        }
        if (card_number / n_n == 4)
        {
          printf("VISA\n");
        }
        else
        {
         printf("INVALID\n");
        }
      }
    }
    else
    {
      //Check if its 16 digits long
      if (digits == 16)
      {
        //Check if its starts with 51,52,53,54,55
        n_n = 10;
        for (int codestart1 = 3 ; codestart1 < digits; codestart1++ )
        {
          n_n = n_n * 10;
        }
        if (card_number / n_n == 51 || card_number / n_n == 52
        || card_number / n_n == 53 || card_number / n_n == 54
        || card_number / n_n == 55)
        {
          printf("MASTERCARD\n");
        }
        else
        {
          //Check if it starts with 4
          n_n = 10;
          for (int codestart1 = 2 ; codestart1 < digits; codestart1++ )
          {
            n_n = n_n * 10;
          }
          if (card_number / n_n == 4)
          {
            printf("VISA\n");
          }
          else
          {
            printf("INVALID\n");
          }
        }
      }
      else
      {
        //Check if its 13,14 digits long
        if (digits == 13 || digits == 14)
        {
          //Check if it starts with 4
          n_n = 10;
          for (int codestart1 = 2 ; codestart1 < digits; codestart1++ )
          {
            n_n = n_n * 10;
          }
          if (card_number / n_n == 4)
          {
            printf("VISA\n");
          }
          else
          {
            printf("INVALID\n");
          }
        }
        else
        {
          printf("INVALID\n");
        }
      }
    }
  }
  else
  {
    printf("INVALID\n");
  }
}