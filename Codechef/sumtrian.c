#include<stdio.h>
#define max(x,y) (( (x) > (y) ) ? (x) : (y) )

int main()
{
	unsigned short int t,n,i,j;
	scanf("%hd",&t);
	while(t--)
	{
		scanf("%hd",&n);
		unsigned short int k,a[n],b[n],arr[n],*cur,*old,sum=0;
		cur=a;
		old=b;
		b[0]=0;
		for(i=0;i<n;i++)
		{
			k=0;
			for(j=0;j<=i;j++)
				scanf("%hd",&arr[j]);
			cur[0]=arr[k++]+old[0];
			j=1;
			while(j<i)
			{
				cur[j]=arr[k++]+max(old[j-1],old[j]);
				j++;
			}
			if(i)
				cur[j]=arr[k++]+old[j-1];
			if(cur==a)
			{
				cur=b;
				old=a;
			}
			else
			{
				cur=a;
				old=b;
			}
		}
		for(i=0;i<n;i++)
			sum=max(sum,old[i]);
		printf("%hd\n",sum);
	}
	return 0;
}
