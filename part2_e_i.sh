#!/bin/bash

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

let MAX=${list[0]}
let K=1

while [ $K -lt $N ]
do 
if [ $MAX -lt ${list[$K]} ]
then
MAX=${list[$K]}
fi
let K=$K+1
done

echo MAXIMUM ELEMENT HERE IS $MAX

