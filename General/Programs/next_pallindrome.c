#include<stdio.h>
int pall(unsigned int);
int next_pall(unsigned int);

int main()
{
	unsigned int num;
	printf("Enter the number : ");
	scanf("%u",&num);
	next_pall(num);
}

int pall(unsigned int num)
{
	unsigned int count,nm=num,i,n=num;
	for(count=0;num>0;num/=10,count++);
	for(i=0;i<count;i++)
	{
		num=num*10+nm%10;
		nm/=10;
	}
	if(num==n)
		return 0;
	else
		return 1;
}

int next_pall(unsigned int num)
{
	if(!pall(num))
	{	printf("Number is pallindrome itself.\n");
		return 0;
	}
	unsigned int count,nm=num,i,n=num,low=0,high=0,hg,no;
	for(count=0;num>0;num/=10,count++);
	for(i=0;i<count/2;i++)
	{
		low=low*10+nm%10;
		nm/=10;
	}
	no=high=nm;
	if(count%2)
		high=high/10;
	hg=high;
	for(;hg>0;hg/=10)
		no=no*10+hg%10;
	if(no<n)
	{
		nm++;
		if(!(count%2))
			high++;
		for(;high>0;high/=10)
			nm=nm*10+high%10;
		no=nm;
	}
	printf("Num : %d\n",no);
}
