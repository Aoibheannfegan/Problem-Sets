#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(char character, int key) ;
int main(int argc, string argv[])

{
    string key = argv[1];
    bool isKey = (isdigit(key));

    if (argc == 2)
    {
        if(isKey == false)
        {
            printf("Usage: ./caesar key\n");
        }

        else
        {
            string plain_text = get_string("Plain text: ");
            printf ("ciphertext: ");

            for (int z = 0, x = strlen(plain_text); z < x; z++)
            {
                int keyaslong = atoi(key);
                char currentchar = plain_text[z];
                encrypt(currentchar, keyaslong);
            }
        }
    }

    else
    {
         printf("Usage: ./caesar key\n");
    }
    printf("\n");

}




void encrypt(char character, int key)
 {
    bool isletter = isalpha(character);
    if (isletter)
    {
        if (isupper(character))
        {
             char encryptedCharacter = (character + key - 97) % 26 + 97;
             printf("%c", encryptedCharacter);
        }

        else
        {
             char encryptedCharacter = (character + key - 65) % 26 + 65;
             printf("%c", encryptedCharacter);
        }
    }

 }
