#include<stdio.h>

int head=-1,arr[20];

int push(int data)
{
	if(head==sizeof(arr)/sizeof(int)-1)
		return -1;
	else
		arr[++head]=data;
	return 0;
}

int pop(void)
{
	if(-1==head)
		return -1;
	else
		return arr[head--];
}

void print(void)
{
	int i;
	for(i=0;i<=head;i++)
		printf("%d-->",arr[i]);
}
