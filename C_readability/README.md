# Text Readability Score in C

This program calculates the readability score of a given text using the **Coleman-Liau Index**. The score estimates the U.S. grade level appropriate for the text.

## Coleman-Liau index
A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

```index = 0.0588 * L - 0.296 * S - 15.8```

where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

## Requirements

### Tools

- **C Compiler** (e.g., `gcc`)

### Libraries

- **CS50 Library**: This program uses the `cs50.h` library for input handling (specifically `get_string()`).
- **Standard C Libraries**: The program uses `<ctype.h>`, `<stdio.h>`, and `<string.h>` for character manipulation and string operations.

## Installation

1. Install the **CS50 Library** if it's not already installed.

2. Compile the program with:
    ```bash
    gcc -o readability readability.c -lcs50
    ```

3. Run the program using:
    ```bash
    ./readability
    ```

## Usage

1. The program prompts the user to input a block of text.
2. It analyzes the text to count:
   - **Letters**: Alphabetic characters.
   - **Words**: Sequences separated by spaces.
   - **Sentences**: Sequences ending with `.`, `?`, or `!`.
3. It calculates the readability score using the **Coleman-Liau Index**.

### Example

```bash
$ ./readability
Text: Congratulations! Today is your day. You re off to Great Places!
Grade 3
```

