#include "Header.h"

IntArray::IntArray()
{
	arr = nullptr;
	 size = 0;
}

IntArray::IntArray(int n)
{
	arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	size = n;

}
IntArray::~IntArray()
{
	delete[] arr;
	size = 0;
}
int IntArray :: Size()
{
	return size;
}
int IntArray::get(int k)
{
	if (size > 0 && size >= k + 1)
		return arr[k];
	else if(size==0) std::cout<<"Size is 0";
  else std:: cout<<"Postition is out of bound";
}
void IntArray::put(int k, int value)
{
	if (size > 0 && size >= k + 1)
		arr[k] = value;
	else if(size==0) std::cout << "Cannot put value: Size is 0";
  else std:: cout<<"Cannot put value: position is out of bound";
}
