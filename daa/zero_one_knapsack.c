#include <stdio.h>
int max(int a, int b)
{
	return (a>b)?a:b;
}
int knapsack(int W, int wt, int val[], int n)
{
	int i, w, K[n+1[W+1];
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if(i==0 || w==0)
				K[i][w] = 0;
			else if (wt[i-1] <= w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
	return K[n][W];
}
int main()
{
	int i, n, val[20], wt[20], W;
	printf("Enter no. of items: ");
	scanf("%d",&n);
	printf("Enter value and weights of items: \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d%d",&val[i],&wt[i]);
	}
	printf("\nEnter the size of knapsack: ");
	scanf("%d",&W);
	printf("%d", knapsack(W,wt,val,n));
	return 0;
}