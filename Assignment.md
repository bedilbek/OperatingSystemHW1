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
/* Program using UNIX I/O primitives to perform file operations */
/*FileName: file_oper.c*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEF_MODE S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH
 /*
defining the permissions of the created file
*/

int main() 
{
	/*
		int fd 
		int fd1
		int len
		int i
		int fsize
		int nbytes

		char ch - to store temporary char
		char cf
		char buf[512] - to store file content 
		char fname[25] - to store a file name
		char cname[25] - to store second file name
	*/
	int fd, fd1, len, i, fsize, nbytes;
	char ch=0, cf, buf[512], fname[25], cname[25];

	
	/*
		File creation
	*/
	printf("CREATING A NEW FILE WITH ALL ACCESS RIGHTS TO USER AND GROUP AND EXECUTE ACCESS TO OTHERS\n");
	
	printf("ENTER FILE NAME : ");
	scanf("%s", fname);
	
	fd = open(fname, O_CREAT|O_TRUNC|O_WRONLY|O_APPEND, DEF_MODE);
/*
definition of function open() ====> open(const char*file_name, int oflags, mode_t mode)
oflags ==>> defines the method(s) in which the file should be opened. Method_flags can be separated by BITWISE OR |, if many.
mode ==>> defines the permissions of the file when created, can be separated by BITWISE OR, if many.
O_CREAT => create the file, if doesn't exist and 3rd parameter must be present
O_TRUNC ==> Initially clear all data from the file. It means even the file exists, data in it will be erased.
O_WRONLY ==> The file is for write only.
O_APPEND  ==>  Append new information to the end of the file

*/
	
	if (fd < 0)
	{
		printf("cannot create FILE %s \n", fname);
	}	
	else
	{
		printf("NOW ENTER YOUR PROGRAM OR TEXT LINE BY LINE- ONCE YOU FINISH PRESS KEYS Ctrl+D\n");
		
		i=0;

		ch = getchar();
		
		/* to remove the last newline character entered*/
		while ( (ch=getchar()) != EOF)
			buf[i++]=ch;

		fsize=i-2;

		buf[fsize]='\0';

		printf("Total characters stored in your file = %d\n", fsize);
		
		write(fd, buf, fsize);
/*
Definition of function write(int, const void *buf, size_t nbytes) ===> write(file_descriptor, buffer_pointer, number_of_written_bytes)


*/
		
		close(fd);
/*
file is closed  with close(file_descriptor) function
*/
	}
	

	/*
		Opening an existing file
	*/
	printf("OPENING AN EXISTING FILE\n");
	
	printf("ENTER FILE NAME : ");
	scanf("%s", fname);
	
	fd = open(fname, O_RDWR|O_APPEND, DEF_MODE);
/*
O_RDWR ==> says open the file so that it can be read and written.
O_APPEND ==> append to the end of the file
DEF_MODE is the same
*/
	
	if (fd < 0)
	{
		printf ("cannot open FILE %s - does not exist \n", fname);
	}
	else
	{
		printf(" READING YOUR FILE CONTENTS\n");

		nbytes=read(fd, buf, sizeof(buf));
		len=strlen(buf);
/*
Definition of function read(fd, buf, sizeof(buf))==>  
fd - file_descriptor
buf(char array) - buffer for storing content of the file
sizeof(buf) - number of bytes to read before truncating data
*/

		printf("CONTENTS OF YOUR FILE %s - size= %d\n",fname, len);

		puts(buf);// printing the file content

		close(fd);// file closed
	}
	

	/*
		Copying a file
	*/
	printf("COPYING A FILE \n");
	
	printf("ENTER NAME OF CURRENT FILE TO BE COPIED FROM :");
	scanf("%s", fname);
	printf("ENTER NAME OF NEW FILE NAME TO BE COPIED TO :");
	scanf("%s", cname);
	
	fd = open(fname, O_RDONLY, DEF_MODE);
/*
firstly, the file which is to be opened is opened in read-only(O_RDONLY) mode
*/
	
	if (fd < 0)
	{
		printf ("cannot open FILE %s - does not exist \n", fname);	
	}
	else
	{
		if(nbytes = read(fd, buf, sizeof(buf)) < 0) //negative number is returned if there is a system call error
		{
			printf("FILE READ ERROR\n");	
		}
		else
		{
			fd1 = open(cname, O_CREAT|O_TRUNC|O_WRONLY, DEF_MODE);
			/*
			THEN new file with name cname is created
			*/
			
			if (fd1 < 0) // negative value is returned when an error occurs while opening file
			{
				printf("Cannot create New file %s\n", cname);	
			}
			else
			{
				len=strlen(buf);

				if( nbytes=write(fd1, buf, len) < 0) // negative value is returned when an error occurs while writing to file
					printf("FILE WRITE ERROR\n");
				else
					printf("FILE %s has been copied to %s successfully OK ......\n",fname,cname);
				close(fd1);
			}
			
			close(fd);
		}
	}
	

	/*
		Renaming a file
	*/
	printf("RENAMING A FILE \n");
	
	printf("ENTER CURRENT FILE NAME :");
	scanf("%s", fname);
	printf("ENTER NEW FILE NAME :");
	scanf("%s", cname);
	printf("FILE %s has been renamed to %s OK......\n", fname, cname);
	
	rename(fname, cname); /*using this function the file is renamed, fname and cname are char arrays*/

	
	
	/*
		Deleting a file
	*/
	printf("DELETING A FILE \n");
	
	printf("ENTER FILE NAME :");
	scanf("%s", fname);
	
	ch = getchar(); /* to remove the last newline character entered*/
	
	printf("PLEASE CONFIRM - SURE YOU WANT TO DELETE ....PRESS y/n :");
	scanf("%c", &cf);
	
	if (cf == 'y')
	{
		unlink(fname);/* using this unlink() function the the file is deleted*/
		printf("FILE %s deleted OK......\n", fname);
	}
	else
	{
		printf("FILE %s not deleted OK......\n", fname);	
	}

}
/*end_of: file_oper.c================================================================================*/
In the code above, proper comments are provided to explain file operations and Unix i/o primitives used.

RESULTS AND SCREENSHOTS:
Here should be "part1_B#1.png".
In the screenshot above we can see how the file_oper.c is given to compilation and executed. And partially there is shown how the program works, using i/o operations.
Here should be "part1_B#2.png" and "part1_B#3.png".
These two screenshots above are to demonstrate how the C program went on working.
#### C.
a) Sample shell script. This script asks you your name, and as you press enter it shows you info about your home dir, hard disk free space and others, which are provided in the screenshot below.
Here should be part1_C_a.png.
______________________________________________________________________
b) File-Line, word and byte count
This script counts you number of characters, words and lines in the file that you specified. 
wc -l $FNAME - counts #of lines
wc -w $FNAME - counts #of words
wc -c $FNAME - counts #of bytes
The screenshot below is showing how the script went on.
Here should be part1_C_b.png.
______________________________________________________________________
c) File Sorting
This script asks you enter file name and 10 names which will be stored in this file. And the entered names are sorted in both orders(asc and desc).
Keyword used to sort is: sort, sort -r for reverse order.
The screenshot below is showing how the script went on.
Here should be part1_C_c.png.
______________________________________________________________________
d) Examples for Conditional construct if ...then....else ...fi.
This script gets from user the value of LONG and using the
syntax: if [$LONG -eq 1], which means "if LONG is equal to 1" branches into two cases ls-la or ls, which show extended and short directory listing. 
The screenshot below is showing how the script went on.
Here should be part1_C_d.png.
______________________________________________________________________
e) i) while do ..... done construct
The script shows how while-do-done loop structure works, calculating the sum of the first odd integers. Variable A here serves as an iterator for checking the limit, B and C are used to calculate the sum. And the sum is stored in variable B.
The screenshot below is showing how the script went on.
Here should be part1_C_e_i.png.
______________________________________________________________________
ii) for do .....done construct
There are two scripts here, the first script shows how for-do-done loop structure works with the example of finding the files with the extenion .c.
And the next script(sum100.sh) computes the sum of first 100 integers using for-do-done structure.
The screenshots below are showing how the scripts went on.
Here should be part1_C_e_ii.png.
______________________________________________________________________
iii) until do..... done construct
The script shows how the until-do-done loop structure works, computing the factorial of the entered value n.
The screenshot below is showing how the script went on.
Here should be part1_C_e_iii.png.
______________________________________________________________________

f) Example for Multi-way Branch - case .....esac
The script shows how to use Multi-way branching case...esac. The program provides you with 11 choice menu for dealing with flies or giving some info(linux version, etc).
Branches are finished with double-semicolons(;;) which means the end of the branch. 
And in the last choice most interesting there is *) case which means default case(any other value which is not specfified above). 
case is finished with esac. 
The screenshot below is showing how the script went on.
Here should be part1_C_f_1.png and part1_C_f_2.png.
______________________________________________________________________

g) Example for Select do ....done and if ...elif ....fi constructs.
The script shows how to use select-do-done and if-elif structres. In the string variable OPTIONS the options are specified, So that "select choice in $options" provides you menu. if-elif structure is used to find the selected option and execute proper commands. 
The screenshot below is showing how the script went on.
Here should be part1_C_g_1.png, part1_C_g_2.png. part1_C_g_3.png.
______________________________________________________________________

h) Passing parameters using Command Line Arguments
The scipt demonstrates the use of command line argguments. $1 is for getting the first command line argument, and $2 is for second. THe program gets $1 and $2 as the names of the files, where the content of the file1 should be copied to file2.
The screenshot below is showing how the script went on.
Here should be part1_C_h.png.
______________________________________________________________________

i) Length of a string
The script reads the string and gives the length of the string as output. ${#STR} is used to show the length of the string.
The screenshot below is showing how the script went on.
Here should be part1_C_i.png.
______________________________________________________________________


j) Use of Special Variables
The script shows the use of special variables. 
$0 - contains the name of the running script
$# - contains # of command line arguments
$@ - contains All the arguments supplied to the bash script 
$? - contains The exit status of the most recently run process 
$$ - contains The process ID of the current script
$USER - contains User Name of the user running the script 
$HOSTNAME- contains The hostname of the machine the script is running on
$SECONDS- contains The number of seconds since the script was started
$LINENO - contains Current line number in the Bash script
$RANDOM - contains Random number returned by the RANDOM variable 
The screenshot below is showing how the script went on.
Here should be part1_C_j.png.
______________________________________________________________________

k) Using Arrays

i) In this script we can see the declaration format of  the array - name=(1 2 3 4). And each element of the array is referenced like this - ${list[$I]}.
and the array is printed out using the while loop.

ii) This is the next example of using arrays. Here the maximum element is found in the given array.

iii) In this script array of the size of n is created and n values are taken from input. And in this array the maximum element is found and echoed into screen.

l) Procedure Invocation
The scipt shows how the procedures are invocated and how variables are passed into them. $? this expands the exit status of the most recently executed command

### PART2
#### A.
91) gives all files in current directory with extension .o and its informaiton
92) gives all files current directory with extension .c and its information
93) gives all files current directory with extension .sh and its inforamtion
94) gives all files in current directory with its information
95) show content of given file
96) first takes 14 lines from begginning as content and shows 1 line from the end of taken content from file
97) delete 1st row from core4info, -i means insertion
98) shows content of core4info
99) delete the last row from core4info file
100) shows content of core4info file
101) prints 13 line of core4info
102) prins byte count in 13th line
103) prints word count in 13th line
104) prints revese version of 13th line
105) prints from 13th to 18th the line
106) prints new line counts from 13th to 18the line
107) prints word count from 13th line to 18th line
108) prints byte count fro 13th line to 18th line
109) prints the last row of the core4info file
110) the first it takes revese string, then split by delimeter and takes the first word, then prints revese version of this word
111) the first it splits string by the delitmeter and prints the 4th element taken array
112) prints 4th element from every row
113) prints 4th and 6th elements from every row
114) prints from 1st to 7th element in every row
115) prints from beginning till 6th element from every row
116) prints from 10th till end of every row
117) ~~~it gives error~~~
118) prints 2nd element of array which is taken from splitting by delimeter from each row(new line)
119) prints from 1st till 2nd element of an array which is taken from splitting by delimeter from each row
120) the same as 118
121) prints 2nd and 3rd element of an array which is taken by splitting by delimeter from each row
122) prints from 1st till 3rd element of an array which is taken by splitting by delimeter from each row
123) prints from beginnging till 3rd element of an array which is taken by splitting by delimeter from each row
124) prints from 2nd till end of an array which is taken by splitting by delimeter from each row
125) prints 1st element of an array which is splitted by delimeter ':' of every row
126) prints 2nd and 3rd element of an array which is splitted by delimeter of every row, putting delimeter di separate elements
127) copy file /etc/passwd to current directory with filename as password
128) prints content of password file
129) should print 1st element of an array splitting by delimeter, but as there is no delimenter ' ', it prints the whole content
130) as delimenter ' ' it takes every row and prints characters from 1st to 10th
131) it revers the content and shows 1st element of an array which is spleetted by delimeter
132) prints characters from 10th till 50th character of reverse content of file
133) prints the lines where it contains word CHOICE in select.sh file
134) prints the lines where it contains word 'echo' in case.sh file
135) prints every new line which starts with small letters (it is given as regex) in file
136) prints every new line which starts with capital letters (as given in regex) in file
137) prints every new line which starts numbers (as given in regex) in file
138) prints every new line which starts with space ' ' in file
139) reads every file recursively and find line exact maches with given string 'esac', then prints filename and line
140) prints files which does not contain string 'esac' in current directory
141) prints files which contains the string 'file' in current directory
142) prints files and lines which matches with string 'esac'
143) print files with any name with any extension and lines which matches with string 'esac'
144) prints files with any name with any extension and lines which matches with string 'case'
145) prints files with any name with any extension and lines with line number which matches with string 'case'
146) prints only matched lines with string 'case' in case.sh file
147) prints line number and matched line with string 'esac' in case.sh file
148) prints line number and matched line with string 'case' in case.sh file
149) prints line which matched with string 'case' in case.sh file
150) prints line which matched with string 'echo' in case.sh file
151) 1st it takes echo matched lines and prints count of lines
152) prints byte offset of matched string 'case' in file case.sh
153) prints only matched results with line number and byte offset in file case.sh
154) prints byte offset, line number with full line which matched with string 'case'
155) prints byte offset for every match
156) prints only matches with byte offset and line number in file case.sh
157) prints byteoffset, line number of matched string with full line
158) prints byte offset of matched string
159) prints matched string line and line number
160) prints lines which starts with 'case' string in case.sh file
161) prints lines which ends with string 'OK' in case.sh file
162) prints lines which ends with string 'ne' in case.sh file
163) prints lines which ends with character ':' in case.sh file
164) prints lines which starts with 'while' string in case.sh file
165) prints lines which starts with 'echo' string in case.sh file
166) prints lines which does not match with string 'echo' in case.sh file
167) prints lines which does not start with string 'echo' in case.sh file
168) prints lines which does not start with string 'while' in case.sh file
169) prints count of matches 'case' string in case.sh file
170) prinst count of matches 'echo' string in case.sh file
171) prints count of matches 'unix' string in file.txt file
172) print lines which matches with string 'read' in case.sh file
173) prints only matched with string 'read' as regex in file case.sh
174) prints line countes of matched string 'read' in case.sh
175) append next strings which ends with command+D to part2q file
176) prints 3rd line of part2q file
177) prints matched words on 3rd line
178) prints count of matched words on 3rd line
179) prints 1st line of part2q file
180) prints count of matched words on 1st line
181) sed --n '1 p' part2q | grep -o "the" | wc -l - shows how many the word "the" have in first line in file part2q
182) sed 's/the/THE/' part2q - replace "the" to "THE" in each line of file part2q, however it will replace only first occurence in each line
183) sed 's/THE/the/g' - globally replace "THE" to "the" in file part2q
184) sed 's/the/THE/2' - replace second occurence "the" to "THE" in file part2q
185) sed 's/the/THE/3' - replace third occurence "the" to "THE" in file part2q
186) sed 's/the/{&}/' part2q - replace the first occurrence "the" to "{the}" in each line of file part2q, in another words put "the" into brackets "{}", however it will replace only first occurence in each line
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
(i) 
SCRIPT:
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

(ii) In this script it is almost the same as in the previous script, but it checks for "greater than".

(iii) 
SCRIPT:
...Enter values to list...
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

Here should be  part2e_i_ii_iii.png file.
########################################################

#### F.
The command 'sed' was used to substitute.

Scipts:
(i)
sed 's/.*/\U&/g' < part2q > part2ql
echo Letters IN part2q FILE  have been UPPERCASED and stored IN part2ql FILE

(ii)
sed 's/.*/\L&/g' < part2q > part2qu
echo Letters IN part2q FILE  have been lowercased and stored IN part2ql FILE

(iii)
cat part2q > part2qr
sed -i '/commands/ s/the/THE/g' part2qr
sed -i 's/commands/COMMANDS/g' part2qr
echo In part2q the lines with word \'commnads\' found and the occurencies with \'the\' IN these lines were UPPERCASED and the words \'commands\' as well.

(iv)
cat part2q > part2m
sed -i -e '1 d' part2m
sed -i -e '$ d' part2m
echo First and LAST lines are DELETED from part2m FILEs

(v)
cat part2q part2ql part2qu part2qr part2m > part2qa
echo The contents of part2q part2ql part2qu part2qr part2m FILES were copied and pasted IN part2qa

#### G.
In this script to implement the selection menu, 'select' statement was used.
#!/bin/bash

OPTIONS='Halt init0 init6 Poweroff Reboot Shutdown'
PS3='Choose an option: '

select CHOICE in $OPTIONS
do
if [ $CHOICE == Halt ]
 then
   sudo halt
elif [ $CHOICE == init0 ]
 then
   sudo init 0
elif [ $CHOICE == init6 ]
 then
   sudo init 6
elif [ $CHOICE == Poweroff ]
 then
   poweroff
elif [ $CHOICE == Reboot ]
 then
   reboot
elif [ $CHOICE == Shutdown ]
 then
   shutdown
else echo NO such option
fi
done

##There are results during the execution in the screenshot below 
Here should be  part2_f&g.png file.
#### H.
	CODE
/* Program using UNIX I/O primitives to perform file operations  with menu driven*/
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define DEF_MODE S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH

void createNewFile();
int openExistingFile();
void readFromFile(int fd, int nbytes);
void writeToFile(int fd, int i);
void findInFile(int fd);
void deleteFile();
void renameFile();
void copyFile();

int main()
{
    int option = 1;
    int fd, len;
    char filename[25];
    while (option >= 1 && option <= 9)
    {
        printf("----MENU TO PERFORM FILE OPERATIONS----\n");
        printf("1. Create a new file\n");
        printf("2. Open an existing file\n");
        printf("3. Read from a file\n");
        printf("4. Write to a file\n");
        printf("5. Seek the contents of the opened file\n");
        printf("6. Delete a file\n");
        printf("7. Rename a file\n");
        printf("8. Copy a file\n");
        printf("9. Quit\n");
        printf("Choose an operation (1-9) : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: createNewFile();
                break;
            case 2: fd = openExistingFile();
                break;
            case 3: readFromFile(fd, 0);
                break;
            case 4: writeToFile(fd, 0);
                break;
            case 5: findInFile(fd);
                break;
            case 6: deleteFile();
                break;
            case 7: renameFile();
                break;
            case 8: copyFile();
                break;
            case 9: return 0;
            default: printf("Entered wrong option, try again later, PLEASE");
                break;
        }
    }
}

void createNewFile()
{
    int fd, fsize;
    char ch=0, buf[512], fname[25], cname[25];
    printf("CREATING A NEW FILE WITH ALL ACCESS RIGHTS TO USER AND GROUP AND NO EXECUTE ACCESS TO OTHERS\n");
    printf("ENTER FILE NAME : ");
    scanf("%s", fname);
    fd = open(fname, O_CREAT|O_TRUNC|O_WRONLY|O_APPEND, DEF_MODE);

    if (fd < 0)
        printf ("cannot create FILE %s \n", fname);
    else
    {
        printf("FILE %s CREATED", fname);
        close(fd);
    }
    printf("\n\n");
}

int openExistingFile()
{
    /**
    TODO: complete
    **/

    int fd, option, mode;
    char ch=0, cf, buf[512], fname[25], cname[25];

    printf("OPENING AN EXISTING FILE\n");
    printf("ENTER FILE NAME : ");
    scanf("%s", fname);
    printf("PLEASE CHOOSE THE MODE: \n");
    printf("1.READ ONLY; 2.WRITE ONLY WITH APPEND; 3.READ & WRITE WITH APPEND : ");
    scanf("%d", &option);

    switch(option)
    {
        case 1: mode = O_RDONLY;
            break;
        case 2: mode = O_WRONLY|O_APPEND;
            break;
        case 3: mode = O_RDWR|O_APPEND;
            break;
        default: printf("Please choose correct mode! \n");;
            break;
    }
    fd = open(fname, mode, DEF_MODE);
    if (fd < 0)
        printf ("cannot open FILE %s - does not exist \n", fname);
    else
    	printf("File %s opened\n\n", fname);
    return fd;
}

void readFromFile(int fd, int nbytes)
{
    int offset;
    char buf[512];
    printf("HOW MANY BYTES YOU WANT TO READ, IF TILL THE END, ENTER -1 : ");
    scanf("%d", &offset);
    if (fd < 0)
        printf ("cannot open FILE - does not exist \n");
    else
    {
        int len;
        read(fd, buf, sizeof(buf));

        if (offset == -1) {
            len = 512;
        }
        else {
            if (nbytes != 0)
                len = offset + nbytes;
            else len = offset;
        }
        for (int i = nbytes; i < len; i++)
        {
            if (buf[i] == '\0')
                break;
            printf("%c", buf[i]);
        }
    }
    printf("\n\n");
}

void writeToFile(int fd, int i)
{
    char ch=0, buf[512];
    printf("WRITING TO AN EXISTING FILE\n");
    if (fd < 0)
        printf ("Cannot open a FILE for writing \n");
    else if (i >=512)
        printf ("Cannot write to a file, range exceeded \n");
    else
    {
        printf("NOW ENTER YOUR PROGRAM OR TEXT LINE BY LINE- ONCE YOU FINISH PRESS KEYS Ctrl D together\n");
        ch=getchar();
        /* to remove the last newline character entered*/
        while((ch=getchar()) != EOF)
            buf[i++]=ch;
        buf[i]='\0';
        printf("\nTotal characters stored in your file = %d\n", i);
        write(fd, buf, i);
    }
    printf("\n\n");
}

void findInFile(int fd)
{
    /**
    TODO: complete
    **/
    int nbytes, option;
    printf("SEEKING THE CONTENTS FROM AN EXISTING FILE\n");
    printf("HOW MANY BYTES YOU WANT TO TO BE SKIPPED, TO GO TO THE END, ENTER -1: ");
    scanf("%d", &nbytes);
    if (fd < 0)
        printf ("Cannot open FILE - does not exist \n");
    else if (nbytes < 0)
        printf("Entered wrong parameters for seeking, try again with different values\n");
    else
    {
        printf("What kind of operation you want? 1.READ; 2.WRITE : ");
        scanf("%d", &option);
        if (option == 1) {
            readFromFile(fd, nbytes);
        }
        else if (option == 2)
        {
            writeToFile(fd, nbytes);
        }
        else {

            printf("Wrong option has been choosen, please try again with different value\n");
        }
    }
    printf("\n\n");
}

void deleteFile()
{
    char cf, fname[25];
    printf("DELETING A FILE \n");
    printf("ENTER FILE NAME :");
    scanf("%s", fname);
    getchar(); /* to remove the last newline character entered*/
    printf("PLEASE CONFIRM -SURE YOU WANT TO DELETE ....PRESS y/n :");
    scanf("%c", &cf);
    if (cf == 'y')
    {
        unlink(fname);
        printf("FILE %s deleted OK......\n", fname);
    }
    else
        printf("FILE %s not deleted OK......\n", fname);
    printf("\n\n");

}


void renameFile()
{
    char fname[25], cname[25];
    printf("RENAMING A FILE \n");
    printf("ENTER CURRENT FILE NAME :");
    scanf("%s", fname);
    printf("ENTER NEW FILE NAME :");
    scanf("%s", cname);
    printf("FILE %s has been renamed to %s OK......\n", fname, cname);
    rename(fname, cname);
    printf("\n\n");
}

void copyFile()
{
    int fd, fd1, len;
    char buf[512], fname[25], cname[25];

    printf("COPYING A FILE \n");
    printf("ENTER NAME OF CURRENT FILE TO BE COPIED FROM :");
    scanf("%s", fname);
    printf("ENTER NAME OF NEW FILE NAME TO BE COPIED TO :");
    scanf("%s", cname);
    fd = open(fname, O_RDONLY, DEF_MODE);
    if (fd < 0)
        printf ("cannot open FILE %s - does not exist \n", fname);
    else
    {
        if(read(fd, buf, sizeof(buf)) <0)
            printf("FILE READ ERROR\n");
        else
        {
            fd1 = open(cname, O_CREAT|O_TRUNC|O_WRONLY, DEF_MODE);
            if (fd1 < 0)
                printf("Cannot create New file %s\n", cname);
            else
            {
                len=strlen(buf);
                if(write(fd1, buf, len) < 0)
                    printf("FILE WRITE ERROR\n");
                else
                    printf("FILE %s has been copied to %s successfully OK ......\n",fname,cname);
                close(fd1);
            }
            close(fd);
        }
    }
    printf("\n\n");
}
	
	[screenshot 2H.1.png]
	
	Here from the menu of our program we choose 1st option to create new File.
	After completing the given steps we see the message that new File created

	Then after completing file operation, again menu is shown

	In this part, we will open the file
	We choose the option 2 to open the newFile
	After completing the given steps we see the message that newfile is opened

	[screenshot 2H.2.png]

	Here by choosing the option 4 to write to opened file.
	We write the text and blue underlined text is that we have written. after finishing the writing press ^D to stop
	we see the message that text is written into the file

	Now to check whether the changes to file is made, we will reopen the file by choosing the option 2.

	[screenshot 2H.3.png]

	We choose the option 3 to read the opened file.
	From the blue underlined text that changes were made to file and it has read the file where we wrote.

	[screenshot 2H.4.png]

	Now we will try to seek from a file and read it.
	We choose the option 5 to seek from the opened file.
	We choose how many bytes should be skipped inside the file. 5 bytes skipping is chosen.
	We choose what operation we will do, 1st option to read the file.
	We choose we want to read 3 bytes from the file.
	We have been messaged with blue underlined text which represents reading file from 5 bytes till 8 bytes.

	[screenshot 2H.5.1.png]

	Now we will try to seek from a file and write into it.
	We choose the option 5 to seek from the opened file.
	We choose how many bytes should be skipped inside the file. 2 bytes skipping is chosen.
	We choose what operation we will do, 2st option to write into the file.
	We write the text we want, and to finish we press ^D.
	We have been messaged in the last file that 24 bytes totals characters are stored into file.

	[screenshot 2H.5.2.png]

	Now we will see the changes that we have made to file.
	We choose the option 3 to read from the file
	From last blue underlined text we can see what we wrote into file

	[screenshot 2H.6.png]

	Now we delete file by choosing the option 6
	we see the message that file is deleted

	We check by opening the file with option 2
	We see that file cannot  be opened

	[screenshot 2H.7.png]

	Now we rename the file.
	First we will create file newNewFile by choosing the option 1.
	Second, rename the file to JustNewFile by choosing the option 7.

	[screenshot 2H.8.png]

	First we will write to a file text to copy it to other new file.

	In the end we see that file has been copied to other file.

	[screenshot 2H.9.png]

	If we open and read the file, we see that file has been copied and all the text inside also has been copied to that file.
	
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
