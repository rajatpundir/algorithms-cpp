#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
    return(x*x*x-2*x*x-5);
}
void main()
{
    float a=0,b=0,c=0,t=0;
    int i,j;
    printf("\nEnter values ");
    printf("\na=");
    scanf("%f",&a);
    printf("\nb=");
    scanf("%f",&b);
    while(f(a)*f(b)>0)
    {
        printf("\nTry again \n");
        printf("\na=");
        scanf("%f",&a);
        printf("\nb=");
        scanf("%f",&b);
    }
    if(f(a)==0)
        printf("\nroot=%f",a);
    else if(f(b)==0)
        printf("\nroot=%f",b);
    else
    {
        printf("\nMax no. of iterations allowed=");
        scanf("%d",&i);
        printf("\nTolerance=");
        scanf("%f",&t);
        j=i;
        do
        {
            c=(a+b)/2;
            if(f(a)*f(c)<0)
                b=c;
            else
                a=c;
            printf("\nx%d=%g",j-i,c);
        }
        while(((--i)!=0)&&(fabs(a-b)>t));
    }
    getch();
}
