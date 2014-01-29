#include<stdio.h>
void escape(char[],char[]);

int main()
{
	char s[20],t[20];
	printf("Enter the Strings : \n");
	scanf("%[^NULL]",s);
	escape(s,t);
	return 0;
}

void escape(char s[],char t[])
{
	int i,j;
	for(i=0,j=0;s[i];i++)
		switch(s[i])
		{
			case '\n':
				t[j++]='\\';
				t[j++]='n';
				break;
			case '\t':
				t[j++]='\\';
				t[j++]='t';
				break;
			default:
				t[j++]=s[i];
				break;
		}
	t[j]=0;
	printf("%s\n",t);
	return;
}
