#include<iostream>
#include<complex>
using namespace std;

template<class T>

inline void swap1(T& x,T& y)
{
	T c=x;
	x=y;
	y=c;
}

int main()
{
	int a=2,b=3;
	double c=3.3,d=4.4;
	complex<double>r(4.5,5.6),s(2.3,3.4);
	swap1(a,b);
	swap1(c,d);
	swap(r,s);
	cout<<a<<"\t"<<b<<endl;
	cout<<c<<"\t"<<d<<endl;
	cout<<r<<"\t"<<s<<endl;
	return 0;
}
