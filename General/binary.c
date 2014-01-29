#include<stdio.h>
#include<math.h>
void int_represent(int);
void float_represent(float);
void single_precision(double);

int main()
{
	double num;
	printf("Enter the number : ");
	scanf("%lf",&num);
	single_precision(num);
}

void int_represent(int num)
{
	static char bin[32],sign,i;
	if(num<0)
	{
		sign=1;
		num=-num;
	}
	while(num>0)
	{
		bin[i++]=num%2;
		num/=2;
	}
	if(sign)
	{
		for(i=0;!bin[i];i++);
		for(i=i+1;i<32;i++)
			bin[i]=bin[i]^1;
	}
	printf("\nBinary Representation :");
	for(i=31;i>=0;i--)
		printf("%d",bin[i]);
}

void float_represent(float num)
{
	static char bin[128],i=127;
	while(num!=0 && i>=0 )
	{
		bin[i--]=(int)(num*2);
		num=num*2;
		num-=(int)num;
	}
	printf("\n");
	for(i=127;i>=0;i--)
		printf("%d",bin[i]);
	printf("\n");
}

void single_precision(double num)
{
	static char bin[32],intg[128],i;
	if(num<0)
	{
		bin[31]=1;
		num=-num;
	}
	double nm=fmod(num,1.0);
	printf("%f",nm);
}
		
