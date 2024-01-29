#!/bin/bash

if [ $# -ne 2 ]; then
echo "Input should be names of two directories."
exit 1
fi

dir1="$1"
dir2="$2"

if [ ! -d "$dir1" ] || [ ! -d "$dir2" ]; 
then
echo "Error: Directories not found."
exit 1
fi

for file in $(find "$dir1" -type f); 
do
filename="$(basename "$file")"
if [ ! -e "$dir2/$filename" ]; 
then
echo "$filename present in $dir1 but not in $dir2"
fi
done

