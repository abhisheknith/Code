#include <iostream>
#include <string.h>
using namespace std;

void swap(char str[],int m,int n ) {
	char temp=str[m];
	str[m]=str[n];
	str[n]=temp;
}
bool duplicate(char str[], int start, int end)
{   if(start == end) 
      return false; 
    else 
      for(; start<end; start++) 
        if (str[start] == str[end])
          return true;
    return false;
}
void Permute(char str[], int start, int end)
{
    if(start >= end){
      cout<<str<<endl;
      return;
    }
    for(int i=start;i<=end;i++)
    {  if(!duplicate(str,start,i))
       {
        swap(str,start,i);
        Permute(str,start+1,end);
        swap(str,start,i);
       }
    }
}

int main()
{
  char Str[]="abcd";
  Permute(Str,0,strlen(Str)-1);
  return 0;
}
