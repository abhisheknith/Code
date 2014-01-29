#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	int i;
	char buf[20];
	i=open("./fifo",O_RDONLY);
	if(i==-1)
	{
		printf("Error.\n");
		return 0;
	}
	read(i,buf,9);
	printf("%s",buf);
	return 0;
}
