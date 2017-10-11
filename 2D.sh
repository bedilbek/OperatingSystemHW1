#!/bin/bash
echo "Enter filename: "
read FILENAME

if [ -e $FILENAME ]
then
	echo $FILENAME exists
	
	if [ -f $FILENAME ] 
	then
		echo $FILENAME is a regular file 
	fi	

	if [! -s $FILENAME ] 
	then
		echo $FILENAME is an empty file 
	fi	

	if [ -d $FILENAME ] 
	then
		echo $FILENAME is a directory 
	fi	

	if [ -L $FILENAME ] 
	then
		echo $FILENAME is a symbolic link
	fi	

	if [ -b $FILENAME ] 
	then
		echo $FILENAME is a block special file
	fi	

	if [ -c $FILENAME ] 
	then
		echo $FILENAME is a character special file
	fi	

	if [ -p $FILENAME ] 
	then
		echo $FILENAME is a named pipe 
	fi	

	if [ -f $FILENAME ] 
	then
		echo $FILENAME is readable 
	fi	

	if [ -w $FILENAME ] 
	then
		echo $FILENAME is writable 
	fi

	if [ -e $FILENAME ] 
	then
		echo $FILENAME is executable 
	fi



else
	echo File does not exist

fi