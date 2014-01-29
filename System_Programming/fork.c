#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#define LINUX

int main()
{
	int pid;
	#ifdef LINUX
		pid=fork();
	#endif
	#ifdef WINDOWS 
		pid=child();
	#endif
	if(pid)
	{
		printf("Parent\n");
	}
	else
	{
		printf("Child\n");
	}
	return 1;	
}
