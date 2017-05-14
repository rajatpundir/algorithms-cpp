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


    //Trapezoidal Integration
    for(i=0; i<n; i++)
        I+=h/2*(D[i][1]+D[i+1][1]);
    printf("\n\nNumerically Integrated Value=%g\n",I);

}
