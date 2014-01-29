//Implement basic string functions .....

#include<stdio.h>
void strcopy(char[],char[]);
void strappnd(char[],char[]);
int strlen(char[]);
void strupr(char[]);
void strlwr(char[]);

int main()
{
	static char str1[32],str2[32];
	printf("Enter the string :");
	scanf("%s",str1);
	strlwr(str1);
	printf("%s\n",str1);
	printf("%d\n",strlen(str1));
	strupr(str1);
	printf("%s\n",str1);
}
/*
void strcpy(char str1[],char str2[])
{
	int i;
	for(i=0;str2[i];str1[i]=str2[i++]);
}

void strappend(char str1[],char str2[])
{
	int i,j;
	for(i=0;str1[i];i++);
	for(j=0;str2[j];str1[i++]=str2[j++]);
}
*/
int strlen(char str1[])
{
	static int i;
	for(i=0;str1[i];i++);
	return i;
}

void strlwr(char str1[])
{
        int i;
        for(i=0;str1[i];i++)
                if(str1[i]<='Z' && str1[i]>='A')
                        str1[i]+='a'-'A';
}

void strupr(char str1[])
{
        int i;
	for(i=0;str1[i];i++)
		if(str1[i]<='z' && str1[i]>='a')
			str1[i]+='A'-'a';
}
