# Caesar Cipher in C

This project implements a simple Caesar cipher encryption program in C, which shifts each letter of a given text by a specified key.

## Requirements

To run this program, the following tools and libraries are required:

### Tools

- **C Compiler** (e.g., `gcc`)

### Libraries

- **CS50 Library**: This program uses the `cs50.h` library for input handling (specifically `get_string()`).

### Installation

1. Install the **CS50 Library** for C if it's not already installed.

2. Compile the code using a C compiler. You can use the following command:
    ```bash
    gcc -o caesar caesar.c -lcs50
    ```

3. Run the program with the following command:
    ```bash
    ./caesar <key>
    ```

   Replace `<key>` with a positive integer that represents the shift value for the Caesar cipher.

## Usage

1. The program accepts exactly one command-line argument (a positive integer `key`) to encrypt the text.
2. If the argument is not provided or is invalid (e.g., a non-digit character or a negative integer), the program will display an error message and exit.
3. The program prompts the user to enter plaintext text, which will then be encrypted using the Caesar cipher.
4. After encryption, the program will output the corresponding ciphertext.

### Example

```bash
$ ./caesar 3
plaintext:  Hello, World!
ciphertext: Khoor, Zruog!
