#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>
typedef struct node
{
    char str[100];
    struct node *next;
} q;
q *top=NULL,*top2=NULL;
char addd[300],filename[30];
int flag=1;
void push(char a[])
{
    q *p;
    p=(q*)malloc(sizeof(q));
    if(p==NULL)
    {
        printf("MEMORY PROB");
        return;
    }
    p->next=top;
    top=p;
    strcpy(p->str,a);
}
_TCHAR g_szDrvMsg[] = _T("A:\n");
void push2(char a[])
{
    q *p;
    p=(q*)malloc(sizeof(q));
    if(p==NULL)
    {
        printf("Memory Not Enough");
        return;
    }
    p->next=top2;
    top2=p;
    strcpy(p->str,a);
}
void display()
{
    char s[256]="";
    q *p;
    p=top;
    while(p!=NULL)
    {
        push2(p->str);
        p=p->next;
    }
    p=top2;
    while(p!=NULL)
    {
        strcat(addd,"\\");
        strcat(addd,p->str);
        p=p->next;
    }
}
void pop()
{
    q *p;
    p=top;
    top=top->next;
    free(p);
}
void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL)
    {
        pop();
        return;
    }
    chdir(dir);
    while(((entry = readdir(dp)) != NULL))
    {
        stat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode))
        {
            if(strcmp(".",entry->d_name) == 0 ||strcmp("..",entry->d_name) == 0)
                continue;

            if(dp!=NULL)
                push(entry->d_name);
            printdir(entry->d_name,depth+4);
        }
        else
        {
            if(strcmp(filename,entry->d_name)==0)
            {
                printf("file is found\n\n");
                push(entry->d_name);
                flag=0;
                main();
            }
        }
    }
    if(top!=NULL)
        pop();
    chdir("..");
    closedir(dp);
}
int main(int argc, char* argv[])
{
    FILE *fp;
    int i=0;
    char ch,str[10],s[20],tmp;
    static char ww[256]="";
    if(flag==1)
    {
        printf("Enter the file name to be searched : ");
        scanf("%s",filename);
        ULONG uDriveMask = _getdrives();
        if (uDriveMask == 0)
            printf( "_getdrives() failed with failure code: %d\n", GetLastError());
        else
       {
           printf("Drives:");
            while (uDriveMask)
            {if(uDriveMask & 1)
                printf("%s", g_szDrvMsg);
                ++g_szDrvMsg[0];
                uDriveMask >>= 1;
                printf("\n");
             }

        }
        printf("Enter the drive letter to be searched\n ");
        scanf("%s",ww);
        toupper(ww);
        strcat(ww,":\\");
        puts("Searching...");
        if(strcmp("\\:\\",ww)==0)
            printdir("\\",0);
        else
            printdir(ww,0);
}
    printf("file address: \n");
    display();
    strcat(ww,addd);
    for(i=3; ww[i]!='\0'; i++)
    ww[i]=ww[i+1];
    puts(ww);
    exit(0);
}
