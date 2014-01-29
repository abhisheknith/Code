#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<errno.h>
#include<arpa/inet.h>
#include<pthread.h>

void *fun(void *fd)
{
	int rt;
	while(1)
	{
		rt=write((int)fd,"Abhishek",10);
		if(rt==-1)
			printf("%s\n",strerror(errno));
	}
}
	
int main()
{
	int sockfd,ret;
	socklen_t len;
	struct sockaddr_in server,client;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("%s",strerror(errno));
		return 0;
	}
//	printf("%d",sockfd);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(1111);
	len=sizeof(server);
	ret=bind(sockfd,(struct sockaddr *)&server,len);
	if(ret==-1)
	{
		printf("%s",strerror(errno));
		return 0;
	}
	ret=listen(sockfd,10);
	if(ret==-1)
	{
		printf("%s",strerror(errno));
		return 0;
	}
	ssize_t rt;
	pthread_t threadid;
	while(1)
	{
		ret=accept(sockfd,(struct sockaddr *)&client,&len);
		if(ret==-1)
		{
			printf("%s",strerror(errno));
		//	return 0;
		}
		pthread_create(&threadid,NULL,fun,(void *)ret);
	}
}
