#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
    int fd[2],nbw,nbr;
    char str[100],arr[100];
    pid_t pid;
    pipe(fd);
    pid=fork();
    if(pid>0)
    {
        printf("\nEnter a message to send to child Process : ");
        gets(str);
        nbw=write(fd[1],str,strlen(str));
        printf("\nParent Wrote %d bytes for message : %s\n",nbw,str);
    }
    else
    {
        nbr=read(fd[0],arr,sizeof(arr));
        arr[nbr]='\0';
        printf("\nChild Received a message %s of size %d from Parent\n",arr,nbr);
    }
    return 0;
}
