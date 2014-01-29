#include<stdio.h>
#include<float.h>
#include<limits.h>

int main(int argc, char *args[])
{
	printf("\nMax value of signed char = %d\n",(char)((unsigned char) ~0 >>1));
	printf("Min value of signed char = %d\n",-(char)((unsigned char) ~0 >>1)-1);
	printf("Max value of signed short = %d\n",(short)((unsigned short) ~0 >>1));
	printf("Min value of signed short = %d\n",-(short)((unsigned short) ~0 >>1));
	printf("Max value of signed int = %d\n",(int)((unsigned int) ~0 >>1));
	printf("Min value of sigend int = %d\n",-(int)((unsigned int) ~0 >>1));
	printf("Max value of signed long = %ld\n",(long)((unsigned long) ~0 >>1));
	printf("Min value of signed long = %ld\n\n",-(long)((unsigned long) ~0 >>1));
	printf("Max value of unsigned char = %u\n",(unsigned char) ~0);
	printf("Max value of unsigned short = %u\n",(unsigned short) ~0);
	printf("Max value of unsigned int = %u\n",(unsigned int) ~0);
	printf("Max value of unsigned long = %lu\n\n",(unsigned long) ~0);
	printf("Max value of float = %f\n",FLT_MAX);
	printf("Min value of float = %f\n",-FLT_MAX);
	printf("Max value of double = %d\n",INT_MIN);
	printf("Min value of double = %f\n",-DBL_MAX);
}
