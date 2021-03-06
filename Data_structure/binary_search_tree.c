#include<stdio.h>
#include<stdlib.h>
struct node *rrotate(struct node *cur,struct node **root);
struct node *lrotate(struct node *cur,struct node **root);

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

int insert_queue(struct node *ptr,struct queue **head)
{
        if(*head==NULL)
        {
                *head=(struct queue*)malloc(sizeof(struct queue));
                if(*head==NULL)
                        return -1;
                (*head)->ptr=ptr;
                (*head)->next=NULL;
                return 0;
        }
        struct queue *temp=*head;
        while(temp->next!=NULL)
                temp=temp->next;
        temp->next=(struct queue*)malloc(sizeof(struct queue));
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

int insert(int data,struct node **root)
{
	struct node *temp,*tmp=(struct node*)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Allocation Failure.\n");
		return -1;
	}
	tmp->data=data;
	tmp->left=tmp->right=NULL;
	if(*root==NULL)
	{
		*root=tmp;
		return 0;
	}
	temp=*root;
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

int delete_node(int data,struct node **root)
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

int depth(struct node *temp)
{
	int ldepth,rdepth,dpth;
	if(!temp)
		return 0;
	ldepth=depth(temp->left);
	rdepth=depth(temp->right);
	dpth=1+(ldepth>rdepth?ldepth:rdepth);
//	printf("%d --> %d\n",temp->data,dpth);
	return dpth;
}

struct node *lrotate(struct node *cur,struct node **root)
{
	struct node *par,*X;
	par=cur;
	X=cur->left;
	cur->left=X->left;
	cur=X->left;
	while(cur->right!=NULL)
	{
		par=cur;
		cur=cur->right;
	}
	cur->right=X;
	if(depth(cur->right)-depth(cur->left)>1)
	{
		rrotate(par,root);
	}
}

struct node *rrotate(struct node *cur,struct node **root)
{
	struct node *par,*X;
	par=cur;
	X=cur->right;
	cur->right=X->right;
	cur=X->right;
	while(cur->left!=NULL)
	{
		par=cur;
		cur=cur->left;
	}
	cur->left=X;
	if(depth(cur->left)-depth(cur->right)>1)
	{
		lrotate(par,root);
	}
}

/*struct node *balance_tree(struct node *cur,struct node *par,struct node **root)  Under Construction
{
	int ldepth,rdepth;
	if(cur==NULL)
		return NULL;
	balance_tree(cur->left,cur,root);
	balance_tree(cur->right,cur,root);
	ldepth=depth(cur->left);
	rdepth=depth(cur->right);
	if(ldepth-rdepth>1)
		lrotate(par,root);
	if(rdepth-ldepth>1)
		rrotate(par,root);
}*/

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

int main()
{
	struct node *root=NULL;
	int choice=1,data,ret;
	while(choice)
	{
printf("\n\t\tMENU\n1:Insert\t2:Delete\t3:Print  \t4:Print by level\t5:Inorder\t6:Preorder\t7:Postorder\t8:Mirror Image\t9:Depth  \t0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number : ");
				scanf("%d",&data);
				insert(data,&root);
				break;
			case 2:
				printf("Enter the number : ");
				scanf("%d",&data);
				ret=delete_node(data,&root);
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
				break;
			case 9:
				ret=depth(root);
				printf("\n%d\n",ret);
				break;
			case 0:
				printf("\n\n\t\t\t\t\tThanx...\n");
				return 0;
			default:
				printf("Wrong Input.Plz enter again ... \n");
				break;
		}
	}
}
