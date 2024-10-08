#include <stdio.h>

void swap(int a, int b)

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is: %i, y is: %i\n", x, y);
    swap(x, y);
    printf("x is: %i, y is: %i\n", x, y); // result here will not change, passing the function wil make a copy of x and y
                                          // and will swap the copy, all those data are locked in the scope of the function and will 
                                          // be discarded when the function return 
}

// swap function stored value into temporary before reasigning a.
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;

}

// below the correct way to define and call swap so it affects the actual x and y values 
// using their adress to edit their memory instead of copy


#include <stdio.h>
void swap(int *a, int *b)

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is: %i, y is: %i\n", x, y);
    swap(&x, &y);  // Ici, il faut passer les adresses de x et y et non plus les variables directement.
    printf("x is: %i, y is: %i\n", x, y); 
}

// la fonction swap affecte directement les valeurs de x et y  dans leur zone de mémoire en utilisant leurs adresses comme arguments.
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

