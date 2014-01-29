#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	int *arr,sum=0,SUM,i,low=0,high=0,temp;
	arr=malloc(size*sizeof(int));
	printf("Enter the array : \n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	SUM=arr[0];
	printf("\n");
	for(i=0;i<size;i++)
	{
		sum=sum+arr[i];
		if(SUM<sum)
		{
			low=temp;
			high=i;
			SUM=sum;
		}
		if(sum<1)
		{
			temp=i;
			sum=0;
		}
	}
	for(i=low;i<=high;i++)
		printf("%d\t",arr[i]);
	printf("\n%d\n",SUM);
}
