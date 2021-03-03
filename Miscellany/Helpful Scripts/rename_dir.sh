#!/bin/bash

# Takes directory entries specified and renames them using the pattern provided.

for directory in *
do
    if [ -d "$directory" ]
    then
      mv "${directory}" "${directory}_temp" || echo 'Could not rename '"$directory"''
    fi
done