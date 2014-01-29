#include<stdio.h>

int main()
{
	char str[]="Abhishek",str1[20];
	FILE *fp;
	fp=fopen("file","w+");
	fprintf(fp,"%s",str);
	putc('\n',fp);
	printf("%ld",ftell(fp));
	fseek(fp,-8,SEEK_CUR);
	fscanf(fp,"%[^EOF]",str1);
	printf("%s",str1);
	fclose(fp);
	return 0;
}
