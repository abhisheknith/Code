#include<stdio.h>

int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m=n-n%3;
		while((n-m)%5!=0 && m>=0)
		{
			m-=3;
		}
		if(m<0)
			printf("-1");
		else
			for(;n>0;n--)
				if(m-->0)	printf("5");
				else		printf("3");
		printf("\n");
	}
	return 0;
}
