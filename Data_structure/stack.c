#include<stdio.h>
#include<unistd.h>
#include"../Library/linked_list.c"

struct NODE
{
	int data;
	struct NODE *next;
}*head;

int push(int data)
{
	int ret=insert_beg(data,&head);
	if(ret == -1)
	{
		printf("Failure. \n");
		return -1;
	}
}

int pop()
{
	int ret=delete_beg(&head);
	if(ret==-1)
	{
		printf("Empty.\n");
		return -1;
	}
	printf("Popped element : %d\n",ret);
	return 0;
}

int main()
{
	int lib=uselib("/home/luv/Ccode/Library/liblinked_list.so");
	if(lib==-1)
		printf("Failure");
	head=NULL;
	int data,choice;
	while(choice)
	{
		printf("\t\tMENU\n1:Push\n2:Pop\n3:Print\n0:Exit\f");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				print(&head);
				break;
			case 0:
				return 0;
			default:
				printf("Wrong Input . Please enter again.....\n");
				break;
		}
	}
	return 0;
}
