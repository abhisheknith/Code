#include<stdio.h>
void swap(int *a,int *b) 
{
	*a=*a^*b,*b=*a^*b,*a=*a^*b;
}
void quick_sort(int arr[],int low,int high)
{
	if(low>=high)
		return;
	int pivot=arr[low];
	int i=low,j=high;
	while(i<j)
	{
		while(arr[j]>pivot)
			j--;
		while(arr[i]<=pivot)
			i++;
		if(i<j)
			swap(&arr[i],&arr[j]);
	}
	arr[low]=arr[j];
	arr[j]=pivot;
	quick_sort(arr,low,j-1);
	quick_sort(arr,j+1,high);
}

int main()
{
	int size;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	int arr[size],i;
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	quick_sort(arr,0,size-1);
	for(i=0;i<size;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}
