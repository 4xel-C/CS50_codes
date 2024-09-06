// C program to check up the correctness of a credit card

#include <cs50.h>
#include <stdio.h>

int count_length(long num)
{
    int count = 0;

    if (num == 0)
    {
        return 1;
    }

    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int main(void)
{

    // prompt user for credit card number
    long card = get_long("Card number:\n");
    long number = card;
    int length = count_length(card);
    int sum = 0;

    // count_length of the number

    if ((length != 15) && (length != 16) && (length != 13))
    {
        printf("INVALID\n");
        return 0;
    }
    // get the first numbers (each 2 numbers starting for last)
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
        if ((number % 10) * 2 > 9)
        {
            sum += ((number % 10) * 2) % 10;
            sum += ((number % 10) * 2) / 10;
        }
        else
        {
            sum += ((number % 10) * 2);
        }
        number /= 10;
    }

    if ((length == 15) && ((card / 10000000000000 == 34) || (card / 10000000000000 == 37)) &&
        sum % 10 == 0)
    {
        printf("AMEX\n");
    }
    else if ((length == 16) && ((card / 100000000000000 > 50) && (card / 100000000000000 < 56)) &&
             sum % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13) && (card / 1000000000000 == 4) && sum % 10 == 0)
    {
        printf("VISA\n");
    }

    else if ((length == 16) && (card / 1000000000000000 == 4) && sum % 10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
