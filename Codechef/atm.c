#include<stdio.h>

int main()
{
	unsigned int fetch;
	float initial_bal,final_bal;
	scanf("%d%f",&fetch,&initial_bal);
	if(fetch && (fetch+0.5)<=initial_bal && fetch%5==0)
		final_bal=initial_bal-fetch-0.50;
	else
		final_bal=initial_bal;
	printf("%.2f\n",final_bal);
	return 0;
}
