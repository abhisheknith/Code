#include<stdio.h>
#include<string.h>

unsigned long long int arr[80][80];

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
        int t;
        scanf("%d",&t);
        bzero((void *)arr,80*80*sizeof(long long int));
	while(t--)
	{
		int i=0;
		long long int n;
		scanf("%lld",&n);
		while(comb(i,i/2)<n)
			i++;
		printf("%d\n",i);
	}
	return 0;
}
