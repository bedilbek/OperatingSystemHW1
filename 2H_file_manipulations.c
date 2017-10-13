/* Program using UNIX I/O primitives to perform file operations */
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