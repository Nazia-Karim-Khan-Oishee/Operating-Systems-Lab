#!/bin/bash

DATE=$(date +%Y%m%d%H%M%S)

for file in $(find "/home/nazia/Desktop/CSE4502/Lab04/" -type f);
do
filename=$(basename $file)
dir=$(dirname $file)
new_filename="$DATE""$filename"
mv $file "$dir""/""$new_filename"
echo "$filename renamed as $new_filename"
done
