#include<stdio.h>

int setbits(int x,int p,int n,int y)
{
	return ((x>>(p+n-1))<<(n+p-1))|((((1<<n)-1)&y)<<p-1)|(((1<<p-1)-1)&x);
}

int main()
{
	printf("%d",setbits(127,1,3,4));
}
