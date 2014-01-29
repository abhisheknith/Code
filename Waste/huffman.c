#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

in(struct node *start)
	   {
		if(start==NULL)
			return;
		in(start->left);
		printf("%d ",start->data);
		in(start->right);
	   }
int *freq(char str[],char ch[],struct node *f[],int len)
{
	int i,j,k=-1,length;
	for(i=0;i<len;i++)
	  {
	    f[i]=(struct node *)malloc(sizeof(struct node));
	    f[i]->data=1;
	    f[i]->left=NULL;
	    f[i]->right=NULL;
	  }

	for(i=0;i<len;i++)
	  {
	    if ( str[i] != '1' )
	      {
		 k++;

		ch[k]=str[i];

	 	for(j=i+1;j<len;j++)
    	           if(str[j]==str[i])
	              {
		        f[k]->data++;
			str[j]='1';
		      }
	      }
	  }
	for(length=0;ch[length];length++);

	for(i=0;i<length;i++)
	  printf("%c",ch[i]);
	   printf("\n");
	for(i=0;i<length;i++)
	  printf("%d",f[i]->data);

	 printf("\n");

	return &length;
}

struct node *delmin(struct node *f[],int n)
{
	heapsort(f,n);

	return f[n-1];
}

heapsort(struct node *a[],int n)
{
	int i,t;
//	char k;
	heapify(a,n);

	for(i=n;i>=2;i--)
	 {
	   t=a[i-1]->data;
	   a[i-1]->data=a[0]->data;
	   a[0]->data=t;

	  adjust(a,1,i-1);
	}

}

heapify(struct node *a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	 adjust(a,i,n);
}

adjust(struct node *a[],int i,int n)
{
	int j,item;
//	char k;
	j=2*i;
	item=a[i-1]->data;
//	k=ch[i-1]
	while(j<=n)
	{
	  if(j<n && (a[j-1]->data) > (a[j]->data))
	    j=j+1;

	   if(item <= (a[j-1]->data))
	    break;
	   else
	    {
	      a[(j/2)-1]->data = a[j-1]->data;
//	      ch[(j/2)-1]=ch[j-i];
	      j=2*j;
	    }
	}
        a[(j/2)-1]->data=item;
//	ch[(j/2)-1]=k;
}

insert(struct node *a[],int data,int i)
{
	a[i]->data=data;
	heapify(a,i+1);
	return;
}

struct node *huffman(int len,struct node *f[])
{
	int i;
	struct node *temp;
	for(i=len;i>1;i--)
	{
	   temp=(struct node *)malloc(sizeof(struct node));
//	   temp->left=(struct node *)malloc(sizeof(struct node));
//	   temp->right=(struct node *)malloc(sizeof(struct node));
	   temp->left=delmin(f,i);
	   temp->right=delmin(f,i-1);

	   temp->data=(temp->left)->data + (temp->right)->data;
		printf("%d ",temp->data);
	   insert(f,temp->data,i-2);
	}
	printf("\n");
	return f[i-1];

}

main()
{
	char str[30];
	int len;

	printf("enter the string\n");
	scanf("%s",str);

	for(len=0;str[len]!='\0';len++);

	 struct node *f[len];
	 char ch[len];

	len=*freq(str,ch,f,len);

	struct node *start = huffman(len,f);
      /* int i;
	for(i=0;i<5;i++)
	  {
	  printf("%d",start->data);
	  start=start->left;
	  }*/
	in(start);
}
