#include<stdio.h>

int rightrot(int x,int n)
{
	return ((((1<<n)-1)&x)<<sizeof(x)*8-n)|((x>>n)&(1<<(sizeof(x)*8-n)-1));
}

int main()
{
	printf("%d",rightrot(-32,5));
}
