#include <stdio.h>
#include "commons.h"
int main()
{
	int i,n,arr[100];
	FILE *fp = fopen("sort_input.txt","r");
	n = dignum(fp); // n is the no. of items in the array to be sorted
	for (i = 0; i < n; i++)
	arr[i] = dignum(fp);
	sort_insertion(arr,n);
	for (i = 0; i < n; i++)
	printf("-%d-\n",arr[i]);
	return 0;
}