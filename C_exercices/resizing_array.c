//  Exemplify resizing array in c

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    // allocation de mémoire pour un array de 3 entiers, return un pointeur
    int *list = malloc(3 * sizeof(int)); 
    // si l'allocation ne fonctionne pas (return NULL) => stop le programme
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;  // Place l'integer 1 à l'adresse indiqué par le pointeur *list
    list[1] = 2;  // Place l'integer 2 à l'adresse indiqué par le pointeur *list + 1 fois la taille d'un int (pour se déplacer dans la mémoire)
    list[2] = 3;

    int *tmp = malloc(4 * sizeof(int));
    if tmp == NULL
    {
        free(list); // freeing the allocated space at the beginning so there is no memory leak.
        return 1;
    // iterating list to copy in temp
    for (i = 0,  i < 3, i++)
    {
        tmp[i] = list[i]; // placing the array into temporary location
    }
    tmp[3] = 4; // increasing the array size by using the last 4 bytes of tmp
    // freeing list to free the memory
    free(list);
    //  Attributing the tmp memory to list, so that both pointers points the same chunk of memory
    list = tmp;
}