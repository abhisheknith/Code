#include<stdio.h>
int nit(int,int);
typedef int(*pf)(int,int);
int proc(pf,int,int);

int main ()
{
printf("%d\n",proc(nit,6,6));
return 0;
}
int nit(int a,int b)
{
return(a==b);
}
int proc(pf p,int a,int b)
{
return((*p)(a,b));
}
