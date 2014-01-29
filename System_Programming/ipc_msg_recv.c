#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/shm.h>
#include<errno.h>
#include<string.h>

struct msgbuf
{
	long mtype;
	char mtext[10];
};

int main()
{
	struct msgbuf msgp;
	size_t size=10;
	ssize_t sz;
	key_t key=210;
	int msg=msgget(key,IPC_CREAT);
	printf("%d\n",msg);
	sz=msgrcv(msg,(void *)&msgp,size,1,IPC_NOWAIT);
	printf("%d\n",(int)sz);
	if(sz==-1)
	{
		printf("Error.\n");
		printf("%s\n",strerror(errno));
		return 0;
	}
	printf("%s",msgp.mtext);
	return 0;
}
