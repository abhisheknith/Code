#include<stdio.h>

long long int gcd(long long int x,long long int y)
{
        if(0==y)
                return x;
        else
                return gcd(y,x%y);
}

int main()
{
	long long int t,n,u,l,count,tmp,g;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		l=2;
		u=n;
		count=n;
		while(u>=l)
		{
			tmp=n/l;
			count+=tmp;
			count+=(u-tmp)*(l-1);
			u=tmp;
			l++;
		}
		if(n==2){printf("3/4\n"); continue;}
		if(u==l-2) count-=u;
		g=gcd(count,n*n);
		printf("%lld/%lld\n",count/g,n*n/g);
	}
	return 0;
}
