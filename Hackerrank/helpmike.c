#include<stdio.h>

int main()
{
	int t,n,k,tmp1,tmp2;
	long long int count,total;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		total=count=0;
		for(tmp1=1;tmp1<=k;tmp1++)
		{
			tmp2=k-tmp1;
			while(tmp2<=tmp1)
				tmp2=k+tmp2;
			if(tmp2>n)
				continue;
			count+=(((n-tmp2)/k)+1);
		}
		total=((n/k)*(count%k+count))/2;
		if((n+1)%k==0)
			total=((n/k)*(count+k))/2+1;
		printf("%lld\n",total);
	}
	return 0;
}
