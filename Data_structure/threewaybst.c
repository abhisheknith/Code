#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *child[3];
};
/*
struct queue
{
	struct node *ptr;
	struct queue *next;
};

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
*/
int insert(int data,struct node **root,int n)
{
	int i=-1;
	struct node *temp,*tmp=(struct node*)malloc(sizeof(struct node));
/*	if(tmp==NULL)
	{
		printf("Allocation Failure.\n");
		return -1;
	}*/
	tmp->data=data;
	while(++i<n)
		tmp->child[i]==NULL;
	if(*root==NULL)
	{
		*root=tmp;
		return 0;
	}
/*	temp=*root;
	while(1)
	{
		if(temp->data>=data)
		{
			if(temp->left==NULL)
			{
				temp->left=tmp;
				return 0;
			}
			else
			{
				temp=temp->left;
				continue;
			}
		}
		else
		{
			if(temp->right==NULL)
			{
				temp->right=tmp;
				return 0;
			}
			else
			{
				temp=temp->right;
				continue;
			}
		}
	}*/
}
/*
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

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
	return;
}

void preorder(struct node *root)
{
        if(root==NULL)
                return;
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
        return;
}

void postorder(struct node *root)
{
        if(root==NULL)
                return;
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
        return;
}

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

void image(struct node **root)
{
	if(*root==NULL)
		return ;
	image(&(*root)->left);
	image(&(*root)->right);
	struct node *tmp;
	tmp=(*root)->left;
	(*root)->left=(*root)->right;
	(*root)->right=tmp;
	return;
}
*/
int main()
{
	struct node *root=NULL;
	int choice=1,data,ret;
	while(choice)
	{
		printf("\n\t\tMENU\n1:Insert\t2:Delete\t3:Print\t\t4:Print by level\t5:Inorder\t6:Preorder\t7:Postorder\t8:Mirror Image\t0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number : ");
				scanf("%d",&data);
				insert(data,&root,3);
				break;
/*			case 2:
				printf("Enter the number : ");
				scanf("%d",&data);
				ret=delete(data,&root);
				if(ret==-1)
					printf("Data not found");
				else
					printf("Deleted.\n");
				break;
			case 3:
				print(root);
				break;
			case 4:
				print_level(root);
				break;
			case 5:
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
			case 0:
				printf("\n\n\t\t\t\t\tThanx...\n");
				return 0;
			default:
				printf("Wrong Input.Plz enter again ... \n");
				break;
		}
	}
}
