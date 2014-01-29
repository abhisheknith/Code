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
	strcpy(msgp.mtext,"Abhishek");
	msgp.mtype=1;
	int i=0;
	key_t key=210;
	int msg=msgget(key,IPC_CREAT);
	printf("%d\n",msg);
	i=msgsnd(msg,(void *)&msgp,size,IPC_NOWAIT);
	if(i==-1)
		printf("Error.\n");
	printf("%s\n",strerror(errno));
	return 0;
}
