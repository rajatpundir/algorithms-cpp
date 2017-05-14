#include<stdio.h>
void main()
{
    int a[100],b[100],bp=0,c[100],d,i,j,k,l,n,z,lr,loc,incheck,check;
    puts("Input set size:");
    scanf("%d",&d);
    puts("Input number of elements:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        puts("Input element");
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        if(bp<d)
        {
            check=0;
            for(j=0; j<bp; j++)
            {
                if(a[i]==b[j])
                {
                    check=1;
                    break;
                }
            }
            if(check)
            {
                printf("\nEmpty&Hit=%d",a[i]);
            }
            else
            {
                printf("\nEmpty&Miss=%d",a[i]);
                b[bp]=a[i];
                bp++;
            }
        }
        else
        {
            check=0;
            for(j=0; j<d; j++)
            {
                if(a[i]==b[j])
                {
                    check=1;
                    break;
                }
            }
            if(check)
            {
                printf("\nHit=%d",a[i]);
            }
            else
            {
                puts("\nMiss");
                for(k=0; k<d; k++)
                {
                    check=1;
                    for(z=i+1; z<n; z++)
                    {
                        if(b[k]==a[z])
                        {
                            c[k]=z;
                            check=0;
                            break;
                        }
                    }
                    if(check)
                        c[k]=-1;
                }
                lr=c[0];
                loc=0;
                for(l=0; l<d; l++)
                {
                    if(c[l]>lr)
                    {
                        lr=c[l];
                        loc=l;
                    }
                }
                b[loc]=a[i];
                for(l=0; l<d; l++)
                    printf("%d ",b[l]);
                puts("");
            }
        }
    }
}