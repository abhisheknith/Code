#include<stdio.h>

int main()
{
	short int t,m,n,k;
	scanf("%hd",&t);
	while(t--)
	{
		scanf("%hd%hd%hd",&m,&n,&k);
		if((m==1 || n==1) &&(m==2 || n==2) && !(m==2 && n==2))
			printf("%hd\n",0);
		else if(m==1 || n==1)
			printf("%d\n",k);
		else
			printf("%d\n",(k+1)/2);
	}
	return 0;
}
