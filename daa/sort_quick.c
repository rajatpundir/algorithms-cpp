#include <stdio.h>
#include "commons.h"
void sort_quick(int[],int,int);
int main()
{
	int i,n,arr[100];
	FILE *fp = fopen("sort_input.txt","r");
	n = dignum(fp); // n is the no. of items in the array to be sorted
	for (i = 0; i < n; i++)
	arr[i] = dignum(fp);
	sort_quick(arr,0,n-1);
	for (i = 0; i < n; i++)
	printf("-%d-\n",arr[i]);
	return 0;
}