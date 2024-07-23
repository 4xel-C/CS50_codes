#include <cs50.h>
#include <stdio.h>

void draw(int n);  // prototype to tell the program the function exist in the code

int main(void)
{
    int height = get_height("Height: ");
    draw(height);
}

void draw(int n)   // definiton de la fonction qui dessine des pyramides. Retourne void car ne retourne aucune valeur.
{
    // if nothing to draw, return
    if (n <= 0)
    {
        return;
    }
    draw(n-1);

    for (i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}