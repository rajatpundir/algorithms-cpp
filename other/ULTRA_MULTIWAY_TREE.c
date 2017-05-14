/*1.You will be given a file with two lines. First line will contain two integers separated by commas(say X,Y). In the next line there will be Y number of integers again separated by commas. You should be able to output all the possible combinations from the Y integers (an integer can be used infinite number of times) which addition will give the value X.

Example Input

10,4
 2,5,3,6

The output will be:
 2+2+2+2+2
 2+2+3+3
 2+2+6
 2+3+5
 5+5

The order of the output does not matter
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
typedef struct node
{
    int data;
    int sum;
    char str[20];
    struct node *next;
    struct node *child;
} node;
node * new_node(int,int,char[]);
node * add_sibling(node *, int,int,char[]);
node * add_child(node *, int,int,char[]);
void trav(node *,int[10],int);
void traverse(node *,int);

void main()
{
    int i,x,y,z,a[10];
    FILE *fp;
    char file[256],num[10],ch;
    node *root = new_node(0,0,"");
    puts("Input file name: ");
    gets(file);
    fp=fopen(file,"r");
    do
    {
        ch=getc(fp);
        if(isdigit(ch))
            break;
    }
    while(ch!=EOF);
    i=0;
    while(isdigit(ch))
    {
        num[i++]=ch;
        ch=getc(fp);
    }
    num[i]='\0';
    x=atoi(num);
    do
    {
        ch=getc(fp);
        if(isdigit(ch))
            break;
    }
    while(ch!=EOF);
    i=0;
    while(isdigit(ch))
    {
        num[i++]=ch;
        ch=getc(fp);
    }
    num[i]='\0';
    y=atoi(num);
    for(z=0; z<y; z++)
    {
        do
        {
            ch=getc(fp);
            if(isdigit(ch))
                break;
        }
        while(ch!=EOF);
        i=0;
        while(isdigit(ch))
        {
            num[i++]=ch;
            ch=getc(fp);
        }
        num[i]='\0';
        a[z]=atoi(num);
    }
    for(i=0; i<y; i++)
        trav(root,a,y);
    printf("\nOUTPUT:");
    traverse(root,x);
    fclose(fp);
    getch();
}

void trav(node *root,int a[10],int y)
{
    int i;
    if(root==NULL)
        return;
    trav(root->next,a,y);
    if(root->child==NULL)
    {
        for(i=0; i<y; i++)
            add_child(root,a[i],root->sum,root->str);
        return;
    }
    trav(root->child,a,y);
}

void traverse(node *root,int x)
{
    if(root==NULL)
        return;
    traverse(root->next,x);
    if(root->sum==x)
        printf("\n%.*s",strlen(root->str)-1,root->str);
    traverse(root->child,x);
}

node * new_node(int data,int s,char st[10])
{
    node *new_node = malloc(sizeof(node));
    if ( new_node )
    {
        new_node->next=NULL;
        new_node->child = NULL;
        new_node->data = data;
        new_node->sum = data+s;
        strcpy(new_node->str,"");

        if(new_node->data!=0)
        {
            itoa(new_node->data,new_node->str,20);
            strcat(new_node->str,"+");
            strcat(new_node->str,st);
        }
    }
    return new_node;
}

node * add_sibling(node * n, int data,int s,char st[20])
{
    if ( n == NULL )
        return NULL;
    while (n->next)
        n = n->next;
    return (n->next = new_node(data,s,st));
}

node * add_child(node * n, int data,int s,char st[20])
{
    if ( n == NULL )
        return NULL;
    if ( n->child )
        return add_sibling(n->child, data,s,st);
    else
        return (n->child = new_node(data,s,st));
}
