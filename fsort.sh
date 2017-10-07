#!/bin/bash
echo =============================================================
echo ENTER A FILE NAME TO STORE 10 NAMES
read FILE
echo ENTER 10 NAMES ONE BELOW THE OTHER ON SEPARAT LINEs and THEN PRESS ^D
cat >> $FILE
echo PRESS Enter KEY
read key
echo =============================================================
echo your FILE $FILE CONTENTS
cat $FILE
echo PRESS Enter KEY
read key
echo =============================================================
echo FILE SORTING IN ALPHABETICAL ORDER
sort $FILE
echo PRESS Enter KEY
read key
echo =============================================================
echo FILE SORTING IN REVERSE ALPHABETICAL ORDER
sort -r $FILE
echo PRESS Enter KEY
read key