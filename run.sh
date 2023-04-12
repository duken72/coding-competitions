#!/bin/bash

clear
g++ -std=c++20 -DLOCAL -Wall duke.cpp -o out &&
time ./out < input.txt &&
rm -f out
