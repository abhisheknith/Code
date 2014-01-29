#include<iostream>
using namespace std;

template<class T>
T sum(T arr[],int size)
{
	T total=0;
	for(int i=0;i<size;i++)
		total+=arr[i];
	return total;
}

int main(void)
{
	int arr[]={1,2,3,4,5};
	double arr1[]={1.1,2.1,3.1,4.1,5.1};
	cout<<sum(arr,5)<<endl<<sum(arr1,5)<<endl;
	return 0;
}
