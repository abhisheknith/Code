#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/shm.h>
int main()
{
	char *p,*b,*add=NULL;
	int i=0;
	int shm=shmget(12,10,IPC_EXCL);
	b=shmat(12,add,SHM_RDONLY);
	sleep(20);
	printf("%c",*p);
	/*while(1)
	{
		if(*p=='0')
			sleep(1);
		else
		{
			printf("%c",*p);
			*p=0;
			p=b+(++i%10);
		}
	}*/
}
