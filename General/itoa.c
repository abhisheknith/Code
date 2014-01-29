#include<stdio.h>

int main(int argc, char *argv[])
{
	int num,i,sign=0;
	char ASCII[10];
	printf("Enter the number :");
	scanf("%d",&num);
	if(num<0)
	{
		num=-num;
		sign=1;
	}
	for(i=0;num>0;i++,num/=10)
		ASCII[i]=num%10+'0';
	if(sign)
		ASCII[i++]='-';
	for(;i>=0;i--)
		printf("%c",ASCII[i]);
}
