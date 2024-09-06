// Compute the readability score of a text to estimate the level adapted.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    float letters = 0;
    float words = 1;
    float sentances = 0;

    //    converting text to uppercase for easiest letters detection using ASCII table

    for (int i = 0, l = strlen(text); i < l; i++)
    {
        // uppercase the letter
        text[i] = toupper(text[i]);

        // count letters
        if (text[i] > 64 && text[i] < 91)
        {
            letters++;
        }

        // count words
        else if (text[i] == 32)
        {
            words++;
        }

        // count sentances
        else if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sentances++;
        }
    }

    //    calculate average number of letters:
    float L = (letters / words) * 100;
    // calculate average number of sentances
    float S = (sentances / words) * 100;

    // apply Coleman-Liau index
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    // print the result
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {

        int int_index = index + 0.5;

        printf("Grade %i\n", int_index);
    }
}
