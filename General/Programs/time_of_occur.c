//To count number of each character in a given string ...

#include<stdio.h>
char* count(char[]);

int main()
{
	static char str[256],*cnt;
	printf("Enter the string : ");
	scanf("%s",str);
	cnt=count(str);
	int i=0;
	for(;i<256;i++)
		printf("%c\t%d\t\t",i,cnt[i]);
}
char* count(char str[])
{
	int i;
	static char cnt[256];
	for(i=0;str[i];cnt[str[i++]]++);
	return cnt;
}
