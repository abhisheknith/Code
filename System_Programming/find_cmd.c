#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char *argv[],char *envp[])
{
	int i;
	if(argc!=5)
	{
		printf("Not valid.\n");
	//	return -1;
	}
	for(i=0;i<16;i++)
		printf("%s\n",envp[i]);
	if(strcmp(argv[1],"find"))
	{
		printf("Command not found.\n");
		return -2;
	}
	chdir(argv[2]);
	DIR *P=opendir(".");
	struct dirent *X;
	while((X=readdir(P))!=NULL)
	{
		if(!(strcmp("-name",argv[3])))
		{
			if(!(strcmp(X->d_name,argv[4])))
			{	printf("Found.\n");
				return 0;
			}
		}
		if(!(strcmp("-size",argv[3])))
		{
			struct stat *buf;
			int ret=stat(X->d_name,buf);
			printf("%d\n",ret);
			return 0;
			//printf("%d",(int)(buf->st_ino));
		}
		else
		{
			printf("Wrong Command");
			return 0;
		}
	}
}
