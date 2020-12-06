#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int count_letters (string quote);
int count_words (string quote);
int count_sentences (string quote);
float average_letters (int total_letters, int total_words);

int main(void)
{
    string quote = get_string("Text: ");

    int letters = count_letters(quote);
    int words = count_words(quote);
    int sentences = count_sentences(quote);
    float L = average_letters(count_letters(quote), count_words(quote));
    float S = average_letters(count_sentences(quote), count_words(quote));
    float grade =  0.0588 * L - 0.296 * S - 15.8;

    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf ("Grade: %.0f \n", grade);
    }

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

int count_words (string quote)
{
    int sum = 0;
    for (int i = 0; i < strlen(quote); i++)
    {
        char currentchar = quote[i];
        bool isword = (isspace(currentchar));

        if(isword)
        {
            sum ++;
        }
    }
    return sum + 1;
}

int count_sentences (string quote)
{
    int sum = 0;
    for (int i = 0; i < strlen(quote); i++)
    {
        char currentchar = quote[i];
        bool issentence = (currentchar == '.' || currentchar == '!' || currentchar == '?');

        if(issentence)
        {
            sum ++;
        }
    }
    return sum;
}

//average number of letters per 100 words
float average_letters (int total_letters, int total_words)
{
  float average = ((float)total_letters / (float)total_words)*100;
  return average;
}

//average number of sentences per 100 words
float average_sentences (int total_sentences, int total_words)
{
  float average = ((float)total_sentences / (float)total_words)*100;
  return average;
}
