#!/bin/bash

echo "Enter a string: "
read input

cons=""

if [ ${#input} -eq 0 ]; then
echo "Please provide a string.
Usage: ./print_consonant_210032401.sh string"
exit
fi

if [[ "$input" =~ [[:space:]] ]]; then
echo "String can not contain any space"
exit
fi

for ((i=0;i<${#input};i++)); 
do
char="${input:i:1}"
if ! [[ "$char" =~ [aeiouAEIOU] ]]; then
cons="$cons$char"
fi
done

echo "$cons"
