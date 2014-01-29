#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v(10);
	for(int i=1;i<=10;i++)
		v[i-1]=2*i;
	for(vector<int>::iterator i=v.begin(); i != v.end(); i++)
		cout<<*i<<"\t";
	cout<<endl;
	for(auto &i:v)			//Call by value won't effect the vector
		i++;
	for(auto i:v)
		cout<<i<<"\t";
	cout<<endl;
	return 0;
}
