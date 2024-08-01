#include <cs50.h>   // load the library to "get_string"  from cs50 library file
#include <stdio.h>  // load the library for fucntion (printf) Studio.h contains all the function (header file)

//  first function to print 'hello'
int main(void)
{
    printf("hello, world");
}


// declare a string variabe "answer" and use it in string format to printf the following sentance.
int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}

//  format code: 
// %c
// %f
// %i  => integer
// %li
// %s => string

// Conditional
if (x<y)
{
    printf("x is less than y\n");
}
else if (x>y)
{
    printf("x is greater than y\n");
}
else if (x == Y)
{
    printf('x is equal to y \n');
}

// declaring variable needs to specify data type

// declare a counter variable and add 1
int counter = 0;
counter = coutner + 1;
counter += 1;
counter ++   // another way to increment the variable by 1.
counter -- // decrease counter of 1