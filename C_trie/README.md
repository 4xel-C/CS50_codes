# Dog Names Trie

This C program implements a Trie data structure to store popular dog names and check if a given word exists in the trie. The dog names are read from an input file and stored in the trie for efficient look-up. The program allows the user to input a word and check if it exists in the trie.

## Requirements

- **C Compiler**: GCC (GNU Compiler Collection)
- **CS50 Library**: The program uses `get_string` from the CS50 library for reading user input.

## How It Works

1. **Trie Data Structure**: The program creates a trie to store the dog names. Each letter of a name is stored in a separate node, with each node having 26 possible child nodes (one for each letter of the alphabet).
2. **Check Function**: The user can input a word, and the program will check if the word exists in the trie.
3. **Memory Management**: The program ensures that memory is freed after use, by recursively unloading the trie.

### Functions:
- **check(word):** Takes a word as input and checks if it exists in the trie. Returns true if found, false otherwise.
- **unload():** Frees the memory allocated for the trie.
- **unloader(node *current):** Recursively frees the memory of each node in the trie.

## How to Run

1. Install the CS50 library (if you haven't already).
2. Compile the code:
    ```bash
    gcc trie.c -o trie
    ```

3. Run the program:
    ```bash
    ./trie dog_names.txt
    ```

   - Replace `dog_names.txt` with the path to the file containing dog names. Each name should be on a new line.

## Example:

```bash
./trie dog_names.txt
Check word: Max
Found!

Check word: Bruno
Not Found.
```
## File format: 
The input file (e.g., `dog_names.txt`) should contain dog names, each on a separate line:
```
Max
Bella
Charlie
Lucy
Daisy
```