#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // le code suivant permet de tester que la copie de s avec t copie les adresses où les strings sont enregistrés. Lorsque l'on modifie ainsi 1 variable, l'autre est aussi modifiée.
    
    string s = "hi !";
    string t = s;

    t[0] = toupper(t[0]);

    printf("%s\n", s);
    printf("%s\n", t);
}



// le code ci dessous permettra de creer un duplicat de l'une des variables et d'allouer sa valeur à un autre espace mémoire.

int main(void)
{
    char *s = "hi!";
    if (s == NULL)
    {
        return 1; // error checking
    }

    char *t = malloc(strlen(s) + 1); // malloc (memory allocation) permet de reserver un certain nombres de bytes dans la mémoire (ici le nombre de byte correspondant a la longueur de la string que l'on veut copier + 1 pour \0)
    if (t == NULL)
    {
        return 1;  // error checking
    }

// dans la boucle, i va jusqu'à la dernière valeur de la strlen(s) pour récupérer la valeur stop: \0

strcpy(t, s);  //permet de copier s dans la mémoire à l'adresse t.

if (strlen(t) > 0)
{
    t[0] = toupper(t[0]):
}

printf("%s\n", s);
printf("%s\n", t);

free(t)  // permet de libérer la mémoire allouée pour t pour éviter les fuites de mémoire.
return 0 // permet de retourner la valeur cachée de '0' pour le programme, signifant la bonne exécution de ce dernier. 

}