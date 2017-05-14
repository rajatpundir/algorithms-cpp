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
    int num,cac;
    nd *front=NULL,*rear=NULL,*tmp=NULL;
    printf("\n\nInput Cache size:");
    scanf("%d",&cac);
    while(1)
    {
        printf("\n\nInput number:");
        scanf("%d",&num);
        tmp=front;
        while(tmp!=NULL)
        {
            if(tmp->info==num)
                break;
            tmp=tmp->next;
        }
        if(tmp==NULL)
        {
            puts("Miss!");
            rear=qinsert(rear,num);
            if(front==NULL)
                front=rear;
            if(qlength(front)>cac)
            {
                front=qserve(front);
                if(front==NULL)
                    rear=NULL;
            }
        }
        else
            puts("Hit!");
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