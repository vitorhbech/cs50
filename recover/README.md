# Recover — JPEG Recovery

Program that recovers JPEG images from a raw forensic memory card dump.

This project was developed as part of Harvard's CS50: Introduction to Computer Science course. The program scans blocks of memory looking for JPEG file signatures and reconstructs images that were previously stored on the card.

# How It Works

The program reads the memory card image in blocks of 512 bytes and checks for JPEG header signatures. When a new JPEG is detected, the program creates a new file and continues writing data until the next JPEG header appears.

# Concepts Practiced

- file I/O in C
- binary data processing
- memory block scanning
- digital forensics fundamentals