#include<stdio.h>
#define MAX 100
static float fib_mem[MAX];
float fib(int n)
{
	if(n==0||n==1)
	{
		fib_mem[n]=1;
		return 1;
	}
	if(fib_mem[n])
	{
		return fib_mem[n];
	}
	else
	{
		return fib_mem[n]=fib(n-1)+fib(n-2);
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	fib(n-1);
	for(i=0;i<n;i++)
		printf("%.0f   ",fib_mem[i]);
	printf("\n");
	return 0;
}
