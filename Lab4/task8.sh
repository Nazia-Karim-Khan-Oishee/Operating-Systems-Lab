#!/bin/bash

read -p "Enter the directory path: " dir_name

if [ ! -d "$dir_name" ]; 
then
echo "Source directory '$dir_name' not found."
exit 1
fi

large_file="/home/nazia/Desktop/CSE4502/Lab03/Large_Files"

if [ ! -e "$large_file" ]; then
    mkdir "$large_file"
fi



read -p "Enter the minimum size of a file in bytes: " min_size

if [ -z "$min_size" ] || [ "$min_size" -le 0 ]; 
then
echo "Error: Provide a valid minimum size greater than 0."
exit 1
fi
i=0

for file in $(find "$dir_name" -type f); 
do
file_size=$(wc -c < "$file")

if [ "$file_size" -gt "$min_size" ]; 
then
i=$((i + 1))
mv "$file" "$large_file/$(basename "$file")"
echo "Moved '$file' to '$large_file/'."
fi

done

if [[ "$i" == 0 ]]; 
then
echo "No files more than $min_size"
fi

