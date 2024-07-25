#include <stdio.h>
#include <stlib.h>

// creating chained list / node datatype

typedef struct node  // declaring node datatype
{
    int number;       // will store a number
    struct node *next;     // will store the adress of the next node
} node;

int main(int argc, char *argv[])
{
    node *list = NULL // Initialisation du pointeur list qui pointe 0x0 valeur nulle.

    // taking the numbers from the command prompt
    for i (int i = 1, i < argc, i++)
    {
        int number = atoi(argv[i]); // convertir string into number because argv is an array of string et recupère l'argument prompt dans la variable number

        node *n = malloc(sizeof(node)); // creation du node pointé par n
        if (n == NULL)
        {
            // free memorey thus far
            return 1;
        }
        n->number = number; // attribution de la valeur stocker dans number dans le node créé
        n->next = list; // *n.next pointe dans le même node que le pointeur list
        list = n; // le pointeur list pointe le même node que n, soit le node creer.
        // Le node est ainsi insérer devant les autres nodes
    }

}