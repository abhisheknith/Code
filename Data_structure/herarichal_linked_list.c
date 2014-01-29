#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next,*child;
};

int insert(int data,struct node **head)
{
	struct node *tmp,*temp=*head;
	if(*head==NULL)
	{
		do
		{
			tmp=malloc(sizeof(struct node));
			if(tmp==NULL)
				return -1;
			tmp->data=data%10;
			tmp->next=NULL;
			tmp->child=NULL;
			if(*head==NULL)
			{
				*head=temp=tmp;
				printf("%d\n",(*head)->data);
			}
			else
			{
				temp->child=tmp;
				temp=tmp;
			}
			data/=10;
		}while(data!=0);
		return 0;
	}
	while(data!=0)
	{
		while(temp->data!=data%10 && temp->next != NULL)
			temp=temp->next;
		if(temp->data!=data%10)
		{
			tmp=malloc(sizeof(struct node));
			if(tmp==NULL)
				return -1;
			tmp->data=data%10;
			tmp->next=NULL;
			tmp->child=NULL;
			temp->next=tmp;
			temp=tmp;
			data/=10;
			while(data!=0)
			{
				tmp=malloc(sizeof(struct node));
				if(tmp==NULL)
					return -1;
				tmp->data=data%10;
				tmp->next=NULL;
				tmp->child=NULL;
				temp->child=tmp;
				temp=tmp;
				data/=10;
			}
			return 0;
		}
		else
		{
			data/=10;
			temp=temp->child;
			continue;
		}
		return 0;
	}
}

int search(int data,struct node *temp)
{
	if(temp==NULL)
		return -1;
        while(data!=0)
        {
                while(temp->data!=data%10 && temp->next != NULL)
                        temp=temp->next;
                if(temp->data!=data%10)
			return -1;
		else
		{
			temp=temp->child;
			data/=10;
		}
	}
	return 0;
}

int main()
{
	int data,choice=1,ret;
	struct node *start=NULL;
	while(choice)
	{
		printf("\t\tMENU\n1:Insert\t2:Search\t0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the Number : ");
				scanf("%d",&data);
				insert(data,&start);
				if(ret==-1)
					printf("Allocation Failure.\n");
				break;
			case 2:
				printf("Enter the number : ");
				scanf("%d",&data);
				ret=search(data,start);
				if(ret==-1)
					printf("Not Found.\n");
				else
					printf("Found.\n");
				break;
			case 0:
				return 0;
			default:
				printf("Wrong Input.Plz enter again......\n");
		}
	}
}
