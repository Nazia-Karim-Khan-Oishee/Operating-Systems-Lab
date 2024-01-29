#!/bin/bash

cons=""
vowels=""

input=$1

if [ ${#input} -eq 0 ]; then
echo "Please provide a string.
Usage: ./separate_vowls_consonant.sh <string>. <string> should not contain any space"
exit
fi


for ((i=0;i<${#input};i++)); 
do
char="${input:i:1}"
if [[ "$char" =~ [aeiouAEIOU] ]]; then
vowels="$vowels$char"
else
cons="$cons$char"
fi
done

echo "Vowels: $vowels"
echo "Consonants: $cons"

