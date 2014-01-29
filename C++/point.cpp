//Implementing operator(+ and <<)  overloading on template class point to represent coordinates (x,y)

#include<iostream>
using namespace std;

template<class T> class point
{
	T x,y;									//Variables
	
    public:
	friend ostream& operator<<(ostream& out,point<double> p);		//Prototypes and friend funtion
	explicit operator double();
	point operator+(point p)
	{
		return point(x+p.x,y+p.y);
	}

	point():x(0.0),y(0.0){}							//Constructors
	point(T u):x(static_cast<double>(u)),y(0.0){}
	point(T u,T v):x(static_cast<double>(u)),y(static_cast<double>(v)){}
};

ostream& operator<<(ostream& out,point<double> p)
{
	out<<"("<<p.x<<","<<p.y<<")";
	return out;
}

template<> point<double>::operator double()
{
	return x*x+y*y;
}

int main()
{
	point<double> p,p2(1,2.0);
	double d=3.5;
	p=d;
	cout<<p<<"+"<<p2<<"=";
	cout<<p+p2<<endl;
	return 0;
}
