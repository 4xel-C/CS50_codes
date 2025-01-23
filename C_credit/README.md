# Credit Card Validation in C

This project implements a program to validate the correctness of a credit card number based on its length, the Luhn algorithm, and the card's prefix. It can identify if the card is an American Express (AMEX), MasterCard, or Visa card.

## Requirements

To run this program, the following tools and libraries are required:

### Tools

- **C Compiler** (e.g., `gcc`)

### Libraries

- **CS50 Library**: This program uses the `cs50.h` library for input handling (specifically `get_long()`).

### Installation

1. Install the **CS50 Library** for C if it's not already installed.

2. Compile the code using a C compiler. You can use the following command:
    ```bash
    gcc -o credit_card_validation credit_card_validation.c -lcs50
    ```

3. Run the program with the following command:
    ```bash
    ./credit_card_validation
    ```

4. Enter a credit card number when prompted.

## Usage

1. The program prompts the user for a credit card number.
2. It checks the length of the card number. Valid lengths are 13, 15, or 16 digits.
3. The program uses the Luhn algorithm to validate the card number.
4. Based on the prefix and the length, the program outputs the card type: AMEX, MasterCard, Visa, or INVALID.

### Example

```bash
$ ./credit_card_validation
Card number:
378282246310005
AMEX
```

## Luhn Algorithm

So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

<u>4</u>0<u>0</u>3<u>6</u>0<u>0</u>0<u>0</u>0<u>0</u>0<u>0</u>0<u>1</u>4

Okay, let’s multiply each of the underlined digits by 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Now let’s add those products’ digits (i.e., not the products themselves) together:

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

The last digit in that sum (20) is a 0, so the card is legit!