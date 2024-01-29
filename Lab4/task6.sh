#!/bin/bash

read -p "Enter directory path: " directory_path

if [ ! -d "$directory_path" ]; 
then
echo "Error: The provided path is not a valid directory path."
exit 1
fi

insecure_permissions=("rwxrwxrwx" "---rwxrwx" "r--rwxrwx")

i=0

for file in $(find "$directory_path" -type f); 
do

permissions=$(ls -la "$file" | awk '{print $1}')
for pattern in "${insecure_permissions[@]}"; 
do

if [[ "$permissions" == *"$pattern"* ]]; 
then
echo "$file has ($permissions) permission which is insecure."
i=$((i+1))
break
fi

done

done

if [[ "$i" == 0 ]]; then
    echo "This directory has no file with insecure permissions."
fi

