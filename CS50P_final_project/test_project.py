import pytest 
from unittest import mock
import sys

from project import  want_save, want_play_again, answer_quizz_lvl_1, answer_quizz, select_difficulty

# checking select_difficulty
@mock.patch('builtins.input', side_effect=['1'])
def test_select_difficulty_1(mock_input):
    assert select_difficulty() == 1

@mock.patch('builtins.input', side_effect=['2'])
def test_select_difficulty_2(mock_input):
    assert select_difficulty() == 2

@mock.patch('builtins.input', side_effect=['3'])
def test_select_difficulty_3(mock_input):
    assert select_difficulty() == 3

@mock.patch('builtins.input', side_effect=['6', "wrong", '1'])
def test_select_difficulty_error(mock_input, capsys):
    result = select_difficulty()
    captured = capsys.readouterr()
    assert "!! Incorrect input !!" in captured.out
    assert result == 1

@mock.patch('builtins.input', side_effect=['6', "wrong", "quit"])
def test_select_difficulty_exit(mock_input):
    with pytest.raises(SystemExit) as exc_info:
        sys.exit()
    assert exc_info.type is SystemExit


# Checking answer_quizz_lvl_1
@mock.patch('builtins.input', side_effect=['4'])
@mock.patch('random.choice', return_value="HCl")
@mock.patch('random.sample', return_value=[14, 9, 12])
@mock.patch('random.shuffle')
def test_answer_quizz_lvl_1_correct(mock_shuffle, mock_sample, mock_choice, mock_input, capsys):
    result = answer_quizz_lvl_1()
    captured = capsys.readouterr()
    
    assert "What is the pka of HCl?" in captured.out
    assert "4) 0" in captured.out  
    assert result == 1  

@mock.patch('builtins.input', side_effect=['quit'])
def test_answer_quizz_lvl_1_exit(mock_input):
    with pytest.raises(SystemExit) as exc_info:
        sys.exit()
    assert exc_info.type is SystemExit


# Checking answer_quizz
@mock.patch('builtins.input', side_effect=['0'])
@mock.patch('random.choice', return_value="HCl")
def test_answer_quizz_right_answer(mock_choice, mock_input, capsys):
    result = answer_quizz(3)
    captured = capsys.readouterr()
    assert "Exact answer ! Correct !" in captured.out
    assert result == 1  

@mock.patch('builtins.input', side_effect=['3'])
@mock.patch('random.choice', return_value="HCl")
def test_answer_quizz_wrong_answer(mock_choice, mock_input, capsys):
    result = answer_quizz(3)
    captured = capsys.readouterr()
    assert "Incorrect! Correct answer was: 0" in captured.out
    assert result == 0 

@mock.patch('builtins.input', side_effect=['2'])
@mock.patch('random.choice', return_value="HCl")
def test_answer_quizz_tolerance(mock_choice, mock_input, capsys):
    result = answer_quizz(2)
    captured = capsys.readouterr()
    assert "Correct! The exact answer was: 0" in captured.out
    assert result == 1 

# Checking want_save
@mock.patch('builtins.input', side_effect=['y'])
def test_want_save_yes(mock_input):
    assert want_save() == True  # noqa: E712

@mock.patch('builtins.input', side_effect=['no'])
def test_want_save_no(mock_input):
    assert want_save() == False  # noqa: E712

# Checking want_play_again
@mock.patch('builtins.input', side_effect=['no'])
def test_want_play_again_no(mock_input):
    assert want_play_again() == False  # noqa: E712

@mock.patch('builtins.input', side_effect=['yes'])
def test_want_play_again_yes(mock_input):
    assert want_play_again() == True  # noqa: E712
