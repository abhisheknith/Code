#include<stdio.h>
void pall(unsigned int);
int main()
{
	unsigned int num;
	printf("Enter the number : ");
	scanf("%u",&num);
	pall(num);
}

void pall(unsigned int num)
{
	unsigned int count,nm=num,i,n=num;
	for(count=0;num>0;num/=10,count++);
	for(i=0;i<count;i++)
	{
		num=num*10+nm%10;
		nm/=10;
	}
	if(num==n)
		printf("Pallindrome\n");
}
