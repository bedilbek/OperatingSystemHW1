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

echo ENTER KEY: 
read KEY
let K=0
let INDEX=-1

while [ $K -lt $N ]
do 
if [ $KEY -eq ${list[$K]} ]
then
INDEX=$K
break
fi
let K=$K+1
done

if [ $INDEX -eq -1 ]
then
echo NOT FOUND
else
echo KEY ${list[$K]} FOUND IN the list 
echo ITS position is $K starting from 0
fi
