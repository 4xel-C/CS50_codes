#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // creer une nouvelle structure de données nommée "person", avec chaque élément contenant un nom et un numéro.
    typedef struct
    {
        string name;    // Valeurs constituant 1 élément de la structure créée
        string number;   
    }
    person;  // Nom de la strucutre de donnée

    person people[3]; // creer la variable people dont la structure est "person"

    people[0].name = "Carter"; // creer une instance de person en index 0 et ajoute le nom Carter.
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[3].number = "+1-949-468-2750";
    
    string name = get_string("Name: ");
    for (i = 0,; i < 3; i++)
    {
        if (strcomp(people[i].name, name) == 0 )
        {
            printf("Found: %s\n", people[i].number);
            return 0;
        }
    }
    return 1
}
