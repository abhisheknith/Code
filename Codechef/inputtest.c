#include<stdio.h>

int main()
{
	unsigned int n,k,count=0,num;
	scanf("%d%d",&n,&k);
	if(k>10000000 || n>10000000 || k<1 || n<1)
		return 0;
	for(;n>0;n--)
	{
		scanf("%d",&num);
		if(num>0 && num<1000000000 && num%k==0)
			count++;
	}
	printf("%d\n",count);
	return 0;
}
