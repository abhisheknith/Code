#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>

struct info
{
	int *arr;
	int low,high;
};

void swap(int *a,int *b) 
{
	*a=*a^*b;*b=*a^*b;*a=*a^*b;
}

void *quick_sort(void *in)
{
	struct info *inf=(struct info*)in;
	int *arr=inf->arr,low=inf->low,high=inf->high,ret;
	if(low>=high || low<0)
		return NULL;
	int pivot=arr[low];
	int i=low,j=high;
	while(i<j)
	{
		while(arr[j]>pivot)
			j--;
		while(arr[i]<=pivot)
			i++;
		if(i<j)
			swap(&arr[i],&arr[j]);
	}
	pthread_t thread_id1,thread_id2;
	arr[low]=arr[j];
	arr[j]=pivot;
	inf->low=low;
	inf->high=j-1;
	ret=pthread_create(&thread_id1,NULL,quick_sort,(void *)&inf);
	if(ret==-1)
		printf("%s\n",strerror(errno));
	ret=pthread_join(thread_id1,NULL);
	if(ret==-1)
		printf("%s\n",strerror(errno));
	inf->low=j+1;
	inf->high=high;
	struct info infi=*inf;
	ret=pthread_create(&thread_id2,NULL,quick_sort,(void *)&infi);
	if(ret==-1)
		printf("%s\n",strerror(errno));
	ret=pthread_join(thread_id2,NULL);
	if(ret==-1)
		printf("%s\n",strerror(errno));
}

int main()
{
	int size,ret;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	int arr[size],i;
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	pthread_t thread_id;
	struct info inf;
	inf.arr=arr;
	inf.low=0;
	inf.high=size-1;
	ret=pthread_create(&thread_id,NULL,quick_sort,(void *)&inf);
	if(ret==-1)
		printf("%s\n",strerror(errno));
	ret=pthread_join(thread_id,NULL);
	if(ret==-1)
		printf("%s\n",strerror(errno));
	for(i=0;i<size;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}
