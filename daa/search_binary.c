#include <stdio.h>
#include "commons.h"
int search_binary(int[],int,int);
int main()
{
	int i,n,arr[100];
	FILE *fp = fopen("search_input.txt","r");
	n = dignum(fp); // n is the no. of items in the array to be sorted
	for (i = 0; i < n; i++)
	arr[i] = dignum(fp);
	puts("Element to search?");
	scanf("%d",&i);
	if(search_binary(arr,n,i))
		puts("Found!");
	else
		puts("Not Found!");
	return 0;
}