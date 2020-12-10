#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

char ciphertext (char currentchar, int keyaslong);
int main(int argc, string argv[])

{
    string key = argv[1];

    if (argc == 2)
    {
        bool isKey = (isdigit(key));
        if(isKey == false)
        {
            printf("Usage: ./caesar key\n");
        }
    }

    else
    {
         printf("Usage: ./caesar key\n");
    }
    
    
    
    string plain_text = get_string("Plain text: ");
    printf ("ciphertext: ");

    for (int z = 0, x = strlen(plain_text); z < x; z++)
    {
        int keyaslong = atoi(key);
        char currentchar = plain_text[z];
        printf("%c", ciphertext(currentchar,keyaslong));
    }
    printf("\n");

}



char ciphertext (char currentchar, int keyaslong)
{
        bool isletter = isalpha(currentchar);
        int cipher = (int)currentchar;

        if (isletter)
        {
            if (isupper(currentchar))
            {
                int upper = cipher - 65;
                return (char)(upper + keyaslong) % 26;
            }

            else if (islower(currentchar))
            {
                int lower = cipher - 97;
                return (char)(lower + keyaslong) % 26;
            }
        }
        else
        {
            return currentchar;      
        }

}
