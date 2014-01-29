#include<stdio.h>

unsigned short int length,fct[80];
void fact(short int);

void fact(short int num)
{
	unsigned short int j,temp,sum=0,i;
	length=1;
	for(i=1;i<80;i++)
		fct[i]=0;
	fct[0]=1;
	for(i=1;i<=num;i++)
	{
		j=temp=0;
		while(j<length)
		{
			sum=temp+fct[j]*i;
			fct[j++]=sum%100;
			temp=sum/100;
		}
		while(temp>0)
		{
			fct[j++]=temp%100;
			temp/=100;
			length++;
		}
	}
	printf("%d",fct[length-1]);
	for(i=length-1;i>0;i--)
		if(fct[i-1]>=10)
			printf("%hd",fct[i-1]);
		else
			printf("0%hd",fct[i-1]);
	printf("\n");
	return;
}

int main()
{
	unsigned short int num,k;
	scanf("%hd",&k);
	for(;k>0;k--)
	{
		scanf("%hd",&num);
		fact(num);
	}
	return 0;
}
