#include<stdio.h>

int calc_gcd(int x,int y)
{
	if(0==y)
		return x;
	else
		return calc_gcd(y,x%y);
}

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int gcd;
	gcd=calc_gcd(x,y);
	printf("%d\n",gcd);
	return 0;
}
