#include<stdio.h>
#include<string.h>

unsigned long long int arr[100][100];

unsigned long long int comb(int n,int k)
{
	if(arr[n][k])
	{
		return arr[n][k];
	}
	if(k==1  || n-k==1)
		return n;
	if(n==k)
		return 1;
	return (arr[n][k]=comb(n-1,k-1)+comb(n-1,k));
}

int main()
{
	int n,k,t;
	scanf("%d",&t);
	bzero((void *)arr,100*100*sizeof(long long int));
	while(t--)
	{
		scanf("%d%d",&n,&k);
		printf("%llu\n",comb(n,k));
	}
	return 0;
}
