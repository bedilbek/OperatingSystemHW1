// Part 1 B source code
/* Program using UNIX I/O primitives to perform file operations */
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
