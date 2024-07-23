// Code to include argument in command prompt to interact with the code

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // check if argument number == 2 (file name + argument)
    if (argc == 2) 
    {
        printf("Hello: %s", argv[1]);  // permet d'accéder à l'argument après le nom du fichier.
    }
    else
    {
        printf("Hello, world\n");
    }
}
