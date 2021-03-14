#include <iostream>
#include<string>
using namespace std;

void Resize(char*& ptr, int& len)
{
	char* help = ptr;
  //Отново, като в задача 2, с помощен указател, който сочи същото като ptr, си помагаме за "увеличването" на размера на масива ни, като всъщност просто презаписваме данните
  //в ново заделения ни, който е двойно по-голям.
	ptr = new char[2 * len];
	for (int i = 0; i < len; i++)
		ptr[i] = help[i];
	delete[]help;
	len *= 2;
}

char* FillArray(string S, int len)
{
//Заделяме си динамично масив, към който ptr сочи, започваме да копираме елементите от S в масива ни, като при евентуален недостиг, 
//удвояваме размера на масива ни с функцията Resize.
	char* ptr = new char[len];
	int i = 0;
	while (S[i] != '\0')
	{
		if (i == len)
			Resize(ptr, len);
		ptr[i] = S[i];
		i++;

	}
	if (i != len)//Ако не сме стигнали края на масива по време на цикъла, просто записваме терминиращия символ и сме готови.
		ptr[i] = '\0';
 //В противен случай, отново трябва да порменим размера на масива. (Ако искате, тук може да си направите нова функция, която го увеличава само с 1, тъй не е нужно да се удвоява)
	else { Resize(ptr, len); ptr[i] = '\0'; }


	return ptr;
}

int main()
{
  string S;
	getline(cin, S);
	int n; cin >> n;
	char* ptr = FillArray(S, n);
	cout << ptr;
  delete [] ptr;
	return 0;
}

