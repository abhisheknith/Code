#include<stdio.h>
#include<pthread.h>
int i=0;
void *print1(void *str)
{
	printf("%d\n",*i);
}
void *print2(void *i)
{
	printf("%d\n",);
}
int main()
{
	int turn=1,i=0;
	while(i++<100)
	{
		if(turn==1)
			print1(itoa(i));
		else
			print2(itoa(i));
	}
}
