#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    int x = get_int("x ");   // the scope of x and y exist only into the context of main(void)
    int y = get_int("y ");

    int z = add();
    printf("%i\n", z);
}

int add(int a, int b)  // int mean the function return an int value
{
    return a + b;
}

// possibilité de rendre le code plus lisible: 

{
    int x = get_int("x ");   // the scope of x and y exist only into the context of main(void)
    int y = get_int("y ");

    printf("%i\n", add(x, y));
}


// la fonction suivante permet de print la division de x par y
int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    float z = (float) x / (float) y   // type casting, conversion of x and y into float
    print("%f\n", z);
}