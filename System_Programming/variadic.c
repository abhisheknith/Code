#include<stdio.h>
#include<stdarg.h>

sum(int num,...)
{
	int sm=0,i;
	va_list p;
	va_start(p,num);
	for(i=0;i<num;i++)
		sm+=va_arg(p,int);
	return(sm);
}

int main()
{
	printf("%d",sum(2,3,4));
}
