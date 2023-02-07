#!/bin/bash
# link

# Done: 
# Undone: 
clear
g++ -DDEBUG=false -Wall "$1" -o out
if [ -f "${1%'.cpp'}.txt" ]; then
    ./out < "${1%'.cpp'}.txt"
else
    ./out
fi
rm -f out
