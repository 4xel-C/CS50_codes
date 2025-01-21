# Speller

This C program implements a spell checker that loads a dictionary, checks the spelling of words from a given text file, and reports any misspelled words. It also measures and reports the time taken for various operations such as loading the dictionary, checking words, determining the dictionary size, and unloading the dictionary.

## Requirements

- **C Compiler**: GCC (GNU Compiler Collection)
- **CS50 Library**: This program requires the CS50 library for the `load`, `check`, and `unload` functions. Follow the instructions to install the CS50 library: [CS50 Library Installation](https://cs50.harvard.edu/x/2021/psets/1/pset1/#getting-started).
- **Dictionary File**: The program uses a dictionary file, which should be placed in the `dictionaries/large` folder or specified as a command-line argument.

## How It Works

1. The program takes in a dictionary file and a text file containing words to check.
2. It loads the dictionary and checks each word in the text file for spelling errors.
3. The program prints out any misspelled words and provides timing benchmarks for operations like loading the dictionary, checking words, and unloading the dictionary.

## How to Run

1. Install the CS50 library (if you haven't already).
2. Compile the code:
    ```bash
    gcc speller.c -o speller -lcs50
    ```

3. Run the program:
    ```bash
    ./speller [DICTIONARY] text
    ```

   - Replace `[DICTIONARY]` with the path to the dictionary file you want to use (optional, defaults to `dictionaries/large`).
   - Replace `text` with the text file you want to spell check.

### Example:

```bash
./speller dictionaries/large example.txt
