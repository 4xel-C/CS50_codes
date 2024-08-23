#include <stdio.h>
#include <string.h>

int main(void)
{
    int string_length(string s)
     {
        int n = 0;
        while(s[n] != '\0') // Valeur que l'on trouve après le derniere caratère de n'importe quelle string
        {
            n++;
        }

        return n;
     }
}

// possiblity to declare variable inside a for loop: 

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i])
    }
} 


// transformation lowercase en uppercase en se basant sur la relation entre les mlinuscules et les majuscules de la table ASCII.

int main(void)
{
    string s= get_string("Input: ");
    printf("Outpout: ");

    for (int i = 0, N = strlen(s); i < N; i++)
    {
        // if lowercase
        if s[i] >= 'a' && s[i] <= 'z'
        {
            printf("%c", s[i] - 32)  // dans la table ASCII, la relation entre les lettres majuscules et minuscules est 32.
        }
    }
}