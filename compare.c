
// pre processing line (start before the code, and load the library)
#include <cs50.h>
#include <stdio.h>

int main(void)  // create a main fucntion to give the starting point of the program and run subsequently the rest of the code.
{
    int x = get_int("What is x? ");
    int y = get_int("Waht is y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else
    {
        printf("x is not less than y \n");
    }
}

//  string: double quote character "This is a test"
// Character: single quote character 't'

{
    char c = get_char("Do you aggre? ");

    if (c == 'y' || c == 'Y')  // || represent "or" and && represent 'and'
    {
        printf("Agreed!\n");
    }
}

// loops

int i = 0;  // most conventionnel way to do it is to start counting at 0 to avoid wasting some bits.

while (i < 0)  // while loop
{
    printf('Meow\n');
    i++;
}



for(int i = 0; i < 3; i++ )  // for loop
{
    printf("meow\n");
}

while(True)
{
    printf("meow\n");
}

// functions

void meow(void) // The function meow is declared bellow, but can be declared without details lihe this line if the full declaration come after
                // This is calles a "prototype"
while(True)
{
    meow();  // calling the function meow
}

void meow(void)   // create a function meow that has no return value (first void) and takes no arguments
{
    printf("meow\n");
}

// functions with arguments

void meow(int n);

{
    meow(3000);
}

void meow(int n)  // declare a function with arguments n (integer)
{
    for (int i = 0; i < n; n++)
    {
        printf("meow\n");
    }
}