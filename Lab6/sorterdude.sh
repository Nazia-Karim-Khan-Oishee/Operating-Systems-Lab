#!/bin/bash



if [ $# -eq 0 ]; then

echo "Syntax Error!!"

echo "Syntax: ./sorterdude.sh <number 1> <number 2> <number 3>"

echo "<number_n> <order>"
echo "<unique>"
exit 1

fi


if [ "$1" == "-h" ]; then

echo "./sorterdude.sh sorts a list"

exit 0

fi


numbers="@"

asc_order =$(echo "$numbers"  | sort -n )

asc_order =$(echo "$numbers"  | sort -n -r )




