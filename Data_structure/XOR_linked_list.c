#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
}*prev,*next,*temp;

/*int insert_beg(int data,struct NODE **head)
{
	if(*head==NULL)
	{
		*head=malloc(sizeof(struct NODE));
		if(*head==NULL)
			return -1;
		(*head)->data=data;
		(*head)->next=NULL;
		return 0;
	}
	struct NODE *temp;
	temp=malloc(sizeof(struct NODE));
	if(temp==NULL)
		return -1;
	temp->data=data;
	temp->next=*head;
	*head=temp;
	return 0;
}
*/
int insert_end(int data,struct NODE **head)
{
	if(*head==NULL)
	{
		*head=malloc(sizeof(struct NODE));
		if(*head==NULL)
			return -1;
		(*head)->data=data;
		(*head)->next=NULL;
		temp=*head;
		prev=next=NULL;
		return 0;
	}
	next=malloc(sizeof(struct NODE));
	if(next==NULL)
		return -1;
	next->data=data;
	next->next=NULL;
	temp->next=(long int)next^(long int)prev;
	prev=temp;
	temp=next;
	next=NULL;
	return 0;
}

void print(struct NODE *tmp)
{
	struct NODE *prv=NULL;
	struct NODE *nxt;
	while(tmp->next!=prev)
	{
		printf("%d-->",tmp->data);
		nxt=(long int)tmp->next^(long int)prv;
		prv=tmp;
		tmp=nxt;
	}
	return;
}
/*
int delete_data(int data,struct NODE **head)
{
	struct NODE *temp;
        temp=*head;
        while(temp!=NULL && temp->data!=data)
                temp=temp->next;
	if(temp==NULL)
        	return -1;
	else if(temp==*head)
	{
		*head=(*head)->next;
		free(temp);
	}
	else if(temp->next==NULL)
	{
		struct NODE *ptr;
		ptr=*head;
		while(ptr->next!=temp)
			ptr=ptr->next;
		ptr->next=NULL;
		free(temp);
	}
	else
	{
		struct NODE *ptr=temp->next;
		temp->data=ptr->data;
		temp->next=ptr->next;
		free(ptr);
	}
	return 0;
}

int delete_beg(struct NODE **head)
{
	if(*head==NULL)
		return -1;
	struct NODE *temp=*head;
	*head=(*head)->next;
	int data=temp->data;
	free(temp);
	return data;
}
*/

int main()
{
	struct NODE *head;
	head=NULL;
	int data,choice=1,ret;
	printf("PLZ enter your choice :\n");
	while(choice)
	{
		printf("1:Insert\t2:Delete_data\t3:Delete_beg\t4:Insert_end\t5:Print\t\t0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Element to be inserted : ");
				scanf("%d",&data);
				ret=insert_end(data,&head);
				if(-1==ret)
					printf("Failure in insertion");
				break;
/*
			case 2:
				printf("Element to be deleted : ");
				scanf("%d",&data);
				ret=delete_data(data,&head);
				if(-1==ret)
					printf("Data wasn't there.\n");
				break;
*/
			case 5:
				print(head);
				break;
/*
			case 3:
				ret=delete_beg(&head);
				if(ret==-1)
					printf("Empty.\n");
				else
					printf("Deleted element is %d.\n",ret);
				break;
			case 4:
				printf("Element to be inserted : ");
                                scanf("%d",&data);
                                ret=insert_beg(data,&head);
                                if(-1==ret)
                                        printf("Failure in insertion");
                                break;
*/
			case 0:
				return 0;
			default:
				printf("Wrong input. PLZ enter again.\n");
				break;
		}
	}
}
