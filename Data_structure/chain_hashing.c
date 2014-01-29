#include<stdio.h>
#include<stdlib.h>
#define size 10
#define hash_key(a) a%size

struct NODE
{
	int data;
	struct NODE *next;
};

struct node
{
	struct NODE *start;
}hash[size];

int insert(int data,struct NODE **head)
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
	struct NODE *temp=*head; 
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=malloc(sizeof(struct NODE));
	if(temp->next==NULL)
		return -1;
	temp=temp->next;
	temp->data=data;
	temp->next=NULL;
	return 0;
}

int print(int data,struct NODE *temp)
{
	if(temp==NULL)
		return -1;
	if(data==temp->data)
	{
		printf("%d\n",temp->data);
		return 0;
	}
	return print(data,temp->next);
}

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

int put(int data)
{
	int k=hash_key(data);
	return insert(data,&(hash[k].start));
}

int get(int data)
{
	int k=hash_key(data);
	if(hash[k].start==NULL)
		return -1;
	return print(data,(hash[k].start));
}

int delete(int data)
{
	int k=hash_key(data);
	return delete_data(data,&(hash[k].start));
}

int main()
{
	int data,choice=1,ret;
	while(choice)
	{
		printf("1:Put \t2:Get \t3:Delete \t0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number : ");
				scanf("%d",&data);
				ret=put(data);
				if(ret==-1)
					printf("Insertion Failure.\n");
				break;
			case 2:
				printf("Enter the number : ");
				scanf("%d",&data);
				ret=get(data);
				if(ret==-1)
					printf("Not Found.\n");
				else
					printf("Found.\n");
				break;
			case 3:
				printf("Enter the number : ");
				scanf("%d",&data);
				ret=delete(data);
				if(ret==-1)
					printf("Not Found.\n");
				else
					printf("Deleted.\n");
				break;
			case 0:
				return 0;
			default:
				printf("Wrong Input. Please try again ...\n");
				break;
		}
	}
	return 0;
}
