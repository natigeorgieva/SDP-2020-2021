#include <iostream>
#include<fstream>
#include<string>
//Във файла "new.txt" вече е записан текста "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
//Във функцията TextChange създаваме файла "example.txt", в който записваме вече променения текст.

void TextChange(fstream& file, char a, char b)
{
  file.close();//Затваряме файла "new.txt", въпреки че и автоматично ще стане
	file.open("example.txt");
	string str;
	getline(file, str);//Записваме си във стринг съдържаението на файла
	int i = 0;
	ofstream myFile("new.txt");//Отваряме си нов файл за записването на променения текст и го записваме символ по символ
	while (str[i] != '\0')
	{
		if (str[i] == a)
		{
			myFile << '"'<<b<<'"';
			i++;
			continue;
		}
		myFile << str[i];
		i++;
	}
file.close();
}

int main()
{
  fstream file("new.txt");
  file<<"Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  TextChange(file, 'o', 'u');
	
  return 0;
}
