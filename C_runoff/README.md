# Election Simulation: Runoff Voting

This program simulates an election using the runoff voting system. It allows voters to rank candidates and handles multiple rounds of voting until a winner is determined or a tie occurs. It uses a custom data structure to store candidates, votes, and election progress.

## Features
- Supports multiple rounds of voting until a winner emerges.
- Handles ties between candidates by eliminating candidates with the least votes.
- Stores voter preferences and candidate details using a custom data structure.

## Prerequisites
- CS50 library for `get_int()` and `get_string()` functions.
- C compiler (e.g., GCC) to compile the program.

## Usage
1. Clone this repository or copy the code into a `.c` file.
2. Compile the program using:
   ```bash
   gcc -o runoff runoff.c -lcs50
   ```
3. Run the program with the candidate names as command-line arguments:
   ```./runoff candidate1 candidate2 candidate3```
4. The program will prompt for the number of voters and their rankings of the candidates.

## Code Explanation

### Key Concepts

*   **Runoff Voting:**  
    A system where the candidate with the fewest votes is eliminated after each round until a winner is found.
*   **Data Structures:**
    *   `candidate` structure contains `name`, `votes`, and `eliminated` status.
    *   `preferences` 2D array stores voters' preferences for candidates.

### Functions

*   `vote(voter, rank, name)`: Records a voter's preference for a candidate.
*   `tabulate()`: Calculates the votes for each candidate based on the voters' preferences.
*   `print_winner()`: Checks if any candidate has received more than half the votes.
*   `find_min()`: Returns the minimum number of votes any remaining candidate has.
*   `is_tie(min)`: Checks if all remaining candidates have the same number of votes.
*   `eliminate(min)`: Eliminates candidates with the minimum number of votes.

### Flow

1.  **Input**: The program prompts for the number of voters and their ranked choices for candidates.
2.  **Voting Process**: Votes are recorded, and in each round, the votes are tabulated for non-eliminated candidates.
3.  **Elimination**: The candidate with the least votes is eliminated each round. If there's a tie, all non-eliminated candidates win.
4.  **Winning**: If a candidate receives more than half the votes, they are declared the winner.
