#include<stdio.h>
int main()
{
	int n,q,m,k,i;
	char str[6];
	scanf("%d",&n);
	int bal[n];
	bzero((void *)bal,n*sizeof(int));
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",str);
		if(str[0]=='A')
		{
			scanf("%d",&k);
			printf("%d",bal[k-1]);
		}
		else
		{
			scanf("%d%d",&k,&m);
			i=k;
			while(i<n)
			{
				bal[i-1]+=m;
				i+=k;
			}
		}
	}
	return 0;
}
