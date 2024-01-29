#!/bin/bash



read -p "Enter the directory path: " directory



if [ ! -d "$directory" ]; then

    echo "Directory not found."

    exit 1

fi



small_files=0

medium_files=0

large_files=0





declare -a small_file_list

declare -a medium_file_list

declare -a large_file_list





for file in $(find "$directory" -type f); do

size=$(stat -c %s "$file")



if [ "$size" -lt 500 ]; then

small_files=$((small_files + 1))

small_file_list+=("$file")

elif [ "$size" -lt 10000 ]; then

medium_files=$((medium_files + 1))

medium_file_list+=("$file")

else

large_files=$((large_files + 1))

large_file_list+=("$file")

fi

done





echo "Number of Small Files: $small_files"

if [ $small_files -gt 0 ]; then

for file in "${small_file_list[@]}"; do

echo "$file"

done

fi



echo "Number of Medium Files: $medium_files"



if [ $medium_files -gt 0 ]; then

for file in "${medium_file_list[@]}"; do

echo "$file"

done

fi



echo "Number of Large Files: $large_files"

if [ $large_files -gt 0 ]; then

echo "Large Files:"

for file in "${large_file_list[@]}"; do

echo "$file"

done

fi

