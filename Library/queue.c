#include<stdio.h>

#define length (sizeof(arr)/sizeof(int))

int rear=-1,front=-1,arr[5];

int insert(int data)
{
	if((rear+1)%length==front)
		return -1;
	else if(-1==rear)
		front++;
	arr[rear=(++rear)%length]=data;
	return 0;
}

int delete(void)
{
	if(-1==rear)
		return -1;
	else if(front == rear)
	{
		int data=arr[front=(front++)%length];
		front=rear=-1;
		return data;
	}
	else
		return arr[front=(front++)%length];
}

void print(void)
{
	int i=front;
	if(-1==rear)
		return;
	for(;i!=rear;i=(i+1)%length)
		printf("%d-->",arr[i]);
	printf("%d-->",arr[i]);
}
