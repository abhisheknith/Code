#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 5
struct node 
{
	int data[M-1];
	int key;
	struct node *next[M];
};

void swap(int *a,int *b)
{
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}

int insert(int data,struct node **root)
{
	int i=0;
	if(*root==NULL)
	{
     	  	*root=malloc(sizeof(struct node));
		if(*root==NULL)
			return -1;
		(*root)->data[0]=data;
		bzero(&(*root)->next[0],M*sizeof(struct node*));
		(*root)->key=1;
		return 0;
	}

	struct node *temp=*root;

	while(temp->next[0])
	{
		while(data<temp->data[i])
			i++;
		insert(data,&temp->next[0]);
	}

	if(temp->key<M-1)
	{
		while(i<temp->key)
		{
			if(data<temp->data[i])
				swap(&data,&temp->data[i]);
			i++;
		}
		temp->data[i]=data;
		temp->key++;
		return 0;
	}
	else
	{
		
}

int main()
{
        struct node *root=NULL;
        int choice=1,data,ret;
        while(choice)
        {
		printf("\n\t\tMENU\n1:Insert\t2:Delete\t3:Print\t\t4:Print by level\t0:Exit\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("Enter the number : ");
                                scanf("%d",&data);
                                ret=insert(data,&root);
				if(ret==-1)
					printf("Insertion Failure.\n");
                                break;
   /*                     case 2:
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
                                break;*/
                        case 0:
				for(ret=0;ret<root->key;ret++)
					printf("%d\t",root->data[ret]);
                                printf("\n\n\t\t\t\t\tThanx...\n");
                                return 0;
                        default:
                                printf("Wrong Input.Plz enter again ... \n");
                                break;
                }
        }
}
