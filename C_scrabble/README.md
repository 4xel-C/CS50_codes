# Scrabble Score Calculator

This C program calculates the Scrabble score of two given words and determines which player wins based on the score. It prompts both players to input their words, then computes and compares their Scrabble scores.

## How It Works

1. The program takes input from two players (`Player1` and `Player2`).
2. It calculates the score of each player's word based on the Scrabble letter values.
3. The program compares the scores and prints out which player wins, or if there is a tie.

## Requirements

- **C Compiler**: GCC (GNU Compiler Collection)
- **cs50 Library**: This program uses the CS50 library for input handling.

## Scrabble Letter Values

- Letters `A`, `E`, `I`, `O`, `U`, `L`, `N`, `S`, `T`, and `R` are worth 1 point each.
- Letters `D` and `G` are worth 2 points.
- Letters `B`, `C`, `M`, and `P` are worth 3 points.
- Letters `F`, `H`, `V`, `W`, and `Y` are worth 4 points.
- Letters `K` is worth 5 points.
- Letters `J` and `X` are worth 8 points.
- Letters `Q` and `Z` are worth 10 points.

## How to Run

1. Compile the code:
    ```bash
    gcc scrabble.c -o scrabble
    ```

2. Run the program:
    ```bash
    ./scrabble
    ```

3. Enter the words for Player 1 and Player 2 when prompted.

## Example Output
```
Player1: hello 
Player2: world 
Player 1 wins!