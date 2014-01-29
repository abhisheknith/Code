#include<stdio.h>
int main()
{
int n,j,m,k;
printf("enter the number you want");
scanf("%d",&n);

printf("enter the value of m");
scanf("%d",&m);

int  t[m][4];
int a[n];

for(j=0;j<n;j++)
a[j]=j+1;

printf("enter the four");
for(j=0;j<m;j++)
{
for(k=0;k<4;k++)
{
scanf("%d",&t[j][k]);
}
}

for(j=0;j<m;j++)
{
if(t[i][0]==1)
{
for(k=t[i][1]-1;k<t[i][2];k++)
{
a[k]+=t[i][3];
}
}
else if(t[i][0]==2)
{
for(k=t[i][1]-1;k<t[i][2];k++)
{
a[k]-=t[i][3];
}
}
}

int max=min=a[0];
for(j=0;j<n;j++)
{
if(a[j+1]>=max)
max=a[j+1];
else if(a[j+1]<=min)
min=a[j+1];
}

printf("%d",max-min);
}
