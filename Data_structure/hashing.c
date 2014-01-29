#include<stdio.h>
#include<stdlib.h>
#define size 10
#define hash_key(a) a%size
struct node
{
	int data;
	int key;
}hash[size];

int put(int data)
{
	int k=hash_key(data);
	int j=k;
	while(hash[k].key!=0)
	{
		k=(k+1)%size;
		if(j==k)
			return -1;
	}
	hash[k].data=data;
	hash[k].key++;
	return -1;
}

int get(int data)
{
	int j,k=hash_key(data);
	if(hash[k].key==0)
		return -1;
	j=k-1;
	while(hash[k].key!=0 )
	{
		if(hash[k].data==data)
			return 0;
		if(j==k)
			break;
		k=(k+1)%size;
	}
	return -1;
}

int delete(int data)
{
	int k=hash_key(data);
	if(hash[k].key==0)
		return -1;
	int j=k-1;
	while(hash[k].key!=0)
	{
		if(hash[k].data==data)
		{
			hash[k].data=0;
			hash[k].key=0;
			return 0;
		}
		if(j==k)
			break;
		k=(k+1)%10;
	}
	return -1;
}

int main()
{
	int data,choice=1,ret;
	while(choice)
	{
		printf("1:Put \t2:Get \t3:Delete \t4:Exit\n");
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
			case 4:
				return 0;
			default:
				printf("Wrong Input. Please try again ...\n");
				break;
		}
	}
	return 0;
}
