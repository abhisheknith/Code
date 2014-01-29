#include<stdio.h>
void dutch_prob(int[],int);

int main()
{
	static int arr[10];
	int i;
	char ar[10];
	printf("Enter the array of 0 1 and 2 :\n");
	for(;i<10;i++)
		scanf("%[012]%*c",&ar[i]);
	for(i=0;i<10;i++)
		arr[i]=ar[i]-48;
	dutch_prob(arr,10);
	printf("\nArray is : ");
	for(i=0;i<10;i++)
		printf("%d   ",arr[i]);
}

void swap(int *i,int *j)
{
	int c;
	c=*i;
	*i=*j;
	*j=c;
}

void dutch_prob(int arr[],int len)
{
	int i,j,k;
	i=j=k=0;
	while(arr[j++]!=1);j--;
	while(arr[k++]!=2);k--;
	for(;i<len;i++)
	{
		if(arr[i]==0)
		{
			if(i>j && i>k)
			{
				swap(&arr[i],&arr[k]);
				swap(&arr[j++],&arr[k++]);
			}
			else if(i>j && i<k)
				swap(&arr[i],&arr[j++]);
			else if(i<j && i>k)
				swap(&arr[i],&arr[k++]);
		}
		if(arr[i]==1 && i>k)
		{
			swap(&arr[i],&arr[k]);
			if(j>k)
				j=k;
			k++;
		}
	}
}
