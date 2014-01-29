#include<stdio.h>
void swap(int *a,int *b) 
{
	*a=*a^*b,*b=*a^*b,*a=*a^*b;
}
void quick_sort(int arr[],int arr1[],int low,int high)
{
	if(low>=high)
		return;
	int pivot=arr[low];
	int pivot1=arr1[low];
	int i=low,j=high;
	while(i<j)
	{
		while(arr[j]>pivot)
			j--;
		while(arr[i]<=pivot)
			i++;
		if(i<j)
		{
			swap(&arr[i],&arr[j]);
			swap(&arr1[i],&arr1[j]);
		}
	}
	arr[low]=arr[j];
	arr[j]=pivot;
	arr1[low]=arr1[j];
	arr1[j]=pivot1;
	quick_sort(arr,arr1,low,j-1);
	quick_sort(arr,arr1,j+1,high);
}

int main()
{
	int size;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	int arr[size],arr1[size],i;
	for(i=0;i<size;i++)
	{
		arr1[i]=i+1;
		arr[i]=size-i;
	}
	quick_sort(arr,arr1,0,size-1);
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr1[i]);
	}
	printf("\n");
	return 0;
}
