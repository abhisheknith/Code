#include<stdio.h>

void mergesort(int arr[],int low,int high)
{
	
}

int merge(int arr[],int low,int high)
{
	
}

int main()
{
	int size;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	int arr[size],i,j;
	printf("Enter the array :\n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,0,size-1);
