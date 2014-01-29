#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	vector<int>v(10);
	int i=0;
	ifstream ifp("data",ios::in);
	while(!ifp.eof())
	{
		ifp>>v[i++];
		if(i%10==0)
			v.resize(v.size()+10);
	}
	v.resize(i-1);
	for(auto i:v)
		cout<<i<<endl;
	return 0;
}
