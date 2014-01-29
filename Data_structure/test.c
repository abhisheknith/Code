#include<stdio.h>

int main()
{
	while(1)
	{
		int choice;
		printf("\f1:Insert\f2:Delete\f3:Print\f4:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			int ret,data;
			case 1:
				printf("Enter the Data :");
				scanf("%d",&data);
				ret=insert(data);
				if(ret==-1)
					printf("Queue is full.\n");
				else
					printf("Data %d is inserted to queue\n",data);
				break;
			case 2:
				ret=delete();
				if(ret==-1)
					printf("queue is Empty.\n");
				else
					printf("Deleted element is %d\n",ret);
				break;
			case 3:
				print();
				break;
			case 4:
				return 0;
			default:
				printf("Wrong Input.\f Please enter Again \n");
				break;
		}
	}
}
