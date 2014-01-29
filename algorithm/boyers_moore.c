#include<stdio.h>
int arr[26];
void auxilary_array(char str2[])
{
	int i=0,j;
	while(str2[i])
	{
		arr[str2[i]-'a']=i;
		i++;
	}
	return ;
}

int main()
{
	char str1[100],str2[20];
	int i=0;
	printf("Enter strings : \n");
	scanf("%s",str1);
	scanf("%s",str2);
	auxilary_array(str2);
	for(i=0;i<26;i++)
		printf("%d  %c\n",arr[i],i+'a');
	return 0;
}
