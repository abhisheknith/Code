#include<iostream>
#include<cstdlib>
using namespace std;

bool is_connected(bool *graph[],int size)
{
	int old_size=0,c_size=0;
	bool *opn=new bool[size];
	bool *cls=new bool[size];
	for(int i=0;i<size;i++)
		opn[i]=cls[i]=false;
	opn[0]=true;
	while(c_size<size)
	{
		for(int i=0;i<size;i++)
		{
			old_size=c_size;
			if(opn[i] && (cls[i] == false))
			{	c_size++;
				cls[i]=true;
				for(int j=0;j<size;j++)
					opn[j]=opn[j]||graph[i][j];
			}
		}
		if(c_size==size)	return true;
		if(c_size==old_size)	return false;
	}
}

float prob(void) {
	static int next=rand();
	next = next * 1103515245 + 12345;
	float prb;
	prb=static_cast<float>( ((next/65536) % 32768))/32768;
	cout<<prb<<",";
	return prb;
}

int main()
{
	bool **graph;
	int size;
	cin>>size;
	float prb;
	cin>>prb;
	srand(time(0));
	graph=new bool*[size];
	for(int i=0;i<size;i++)
		graph[i]=new bool[size];
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(i==j)
				graph[i][j]=false;
			else
				graph[i][j]=graph[j][i]=(prob()<prb);

	for(int i=0;i<size;i++)
	{
		cout<<endl;
		for(int j=0;j<size;j++)
			cout<<graph[i][j]<<"\t";
	}
	cout<<endl;

	cout<<is_connected(graph,size)<<endl;
	return 0;
}
