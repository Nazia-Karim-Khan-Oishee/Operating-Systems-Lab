#!/bin/bash

if [ $# -eq 0 ]; then
echo "Please provide the correct input in the below format."
echo "Usage: ./palindromeeda.sh <string>"
exit 1
fi

input="$1"

reversed=""
len=${#input}

for ((i = len - 1; i >= 0; i--)); do
reversed="${reversed}${input:i:1}"
done

if [ "$input" == "$reversed" ]; then
echo "I am groot!"
else
echo "I am groot!Try again"
fi
    

