#include<stdio.h>
#include<semaphore.h>
#include<string.h>
#include<errno.h>
int main()
{
	int i=0;
	sem_t sem;
	int ret=sem_init(&sem,0,1);
	if(ret)
		printf("%s",strerror(ret));
	while(i<1001)
	{
		sem_wait(&sem);
		printf("%d\t",i++);
		sem_post(&sem);
	}
}
