#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

void ciphertext (char currentchar, int keyaslong);
int main(int argc, string argv[])

{
    string key = argv[1];

    if (argc == 2)
    {
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            bool isKey = (isdigit(key[i]));
            if(isKey == false)
            {
               printf("Usage: ./caesar key");
            }

            else
            {
                int keyaslong = atoi(key);
                string plain_text = get_string("Plain text: ");
                printf ("ciphertext: ");

                for (int z = 0, x = strlen(plain_text); z < x; z++)
                {
                     char currentchar = plain_text[z];
                     ciphertext(currentchar,keyaslong);
                }
            }
        }
    }

    else
    {
        printf("Usage: ./caesar key");
    }

    printf("\n");
}



void ciphertext (char currentchar, int keyaslong)
{
        bool isletter = isalpha(currentchar);
        int cipher = (int)currentchar;

        if (isletter)
        {
            if (isupper(currentchar))
            {
                int upper = cipher - 65;
                printf("%c", (upper + keyaslong) % 26);
            }

            else if (islower(currentchar))
            {
                int lower = cipher - 97;
                printf("%c",(lower + keyaslong) % 26);
            }
        }

}
