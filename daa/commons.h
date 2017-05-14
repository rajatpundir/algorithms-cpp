#ifndef commons
#define commons

#include <stdio.h>
#include <string.h>

int dignum(FILE *fp)
{
    char num[10],ch;
    int i;
    do
    {
        ch=getc(fp);
        if(isdigit(ch))
            break;
    }
    while(ch!=EOF);
    i=0;
    while(isdigit(ch))
    {
        num[i++]=ch;
        ch=getc(fp);
    }
    num[i]='\0';
    return(atoi(num));
}

// bubble sort
void sort_bubble(int arr[100], int n)
{
    int i,j,temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// selection sort
void sort_selection(int arr[100], int n)
{
    int i,j,min,temp;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// insertion sort
void sort_insertion(int arr[], int n)
{
    int i,j,temp;
    for (i = 1; i < n; i++)
    {
        j=i;
        while(j>0 && arr[j] < arr[j-1])
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

// quick sort
void sort_quick(int arr[],int low, int high)
{
    int i = low,j = high, key= arr[low],temp;
    if (low >= high)
    return;
    while(i < j)
    {
        while(arr[i] <= key)
        {
            i++;
        }
        while (arr[j] > key)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = key;
    sort_quick(arr,low,j-1);
    sort_quick(arr,j+1,high);
}

// merge sort
void merge(int arr[],int low, int mid, int high)
{
    int temp[100],i = low, j = mid +1, k=0;
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    if (i > mid)
    {
        while(j <= high)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    else
    {
        while(i <= mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
    }
    for (i = low, k = 0; i <= high; i++)
    {
        arr[i] = temp[k];
        k++;
    }
}
void sort_merge(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        sort_merge(arr,low,mid);
        sort_merge(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

// linear search
int search_linear(int arr[], int n, int i)
{
    int j;
    for (j = 0; j < n; j++)
    {
        if(arr[j]==i)
            return 1;
    }
    return 0;
}

// binary search
int search_binary(int arr[], int n ,int i)
{
    int low = 0, high = n-1, mid = n/2, check = 0;
    sort_quick(arr,0,n-1);
    while(low <= high)
    {
        if(arr[mid] == i)
        {
            check = 1;
            break;
        }
        else
        {
            if (arr[mid] < i)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            mid = (low + high)/2;
        }
    }
    return(check);
}

#endif