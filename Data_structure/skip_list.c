#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next[2];
};

int insert(int data,struct node **head)
{
	struct node *temp,*tmp=malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Allocation Failure");
		return -1;
	}
	tmp->data=data;
	int i;
	for(i=0;i<2;i++)
		tmp->next[i]=NULL;
	if(*head==NULL)
	{
		*head=tmp;
		return 0;
	}
	else if((*head)->next[1]==NULL)
	{
		if((*head)->next[0]==NULL)
		{
			(*head)->next[0]=tmp;
			return 0;
		}
		else
		{
			(*head)->next[1]=tmp;
			temp=(*head)->next[0];
			temp->next[0]=tmp;
			return 0;
		}
	}
	temp=*head;
	for(i=1;i<=0;i--)
		while((temp->next[i])->next[i]!=NULL)
			temp=temp->next[i];
	printf("%d\n",temp->data);
	temp=temp->next[0];
	temp->next[1]=tmp;
	printf("%ld\n",temp->next[1]);
	temp=temp->next[0];
	temp->next[0]=tmp;
	return 0;
}

void print(struct node *head)
{
	if(head==NULL)
	{
		printf("Empty.\n");
		return ;
	}
	while(head!=NULL)
	{
		printf("%d-->",head->data);
		head=head->next[0];
	}
	printf("\n");
	return ;
}

int main()
{
	struct node *start;
	start=NULL;
	int choice=1,data;
	printf("%ld",sizeof(struct node));
	while(choice)
	{
		printf("\t\tMENU\n1:Insert\t\t2:Print\t\t0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data :");
				scanf("%d",&data);
				insert(data,&start);
				break;
			case 2:
				print(start);
				break;
			case 0:
				return 0;
			default:
				printf("Wrong Input.Plz enter again");
				break;
		}
	}
	return 0;
}
