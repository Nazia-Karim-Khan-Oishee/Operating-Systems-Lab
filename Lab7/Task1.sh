#!/bin/bash



dir=~/CSE4502_200042137
#declare -A file_extensions
textfile_size=0



for file in $(find "$dir" -type f -name "*.txt"); 
do
if [ -f "$file" ]; then
size=$(stat -c %s "$file")
textfile_size=$(()textfile_size + size )

echo "$file : $size "

#extension="${file##*.}"

        

#if [[ -v file_sizes["$extension"] ]]; then

#file_sizes["$extension"]=$((file_sizes["$extension"] + size))

#else

#file_sizes["$extension"]=$size

#fi



fi

done

