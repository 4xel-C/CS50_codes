#include <stio.h>
#include <cs50.h>


// linear search of an array
int main(void)
{
    int numbers[] = {0, 32, 35, 84, 100, 56, 50};
    const int N = get_number("Number: ");

// recherche du nombre dans l'array "numbers
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == N)
        {
            printf('Found\n');
            return 0;    // par convention, un programme return 0 lorsqu'il a fonctionné correctement
        }
    }
    printf("Not found\n");
    return 1  // par convention, un programme return 1 si il n'a pas fonctionné
}
