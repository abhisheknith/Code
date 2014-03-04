#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<vector <int> (3)> board(3);
	for(auto &row:board)
		for(auto &box:row)
			box=0;
	return 0;
} 
