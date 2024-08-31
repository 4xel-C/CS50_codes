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
 
        n->number = 4
        n->next = 0x09830498324


        //  PREPENDING A NODE TO THE LIST
        n->number = number; // attribution de la valeur stocker dans number dans le node créé
        n->next = list; // *n.next pointe dans le même node que le pointeur list
        list = n; // le pointeur list pointe le même node que n, soit le node creer.
        // Le node est ainsi insérer devant les autres nodes
    



        //APPENDING A NODE TO THE LIST
        // Checking if there are any nodes on the list
        if (list == NULL)
        {
            list = n; // connect list to the node (first node)
        }
        // If list has numbers alreadu
        else
        {
            // iteration on the node on the list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) // Commence au début de la liste en établissant ptr (pointeur à list) et à chaque node,
            {                                                    // actualise la valeur du pointeur avec la valeur next du node
                // at the end of the list
                if ptr = NULL
                {
                    // append node
                    ptr->next = n; // Actualise la valeur NULL du dernier node.next avec l'adresse du nouveau node.
                    break;
                }
            }
        }


        //Appending a node to an Ordered list
        //if list is empty (first node)
        if (list == NULL)
        {
            list = n;
        }

        //if number belongs at beginning of the list
        else if (n->number<list->number)
        {
            n->next = list;
            list = n;
        }
        //if number belongs later in the list
        else
        {
            //iterate over nodes in the list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at the end of the list
                if (ptr->next == NULL)
                {
                    // append node
                    ptr->next = n;
                    break;
                }
                //if in the middle of the list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;    // insert the node between the ptr->current node and the next node
                    ptr->next = n;
                    break;

                }
            }
        }
    

    }




    // print whole list
// stocker la valeur du pointeur list dans ptr (pointeur)
    node *ptr = list
    while (ptr != NULL) // tant que ptr ne pointe pas NULL (valeur du pointeur next du dernier node)
    {
        printf("%i\n"ptr->number); // print le nombre du node pointer par le pointeur
        ptr = ptr->next  // change la valeur du pointeur ptr, par la valeur du pointeur next du node

    }
    
}

