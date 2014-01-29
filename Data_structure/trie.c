#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
	char data;
	struct node *child[27];
};

int create_trie(struct node **head)
{
	*head=malloc(sizeof(struct node));
	if(*head==NULL)
		return -1;
	(*head)->data=' ';
	bzero((void *)*head+1,sizeof(struct node *)*27);
	return 0;
}

int insert(char str[],struct node **head)
{
	int i=0;
	struct node *tmp,*temp=*head;
	while(str[i] && temp->child[str[i]-'a']!=NULL)
		temp=temp->child[str[i++]-'a'];
	while(str[i]!=0)
	{
		tmp=malloc(sizeof(struct node));
		if(tmp==NULL)
			return -1;
		tmp->data=str[i];
		bzero((void *)tmp+1,sizeof(struct node *)*27);
		temp->child[str[i]-'a']=tmp;
		temp=tmp;
		i++;
	}
	tmp=malloc(sizeof(struct node));
	if(tmp==NULL)
		return -1;
	tmp->data='0';
	bzero((void *)tmp+1,sizeof(struct node *)*27);
	temp->child[26]=tmp;
	return 0;
}

int search(char str[],struct node *temp)
{
	int i=0;
        while(str[i] && temp->child[str[i]-'a'] != NULL )
        {
		temp=temp->child[str[i++]-'a'];
	}
	if(str[i] || temp->child[26] == NULL)
		return -1;
	return 0;
}

int main()
{
	int choice=1,ret;
	char str[20];
	struct node *start=NULL;
	ret=create_trie(&start);
	if(ret==-1)
	{
		printf("Allocation Failure.\n");
		return 0;
	}
	while(choice)
	{
		printf("\t\tMENU\n1:Insert\t2:Search\t0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the Word : ");
				scanf("%s",str);
				ret=insert(str,&start);
				if(ret==-1)
					printf("Allocation Failure.\n");
				break;
			case 2:
				printf("Enter the Word : ");
				scanf("%s",str);
				ret=search(str,start);
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
