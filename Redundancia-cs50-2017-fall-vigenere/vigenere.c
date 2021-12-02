#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[1])
{
  if (argc != 2)
  {
    printf("Proper use: ./vigenere  one alphabetic word\n");
    return 1;
  }

  string key = argv[1];
  int key_len = strlen(key);

  for (int k = 0; k < key_len; k++)
  {
    if (!isalpha(key[k]))
    {
      printf("Proper use: ./vigenere alphabetic word\n");
      return 1;
      k = k + key_len;
    }
  }

  if (argc == 2)
  {
    string plaintext = get_string("plaintext:  ");
    int plain_len = strlen(plaintext);

    //Make cipher and plain the same so: it is the same length and easily replaced
    string ciphertext = plaintext;


    //Plaintext coding with loop/char
    int j = 0;
    int rotate;
    for (int i = 0; i < plain_len; i++)
    {
      //Key is uppercase
      if (isupper(key[j]))
      {
        rotate = key[j] % 65;
      }
      //Key is lowercase
      if (islower(key[j]))
      {
        rotate = key[j] % 97;
      }
      //Char is in alphabet
      if (isalpha(plaintext[i]))
      {
        //is uppercase
        if (isupper(plaintext[i]))
        {
          if (plaintext[i] + rotate > 90)
          {
            ciphertext[i] = plaintext[i] + rotate - 26;
            j = (j + 1) % key_len;
          }
          else
          {
            ciphertext[i] = plaintext[i] + rotate;
            j = (j + 1) % key_len;
          }
        }
        //is lowercase
        else
        {
          if (plaintext[i] + rotate > 122)
          {
            ciphertext[i] = plaintext[i] + rotate - 26;
            j = (j + 1) % key_len;
          }
          else
          {
            ciphertext[i] = plaintext[i] + rotate;
            j = (j + 1) % key_len;
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