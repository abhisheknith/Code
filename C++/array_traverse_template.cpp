#include<iostream>
using namespace std;

template<class T>
inline void traverse(const T data[],int size=5)
{
	for(int i=0;i<size;++i)
		cout<<data[i]<<"\t";
	cout<<endl;
}

int main(void)
{
	int data[]={1,2,3,4,5};
	traverse(data);
	traverse(data,5);
	return 0;
}
