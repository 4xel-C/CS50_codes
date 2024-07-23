#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("Size: ");
    while (n < 1)
    {
        n = get_int("Size: ");
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
    }
}

//  posibility to write a better code by avoiding repeating some lines.

int main(void)
{
    int n; // declaring thte variable int n
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);   // permet de boucler le code block "do" tant que n n'est pas positif 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
    }
}