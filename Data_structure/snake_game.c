#include<stdio.h>

#define MAXROW 30
#define MAXCOL 150

void display();
void snake();
void food();
void start();

static int snake_len,arr[MAXROW][MAXCOL];

int main()
{
	start();
	display();
}

void start()
{
	int i,j;
	for(i=0;i<MAXROW;i++)
		arr[i][1]=arr[i][MAXCOL-1]=-1;
	for(i=0;i<MAXCOL;i++)
		arr[1][i]=arr[MAXROW-1][i]=-1;
	for(i=70;i<80;i++)
		arr[15][i]=1;
}
	
void display()
{
	printf("%c[2J",27);
	int i,j;
	for(i=1;i<MAXROW;i++)
	{
        	for(j=1;j<MAXCOL;j++)
		{
			printf("%c[%d;%dH",27,i,j);
			if(arr[i][j]==-1)
				printf("+");
			if(arr[i][j]==1)
				printf("*");
		}
	}
	printf("%c[35;1H",27);
}
