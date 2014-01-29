#include<stdio.h>
int main()
{
	long int n,i,j,count;
	int testcases,k;

	scanf("%d",&testcases);

	while(testcases)
	{
		scanf("%ld%d",&n,&k);
		count=0;

		for(i=1;i<n;i++)
		{
			count+=(((n+i)/k)-((2*i)/k));
		}
		printf("%ld\n",count);
		testcases--;
	}
	return 0;
}
