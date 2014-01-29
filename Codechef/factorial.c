#include<stdio.h>

int main()
{
	unsigned int t,n,z,i;
	scanf("%d",&t);
	if(t>100000 || t<1)
		return 0;
	for(;t>0;t--)
	{
		z=0;
		i=5;
		scanf("%d",&n);
		if( n>0 && n<=1000000000)
		{
			while(n/i>0)
			{
				z+=n/i;
				i*=5;
			}
			printf("%d\n",z);
		}
	}
	return 0;
}
