#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data,lrange,rrange;
	struct node *left,*right;
};

int sum(int lrange,int rrange,int *arr)
{
	if(lrange>rrange)
		return -1;
	int i,sum=0;
	for(i=lrange;i<=rrange;i++,arr++)
		sum+=*arr;
	return sum;
}

int insert(int lrange,int rrange,int *arr,struct node **root,struct node *temp_root)
{
	if(*root==NULL)
	{
		*root=malloc(sizeof(struct node));
		if(!(*root))
			return -1;
		(*root)->data=sum(lrange,rrange,arr);
		(*root)->lrange=lrange;
		(*root)->rrange=rrange;
		(*root)->left=(*root)->right=NULL;
		temp_root=*root;
	}
	struct node *tp,*tmp,*temp=temp_root;
	tmp=malloc(sizeof(struct node));
	if(!tmp)
		return -1;
	tmp->data=sum(lrange,(lrange+rrange)/2,arr+lrange);
	tmp->lrange=lrange;
	tmp->rrange=(lrange+rrange)/2;
	tmp->left=tmp->right=NULL;
	temp->left=tmp;
	if(tmp->lrange<(tmp->lrange+tmp->rrange+1)/2)
		insert(lrange,(lrange+rrange)/2,arr,root,temp_root->left);

	tp=malloc(sizeof(struct node));
	if(!tp)
		return -1;
	tp->data=sum((lrange+rrange)/2+1,rrange,arr+((lrange+rrange)/2+1));
	tp->lrange=(lrange+rrange)/2+1;
	tp->rrange=rrange;
	tp->left=tp->right=NULL;
	temp->right=tp;
	if(tp->lrange<(tp->lrange+tp->rrange+1)/2)
		insert((lrange+rrange)/2+1,rrange,arr,root,temp_root->right);
	return 0;
}

int sum_tree(int lrange,int rrange,struct node *root)
{
	if(lrange>rrange)
		return -1;
	static int sum=0;
	if(lrange>root->rrange || rrange<root->lrange)
		return 0;
	if(lrange<=root->lrange && rrange>=root->rrange)
		return root->data;
	else
		sum=sum_tree(lrange,rrange,root->left)+sum_tree(lrange,rrange,root->right);
	return sum;
}
	
void print(struct node *tmp)
{
        if(tmp==NULL)
                return;
        print(tmp->left);
        printf("%d  l=%d  r=%d\n",tmp->data,tmp->lrange,tmp->rrange);
        print(tmp->right);
        return;
}

int main()
{
	struct node *start=NULL;
	int size,i=0,lrange,rrange;
	scanf("%d",&size);
	int *arr;
	arr=malloc(sizeof(int)*size);
	if(!arr)
	{
		printf("Allocation Failure.\n");
		return 0;
	}
	while(i<size)
		scanf("%d",&arr[i++]);
	int ret=insert(0,size-1,arr,&start,NULL);
	if(ret==-1)
		printf("Insertion Fails.\n");
	while(1)
	{
		printf("\nEnter the range :\n");
		scanf("%d%d",&lrange,&rrange);
		printf("Sum is %d\n",sum_tree(lrange,rrange,start));
	}
	print(start);
	printf("\n");
	return 0;
}
