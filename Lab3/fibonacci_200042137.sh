#!/bin/bash

if [ $# -eq 0 ]; then
echo "Please provide the correct input in the below 
format.
Usage: ./fibonacci_210032401.sh number"
exit
fi

n=$1

if [ $n -lt 1 ]; then
echo "Input should be greater than or equal 1"
exit
fi

echo "The first 5 digits of the Fibonacci series are:"

a=1
b=1
echo "$a"

for (( i=1; i<n; i++ ));
do
echo "$b"
c=$(( b + a ))
a=$b
b=$c
done
