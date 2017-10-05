#!/bin/bash
echo Hi, What is your name
read NAME
echo Good Morning $NAME
echo =================================================
echo Your Home directory : $PWD
echo Enviroment variable PATH = $PATH
echo PRESS Enter KEY
read key
echo =================================================
echo HARD DISK FREE SPACE INFO
free
echo PRESS Enter KEY
read key
echo =================================================
echo PROCESSES CURRENTLY RUNNING
ps -la
echo PRESS Enter KEY
read key
echo ==================================================
echo LINUX VERSION
uname -a
echo PRESS Enter KEY
read key
echo ==================================================
echo WHO ARE CURRENTLY LOGGED IN
who -a
echo PRESS Enter KEY
read keyecho ==================================================
read -p 'Login name:' LOGIN
read -sp 'Password:' PASS
echo \n
echo Your LOGIN NAME IS $LOGIN
echo Your PASSWORD IS $PASS