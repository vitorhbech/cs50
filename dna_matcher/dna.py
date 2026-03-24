import csv
import sys


def main():

    if len(sys.argv) != 3:
        print('Missing command-line argument')
        sys.exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1], newline="", encoding='utf-8') as archive_database:
        reader = csv.DictReader(archive_database)
        database = list(reader)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], encoding='utf-8') as archive_sequence:
        dna_sequence = archive_sequence.read()

    #Find longest match of each STR in DNA sequence
    # create a list containing all csv columns
    str_database = {"name": "name"}
    for i in reader.fieldnames:
        if i != "name":
            str_database[i] = longest_match(dna_sequence, i)

    # Check database for matching profiles

    for person in database:
        # convert dict strings in database to int to be able to compare them
        person_dna = {k: int(v) for k, v in person.items() if k != "name"}

        # Check match
        if person_dna == {k: v for k, v in str_database.items() if k != "name"}:
            print(person["name"])
            break
    else:
        print("No Match")

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

    # After checking for runs at each character in sequence, return longest run found
    return longest_run

if __name__ == "__main__":
    main()
