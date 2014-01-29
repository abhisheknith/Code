#include<iostream>
using namespace std;

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
	short int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int in[n],out[n];
		for(i=0;i<n;i++)
			cin>>in[i];
		for(i=0;i<n;i++)
			cin>>out[i];
		quick_sort(out,in,0,n-1);
		for(i=0;i<n;i++)
			cout<<in[i]<<"\t"<<out[i]<<"\n";
		
	}	
	return 0;
}
