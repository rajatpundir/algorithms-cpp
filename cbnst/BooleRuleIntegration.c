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
    scanf("%f",&b);
    printf("\nEnter upper limit -> ");
    scanf("%f",&a);
    printf("\nEnter no. of intervals -> ");
    scanf("%d",&n);
    h=(a-b)/n;
    printf("\nh=%g\n",h);

    //Building Table
    for(i=0; i<=n; i++)
    {
        D[i][0]=b+i*h;
        D[i][1]=f(D[i][0]);
    }

    //Printing Table
    printf("\nTable for x and y:\n");
    for(i=0; i<=n; i++)
    {
        printf("\n");
        for(j=0; j<2; j++)
            printf("\t%g",D[i][j]);
    }

    //Boole Integration
    for(i=0; i<n-3; i+=4)
        I+=2*h/45*(7*D[i][1]+32*D[i+1][1]+12*D[i+2][1]+32*D[i+3][1]+7*D[i+4][1]);
    printf("\n\nNumerically Integrated Value=%g\n",I);

}

