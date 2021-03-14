#include<iostream>
using namespace std;

void ConcatN(int ptr1len, int ptr2len, char*& ptr1, char* ptr2, int N)//Подаваме си и дъжлжината на заделената памет, 
//тъй като няма как да я извлечем от някъде, а трябва да я помним.
{
	int len1 = Strlen(ptr1);
	int len2 = Strlen(ptr2);
	if (N >= 1 && N <= len2)
	{
		if (len1 + N <= ptr1len - 1)//Дължината на масива - 1,тъй като запазваме място за терминиращата нула ('\0')
		{
			for (int i = 0; i < N; i++)
				ptr1[len1 + i] = ptr2[i];
			ptr1[len1 + N] = '\0';
		}
		else
		{
			char* Help = ptr1;
      //Правим си помощен указател, който ни сочи, каквото сочи и ptr1, след това заделяме нова памет за ptr1, която да побере прилепянето на символите.
      //След което копираме всичко от масива, който Help сочи (първоначалния ни), в новия, който ptr1 сочи. След това копираме N символа от ptr2 и слагаме треминиращия символ.
			ptr1 = new char[len1 + N + 1];
			for (int i = 0; i < len1; i++)
				ptr1[i] = Help[i];
			for (int i = 0; i < N; i++)
				ptr1[len1 + i] = ptr2[i];
			ptr1[len1 + N] = '\0';
			delete[] Help;//Не забравяме да освободим паметта от първоначалния масив, тъй като не ни трябва повече.
		}
	}
	else return;
}

int main()
{
  int n;
	cin >> n;
	char* ptr1 = new char[n];// В общия случай може двата масива да са с различна дължина, но за улеснение нека са с една и съща
	char* ptr2 = new char[n];
	cin.ignore();//Иначе няма да се запише нищо в ptr1, тъй като преди getline сме ползвали cin
	cin.getline(ptr1, n);
	cin.getline(ptr2, n);
	cout << ptr1 << endl;//Ако масивът е от тип char, при използването на cout се изкарват симовлите, които съдържа, на екрана, а не адреса на първата клетка (както беше при int).
	cout << ptr2 << endl;
	ConcatN(n, n, ptr1, ptr2, 5);//5 в случая е произовлен брой символи, които да се прилепчт от ptr2 в края на ptr1
	cout << ptr1;
  return 0;
}
