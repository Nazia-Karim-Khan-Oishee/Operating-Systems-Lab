#!/bin/bash

if [ $# -eq 0 ]; then
echo "Please provide the correct input in the below 
format.
Usage: ./reverse-integer_210032401.sh number"
exit
fi

for i in $*;
do
input_num=$i
output=0

while [ $i -gt 0 ];
do
last_digit=$((i % 10))
echo "$last_digit"
output=$((output * 10 + last_digit))
i=$((i / 10))
done

echo "Reverse of $input_num is $output"

done

