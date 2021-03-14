#include<iostream>
using namespace std;

int Strlen(char* ptr)
{
	int i = 0;
	int count = 0;
	while (ptr[i] != '\0')
	{
		count++;
		i++;
	}
	return count;
}

int main()
{
  char ptr[]="Hello";
  cout<<Strlen(ptr);
  return 0;
}
