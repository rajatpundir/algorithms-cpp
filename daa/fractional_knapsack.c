#include <stdio.h>
#include "commons.h"
typedef struct item
{
	int w; // w is the weight of item
	int v; // v is the value of item
	float p; // p is the value per pound
}item;
int main()
{
	int i,j,n=0;
	float value = 0,sum =0 ,weight;
	item items[100],temp;
	FILE *fp = fopen("fractional_knapsack_input.txt","r");
	n = dignum(fp); // n is the no. of items
	weight = dignum(fp); // weight is the weight of knapsack
	printf("No. of items= %d \nWeight of Knapsack= %f\n",n,weight);
	for (i = 0; i < n; i++)
	{
		items[i].w = dignum(fp);
		items[i].v = dignum(fp);
		items[i].p = items[i].v/items[i].w;
	}
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1-i; j++)
		{
			if(items[j].p < items[j+1].p)
			{
				temp.w = items[j].w;
				temp.v = items[j].v;
				temp.p = items[j].p;
				items[j].w = items[j+1].w;
				items[j].v = items[j+1].v;
				items[j].p = items[j+1].p;
				items[j+1].w = temp.w;
				items[j+1].v = temp.v;
				items[j+1].p = temp.p;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if((sum+items[i].w) <= weight)
			{
				sum += items[i].w;
				value += items[i].v;
				if (sum == weight)
					break;
			}
		else
		{
			value += (weight-sum)*items[i].p;
			break;
		}

	}
	printf("\nValue of Knapsack=%f\n", value);
	return 0;
}