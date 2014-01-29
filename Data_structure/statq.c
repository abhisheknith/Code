#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	struct stat *buf;
	int ret=stat("./std",buf);
	printf("%d%d",ret,(int)buf->st_size);
}
