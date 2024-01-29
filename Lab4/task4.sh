#!/bin/bash

read -p "Enter the directory name: " main_directory


if [ -d "$main_directory" ]; 
then
echo "Directory '$main_directory' already exists."
else
mkdir "$main_directory"
fi

cd "$main_directory"

while true; 
do
read -p "Enter a subdirectory name (Press Enter to finish): " sub_directory_name

if [ -z "$sub_directory_name" ]; 
then
echo "Directory structure created successfully!"
break
fi

if [ -d "$sub_directory_name" ]; 
then
echo "Subdirectory '$sub_directory_name' already exists."
else
mkdir "$sub_directory_name"
fi

cd "$sub_directory_name"

while true; 
do

read -p "Enter a file name (Press Enter to finish): " file_name

if [ -z "$file_name" ]; 
then
break
fi

if [ -f "$file_name" ]; 
then
echo "File '$file_name' already exists."
else
touch "$file_name"
fi

done
cd ..
done

echo "Directory structure created successfully."
