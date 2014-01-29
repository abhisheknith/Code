#include<stdio.h>

void swap(int *a,int *b)
{
        *a=*a^*b,*b=*a^*b,*a=*a^*b;
}

void quick_sort(int arr[],int arr2[],int low,int high)
{
	if(low>=high)
		return;
	int pivot=arr[low];
	int pivot2=arr2[low];
	int i=low,j=high;
	while(i<j)
	{
		while(arr[j]<pivot)
			j--;
		while(arr[i]>=pivot)
			i++;
		if(i<j)
		{
			swap(&arr[i],&arr[j]);
			swap(&arr2[i],&arr2[j]);
		}
	}
	arr[low]=arr[j];
	arr2[low]=arr2[j];
	arr[j]=pivot;
	arr2[j]=pivot2;
	quick_sort(arr,arr2,low,j-1);
	quick_sort(arr,arr2,j+1,high);
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i,arr[2][n],arr1[2][n],max1,max2,num,pivot1,pivot2,count,time=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&arr[0][i],&arr[1][i]);
			arr1[0][i]=arr[0][i];
			arr1[1][i]=arr[1][i];
		}
		int row[n],col[n],j;
		for(i=0;i<n;i++)
		{
			row[i]=arr[0][i];
			col[i]=arr[1][i];
		}
		num=n;
		while(num>0)
		{
			quick_sort(arr[0],arr[1],0,n-1);
			quick_sort(arr1[1],arr1[0],0,n-1);
			count=1;
			for(i=1;i<n;i++)
			{
				if(arr[0][i]==-1)
					continue;
				if(arr[0][i]==arr[0][i-1])
					count++;
				else
					count=1;
				if(max1<count)
				{
					max1=count;
					pivot1=arr[0][i];
				}
			}
			count=1;
			for(i=1;i<n;i++)
			{
				if(arr1[1][i]==-1)
					continue;
				if(arr1[1][i]==arr1[1][i-1])
					count++;
				else
					count=1;
				if(max1<count)
				{
					max1=count;
					pivot2=arr1[1][i];
				}
			}
			if(max1>=max2)
			{
				num-=max1;
				for(i=0;i<n;i++)
				{
					if(arr[0][i]==pivot1)
						arr[0][i]=arr[1][i]=-1;
					if(arr1[0][i]==pivot1)
						arr1[0][i]=arr1[1][i]=-1;
				}
			}
			else
			{
				num-=max2;
				for(i=0;i<n;i++)
				{
					if(arr[1][i]==pivot2)
						arr[0][i]=arr[1][i]=-1;
					if(arr1[1][i]==pivot2)
						arr1[0][i]=arr1[1][i]=-1;
				}
			}
		time++;
		}
		printf("%d\n",time);
	}
	return 0;
}
