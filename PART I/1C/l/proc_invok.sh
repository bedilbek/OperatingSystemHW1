#!/bin/bash
len_str() {
#Show the length of a String
echo Enter a string :
read STR
L=${#STR}
return $L
}
print_str(){
len=$?
echo Length of the string $1 is $len
}
len_str
print_str $STR