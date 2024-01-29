#!/bin/bash



read -p "Enter the directpry path: " directory

read -p "Enter the search string: " search_string

read  replacement_string


if [ ! -d "$directory" ]; then

echo "Directory not found."

exit 1

fi

for file in $(find "$directory" -type f -name "*.txt"); do

sed -i "s/$search_string/$replacement_string/g" "$file"

echo "Search string replaced"

done

