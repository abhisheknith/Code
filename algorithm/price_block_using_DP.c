#include<stdio.h>
#define MAX 100000
#define max(a,b) a>b?a:b
int mem[MAX];

int main()
{
	int size;
	do
	{
		printf("Enter the size of block :");
		scanf("%d",&size);
	}while(size>MAX);
	int arr[size],i,j;
//	for(i=0;i<size;i++)
//		arr[i]=i;
	printf("Enter the constraints :\n");
	printf("Size\t:\tPrice\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t:\t",i+1);
		scanf("%d",&arr[i]);
	}
	mem[0]=arr[0];
	for(i=1;i<size;i++)
	{
		mem[i]=arr[i];
		for(j=0;j<=i/2;j++)
			mem[i]=max(mem[i-j-1]+mem[j],mem[i]);
	}
	printf("\nMaximum Price = %d\n",mem[i-1]);
	return 0;
}
