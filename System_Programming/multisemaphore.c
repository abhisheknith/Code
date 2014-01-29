#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<semaphore.h>
int num_threads;
sem_t sem;
void *print(void *myturn)
{
	int i=0;
	int ret=sem_init(&sem,0,1);
	if(ret)
		printf("%s\n",strerror(errno));
	while(1)
	{
		sem_wait(&sem);
		printf("%d\t",i*num_threads+(int)myturn);
		i++;
		fflush(stdout);
		sem_post(&sem);
		sleep(1);
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
