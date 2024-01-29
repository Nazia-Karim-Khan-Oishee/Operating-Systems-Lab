#!/bin/bash



directory_path=~/Desktop/Lab07



mkdir -p "$directory_path/last_7_days" 

mkdir -p "$directory_path/last_30_days" 

mkdir -p "$directory_path/last_40_days"



for file in $(find "$directory_path" -type f -mtime -7); do

mv "$file" "$downloads_directory_path/last_7_days"

done





for file in $(find "$directory_path" -type f -mtime +7 -a -mtime -30); do

mv "$file" "$downloads_directory_path/last_30_days"

done





for file in $(find "$directory_path" -type f -mtime +30 -a -mtime -40 ); do

mv "$file" "$downloads_directory_path/last_40_days"

done



