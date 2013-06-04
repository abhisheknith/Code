#include<stdio.h>
int main()
{
	char p[8];
	scanf("%s",p);
	printf("String is : %s",p);
	int n=0,i=0,in,hex;
	if(p[i++]=='0')
		if(p[i]=='x' || p[i]=='X')
			i++;
	in=1;
	while(in)
	{
		if(p[i]>='0' && p[i]<='9')
			hex=p[i]-'0';
		else if(p[i]>='A' && p[i]<='F')
			hex=p[i]+10-'A';
		else if(p[i]>='a' && p[i]<='f')
			hex=p[i]+10-'a';
		else
			in=0;
		if(in)
		{
			n= n*16 + hex;
			i++;	
			printf("\n%d\n",n);
		}
	}
	printf("\n%d\n",n);
}
