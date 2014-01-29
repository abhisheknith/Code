#include<stdio.h>
#define max(a,b) a>b?a:b

int main()
{
	static int N,price[30],temp,mem[30];
	int i=0,G,temp_wt,temp_pr;
	printf("Enter the number of objects :");
	scanf("%d",&N);
	while(i<N)
	{
		scanf("%d%d",&temp_pr,&temp_wt);
		price[temp_wt-1]=max(temp_pr,price[temp_wt-1]);
		i++;
	}
	printf("Enter the number of people in group :\n");
	scanf("%d",&G);
	int arr[G],j;
	for(i=0;i<G;i++)
	{
		scanf("%d",&arr[i]);
	}
	mem[0]=price[0];
	mem[1]=max(mem[0],price[1]);
	for(i=2;i<30;i++)
	{
		mem[i]=max(mem[i-1],price[i]);
		for(j=0;j<=(i-1)/2;j++)
			mem[i]=max(price[i-j-1]+mem[j],mem[i]);
	}
	for(i=0;i<30;i++)
		printf("%d   %d    %d\n",i+1,mem[i],price[i]);
	printf("\n");
	int value=0;
	for(i=0;i<G;i++)
	{
		temp_wt=arr[i]-1;
		printf("%d\t ",arr[i]);
		value+=mem[temp_wt];
		printf("%d\t ",value);
	}
	printf("\nMaximum Price = %d\n",value);
	return 0;
}
