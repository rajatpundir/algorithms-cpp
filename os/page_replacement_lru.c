#include<stdio.h>
#include<malloc.h>
typedef struct queue
{
    int info;
    struct queue *next;
} nd;
nd* qinsert(nd *,int);
nd* qserve(nd *);
void qdisplay(nd *);
int qlength(nd *);
void main()
{
    int num,cache;
    nd *front=NULL,*rear=NULL,*tmp=NULL,*prev=NULL;
    puts("Input Cache size:");
    scanf("%d",&cache);
    while(1)
    {
        puts("\n\nInput number:");
        scanf("%d",&num);
        tmp=front;
        prev=front;
        while(tmp!=NULL)
        {
            if(tmp->info==num)
                break;
            prev=tmp;
            tmp=tmp->next;
        }
        rear=qinsert(rear,num);
        if(front==NULL)
            front=rear;
        if(tmp==NULL)
        {
            puts("Miss!");
            if(qlength(front)>cache)
            {
                front=qserve(front);
                if(front==NULL)
                    rear=NULL;
            }
        }
        else
        {
            puts("Hit!");
            if(tmp==front)
                front=front->next;
            else
                prev->next=tmp->next;
            free(tmp);
        }
        qdisplay(front);
    }
}
nd * qinsert(nd *rear, int num)
{
    nd *p=(nd*)malloc(sizeof(nd));
    if(p==NULL)
        printf("\nMemory Not Available\n");
    else
    {
        p->info=num;
        p->next=NULL;
        if(rear!=NULL)
            rear->next=p;
        rear=p;
    }
    return(rear);
}
nd * qserve(nd *front)
{
    nd *p;
    if(front==NULL)
        printf("\nQueue is empty\n");
    else
    {
        p=front;
        front=front->next;
        free(p);
    }
    return(front);
}
void qdisplay(nd *front)
{
    if(front==NULL)
        printf("\nQueue is empty.\n");
    else
    {
        do
        {
            printf("%d ",front->info);
            front=front->next;
        }
        while(front!=NULL);
    }
}
int qlength(nd *front)
{
    int i=0;
    if(front==NULL)
        printf("\nQueue is empty.\n");
    else
    {
        do
        {
            i++;
            front=front->next;
        }
        while(front!=NULL);
        return i;
    }
}

