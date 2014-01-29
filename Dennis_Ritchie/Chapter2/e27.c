#include<stdio.h>

int invert(int x,int p,int n)
{
	return ((x>>(p+n-1))<<(n+p-1))|((((1<<n)-1)<<p-1)^x)|(((1<<p-1)-1)&x);
}

int main()
{
	printf("%d",invert(8,1,5));
}
