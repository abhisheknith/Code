#include<stdio.h>
int main()
{
	char s1[100],s2[10];
	int i,j,k;
	scanf("%s%s",s1,s2);
	for(i=j=0;s1[i]!=0;i++)
	{
		for(k=0;s2[k]!=0 && s1[i] != s2[k] ;k++);
		if(s2[k]==0)
			s1[j++]=s1[i];
	}
	s1[j]=0;
	printf("Now String is : %s\n",s1);
}
