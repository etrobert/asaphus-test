# Asaphus Test

Programming test requested by Asaphus Vision (asaphus.de).

## Requirements

Write a function in C++ that accepts two integers countX and countO and returns a string containing exactly countX times the letter 'X' and exactly countO times the letter 'O', but with no four consecutive letters being the same. That is, "XXXX" and "OOOO" may not occur in the result string.

Examples:
1. Called with countX=2 and countO=3, the function may return "XOOOX". Other correct return strings are possible. The function may return any of those, for example "OXOXO".
2. Called with countX=6 and countO=1, the function must return "XXXOXXX", which is the only correct result in this case.

## How to run

In a UNIX based environment simply run `make && ./asaphus-test` to compile the program and run the tests.
