#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	int i;
	i=open("./fifo",O_NONBLOCK|O_WRONLY);
	if(i==-1)
	{
		printf("Error.\n");
		return 0;
	}
	printf("%d\n",i);
	write(i,"Abhishek",9);
	return 0;
}
