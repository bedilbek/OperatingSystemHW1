#!/bin/bash
echo Files in your HOME Directory with extension .c
for FILE in $HOME/*.c
do
echo $FILE
done
Shell script name : sum100.sh
#!/bin/bash
echo COMPUTING SUM OF FIRST 100 INTEGERS
sum=0
for i in {1..100}
do
sum=$sum+$i
done
echo SUM OF FIRST 100 INTEGERS = $sum