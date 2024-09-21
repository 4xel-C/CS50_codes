# Quiz pKa in Chemistry

#### Video Demo: <URL>
#### Description

This project is a simple Python quiz that makes use of terminal prompts to answer 20 questions about pKa values.

What is a pKa? A pKa is a chemical indicator, usually a number between -10 and 40, used to measure the "acidity" of a molecule. The smaller the pKa value, the more acidic the molecule is.

It's an important parameter to consider in organic synthesis, helping chemists determine which reagent to use for their reactions and predict interactions between molecules.

To aid in learning these different pKa values, I’ve implemented a Python quiz to gamify the learning process.

## Project Description

When starting the script, the user will see a short explanatory text on how to answer the questions, followed by a prompt asking for their name.

The user must then choose from 3 difficulty levels:

- **Level 1**: For each of the 20 questions, the script will propose 4 possible answers. The user can select the answer by using numbers 1 to 4 on their keyboard.
- **Level 2**: For each of the 20 questions, the user must directly input the answer as a number. The "tolerance" for level 2 is 2.
- **Level 3**: Same as level 2, but the tolerance is reduced to 0.5.

For each question, if the answer is incorrect or not exactly right, the script will show the correct answer to help with memorization. For a correct answer within the tolerance window, the user will score 1 point.

At the end of the quiz, the user will receive their total points and be prompted to save or not save their score. The script will also display the user’s mean score for the difficulty level they played on and show a leaderboard of the best scores.

## Code and Implementation

The project contains two files:

- **pka.py**:
    - Contains a dictionary with various chemical molecules as keys and their corresponding pKa values as the values. This dictionary is used in the main file to generate questions and check user answers.
    - The file also contains a `Scoreboard` class. This class is used to interact with a CSV file to record all attempts and scores if the user chooses to save their score.
        - The CSV contains 4 columns: the date (as a `datetime` object), the player’s name, their score, and the level on which they played.
    - The instantiation of the class takes one argument: the name (path) of the CSV file to read or create if it doesn’t exist (defaulting to `scores.csv`).
    - The class contains two class parameters: 
        - `fieldnames`: which contains the header for the CSV file, and 
        - `today`: which contains the current date.
    - The class has three methods:
        - `get_data()`: Returns a list of dictionaries to read the data from the file using `csv.DictReader`.
        - `write_score()`: Appends a new line to the CSV to save the user’s score after completing the quiz if they choose to save it.
        - `get_mean_score()`: Returns the mean score for a user at a specific quiz level.

- **project.py**:
    - The script starts by instantiating the leaderboard, connecting to the CSV file.
    - It then prompts the user for their name and uses the `introduction()` function to display the rules and the quiz.
    - The `select_difficulty()` function is called, prompting the user to select a difficulty level (1-3) and saving the value into the `level` variable.
    - Two variables are assigned: 
        - `counter`: to count the number of rounds (up to 20), and 
        - `score`: to keep track of the score.
    - Depending on the selected level, one of two functions will be called 20 times in a loop to display the questions:
        - `answer_quiz_lvl_1()`: Prompts a question with 4 possible solutions and analyzes the user’s response.
        - `answer_quiz()`: Takes the level as a parameter, prompts the user with questions, analyzes the result, and depending on the difficulty, accepts a margin of error.
    - Both functions use the `random` module to select a chemical and a value from the pKa dictionary. The `answer_quiz_lvl_1()` function also selects 3 other possible values, and the `shuffle()` method is called to mix the possibilities with the correct answer. Both functions include input validation and loops to re-prompt the user if the input is incorrect.
    - At the end of the 20 questions, the code prompts the user to save their score with the `want_save()` function, which uses the leaderboard object and `Scoreboard` methods to write the score into the CSV file.
    - The mean score is retrieved from the leaderboard object and displayed. Finally, the `get_scores()` function is called to display the top 20 scores from the file, using the `str.center()` method to format the table for display in the terminal.
    - The user is then prompted to play again, and if they choose to do so, the main function is called again.

- **test_project.csv**:
    - Contains all the code to test the functions implemented in `project.py`. I use `mock` from the `unittest` library and its decorators to control the randomness of the functions and simulate user input, allowing me to capture the `print` statements and return values of my code.

## How to Run

1. Clone the repository.
2. Run `project.py` in your terminal.
3. Follow the prompts and enjoy the quiz!




