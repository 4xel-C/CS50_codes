#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check numbers of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar  key (positive integer)\n");
        return 1;
    }

    // check if digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./caesar  key (positive integer)");
            return 1;
        }
    }

    // convert the argument  into an integer
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Usage: ./caesar  key (positive integer)");
        return 1;
    }

    // ask for the text to encrypt
    string text = get_string("plaintext:  ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // lowercase letters
        if (text[i] > 96 && text[i] < 123)
        {
            text[i] = ((text[i] - 97 + key) % 26) + 97;
        }

        // uppercase letters
        else if (text[i] > 64 && text[i] < 91)
        {
            text[i] = ((text[i] - 65 + key) % 26) + 65;
        }
    }

    //  display encrypted text

    printf("ciphertext: %s\n", text);
    return 0;
}
