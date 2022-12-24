#!/bin/bash
# https://codeforces.com/contest/1772

clear
# Done: a, b, c, d
# Undone: e, f, g
g++ -Wall   e.cpp -o out
./out <     e.txt
rm -f out