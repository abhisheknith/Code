#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<errno.h>
#include<arpa/inet.h>
int main()
{
	int sockfd,ret;
	socklen_t len;
	struct sockaddr_in server,client;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("%s  .\n",strerror(errno));
		return 0;
	}
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(1111);
	len=sizeof(server);
	ret=connect(sockfd,(struct sockaddr *)&server,len);
	if(ret==-1)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	printf("Client.\n");
	size_t count=10;
	ssize_t rt;
	char str[20];
	while(1)
	{
		rt=read(sockfd,str,count);
		printf("%s\n",str);
		if(rt==-1)
			printf("%s\n",strerror(errno));
		sleep(1);
	}
}
