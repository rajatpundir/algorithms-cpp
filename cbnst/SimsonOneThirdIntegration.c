#include<stdio.h>
float f(float x)
{
    return(1/(1+x*x));
}
void main()
{
    int i,j,n;
    float D[20][2],I=0,a,b,h;

    printf("\nEnter lower limit -> ");
    scanf("%f",&a);
    printf("\nEnter upper limit -> ");
    scanf("%f",&b);
    printf("\nEnter no. of intervals -> ");
    scanf("%d",&n);
    h=(b-a)/n;
    printf("\nh=%g\n",h);

    for(i=0; i<=n; i++)
    {
        D[i][0]=a+i*h;
        D[i][1]=f(D[i][0]);
    }

    printf("\nTable for x and y:\n");
    for(i=0; i<=n; i++)
    {
        printf("\n");
        for(j=0; j<2; j++)
            printf("\t%g",D[i][j]);
    }

    for(i=0; i<n-1; i+=2)
        I+=h/3*(D[i][1]+4*D[i+1][1]+D[i+2][1]);
    printf("\n\nNumerically Integrated Value=%g\n",I);

}
