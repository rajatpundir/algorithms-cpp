#include<stdio.h>
void main()
{
    int i,j,n;
    float D[10][10],u,u1,x,y,h,k,a;

    //Input no. of terms and values of x and y
    printf("\nEnter no. of terms -> ");
    scanf("%d",&n);
    printf("\nx0=");
    scanf("%f",&D[0][0]);
    a=D[0][0];
    printf("\nx1=");
    scanf("%f",&D[1][0]);
    h=D[1][0]-D[0][0];
    for(i=2; i<n; i++)
        D[i][0]=D[0][0]+h*i;
    for(i=0; i<n; i++)
    {
        printf("\ny%d=",i);
        scanf("%f",&D[i][1]);
    }

    //Difference Table Calculation
    for(j=2; j<=n; j++)
    {
        for(i=0; i<=n-j; i++)
            D[i][j]=D[i+1][j-1]-D[i][j-1];
    }
    printf("\nDifference Table:\n");
    for(i=0; i<n; i++)
    {
        printf("\n");
        for(j=0; j<n+1-i; j++)
            printf("\t%g",D[i][j]);
    }

    //Newton Forward Interpolation
    while(1)
    {
        printf("\n\nEnter the value of x for which you want value of y -> ");
        scanf("%f",&x);
        k=1;
        u=(x-a)/h;
        u1=u;
        y=D[0][1];
        for(i=2; i<=n; i++)
        {
            y+=(u1*(D[0][i]/k));
            u1*=(u-(i-1));
            k*=i;
        }
        printf("\nValue of y at x=%g is %g\n",x,y);

    }
    getch();

}

