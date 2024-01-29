#!/bin/bash

dir="/home/nazia/Desktop/CSE4502/"
dir1="Missing_files"
filenames="required_files.txt"
#filename="task2.sh"

mkdir -p "$dir""Lab03""/""$dir1"



while read -r file;
do
if [ -e "$dir""Lab03/""$file" ];then
echo "$file exists"
else
touch "$dir""Lab03""/""$dir1""/""$file"
echo "$file created"
fi
done < "$filenames"
