#!/bin/bash

# https://codeforces.com/contest/1760

clear
# Done: a, b, c, d, e
# Undone: f, g
g++ -Wall   g.cpp -o out
./out <     g.txt
rm -f out