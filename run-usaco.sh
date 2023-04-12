#!/bin/bash

clear
g++ -std=c++20 -DLOCAL -Wall usaco.cpp -o out &&
time ./out &&
rm -f out
