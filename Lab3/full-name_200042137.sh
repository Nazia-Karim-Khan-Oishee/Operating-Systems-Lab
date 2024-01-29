#!/bin/bash

echo "First Name:"
read first_name

if [ "$first_name" == "" ]; then
echo "Please provide a valid string"
exit
fi

echo "Middle Name:"
read middle_name

if [ "$middle_name" == "" ]; then
echo "Please provide a valid string"
exit
fi

echo "Last Name:"
read last_name

if [ "$last_name" == "" ]; then
echo "Please provide a valid string"
exit
fi

echo "Hi $last_name, do you want me to display your full 
name? [y|n]"

read option
option=$(echo "$option" | tr '[:upper:]' '[:lower:]')

if [[ "$option" == "y" ]]; then
echo "Your Full Name is $first_name $middle_name $last_name "
elif [[ "$option" == "n" ]]; then
echo "Thank you, $last_name, for your time."
else 
echo "Invalid option. Type either y or n"
fi
