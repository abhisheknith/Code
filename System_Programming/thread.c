#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int i=0,turn=1;

void *printss(void *str)
{
	printf("%d",i);
	turn=0;
}
void *print(void *str)
{
	printf(" %d ",i);
	turn=1;
}

int main()
{
	pthread_t threadid1,threadid2;
	while(i<10)
	{
		if(turn)
		{
			pthread_create(&threadid1,NULL,printss,NULL);
			sleep(1);
		}
		else
		{
			pthread_create(&threadid2,NULL,print,NULL);
			sleep(1);
		}
		i++;
	}
	printf("\n");
	return 0;
}
