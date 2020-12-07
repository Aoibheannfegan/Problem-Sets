#include <stdio.h>
#include <cs50.h>

float average (int length, int results[]);
int main(void)

{
    int number_of_scores = get_int("Number of scores: ");

    int scores[number_of_scores];

    for (int answers = 0; answers < number_of_scores; answers++)
    {
        scores[number_of_scores] = get_int("Score %i:", answers+1);
    }

    printf("Average: %.1f\n", average (number_of_scores, scores));
}

float average (int length, int results[])
{
    int total = 0;
    for (int values = 0; values < length; values++)
    {
        total += results[values];
    }
    return total / length;
}
