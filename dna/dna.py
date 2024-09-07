# this code take 2 command line arguments:
    # the path of a csv file containing the database of dna STR signatures of a list of peoples (Short Tandem Repeat)
    # the path of a txt file containing a sequence of dna to analyse in order to determine the identity of the person based on his dna. 


import csv
from sys import argv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Use: dna.py csc_data dsn_sequence")
        return 1

    # TODO: Read database file into a variable
    database = []
    with open(argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(argv[2]) as file:
        dna = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # iterate through all the STR
    str_count = {}
    for str in database[0]:
        if str == "name":
            continue
        # create the dictionnary key and update the value by the longest run
        str_count[str] = longest_match(dna, str)

    # TODO: Check database for matching profiles
    for row in database:
        # match switch to False if any of the str dosn't match
        match = True
        for str in str_count:
            # if an occurence dosn't match, update match to false  and breack the loop
            if int(row[str]) != str_count[str]:
                match = False
                break
        # return the name only if  the previous loop dosn't update match to false.
        if match == True:
            print(row["name"])
            return row["name"]

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
