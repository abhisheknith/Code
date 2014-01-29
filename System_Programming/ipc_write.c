#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
	char *p,*b,*add=NULL;
	int i=0;
	char str[]="NIT_HAMIRPUR";
	int shm=shmget((key_t)12,10,IPC_CREAT);
	printf("%d\n",shm);
	b=shmat(12,NULL,1);
	memset(b,0,100);
	p=b;
	*p='A';
	sleep(30000000);

/*	while(1)
	{
		i=i%10;
		if(*p==0)
		{
			*p=str[i];
			p=b+(++i%10);
		}
		else
		{
			sleep(1);
		}
	}*/
}
