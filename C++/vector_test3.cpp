#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void getw(string& t,ifstream& in)
{
	in>>t;
}

int read_string(vector<string>&words,ifstream& in)
{
	int i=0;
	while(!in.eof())
		getw(words[i++],in);
	return i-1;
}

int main()
{
	ifstream in("text");
	vector<string> words(100);
	int hm=read_string(words,in);
	words.resize(hm);
	sort(words.begin(),words.end());
	for(auto str:words)
		cout<<str<<"\t";
	cout<<endl;
	return 0;
}
