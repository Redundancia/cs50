#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[1])
{
  if (argc != 2)
  {
    printf("Proper use: ./caesar k\n");
    return 1;
  }

  int rotate = atoi(argv[1]);

  if (argc == 2 && rotate >= 0 )
  {
    //We make sure we only rotate with mod 26 rest is just useless cycle
    rotate = rotate % 26;

    string plaintext = get_string("plaintext:  ");
    int plain_len = strlen(plaintext);

    //Make cipher and plain the same so: it is the same length and easily replaced
    string ciphertext = plaintext;

    //Plaintext coding with loop/char
    for(int i = 0; i < plain_len; i++)
    {
      //Char is in alphabet
      if (isalpha(plaintext[i]))
      {
        //is uppercase
        if (isupper(plaintext[i]))
        {
          if (plaintext[i] + rotate > 90)
          {
            ciphertext[i] = plaintext[i] + rotate - 26;
          }
          else
          {
            ciphertext[i] = plaintext[i] + rotate;
          }
        }
        //is lowercase
        else
        {
          if (plaintext[i] + rotate > 122)
          {
            ciphertext[i] = plaintext[i] + rotate - 26;
          }
          else
          {
            ciphertext[i] = plaintext[i] + rotate;
          }
        }
      }
      //if not in alphabet
      else
      {
        ciphertext[i] = plaintext[i];
      }
    }
    printf("ciphertext: %s\n",ciphertext);
    return 0;
  }
}