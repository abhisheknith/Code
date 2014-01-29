#include<stdio.h>
#define MAX 100
float fib(int n)
{
	if(n==0||n==1)
	{
		return 1;
	}
	return fib(n-1)+fib(n-2);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%.0f   ",fib(n-1));
	printf("\n");
	return 0;
}
