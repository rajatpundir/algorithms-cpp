#include<stdio.h>
#define MAX 10
int w[MAX][MAX], d[MAX][MAX][MAX];
void floyd(int v)
{
	int k=0, i ,j;
	for (i = 1; i <= v; i++)
	{
		for (j = 1; j <= v; j++)
		{
			d[k][i][j] = w[i][j];
		}
	}
	for (k = 1; i <= v; k++)
	{
		for (i = 1; i <= v; i++)
		{
			for (j = 1; j <= v; j++)
			{
				d[k][i][j] = min(d[k-1][i][j],d[k-1][i][k]+d[k-1][k][j]);
			}
		}
	}
}
int min(int a, int b)
{
	if(a <= b)
		return a;
	else
		return b;
}
void main()
{
	int i, j, k, v;
	printf("Enter the no. of vertices: ");
	scanf("%d",&v);
	printf("\nEnter the weights: ");
	for (i = 1; i <= v; i++)
	{
		for (j = 1; j <= v; j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	floyd(v);
	return 0;
}