#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int count_letters (string quote);

int main(void)
{
    string quote = get_string("Text: ");

    printf ("Letters: %i", count_letters(quote));
    
    printf("\n");

}

int count_letters (string quote)
{
    int sum = 0;
    for (int i = 0; i < strlen(quote); i++)
    {
        char currentLetter = quote[i];
        bool isValidChar = (currentLetter >= 'a' && currentLetter <= 'z') || (currentLetter >= 'A' && currentLetter <= 'Z');

        if(isValidChar) 
        {
            sum ++;
        }
    }
    return sum;
}
