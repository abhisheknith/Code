//#include"linked_list.c"
#include<stdio.h>

struct NODE
{
	int data;
	struct NODE *next;
}*head;
struct NODE *head;

void print_stack(struct NODE *temp)
{
        if(temp==NULL)
                return;
        print_stack(temp->next);
        printf("%d-->",temp->data);
        return;
}

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
	head=NULL;
	int data,choice=1;
	while(choice)
	{
		printf("\t\tMENU\n1:Push\n2:Pop\n3:Print\n0:Exit\f");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number : ");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				print_stack(head);
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
