#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>

typedef struct tree //user-defined complex data type for a Binary Search Tree
{
    char info[500]; //string field info containing quartet
    int freq; //integer field freq contains frequency of quartet
    struct tree *left; //pointer to left child of tree
    struct tree *right; //pointer to left child of tree
} tr;
void tinsert(tr*, tr*); //initialisation of tinsert func.
tr * create(char[]); //initialisation of create func.
void traverse(tr *, int *); //initialisation of traverse func.
void tdisplay(tr *, int); //initialisation of tdisplay func.

typedef struct queue //user-defined complex data type for a Queue
{
    char info[50]; //string field info containing single word
    struct queue *next; //pointer to another node in queue
} nd;
nd* qinsert(nd *, char[]); //initialisation of tinsert func.
nd* qserve(nd *); //initialisation of qserve func.
void qdisplay(nd *); //initialisation of qdisplay func.
void stitch(nd *, char[]); //initialisation of stitch func.

typedef struct node {
    char str[100];
    struct node *next;
} q;
void pop();
void push1();
void push2();
void display();
void printdir(char*, int);
void mains(char[]);
q *top = NULL, *top2 = NULL;
_TCHAR g_szDrvMsg[] = _T("A:\n");
char stirr[300], filename[30];
int flag = 1;

int main(int argc, char* argv[]) {
    FILE *fp;
    int i = 0;
    char ch, str[10], s[20], tmp;
    static char ww[256] = "";
    if (flag == 1) {
        printf("Enter the file name to be searched : ");
        scanf("%s", filename);
        ULONG uDriveMask = _getdrives();
        if (uDriveMask == 0)
            printf("_getdrives() failed with failure code: %d\n", GetLastError());
        else {
            printf("Drives:");
            while (uDriveMask) {
                if (uDriveMask & 1)
                    printf("%s", g_szDrvMsg);
                ++g_szDrvMsg[0];
                uDriveMask >>= 1;
                printf("\n");
            }

        }
        printf("Enter the drive letter to be searched\n ");
        scanf("%s", ww);
        toupper(ww);
        strcat(ww, ":\\");
        puts("Searching...");
        if (strcmp("\\:\\", ww) == 0)
            printdir("\\", 0);
        else
            printdir(ww, 0);
    }
    printf("file address: \n");
    display();
    strcat(ww, stirr);
    for (i = 3; ww[i] != '\0'; i++)
        ww[i] = ww[i + 1];
    puts(ww);
    mains(ww);
    exit(0);
}

void mains(char file[256]) {
    FILE *fp; //file pointer fp
    char word[50], str[500], ch; //intialisations of char data types
    nd *front = NULL, *rear = NULL; // intialiastion of queue front and rear pointers
    tr *root = NULL, *p = NULL; //intialiastion of tree root and node pointers
    int i, n; //intialisations of integer data types
    //  puts("\nInput file name\n");
    //  gets(file); //file contains name of file
    fp = fopen(file, "r"); //fp is attached to file
    ch = tolower(getc(fp)); //character is fetched from file
    printf("\nRequired Length: ");
    scanf("%d", &n); //n is length of quartet
    do {
        i = 0;
        while (isalnum(ch)) //isalnum() returns true if ch is alphabet or digit
        {
            if (ch >= 65 && ch <= 90) //character conversion to lowercase
                ch += 32;
            word[i++] = ch; //concatenation of character to string word
            ch = getc(fp); //fetching of next character
        }
        word[i] = '\0'; //adding null character for string completeion
        rear = qinsert(rear, word); //inserting word at rear end of queue
        if (front == NULL) //incrementing front if it was null after word insertion
            front = rear;
        if (qlength(front) == n) //condition if queue length satisfies input length
        {
            stitch(front, str); //words in queue are stitched together to make a group
            p = create(str); //a node of tree type is created with group info
            if (root == NULL) //root of BST is updated if it was null
                root = p;
            else
                tinsert(root, p); //node with group info is inserted into BST
            front = qserve(front); //a word is served from the front of queue
        }
        if (ch != ' ' && front != NULL) //queue is emptied for specific cases
        {
            rear = NULL;
            while (front != NULL)
                front = qserve(front);
        }

        while (1) //file pointer moves forward until next letter or digit is found
        {
            if (isalnum(ch) || ch == EOF)
                break;
            ch = getc(fp);
        }

    }    while (ch != EOF); //do while loop is terminated when file pointer reaches end of file
    fclose(fp); //file is closed
    i = 0;
    traverse(root, &i); //BST is traversed to find max frequency
    printf("\n\nHIGHEST OCCURENCE=%d\n", i);
    tdisplay(root, i); //nodes with highest frequency in BST are displayed
    getch();
}

void traverse(tr *root, int *j) //function to traverse BST to find highest frequency
{
    if (root == NULL)
        return;
    traverse(root->left, j);
    if ((root->freq)>(*j))
        *j = root->freq;
    traverse(root->right, j);
}

void tdisplay(tr *root, int f) //function to display nodes with highest frequency
{
    if (root == NULL)
        return;
    tdisplay(root->left, f);
    if ((root->freq) == f)
        puts(root->info);
    tdisplay(root->right, f);
}

int qlength(nd *front) //function to return length of queue
{
    int l = 0;
    while (front != NULL) {
        front = front->next;
        l++;
    }
    return (l);
}

void stitch(nd *front, char s[50]) //function to stitch together words and make a group
{
    strcpy(s, "");
    do {
        strcat(s, front->info);
        strcat(s, " ");
        front = front->next;
    }    while (front != NULL);
}

nd * qinsert(nd *rear, char s[10]) ////function to insert word at rear end of queue
{
    nd *p = (nd*) malloc(sizeof (nd));
    if (p == NULL)
        printf("\nMemory Not Available\n");
    else {
        strcpy(p->info, s);
        p->next = NULL;
        if (rear != NULL)
            rear->next = p;
        rear = p;
    }
    return (rear);
}

nd * qserve(nd *front) //function to delete a word from front end of queue
{
    nd *p;
    if (front == NULL)
        printf("\nQueue is empty\n");
    else {
        p = front;
        front = front->next;
        free(p);
    }
    return (front);
}

tr * create(char s[500]) //function to create a node of tree type with info as group of words
{
    tr *p = (tr *) malloc(sizeof (tr));
    p->right = NULL;
    p->left = NULL;
    strcpy(p->info, s);
    p->freq = 1;
    return p;
}

void tinsert(tr *node, tr *p) //function to insert a node in Binary Search Tree
{
    if (strcmp(p->info, node->info) == 0) {
        node->freq += 1;
        free(p);
        return;
    } else if (strcmp(p->info, node->info) > 0) {

        if (node->right == NULL) {
            node->right = p;
            return;
        }
        tinsert(node->right, p);

    } else {
        if (node->left == NULL) {
            node->left = p;
            return;
        }
        tinsert(node->left, p);
    }
}

void push(char a[]) {
    q *p;
    p = (q*) malloc(sizeof (q));
    if (p == NULL) {
        printf("MEMORY PROB");
        return;
    }
    p->next = top;
    top = p;
    strcpy(p->str, a);
}

void push2(char a[]) {
    q *p;
    p = (q*) malloc(sizeof (q));
    if (p == NULL) {
        printf("Memory Not Enough");
        return;
    }
    p->next = top2;
    top2 = p;
    strcpy(p->str, a);
}

void display() {
    char s[256] = "";
    q *p;
    p = top;
    while (p != NULL) {
        push2(p->str);
        p = p->next;
    }
    p = top2;
    while (p != NULL) {
        strcat(stirr, "\\");
        strcat(stirr, p->str);
        p = p->next;
    }
}

void pop() {
    q *p;
    p = top;
    top = top->next;
    free(p);
}

void printdir(char *dir, int depth) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if ((dp = opendir(dir)) == NULL) {
        pop();
        return;
    }
    chdir(dir);
    while (((entry = readdir(dp)) != NULL)) {
        stat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
                continue;

            if (dp != NULL)
                push(entry->d_name);
            printdir(entry->d_name, depth + 4);
        } else {
            if (strcmp(filename, entry->d_name) == 0) {
                printf("file found\n\n");
                push(entry->d_name);
                flag = 0;
                main(0, 0);
            }
        }
    }
    if (top != NULL)
        pop();
    chdir("..");
    closedir(dp);
}
