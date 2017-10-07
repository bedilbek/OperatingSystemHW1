#!/bin/bash
echo =================================================
echo Enter a filename to find number of characters, words and lines
read FNAME
cat $FNAME
echo No of lines
wc -l $FNAME
echo No of words
wc -w $FNAME
echo No of bytes
wc -c $FNAME
echo PRESS Enter KEY
read key