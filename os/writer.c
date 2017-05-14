#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int fd,nbw;
    char str[100];
    mknod("myfifo50",S_IFIFO|0666,0);
    printf("\nWriting for Reader Process\n");
    fd=open("myfifo50",O_WRONLY);
    while(gets(str))
    {
        nbw=write(fd,str,strlen(str));
        printf("\nWriter process write %d bytes of string %s\n",nbw,str);
    }
    return 0;
}
