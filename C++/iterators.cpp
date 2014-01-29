#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

template<typename ForwardIterator>
void square(ForwardIterator first,ForwardIterator last)
{
	for(;first!=last;first++)
		*first=(*first)*(*first);
}

template<typename ForwardIterator>
void print(ForwardIterator first,ForwardIterator last)
{
	for(;first<last;first++)
		cout<<*first<<"\t";
	cout<<endl;
}

template<typename Bidirectional>
void reverse(Bidirectional first,Bidirectional last)
{
	for(--last;first<last;first++,--last){
		auto temp=*first;
		*first=*last;
		*last=temp;
	}
}

template<typename RandomAccess>
int BinarySearch(RandomAccess first,RandomAccess last,int num)
{
	int leng;
	RandomAccess mid;
	while(first<last)
	{
		leng=last-first;
		mid=first+leng/2;
		if(*mid<num)
			first=mid+1;
		else if(*mid>num)
			last=mid-1;
		else
			return 1;
	}
	return 0;
}

int main()
{
	vector<int> arr(11);
	int v=1;
	for(auto &i:arr)
		i=v++;
	square(arr.begin(),arr.end());
	print(arr.begin(),arr.end());
	int find=BinarySearch(arr.begin(),arr.end(),81);
	if(find)
		cout<<"Found.\n";
	else
		cout<<"Not Found.\n";
	reverse(arr.begin(),arr.end());
	print(arr.begin(),arr.end());
	return 0;
}
