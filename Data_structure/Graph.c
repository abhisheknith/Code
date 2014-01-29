#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE
{
        int data;
        struct NODE *next;
};

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
	if(temp->data==data)
		return -2;
        while(temp->next!=NULL)
	{
		if(temp->next->data==data)
			return -2;
                temp=temp->next;
	}
        temp->next=malloc(sizeof(struct NODE));
        if(temp->next==NULL)
                return -1;
        temp=temp->next;
        temp->data=data;
        temp->next=NULL;
        return 0;
}

int search(int data,struct NODE *root)
{
        if(root==NULL)
                return -1;
	if(root->data==data)
		return 0;
//	printf("%d\t",root->data);
        search(data,root->next);
	return 0;
}

void dfs(struct NODE **temp,int vert,int index)
{
	struct NODE *tmp=temp[index];
	static short int arr[vert];
	if(arr[index]==1)
		return ;
	while(temp[index]!=NULL)
	{
		printf("%d\t",temp[index]->data);
		arr[index]=1;
		dfs(&temp[temp[index]->data-1],vert,temp[index]->data-1);
		temp[index]=temp[index]->next;
	}
}
	

int main()
{
	int vert;
	printf("Please enter the number of vertices : ");
	scanf("%d",&vert);
	struct NODE *start[vert];
	bzero(start,sizeof(struct NODE *)*vert);
	int x,y,ret,choice=1;
	while(choice)
	{
		printf("\n\n\t\t\t\t\tMENU\n");
		printf("1: Make link\t2: Search link\t3:DFS\t0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter x and y :\n");
				scanf("%d%d",&x,&y);
				ret=insert(y-1,&start[x-1]);
				if(ret==-2)
					printf("Link Exists.\n");
				else if(ret==-1)
					printf("Insertion Failure\n");
				break;
			case 2:
				printf("Enter the link to be search : \n");
				scanf("%d%d",&x,&y);
				ret=search(y-1,start[x-1]);
				if(ret==-1)
					printf("Link does not exist.\n");
				else
					printf("Exists.\n");
				break;
			case 3:
				dfs(&start[0],vert,0);
				break;
			case 0:
				return 0;
			default:
				printf("Wrong Input. PLZ enter again... \n");
				break;
		}
	}
}
