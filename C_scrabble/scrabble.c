// Small script to calculate the scrabble value of a given word

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");
    int score1 = 0;
    int score2 = 0;

    // storing all the letters value in the alphabetical order to retrieve the score of each letters
    // from their ASCII value minus 65 to get the correct index.
    int value[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                     1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // converting each inpout to uppercase to compare them

    // calculate score1 by converting each char into upppercase
    for (int i = 0, n = strlen(word1); i < n; i++)
    {
        // check if the word is a letter
        if ((word1[i] > 64 && word1[i] < 91) || (word1[i] > 96 && word1[i] < 123))
        {
            int index = toupper(word1[i]) - 65;
            score1 += value[index];
        }
    }

    // calculate score2
    for (int i = 0, n = strlen(word2); i < n; i++)
    {
        // check if the word is a letter
        if ((word2[i] > 64 && word2[i] < 91) || (word2[i] > 96 && word2[i] < 123))
        {
            int index = toupper(word2[i]) - 65;
            score2 += value[index];
        }
    }

    // print result
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!\n");
    }
}
