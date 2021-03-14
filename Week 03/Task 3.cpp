#include<iostream>
using namespace std;

bool AreTheFirstNTheSame(char* ptr1, char*ptr2,int n)
{
	if (n > Strlen(ptr1)+1 || n > Strlen(ptr2)+1)// Функция от 1-та задача
		return 0;
  
	//Вече сме си гарантирали, че и двата масива имат дължина поне n (това включва и терминиращия символ)
  
	for (int i = 0; i < n; i++)
		if (ptr1[i] != ptr2[i])
			return 0;

	return 1;
}

