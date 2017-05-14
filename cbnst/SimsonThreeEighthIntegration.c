#include<stdio.h>
#include<math.h>
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
    printf("\nh=%f\n",h);

    //Building Table
    for(i=0;i<=n;i++)
    {
               D[i][0]=a+i*h;
               D[i][1]=f(D[i][0]);
    }

    //Printing Table
    printf("\nTable for x and y:\n");
    for(i=0; i<=n; i++)
    {
        printf("\n");
        for(j=0; j<2; j++)
            printf("\t%f",D[i][j]);
    }

    //Simson Three-Eighth Integration
    for(i=0;i<n-2;i+=3)
        I+=3*h/8*(D[i][1]+3*D[i+1][1]+3*D[i+2][1]+D[i+3][1]);
    printf("\n\nNumerically Integrated Value=%g\n",I);

}
