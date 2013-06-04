#include<stdio.h>
int main()
{
	char s1[100],s2[10];
	int i,k;
	scanf("%s%s",s1,s2);
	for(i=0;s1[i]!=0;i++)
	{
		for(k=0;s2[k]!=0;k++)
			if(s2[k]==s1[i])
			{
				printf("Character found at : %d\n",i);
				return 0;
			}
	}
	printf("-1\n");
}
