#include<iostream>
#include<math>
using namespace std;

inline double fcn(double x){	return x*x-1;}

inline double fcn2(double x){	return x*x*x*x-exp(x)-2;}

double root_find( double f(double),double a,double b,double eps,double *root)
{
	if(b-a<eps)
	{
		*root=static_cast<double>(b+a)/2;
		return f(*root);
	}
	else
	{
		if(f(a)*f((b+a)/2.0)<=0)
			return root_find(f,a,static_cast<double>(b+a)/2,eps,root);
		else
			return root_find(f,static_cast<double>(b+a)/2,b,eps,root);
	}
}

int main(void)
{
	double x;
	printf("Root Finder \n");
	root_find(fcn,0.0,4.0,0.0000001,&x);
	printf("root is at %g with residual %g \n",x,fcn(x));
	root_find(fcn2,0.0,14.0,0.0000001,&x);
	printf("root is at %g\n",x);
	return 0;
}
