#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd;
	char buf[100];
	close(1);
	fd=open("std",O_CREAT|O_RDWR,S_IRWXU);
	dup2(1,fd);
/*	if(fd==1)
		printf("This is standard Output");
	else
		printf("Failure");*/
	ssize_t i=read(fd,buf,50);
	printf("%s",buf);
}
