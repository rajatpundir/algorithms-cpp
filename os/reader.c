#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int fd,nbr ;
    char arr[100];
    mknod ("myfifo50",S_IFIFO|0666,0);
    fd = open ("myfifo50",O_RDONLY);
    printf("If you have a writer process then type a message");
    do{
        nbr = read (fd,arr,sizeof(arr));
        arr[nbr] = '\0';
        printf("\n Reader reads %d bytes and mesaage %s \n",nbr,arr);
    }while(nbr>0);
    return 0;
}
