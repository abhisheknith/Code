#include<iostream>
using namespace std;

template<class T> class point
{
	T x,y;
	
	public:
	operator double()
	{
       		return x*x+y*y;
	}
	ostream& operator<<(ostream& out)
	{
		out<<"("<<x<<","<<y<<")";
		return out;
	}
	operator double();
	point():x(0.0),y(0.0){}
	point(T u):x(static_cast<double>(u)),y(0.0){}
	point(T u,T v):x(static_cast<double>(u)),y(static_cast<double>(v)){}
};


int main()
{
	point<double> p,p2(1,2.0);
	double d=3.5;
	p=d;
	cout<<p2;
	return 0;
}
