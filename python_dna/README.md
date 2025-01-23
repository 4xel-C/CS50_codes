# DNA Sequence Matcher

This Python script matches a given DNA sequence against a database of DNA STR signatures to determine a person's identity based on their DNA. The program takes two command-line arguments:

1. The path to a CSV file containing the DNA STR signature database for a list of people (Short Tandem Repeat).
2. The path to a text file containing the DNA sequence to analyze.

## Concepts

* **DNA STR (Short Tandem Repeat)**: A region of a DNA molecule that contains a short sequence of base pairs repeated multiple times.
* **Longest Match**: The script searches for the longest consecutive repeat of each STR in the given DNA sequence.

## Requirements

- Python 3.x
- `csv` module (included in Python standard library)

## Usage

Run the script from the command line as follows:

```bash
python dna.py <database.csv> <sequence.txt>
```
Where:

* `<database.csv>` is the CSV file containing the DNA STR signatures.
* `<sequence.txt>` is the text file containing the DNA sequence to analyze.

### Example

```bash
python dna.py database.csv sequence.txt
```

## Code Explanation

### Functions

* `main()`: This is the main function that handles command-line arguments, reads the database and DNA sequence, and checks for matching profiles in the database.
* `longest_match(sequence, subsequence)`: This function returns the length of the longest consecutive run of a given subsequence in a sequence of DNA.

### Flow

1. **Command-Line Arguments**: The script first checks for the correct number of command-line arguments.
2. **Read Database**: It then reads the database of DNA STR signatures from the provided CSV file.
3. **Read DNA Sequence**: The DNA sequence to analyze is read from the provided text file.
4. **Match STRs**: The script calculates the longest run of each STR in the DNA sequence.
5. **Compare**: It compares the STR counts with each entry in the database and prints the name of the person with the matching STR counts. If no match is found, it prints "No match."
