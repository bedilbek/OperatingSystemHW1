# Assignment1 Report
### PART1
#### A. UNDERSTANDING UNIX/LINUX COMMANDS
1. ls – list files in a directory
ls -la  - write out all directory entries in long format
-l – write out in long format
-a – write out all directory entries, including those with names starting with ‘.’ (period)
2. pwd – print working directory
3. cd – change directory
4. cat – concatenate and print the content of files
5. cp – copy one or more files to another directory
6. mv – move or rename directories or files
7. who – print all usernames currently logged in
8. whoami – print the current user id and name
9. ps – list the processes running
ps -la – list the running processes in long format and including those with names starting with period
10. more – display output one screen at a time; unable to scroll back in screens
11. less - display output one screen at a time; able to scroll back in screens and has much more functionality than ‘more’ command
12. head – output beginning of a file
13. tail - output ending of a file
14. fg - starts a suspended process running in the foreground
15. rm – deletes a file
16. mkdir – creates a new directory with the given name
17. rmdir – removes a directory with the given name
18. date – outputs the current date/time
19. sudo – execute a single command as a super user
20. apt-get – search for and install a software package
21. chmod – change the access permissions of a file or a group of files
22. echo – outputs a message or a value
23. find – search for files by name within a given directory
24. free – display memory usage
25. diff – display differences between two files 
26. grep – search a file for a given string or expression
27. passwd – change your password
28. wc – output number of chars, lines, words in a file
29. man – help manual
30. sort – sort text files
31. cmp – compare two files
32. bg – run a process in the background
33. file – determine file type
34. time – measure program running time
35. kill – kill a process with a specific PID
36. link – create a link to a file
37. uname – print the system information
38. df – display free disk space
39. du – estimate file space usage
40. chown – change file owner or group
41. chgrp – change group ownership
42. adduser – adds a user
43. addgroup – adds a group
44. deluser – deletes a user
45. delgroup – deletes a group
46. touch – update the last-modified time of a user
47. top – display what processes are consuming the most CPU/memory and output system CPU/memory stats
48. cut – divide a file into several parts
49. sed – stream editor; find and/or replace based on regular expressions
50. uptime – show the time the system is up
#### B.
#### C.
### PART2
#### A.
181) sed --n '1 p' part2q | grep -o "the" | wc -l - shows how many the word "the" have in first line in file part2q
182) sed 's/the/THE/' part2q - replace "the" to "THE" in each line of file part2q, however it will replace only first occurence in each line
183) sed 's/THE/the/g' - globally replace "THE" to "the" in file part2q
184) sed 's/the/THE/2' - replace second occurence "the" to "THE" in file part2q
185) sed 's/the/THE/3' - replace third occurence "the" to "THE" in file part2q
186) sed 's/the/{&}/' part2q - replace all "the" to "{the}" in file part2q, in another words put "the" into brackets "{}", however it will replace only first occurence in each line
187) sed 's/the/THE/p' part2q - replace "the" to "THE" in each line of file part2q and print every line after original to show changes
188) sed --n 's/the/THE/p' part2q - replace "the" to "THE" in each line of file part2q and print only changed lines after original
189) sed 's/the/THE/' part2q | sed 's/commands/instructions/' part2q - replace "the" to "THE" then "commands" to "instructions" in each line of file part2q, however it will replace only first occurence in each line
190) sed -e 's/the/THE/' part2q -e sed 's/commands/instructions/' - add the script to the sed to be executed, that first replace every first occurence "the" to "THE" then "commands" to "instructions" in each line of part2q
191) sed 's/instructions/commands/' - replace every first occurence in each line of part2q "instructions" to "commands"
192) sed '4 s/the/THE/' part2q - replace first occurence "the" to "THE" in 4th line of file part2q
193) sed '1,3 s/the/THE/' part2q - replace first occurence "the" to "THE" in 1st and 3rd lines of file part2q
194) sed '2,$ s/THE/the/' part2q - replace first occurence "THE" to "the" in from 2nd line of file part2q
195) sed '/commands/ s/the/THE/' part2q - replace first occurence "the" to "THE" which comes before the "commands" in sentences of part2q
196) cp part2q part3q - create copy of part2q as part3q in the same direction
197) sed '3 d' part3q - delete 3 rd line in file part3q
198) sed 'p' part3q - print every changed line to show changes in file part3q
199) sed '2,$ d' part3q - delete from 2nd line in file part3q
200) cat part3q - Concatenate part3q to standard output.
201) sed --n 'commands/p' part3q - print every line which has "commands" to show after original in file part3q
202) grep 'commands' part2q - search for and print only lines where has "commands" and highlight
203) grep -v 'commands' part2q - search for and select non-matching lines where has "commands" for print
204) grep -w 'commands' part2q - force pattern to match only whole word "commands"
205) grep -B2 'State' part2q - print 2 lines of leading context till last "State"
206) grep -A2 'State' part2q - print 2 lines of trailing context from "State"
207) grep -C2 'State' part2q - print 2 lines of output context where "State"
208) grep -B2 'and' part2q - print 2 line of leading context till last "and"
209) grep -A2 'and' part2q - print 2 line of leading context from first "and"
210) grep -C2 'and' part2q - print 2 lines of output context where "and"
211) sed --n 'commands/!p' part2q - does not print lines which has "commands" to show after original in file part2q
212) sed '/commands/ a "You need to learn these commands which are very essential"' part2q - replace the text equivalent to 'You need to learn these commands which are very essential'
213) cal - print calendar of current month
214) cal -3 - print calendar including three months that 'current month-1' 'current month' 'current month+1' 
215) cal -y - print calendar of current year
216) passwd - change UNIX password used to login associated with the current effective user ID
217) whoami - print the user name associated with the current effective user ID
218) users - prints the user names associated with all effective user IDs
219) mail -s "Test Mail" n.jandullaev@student.inha.uz - send a message with the given "I want to sleep, I want to eat" to n.jandullaev@student.inha.uz from "Test mail"
220) mail -s "Test Mail" n.jandullaev@student.inha.uz <message.txt - send a message with from message.txt to n.jandullaev@student.inha.uz from "Test mail"
221) mail - prints all messages
222) ping inha.uz - check connection and print how many packages loses during request/response with "inha.uz"
223) ping inha.kr - check connection and print how many packages loses during request/response with "inha.kr"
224) ping google.com - check connection and print how many packages loses during request/response with "google.com"
225) ping amazon.com - check connection and print how many packages loses during request/response with "amazon.com"
226) whereis linux - locate the binary, source, and manual-page files for a command in directory of linux. 
227) which ./case.sh - command to locate path for case.sh, this command is really helpful to find path of executable commands that user don't know about its location. 
228) mount - mount a filesystem
229) vmstat - Report virtual memory statistics
230) netstat - active internet connections ip and pid
#### B. Answer the following questions
1. 
2. touch fileop.c
screenshot-2B.2.png
3. chmod --verbose a-rwX,u+r fileop.c
screenshot-2B.3.png
4. uname -a
After entering this command we will see all the information about operation system, and wee see that Ubuntu is running on this Linux
screenshot-2B.4.png
5. 
First we will run a process (Gnome editor) by its command `gedit`.
now we will suspend it by pressing the buttons (^Z).
After executing `bg %gedit` command gedit will continue running in background.
After executing `fg %gedit` command gedit will continue running in foreground.
Now we will suspend it by pressing the buttons (^Z).
Now if we write `bg` command itself, then it will bring the first process that is in foreground to background.
So now gedit is running in background.
We can find the pid of this process by executing the command `ps -la`.
Now with the found pid we will terminate the process: `sudo kill 9 12703`.
screenshot-2B.5.png
6. to know if remote host is alive we will use command `ping`
ping -c 3 google.com
we are sending 3 packets to google.com to know if the service is alive or not
screenshot-2B.6.png
7. to know history of earlier command we will use command `history`
screenshot-2B.7.png
8. we will use command `top` to find which process is taking how much time, and in the column %CPU we can see the CPU usage percentage of processes 
screenshot-2B.8.png
9. to check how much space left in the disk, execute command `df -h` and see the column Available
screenshot-2b.9.png
10. `ps -a` option causes ps to list all processes created within this terminal
`ps -ef` options cause `-e` option to list all processes and `-f` option to add extra columns of full information about the running processes
screenshot-B2.10.png
11. to find number of processors we use command `nproc` or `grep -E 'cpu cores' /proc/cpuinfo` or from saved file `grep -E 'cpu cores' infocpu`
screenshot-B2.11.png
12. we will use ps and grep to find running zombie processes
`ps axo stat,ppid,pid,tty,time,cmd | grep -e '^Z'`
screenshot-B2.12.png
13. we will use command `find / -name 'part2q' -print` to find file part2q starting from root directory
screenshot-B2.13.png	
14. `uname -m` or `arch` commands find whether system is 32-bit or 64-bit
screenshot-B2.14.png
15. We can use command `ps` with formatting the output collumns to find which process is accessing which file
screenshot-B2.15.png
Here in the screenshot first column "COMMAND" shows the files that are being used with corresponding processes
16. we will use command `sed -i 's/the/THE/g' part2q` to replace all occurences of the with THE
screenshot-B2.16.png
17. `cut -b11-12 listdir`
!screenshot-B2.17.png
18. we will use `du` command with `-h` option to add human readability and `-d` option to determine depth of recursive accessing to directories in home directory to find space usage of directories there
sudo du -hd 1
screenshot-B2.18.1.png
screenshot-B2.18.2.png
19. to find how long system is up `uptime -p` -o option to prettify the output
screenshot-B2.19.png
20. `rev listdir | tee listdir` command displays all lines of listdir in reverse order and writes output to listdir file
!screenshot-B2.20.png
21.
first use command `top` to list all running processes.
there are two ways to sort by cpu usage.
1) press `F` button, select `%CPU` and press button `s` and press `Esc`, now processes are sorted by CPU usage
2) press button `<` or `>` until sorting reaches `%CPU` 
screenshot-B2.21.png
22. to display 10 lines of case.sh we will use command `head -10 case.sh`
screenshot-B2.22
23. to display last 5 lines of case.sh we will use command `tail -5 case.sh`
screenshot-B2.23.png
24. we will use command `tar cvzf hw1.tar.gz HW1.docx` to compress HW1.docx
an then use command `tar xvzf hw1.tar.gz` to decompress that file
screenshot-B2.24.png
25. we will use command `cat -n` to display lines of file along with line number
screenshot-B2.25.png
26. we will use command `chmod -v +x case.sh` to give execution access to all
screenshot-B2.26.png
27. asks the user to delete all files in the current directory, if user presses button `y` then it deletes all files in that directory
screenshot-B2.27.png
28. diff compares files line by line, whereas cmp compares byte by byte.
screenshot-B2.28.png
29. `more -1 array.sh` and `head -1 array.sh` can be used to display first line of array.sh
screenshot-2B.29.png
30. 'tail -1 array.sh' and 'less -X array.sh' can be used to display last line of array.sh
screenshot-2B.30.png
31.	to find the process that is taking maximum memory we will use command `ps` and `sed`
`ps -eo ppid,pid,cmd,%mem --sort=-%mem | sed -n -e '1 p' -e '2 p'` this command formats the output of processes and sorts them by memory percentage in descing order, so we know that 1 row will be format and 2 row will be the process that we are seeking for
screenshot-B2.31.png
Here in the screenshot we see that google chrome is taking maximum memory 5.2% on my system.
32. to find only hidden files in current directory we can use command `find . -type f -iname ".*"`
screenshot-B2.32.png
33. to find currently running process we can dissplay all processes and by filtering we can get only running ones.
`ps -eo state,ppid,pid,time,cmd | grep '^R'`
screenshot-B2.33.png
34. `df -h /` by executing this command and seing the column Available can give a information about remaining disk space on system
screenshot-B2.34.png
35. `wc --lines listdir` command is used to count number of lines in listdir
!screenshot-B2.35.png
36. `wc --words listdir` command is used to count number of words in listdir
!screenshot-B2.36.png
37. `wc --chars listdir` command is used to count number of characters in listdir
38. yes, by command `rm -r *` all files and subdirectories can be deleted
screenshot-B2.38.png
39. tee command is used to read from input and write to standard output and files. For example:
`ps -o pid,tty,time,cmd,%mem --sort=%mem | tee memory_usage`
screenshot-B2.39.png
40. `env` by executing this command, it displays environment variables
41. difference between ls -la > file1 and ls -la > file1 2>&1 is if execution of second command throws exception then it will write that error to the file1, however if there is exception in the execution of first command, it will display to the screen, but will not write to the file
screenshot-B2.41.png
42. first we will display the file with `cat` command, and with `sed` command we will select 8th line, then with `wc` we will count length of line.
`sed -n '8 p' listdir | wc --chars`
!screenshot-B2.42.png
43. `sed -i '1 d' listdir` to delete 1st line of listdir
!screenshot-B2.43.png
44. 'sed -i '$ d' listdir` to delete last line of listdir
!screenshot-B2.44.png
Here we see before and after deletion of last line of listdir
45. `sed -n '1 p' part2q | cut -f5 -d ' '
Here firstly, we select first line and then display 5th word that is delimeted with ' '
screenshot-B2.45.png
Here in the screenshot we can see that 5th word in first line is 'THE'.
46. `sed -n '1 p' part2q | cut -f1 -d ' '`
Here firstly, we select first line and then display first word that is delimeted with ' '
screenshot-B2.46.png
Here in the screenshot we can see that first word in first line is 'type'.
47. `sed -n '1 p' part2q | rev | cut -f1 -d ' ' | rev`
Here firstly, we select first line, then reverse the line, get the first word that is delimeted with ' ' and reverse it again.
screenshot-B2.47.png
Here in the screenshot we can see that last word in first line is 'line'.
48. `echo "WINE Is Not windows Emulator" | rev`
screenshot-B2.48.png
49. `sed -i '1,5 d' listdir` to delete from 1-5 lines of listdir
screenshot-B2.49.png
50. `sed -i '15,$ d' listdir` to delete from 15-till the end lines of listdir
screenshot-B2.50.png
#### C.
#### D.
#### E.
#### F.
#### G.

#### H.

### PART3
3a.

All commands are executed in In Ubuntu Linux Distribution. In current time latest stable source version is 4.10.0. In this document we used “[version]” instead of “4.10.0”



To install linux source first we should update package list by executing command “sudo apt-get update”. It downloads the package lists from the repositories and "updates" them to get information on the newest versions of packages and their dependencies. It will do this for all repositories



	[Screenshot_3_a_1]



After updating we can start  installing linux source. To do it, we execute “sudo apt-get install linux-source” it downloads tar archived latest stable linux source code from internet and stores to “usr/src/linux-source-[version]/”.



	[Screenshot_3_a_2]



Because the source code is compressed we need to uncompress it using “tar xvjf usr/src/linux-source-[version]/ linux-source-[version].tar.bz2” command. The “tar” program is used to create, maintain, modify, and extract files that are archived in the tar format. The “xvjf”   is argument for tar program, argument’s first letter is function, where: 

	x – to extract all files from archive

	v – to operate in verbosely

	j – this option tells tar to read or write archives using the bzip2 compressor

	f – use archive file

The program extracts all linux source archive located in “usr/src/linux-source-[version]/ linux-source-[version].tar.bz2” to “home/user” directory



	[Screenshot_3_a_3]

	[Screenshot_3_a_4]



Linux source installation summary steps:

#updates packages list			$sudo apt-get update

#downloads linux source archive	$sudo apt-get install linux-source

#unarchive tar file			$tar xvjf usr/src/linux-source-4.10.0/ linux-source-4.10.0.tar.bz2



3b.

Here is the complete Linux source directory tree in pdf:

	[File: Kernel_Dir_tree.pdf]

Here is complete linux source code files: 

	[File: Kernel_files_list]

Here are screenshots of commands:

	[Screenshot_3_b_1]


### PART4
4a.

Here are compilation steps screenshots:

	[Screenshot_4a_1] ~ [Screenshot_4a_16]



4b.

In order to compile installed linux source we need first install “libncurses5” and “libncurses5-dev”. “libncurses5” this package contains the shared libraries necessary to run programs compiled with ncurses. “libncurses5-dev” this package contains the header files, static libraries and symbolic links that developers using ncurses will need. To do this you need to execute “$sudo apt-get install libncurses5 libncurses5-dev”.

	[Screenshot_4a_1]

After we need to configure linux source, in which we can choose which features to include in our source. To do this “make menuconfig” is executed. It is a menu-driven user interface, allows the user to choose the features of Linux (and other options) that will be compiled. After configuring source we will save it. For simplicity here I left default options. Then packages list is updated by “$sudo apt-get update”.


	[Screenshot_4a_2] ~ [Screenshot_4a7]


The next step is to install “libssl-dev” package which contains development libraries, header files, and manpages for libssl and libcrypto. This package is part of the OpenSSL project's implementation of the SSL and TLS cryptographic protocols for secure communication over the Internet. It is done by using “$sudo apt-get install libssl-dev”.



	[Screenshot_4a_8]



The final step before compilation is to execute “$make clean” comman. “$make clean” is something you do before recompiling, to make sure you get a clean build and don't have left-over by-products from previous runs. 



	[Screenshot_4a_9]



The final step is to compile and install kernel and modules using “$make deb-pkg”. The “make deb-pkg” command will create five deb packages in ../ that you will need to install with “$dpkg -i linux-*.deb”. 



	[Screenshot_4a_10] ~ [Screenshot_4a_16]



4c.

To test you will install compiled “.deb” files from source with “$dpkg -i linux-*.deb”. After you can reboot to new kernel.



	[Screenshot_4c_1]

	[Screenshot_4c_2]
