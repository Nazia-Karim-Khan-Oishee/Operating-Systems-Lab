#!/bin/bash

read -p "Enter directory path: " directory_path

if [ ! -d "$directory_path" ]; 
then
echo "Error: The provided path is not a valid directory path."
exit 1
fi

total_size_bytes=$(find "$directory_path" -type f -exec wc -c {} \; | awk '{ total += $1 } END { print total }')

suffixes=("B" "KB" "MB" "GB" "TB")
i=0

while ((total_size_bytes > 1024)); 
do
total_size_bytes=$((total_size_bytes / 1024))
i=$((i + 1))
done

echo "Total size of files in '$directory_path': $total_size_bytes ${suffixes[$i]}"

