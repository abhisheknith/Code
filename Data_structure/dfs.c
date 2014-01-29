#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
int time=0;
struct node 
{
	char color;
	int vertexnumber;
	int st,ft;
	struct node *next;
};
struct graph
{
	int v,e;
	struct node *head;
};
struct graph *CreateGraph()
{
	int i;
	int e,v;
	int x,y;
	printf("enter the number of vertices and edges");
	printf("\nvertices=");
	scanf("%d",&v);
	fflush(stdin);
	printf("edges="); 
	scanf("%d",&e);
	struct graph *g=(struct graph *)malloc(sizeof(struct graph));
	g->e=e;
	g->v=v;
	g->head=(struct node *)malloc(g->v * sizeof(struct node));
	for(i=1;i<=v;i++)
	{
		g->head[i].st=g->head[i].ft=0;
		g->head[i].vertexnumber=i;
		g->head[i].color='w';
		g->head[i].next=NULL;
	}	
	printf("\nenter the edges now");
	for(i=1;i<=e;i++)
	{
		printf("\n\nu=");
		scanf("%d",&x);
		printf("v=");
		scanf("%d",&y);
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		if(!temp)
		{
			printf("\nmemory error ");
			return NULL;
		}
		temp->vertexnumber=y;
		temp->color='w';
		
		temp->st=temp->ft=0;
		temp->next=g->head[x].next;
		g->head[x].next=temp;
	}
	return g;
}
void DFS_Visit(struct graph *g,struct node *i)
{
	i->color='g';
	printf("%d ",i->vertexnumber);
	time++;
	i->st=time;
	struct node *temp=i->next;
	for(;temp;temp->next)
	{
		if(temp->color=='w')
			DFS_Visit(g,temp);
	}
	i->color='b';
	i->ft=time=time+1;
}
void DFS(struct graph *g)
{
	int i;
	
	for(i=1;i <= g->v;i++)
	{
		if(g->head[i].color=='w')
			DFS_Visit(g,&(g->head[i]));
	}
}
		
	
		
int main()
{
	struct graph *g=CreateGraph();
	printf("\nthe dfs of the tree\n");
	DFS(g);	
//	getch();
}
