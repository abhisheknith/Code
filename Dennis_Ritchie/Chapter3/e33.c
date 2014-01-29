#include<stdio.h>
void escape(char[],char[]);

int main()
{
	char s[20],t[100];
	printf("Enter the Strings : \n");
	scanf("%[^NULL]",s);
	escape(s,t);
	return 0;
}

void escape(char s[],char t[])
{
	int i,j;
	char c;
	for(i=0,j=0;(c=s[i++]);)
	{
		if(s[i]=='-' && s[i+1]>=c)
		{
			i++;
			while(s[i]>c)
				t[j++]=c++;
		}
		else
			t[j++]=c;
	}
	t[j]=0;
	printf("%s\n",t);
	return;
}
