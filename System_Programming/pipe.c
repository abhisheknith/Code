#include<stdio.h>
#include<unistd.h>

int main()
{
	int fd[4];
	pipe(&fd[0]);
	pipe(&fd[2]);
	int c=fork();
	if(c>0)
	{
		close(fd[0]);
		close(fd[3]);
		write(fd[1],"Hello World",16);
	}
	else
	{
		char buf[20];
		close(fd[1]);
		close(fd[2]);
		read(fd[0],buf,16);
		printf("%s",buf);
	}

}
