#include<unistd.h>
#include<stdio.h>

int main()
{
	int pid;
	char *p[]={""};
	execv("/home/luv/Ccode/General/fork",p);
	printf("Will not be printed");
}
