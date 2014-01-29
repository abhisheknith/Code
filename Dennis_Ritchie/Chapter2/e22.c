#include<stdio.h>
#define LIM 100
int main()
{
	int i=0;
	char c;
	enum loop {NO,YES};
	enum loop true=YES;
	while(true==YES)
	{
		if(i>=LIM-1)
			true=NO;
		else if((c=getchar())=='\n')
			true=NO;
		else if((c=getchar())==EOF)
			true=NO;
		else
			++i;
	}
}
