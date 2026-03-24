# DNA Matcher

This project implements a Python program that identifies profiles in a DNA database based on a given DNA sequence.  
It was developed as a logic and data manipulation exercise, making it a solid entry-level portfolio project for software development internships.

##  How it works
- The program takes two input files:
  1. A **CSV file** containing profiles of individuals and their STR (Short Tandem Repeat) counts.
  2. A **text file** containing a DNA sequence.
- It calculates the longest consecutive run of each STR in the DNA sequence.
- It compares the calculated STR counts with the database.
- If a match is found, the program prints the person’s name; otherwise, it prints `"No Match"`.

##  Usage
1. Clone this repository:
   git clone https://github.com/vitorbech/dna-matcher.git
   cd dna-matcher
   
2. Run the program with the database and sequence files as arguments:
    python dna.py database.csv sequence.txt

# Project structure
dna-matcher/
│── dna.py           # Main program
│── database.csv     # Example DNA database
│── sequence.txt     # Example DNA sequence
│── README.md        # Documentation

# Technologies
- Python 3
- csv module for file handling
- Dictionaries and list comprehensions for data manipulation
- command-line arguments

# Learning goals
- This project demonstrates:
- Reading and parsing CSV and TXT files.
- Using dictionaries and comprehensions effectively.
- Implementing logic to analyze DNA sequences.
- Structuring code into reusable functions.

# Example
Given the following database.csv:
    name,AGATC,AATG,TATC
    Alice,4,1,5
    Bob,3,2,8
    Charlie,5,1,2
    
And a sequence.txt containing a DNA string, running:
    python dna.py database.csv sequence.txt

Might output:
    Alice

If no profile matches, the output will be:
    No Match