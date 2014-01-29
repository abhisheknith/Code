#include<stdio.h>
#include<dirent.h>
#include<string.h>
int ls(char *name)
{
	struct dirent *X;
	DIR *P=opendir(name);
	while((X=readdir(P))!=0)
	{
		printf("%d\t%s\n",X->d_type,X->d_name);
	}
	return 0;
}

int main()
{
	ls(".");
}
