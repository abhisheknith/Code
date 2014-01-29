#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int testcases,r,c,i,j,count=0,s,min;
	unsigned char ch[250];

	memset((void *)ch , 1, 250);
	s=16;

	for(i=2;i<=s;i++)
	{
		for(j=3;j<=250;j++)
		{
			if(j%i==0 && j!=i)
				ch[j]=0;
		}
	}
	ch[0]=count;
	ch[1]=count;
	for(i=2;i<250;i++)
	{
		if(ch[i]==1)
		{
			count++;
			ch[i]=count;
		}
		else
			ch[i]=count;
	}

	scanf("%d",&testcases);

	while(testcases)
	{
		scanf("%d%d",&r,&c);

		char grid[r][c],line[c];
		count=0;

		for(i=0; i<r; i++)
		{
        		scanf("%s", line);
        		strncpy(grid[i], line, c);
    		}

		for(i=2;i<r-2;i++)
		{
			for(j=2;j<c-2;j++)
			{
				min=1;
				if(grid[i][j]=='^')
				{
					while( (j-min)>=0 &&  (j+min)<c && (i-min)>=0 && (i+min)<r)
					{
						if(grid[i][j-min]!='^')
							break;

						else if(grid[i][j+min]!='^')
							break;

						else if(grid[i-min][j]!='^')
							break;

						else if(grid[i+min][j]!='^')
							break;

						min++;
					}

				}
//				printf("%d\ti=%d\tj=%d\n",min,i,j);
				count+=ch[min-1];
			}
		}
		printf("%d\n",count);
		testcases--;
	}
	return 0;
}

