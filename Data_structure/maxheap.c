#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct queue
{
	struct node *ptr;
	struct queue *next;
};

struct node *temp;
int data;

int insert_queue(struct node *ptr,struct queue **head)
{
        if(*head==NULL)
        {
                *head=malloc(sizeof(struct queue));
                if(*head==NULL)
                        return -1;
                (*head)->ptr=ptr;
                (*head)->next=NULL;
                return 0;
        }
        struct queue *temp=*head;
        while(temp->next!=NULL)
                temp=temp->next;
        temp->next=malloc(sizeof(struct queue));
        if(temp->next==NULL)
                return -1;
        temp=temp->next;
        temp->ptr=ptr;
        temp->next=NULL;
        return 0;
}

struct node *delete_queue(struct queue **head)
{
        if(*head==NULL)
                return NULL;
        struct queue *temp=*head;
        *head=(*head)->next;
        struct node *tmp=temp->ptr;
        free(temp);
        return tmp;
}

void swap(int *a,int *b)
{
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}

int insert(int count,struct node **root)
{
	if(*root==NULL)
	{
		*root=malloc(sizeof(struct node));
		if(*root==NULL)
		{
			printf("Allocation Failure.\n");
			return -1;
		}
		(*root)->data=data;
		(*root)->left=(*root)->right=NULL;
		return 0;
	}
	if(count/2>1)
		insert(count/2,root);
	if(temp->data<data)
		swap(&(temp->data),&data);
	if(count%2)
	{
		if(temp->right)
			temp=temp->right;
		else
		{
			temp->right=malloc(sizeof(struct node));
			temp->right->data=data;
			temp->right->left=temp->right->right=NULL;
			return 0;
		}
	}
	else
	{
		if(temp->right)
			temp=temp->left;
		else
		{
			temp->left=malloc(sizeof(struct node));
			temp->left->data=data;
			temp->left->left=temp->left->right=NULL;
			return 0;
		}
	}
}

void print(struct node *tmp)
{
	if(tmp==NULL)
		return;
	print(tmp->left);
	printf("%d  ",tmp->data);
	print(tmp->right);
	return;
}

void print_level(struct node *root)
{
	if(root==NULL)
		return;
	struct queue *start=NULL;
	struct node *tmp;
	insert_queue(root,&start);
	while(start!=NULL)
	{
		tmp=delete_queue(&start);
		printf("%d  ",tmp->data);
		if(tmp->left)
			insert_queue(tmp->left,&start);
		if(tmp->right)
			insert_queue(tmp->right,&start);
	}
}
/*
int delete(int data,struct node **root)
{
	if(*root==NULL)
		return -1;
	struct node *ptr,*temp=*root;
	ptr=*root;
	while(1)
	{
		if(temp->data==data && temp->left!=NULL && temp->right!=NULL)
		{
			ptr=temp;
			struct node *tmp=temp->right;
			while(tmp->left!=NULL)
			{
				ptr=tmp;
				tmp=tmp->left;
			}
			temp->data=tmp->data;
			tmp->data=data;
			temp=tmp;
		}
		if(temp->data==data)
		{
			if(temp->left==NULL && temp->right==NULL)
			{
				if(ptr->left==temp)
					ptr->left=NULL;
				else
					ptr->right=NULL;
			}
			else
			{
				if(temp->left==NULL)
				{
					if(ptr->right==temp)
						ptr->right=temp->right;
					else
						ptr->left=temp->right;
				}
				else
				{
					if(ptr->left==temp)
						ptr->left=temp->left;
					else
						ptr->right=temp->left;
				}
			}
			free(temp);
			return 0;
		}
		else if(temp->data<data)
		{
			ptr=temp;
			if(temp->right==NULL)
				return -1;
			temp=temp->right;
		}
		else
		{
			ptr=temp;
			if(temp->left==NULL)
				return -1;
			temp=temp->left;
		}
	}
}
*/
int depth(struct node *tmp)
{
	int ldepth,rdepth,dpth;
	if(!tmp)
		return 0;
	ldepth=depth(tmp->left);
	rdepth=depth(tmp->right);
	dpth=1+(ldepth>rdepth?ldepth:rdepth);
	printf("%d --> %d\n",tmp->data,dpth);
	return dpth;
}

int main()
{
	struct node *root=NULL;
	int choice=1,ret,count=0;
	while(choice)
	{
		printf("\n\t\tMENU\n1:Insert   2:Delete   3:Print\t4:Print by level\t5:Depth\t0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number : ");
				scanf("%d",&data);
				count++;
				temp=root;
				insert(count,&root);
				break;
/*			case 2:
				printf("Enter the number : ");
				scanf("%d",&data);
				count--;
				ret=delete(&root);
				if(ret==-1)
					printf("Data not found");
				else
					printf("Deleted.\n");
				break;*/
			case 3:
				print(root);
				break;
			case 4:
				print_level(root);
				break;
/*			case 5:
				inorder(root);
				break;
			case 6:
				preorder(root);
				break;
			case 7:
				postorder(root);
				break;
			case 8:
				image(&root);
				break;*/
			case 5:
				ret=depth(root);
				printf("\n%d\n",ret);
				break;
/*			case 10:
				balance_tree(root,root,&root);
				break;*/
			case 0:
				printf("\n\n\t\t\t\t\tThanx...\n");
				return 0;
			default:
				printf("Wrong Input.Plz enter again ... \n");
				break;
		}
	}
}
