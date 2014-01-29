#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int turn=0,num_threads;

void *print(void *myturn)
{
	int i=0;
	while(1)
	{
		if(turn==(int)myturn)
		{
			printf("%d\t",i*num_threads+(int)myturn);
			turn=(turn+1)%num_threads;
			i++;
			fflush(stdout);
		}
		else
		{
			sleep(1);
		}
	}
}

int main()
{
	int i;
	scanf("%d",&num_threads);
	pthread_t threadid[num_threads];
	for(i=0;i<num_threads;i++)
		pthread_create(&threadid[i],NULL,print,(void *)i);
	for(i=0;i<num_threads;i++)
		pthread_join(threadid[i],NULL);
	printf("\n");
	return 0;
}
