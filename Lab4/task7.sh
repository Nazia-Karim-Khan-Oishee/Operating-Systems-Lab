#!/bin/bash

read -p "Enter the directory path: " dir_name
if [ ! -d "$dir_name" ]; 
then
echo "Source directory $dir_name not found."
exit 1
fi

extension_file="extensions.txt"


while read -r extension; 
do

sub_dir="$dir_name"/"$extension"

if [ ! -e "$sub_dir" ];
then
mkdir "$sub_dir"
fi

for file in $(find "$dir_name"/*"$extension" -type f); 
do
mv "$file" "$sub_dir"
echo "Moved $file to $sub_dir"
done
    
done < "$extension_file"


