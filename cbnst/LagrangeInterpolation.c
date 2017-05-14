#include<stdio.h>
void main()
{
    int i,j,n;
    float D[10][2],x,y,z,s;

    //Input no. of terms and values of x and y
    printf("\nEnter no. of terms -> ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nx%d=",i);
        scanf("%f",&D[i][0]);
    }
    for(i=0; i<n; i++)
    {
        printf("\ny%d=",i);
        scanf("%f",&D[i][1]);
    }

    //Printing Table
    printf("\nTable for x and y:\n");
    for(i=0; i<n; i++)
    {
        printf("\n");
        for(j=0; j<2; j++)
            printf("\t%g",D[i][j]);
    }

    //Lagrange Interpolation
    while(1)
    {
        printf("\n\nEnter the value of x for which you want value of y -> ");
        scanf("%f",&x);
        s=0;
        for(i=0; i<n; i++)
        {
            z=1;
            for(j=0; j<n; j++)
            {
                if(i!=j)
                {
                    z*=((x-D[j][0])/(D[i][0]-D[j][0]));
                }
            }
            s+=z*D[i][1];
        }
        printf("\nValue of y at x=%g is %g\n",x,s);

    }

}
