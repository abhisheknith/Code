#include<stdio.h>

int main()
{
	int arr[9592],i=2,j,k=0,flag=0;
	i=2;
	while(i<100000)
	{
		for(j=2,flag=0;j<=i/2;j++)
			if(i%j==0)
			{
				flag=1;
				break;
			}
		if(flag==0)
		{
			arr[k++]=i;
		}
		i++;
	}
//	for(i=0;i<9592;i++)
//		printf("%d  %d\n",arr[i], i);
	return 0;
}
