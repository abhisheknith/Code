#include<stdio.h>

int main()
{
	int arr[10],sum=0,SUM,i,j;
	printf("Enter the array : \n");
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	SUM=arr[0];
	printf("\n");
	for(i=0;i<10;i++)
	{
		sum=sum+arr[i];
		if(sum<1)
			sum=0;
		else if(SUM<sum)
			SUM=sum;
	}
	printf("%d\n",SUM);
}
