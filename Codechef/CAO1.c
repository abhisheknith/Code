#include<stdio.h>
#include<string.h>
int main()
{
	int testcases,r,c,i,j;

	scanf("%d",&testcases);

	while(testcases)
	{
		scanf("%d%d",&r,&c);

		char grid[r][c],line[c];
		int count=0;

		for(i=0; i<r; i++) 
		{
        		scanf("%s", line);
        		strncpy(grid[i], line, c);
    		}

		for(i=2;i<r-2;i++)
		{
			for(j=2;j<c-2;j++)
			{
				int l=0,r=0,b=0,t=0;
				if(grid[i][j]=='^')
				{
					if(grid[i][j+1]=='^' && grid[i][j+2]=='^' ) //for the right traversal
					{
						r=2;
					}
					if(grid[i][j-1]=='^' && grid[i][j-2]=='^') //for the left traversal
					{
						l=2;
					}
					if(grid[i+1][j]=='^' && grid[i+2][j]=='^') //for the bottom traversal
					{
						b=2;
					}
					if(grid[i-2][j]=='^' && grid[i-1][j]=='^') //for the top traversal
					{
						t=2;
					}
				}
				if(l>1 && b>1 && r>1 && t>1)
				{
					count++;
				}
			}
		}
		printf("%d\n",count);
		testcases--;
	}
	return 0;
}

