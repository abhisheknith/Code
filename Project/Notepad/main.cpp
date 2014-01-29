#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
	fstream in,out;
	if(argc!=2)
	{
		printf("No File in Use");
		out.open("Untitled.txt",ios::out|ios::in|ios::ate);
		printf("%c[2J",27);   //clears screen
		printf("%c[0;80H",27); 
		printf("Untitled.txt\n\n");
		while(out)
		{
			char str[100];
			out>>str;
			cout<<str;
		}
	}
	return 0;
}
