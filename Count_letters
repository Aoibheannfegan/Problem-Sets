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
    for (int letters = 0; (letters >= 'a' && letters <= 'z') || (letters >= 'A' && letters <= 'Z'); letters++)
    {
        sum += quote[letters];
    }
    return sum;
}
