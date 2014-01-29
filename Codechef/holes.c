#include<stdio.h>

int main()
{
	unsigned short int t,count,i;
	char str[100];
	scanf("%hd",&t);
	for(;t>0;t--)
	{
		scanf("%s",str);
		i=count=0;
		while(str[i])
		{
			switch(str[i++])
			{
				case 'A':case 'D':case 'O':case 'P':case 'Q':case 'R':
					count++;
					break;
				case 'B':
					count+=2;
					break;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
