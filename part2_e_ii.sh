#!/bin/bash
#This scripts finds and prints the minimum element in a given list
echo Enter n:
read N
echo Enter $N numbers:
let K=0
while [ $K -lt $N ]
do 
read VAL
list[$K]=$VAL
let K=$K+1
done

let MIN=${list[0]}
let K=1

while [ $K -lt $N ]
do 
if [ $MIN -gt ${list[$K]} ]
then
MIN=${list[$K]}
fi
let K=$K+1
done

echo MINUMUM ELEMENT HERE IS $MIN

