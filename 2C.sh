#!/bin/bash
if [ -e "listdir" ]
then
    sed -i "5s/.*/Hi, this new line has been inserted here/" listdir
    echo "Line 5 replaced"
else
	echo "File not found"
fi