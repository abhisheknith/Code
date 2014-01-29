#include<stdio.h>

int binsearch(int x,int arr[],int n)
{
	int low,high,mid;
	low=0;
	high=n-1;
	mid=(high+low)/2;
	while(low<=high && arr[mid]!=x)
	{
		if(x<arr[mid])
			high=mid-1;
		else
			low=mid+1;
		mid=(high+low)/2;
	}
	if(x==arr[mid])
		return mid;
	else
		return -1;
}

int main()
{
	int arr[10],num,i;
	printf("Enter the array :\n");
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	printf("Enter the number :");
	scanf("%d",&num);
	printf("%d\n",binsearch(num,arr,i));
}
