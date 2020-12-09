#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])

{
    string key = argv[1];
    long keyaslong = atol(key);

    if (argc == 2)
    {
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            bool isKey = (isdigit(key[i]));
            if(isKey == false)
            {
               printf("Usage: ./caesar key");
            }
         }
        printf("%ld", keyaslong);
    }
    else
    {
        printf("Usage: ./caesar key");
    }
    printf("\n");
    
    
    
    string plain_text = get_string("Plain text: ");
    printf ("ciphertext: ");

    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        char currentchar = plain_text[i];
        
        bool isletter = isalpha(currentchar);
        
        if (isletter)
        {
              if (isupper(currentchar))
            {
                int upper = ((int)plain_text[i]) - 65;
                int cypher[i] = (upper + keyaslong) % 26;
                printf("%c", (char)(cypher[i] + 65));
            }

            else if (islower(currentchar))
            {
                int lower = ((int)plain_text[i]) - 97;
                int cypher[i] = (lower + keyaslong) % 26;
                printf("%c", (char)(cypher[i] + 97));
            }
        }
        
        else 
        {
            printf("%c", plain_text[i]);
        }

    }
    printf("\n");
}
