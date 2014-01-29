#include<stdio.h>
void conversion(char[]);

int main()
{
	static char gray[32],i;
	printf("Enter the gray representation : ");
	while( (gray[i++]=getchar()) && i<32)if(i>31)break;
	printf("%s\n",gray);
	conversion(gray);
}

void conversion(char gray[])
{
	static char bin[32],sign,i;
	int a,b;
	for(i=31;gray[i]!=48 && i>-1 ;i--);
	bin[i]=gray[i];
	for(;i>0;i--)
	{
		a=gray[i]-'0';
		b=gray[i-1]-'0';
		bin[i-1]=a^b+'0';
	}
	printf("\nBinary Representation :");
	for(i=31;i>=0;i--)
		printf("%d",bin[i]);
}
