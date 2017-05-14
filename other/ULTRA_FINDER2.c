#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char str[70];
} sr;
void highlight(char[],char[]);
int probability(char[],char[],sr[],char[]);
int failsafe(sr[],int,char[],char[]);
int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++)
    {
        int d = tolower(*a) - tolower(*b);
        if (d != 0 || !*a)
            return d;
    }
}
void main()
{
    FILE *fp;
    char word[60],spd[1000],alt[1000],oop[1000],file[100],ch;
    int i,k=0,n,c=0,f=0,q=0,z=0;
    sr ss[1000],rr[100];
    system("CHCP 1252");
    puts("\nInput file name:");
    gets(file);
    fp=fopen(file,"r");
    ch=getc(fp);
    do
    {
        i=0;
        while(isalpha(ch)||isdigit(ch)||(ch>=-65&&ch<=-10))
        {
            word[i++]=ch;
            if(f==0&&isdigit(ch))
            {
                f=1;
                n=ch-48;
            }
            if(c==1)
            {
                q++;
                c=0;
            }
            ch=getc(fp);
        }
        word[i]='\0';
        if(q>n)
            strcpy(rr[z++].str,word);
        else if(q>0)
            strcpy(ss[k++].str,word);
        while(1)
        {
            if(ch=='\n')
                c=1;
            if(isalpha(ch)||isdigit(ch)||ch==EOF)
                break;
            ch=getc(fp);
        }
    }
    while(ch!=EOF);
    for(i=0; i<k; i++)
    {
        ch=ss[i].str[0];
        if(ch>=65&&ch<=90)
            spd[i]=ss[i].str[0];
        else
            spd[i]=' ';
    }
    spd[i]='\0';
    for(i=0; i<z; i++)
    {
        printf("\n");
        strcpy(oop,spd);
        strcpy(alt,oop);
        highlight(oop,rr[i].str);
        if(probability(oop,alt,ss,rr[i].str))
        {
            if(failsafe(ss,k,alt,rr[i].str))
                printf("NOT FOUND");
        }
    }
    fclose(fp);
    getch();
}
void highlight(char spd[1000],char word[60])
{
    int i,j,l,k;
    l=strlen(spd);
    k=strlen(word);
    for(i=0; i<k; i++)
    {
        for(j=0; j<l; j++)
        {
            if((word[i]==spd[j])&&spd[j]!=' ')
                spd[j]='0';
        }
    }
}
int probability(char spd[1000],char alt[1000],sr ss[1000],char word[60])
{
    int a=0,b=0,s=0,c=0,max=0,x=0,y=0,l,i,j,k,m,d,n,h,q,flag=1;
    char new[1000];
    l=strlen(spd);
    k=strlen(word);
    for(i=0; i<l; i++)
    {
        if(spd[i]=='0')
        {
            if(ss[i].str[0]==word[0])
                spd[i]='1';
            else if(ss[i].str[0]==word[k-1])
                spd[i]='2';
        }
        if((isdigit(spd[i])==0)&&spd[i]!=' ')
            spd[i]='#';
    }
    for(i=0; i<l; i++)
    {
        if(spd[i]=='1')
        {
            s=0;
            d=1;
            a=i;
            m=a;
            for(; spd[i]!='#'; i++)
            {
                if((spd[i]=='1')&&(m==a))
                    m=i;
                if(spd[i]==' ')
                    s++;
                else
                    d++;
                if(d>k)
                {
                    i++;
                    break;
                }
            }
            b=i;
            strcpy(new,alt);
            for(n=0,h=0; n<k; n++)
            {
                for(j=a; j<b; j++)
                {
                    if(word[n]==new[j])
                    {
                        h++;
                        new[j]='$';
                        break;
                    }
                }
            }
            if(h==k&&s<k)
            {
                flag=0;
                if(h>max)
                {
                    max=h;
                    x=a;
                    y=b;
                }
            }
            if(m==a)
                i--;
            else
                i=m-1;
        }
    }
    if(flag)
        return 1;
    for(i=x; i<y; i++)
        printf("%s ",ss[i].str);
    return 0;
}
int failsafe(sr ss[1000],int l,char alt[1000],char word[60])
{
    int i,j,f,loc=-1,max=0,z,s;
    for(i=0; i<l; i++)
    {
        f=0;
        if(stricmp(ss[i].str,word)==0)
            z=i;
    }
    for(i=1; i<strlen(word); i++)
    {
        if(word[i]>=65&&word[i]<=90)
            word[i]+=32;
    }
    for(i=0; i<l; i++)
    {
        f=0;
        for(j=0; j<strlen(ss[i].str); j++)
        {
            if(ss[i].str[j]==word[j])
                f++;
            else
                break;
        }
        if((f>max)&&(f<strlen(word)))
            max=f;
    }
    for(i=0; i<l; i++)
    {
        f=0;
        for(j=0; j<strlen(ss[i].str); j++)
        {
            if(ss[i].str[j]==word[j])
                f++;
            else
                break;
        }
        if(f==max)
        {
            alt[i]='0';
            s=i;
        }
    }
    for(i=0; i<strlen(alt); i++)
    {
        if((alt[i]=='0')&&(abs(z-i)<s))
        {
            s=z-i;
            loc=i;
        }
    }
    if(loc==-1)
        return 1;
    if(loc>z)
    {
        for(i=loc;; i++)
        {
            if(alt[i]==' ')
                break;
            printf("%s ",ss[i].str);
        }
    }
    else
    {
        for(i=loc; i!=z; i++)
        {
            if(alt[i]==' ')
                break;
            printf("%s ",ss[i].str);
        }
    }
    return 0;
}
