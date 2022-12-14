#!/bin/bash

# https://codeforces.com/contest/1758

clear
# Done: abc
# Undone: cdef
g++ -Wall   c.cpp -o out
./out <     c.txt
rm -f out