#include<stdio.h>

void calc_x(int B[],int x[],int b[],int sz)
{
	int i,a;
	for(i=0;i<sz;i++)
	{
		a=1;
		B[i]=B[i]%b[i];
		while(a%B[i])
			a+=b[i];
		x[i]=a/B[i];
	}
}

int main()
{
	printf("Enter the number of conditions : ");
	int sz;
	scanf("%d",&sz);
	int c[sz],x[sz],b[sz],B[sz],Z=0,mul=1,i;
	printf("Enter the info about keys : ");
	for(i=0;i<sz;i++)
		scanf("%d%d",&b[i],&c[i]);
	for(i=0;i<sz;i++)
		mul*=b[i];
	for(i=0;i<sz;i++)
		B[i]=mul/b[i];
	for(i=0;i<sz;i++)
		calc_x(B,x,b,sz);
	for(i=0;i<sz;i++)
		printf("%d\t",x[i]);
	for(i=0;i<sz;i++)
		B[i]=mul/b[i];
	printf("\n");
	for(i=0;i<sz;i++)
		Z+=B[i]*x[i]*c[i];
	while(Z>0)
	{
		printf("%d\t",Z);
		Z=Z-mul;
	}
	printf("\n");
	return 0;
}
