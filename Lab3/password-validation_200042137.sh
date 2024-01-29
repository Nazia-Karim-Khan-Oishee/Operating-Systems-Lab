#!/bin/bash

if [ $# -eq 0 ];then
echo "Please provide the correct input in the below 
format.Usage: ./password-validation_210032401.sh password"
exit
fi

pass=$1

if [ ${#pass} -lt 8 ]; then
echo "Weak Password -> Password length should have at least 8 characters."
exit
fi

if ! [[ "$pass" =~ [0-9] ]]; then
echo "Weak Password -> Should use a number"
exit
fi

if ! [[ "$pass" =~ [A-Z] ]]; then
echo "Weak Password -> Should include an upper-case letter"
exit
fi

if ! [[ "$pass" =~ [a-z] ]]; then
echo "Weak Password -> Should include a lower-case letter"
exit
fi

echo "Strong Password."
