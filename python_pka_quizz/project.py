import random
import sys

from pka import pka, Scoreboard

def main():
    leaderboard = Scoreboard("score.csv")
    name = input("What is your name?")
    introduction(name)
    level = select_difficulty()

    counter = 1
    score = 0

    if level == 1:
        while counter < 21:
            print(f"Question {counter}")
            if answer_quizz_lvl_1():
                score += 1
            counter += 1

    else:
        while counter < 21:
            print(f"Question {counter}")
            if answer_quizz(level):
                score += 1
            counter += 1
    
    print("You scored", score, "points!\n")    

    if want_save():
        leaderboard.write_score(name, score, level)
    
    mean = leaderboard.get_mean_score(name, level)

    print(f"\n Your mean on level {level} is {mean:.2f}\n")

    get_scores(leaderboard)

    if want_play_again():
        main()


def introduction(name: str) -> None:
    print(f"\nWelcome {name} to this chemistry's pka quizz game")
    print("You will be prompted for 20 questions")
    print("Use the numbers on  your keyboard to select options if asked")
    print("To stop the quizz, type 'quit'")
    print("Good luck!")
    input("Press enter to continue\n")

def select_difficulty() -> int: 
    """
    Allow the user to select among 3 difficulty levels. 
    The function return the selected level, used in main to choose the corresponding quizz.
    """
    while True:
        level = input("Select your difficulty\n1.Easy (Answer between 4 choices)\n2.medium (tolerance +/- 2)\n3.expert (tolerance +/- 0.5)\n")
        if level == "quit":
            sys.exit()
        try:
            level = int(level)
        except ValueError:
            print("\n !! Incorrect input !!\n")
            continue

        if int(level) not in [1, 2, 3]:
            print("\n !! Incorrect input !!\n")
            continue

        else:
            return int(level)

def answer_quizz_lvl_1() -> int:
    """
    Prompt the user for a level 1 quizz. 
    If the answer is correct, the function return 1, otherwise it return 0
    """
    # select a random reagent for the question and shuffle 4 answer choices
    reagent = random.choice(list(pka))

    # create a copy of all possible values excluding the answer for random selection
    filtered_values = [value for value in pka.values() if value != pka[reagent]]
    choices = random.sample((filtered_values), 3)
    choices.append(pka[reagent])
    random.shuffle(choices)

    # input the user for the question
    print(f"What is the pka of {reagent}? Choose with 1-4")
    for i in range(len(choices)):
        print(f"{i+1}) {choices[i]}")
    
    # input user and check validity
    while True:
        try:
            answer = input()
            if answer == "quit":
                sys.exit()
            answer = int(answer)
        except ValueError:
            print("\nIncorrect input")
            continue
        if 0 < answer < len(choices)+1:
            break
        else:
            print("Incorrect input")
        
    # check answer
    if choices[answer-1] == pka[reagent]:
        print("Correct !")  
        return 1
    else:
        print(f"Incorrect, the answer was: {pka[reagent]}")
        return 0

def answer_quizz(level: int) -> int:
    """
    Prompt the user for a level 2 or 3 quizz. 
    If the answer is correct, the function return 1, otherwise it return 0
    """
    # select a random reagent for the question and shuffle 4 answer choices
    reagent = random.choice(list(pka))

    # input the user for the question
    while True:
        answer = input(f"What is the pka of {reagent}?\n")
        if answer == "exit":
            sys.exit()
        try:
            answer = float(answer)
            break
        except ValueError:
            print("\nIncorrect input")
            continue
    
    # Check if the answer is valid 
    if answer == pka[reagent]:
        print("Exact answer ! Correct !\n")
        return 1 
    if level == 2 and pka[reagent]-2 <= answer <= pka[reagent]+2:
        print(f"Correct! The exact answer was: {pka[reagent]}\n")
        return 1
    if level == 3 and pka[reagent]-0.5 <= answer <= pka[reagent]+0.5:
        print(f"Correct! The exact answer was: {pka[reagent]}\n")
        return 1
    else:
        print(f"Incorrect! Correct answer was: {pka[reagent]}\n")
        return 0

def want_save() -> bool:
    while True:
        try:
            answer = input("Do you want to save your score? (y/n) ").lower()
            break
        except AttributeError:
            pass
    if answer in ["yes", "y"]:
        return True
    else:
        return False
    
def want_play_again() -> bool:
    while True:
        try:
            answer = input("Play again? (y/n) ").lower()
            break
        except AttributeError:
            pass
    if answer in ["yes", "y"]:
        return True
    else:
        return False

def get_scores(leaderboard) -> None:
    """This fonction give the last 20 scores saved in the file"""
    scores = leaderboard.get_data()

    # sort the scores
    sorted_scores = scores.sort(key=lambda x: (int(x["score"])), reverse=True)
    # get the slive of the last 20 scores:
    sorted_scores = scores[-20:]
    headers = "Ranking".center(10, "-") + "Name".center(15, "-") + "date".center(15, "-") + "Score".center(10, "-") + "level".center(10, "-")
    
    print(headers)
    for i, score in enumerate(sorted_scores):
        line =  f"{i}".center(10) + f"{score["name"]}".center(15) + f"{score["date"]}".center(15) + f"{score["score"]}".center(10) + f"{score["level"]}".center(10)
        print(line)

if __name__ == "__main__":
    main()

           
        