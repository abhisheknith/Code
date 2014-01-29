#include<stdio.h>
#include<stdarg.h>

void printf_funct(char *str,...)
{
	int i;
	va_list p;
	va_start(p,str);
	for(i=0;str[i];i++)
	{
		if(str[i]=='%')
		{
			switch(str[++i])
			{
				char *str1;
				int j;
				case 'd':
					putchar(va_arg(p,int));
					break;
				case 'c':
					putchar(va_arg(p,char));
					break;
				default:
					putchar(str[i-1]);
					putchar(str[i]);
					break;
			}
		}
		else
			putc(str[i],stdout);
	}
}

int main()
{
	printf_funct("Abhishek%d",'D',233);
}
