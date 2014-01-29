#include<stdio.h>
void TOH(int,int,int,int);
static long long count=0;
int main()
{
	TOH(31,1,2,3);
	printf("%lld",count);
}

void TOH(int size,int from,int to,int spare)
{
	if(size==1)
	{
		count++;
		//printf("Move Disk from %d to %d \n",from,to);
		return;
	}
	else
	{
		TOH(size-1,from,spare,to);
		TOH(1,from,to,spare);
		TOH(size-1,spare,to,from);
	}
}
