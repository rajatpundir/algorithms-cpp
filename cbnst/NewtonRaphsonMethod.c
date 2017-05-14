#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
    return(x*x*x*x-x*x-x+1);
}
float df(float x)
{
    return(3*x*x*x-2*x-x);
}
void main()
{
    float xn,xn1,a,b,t;
    int i,n,j;
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
        scanf("%d",&n);
        printf("\nTolerance=");
        scanf("%f",&t);
        xn1=(a+b)/2;
        j=i;
        do
        {
            xn=xn1;
            printf("\nx%d=%g",j-i,xn);
            xn1=xn-(f(xn)/df(xn));

        }
        while(((--i)!=0)&&(fabs(xn1-xn)>t));
    }
    getch();
}
