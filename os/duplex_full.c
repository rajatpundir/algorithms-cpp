#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
    int fd[2],nbw,nbr,fd1[2],nbw1,nbr1;
    char str[100],arr[100],str1[100],arr1[100];
    pid_t pid;
    pipe(fd);
    pipe(fd1);
    pid=fork();
    if(pid>0)
    {
        printf("\nEnter a message to send to child Process : ");
        gets(str);
        nbw=write(fd[1],str,strlen(str));
        printf("\nParent Wrote %d bytes for message : %s\n",nbw,str);
        nbr1=read(fd1[0],arr1,sizeof(arr1));
        arr[nbr1]='\0';
        printf("\nParent Received a message %s of size %d from Child\n",arr1,nbr1);
    }
    else
    {
        nbr=read(fd[0],arr,sizeof(arr));
        arr[nbr]='\0';
        printf("\nChild Received a message %s of size %d from Parent\n",arr,nbr);
        printf("\nEnter a message to send to Parent Process : ");
        gets(str1);
        nbw1=write(fd1[1],str1,strlen(str1));
        printf("\nChild Wrote %d bytes for message : %s\n",nbw1,str1);
    }
    return 0;
}
