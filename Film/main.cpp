#include"Header.h"
#include<string>
using namespace std; //Ако не използвате namespace std, трябва да пиешeте std::istream и std::ostream

//cin и cout са обекти, представители на класовете съответно istream и ostream

//Особено важно е да подаваме обектите на двата класа istream и ostream като референции, 
//тъй като за тези два класа не съществува копиращ конструктор, който е нужен, ако подаваме по стойност.

//Тъй като операторите << и >> се декларират като приятелски фунцкии на класа ни Vector, дефинициите им са извън класа и 
//функциите имат пряк достъп до private елементите на класа.

//От фунцкиите на вход и изход връщаме съответния поток, за да може да го използваме няколко пъти наведнъж 
//Пр: Film f1, f2, f3; 
//cin>>f1>>f2>>f3;

istream& operator>>(istream& in, Film& obj)
{
	getline(in, obj.name);
	cout << "Enter max number of ratings: " << endl;
	in >> obj.max_size;
	while (obj.max_size <= 0)
		in >> obj.max_size;
	delete[] obj.rating;
	obj.rating = new double[obj.max_size];
	cout << "Enter number of ratings: " << endl;
	in >> obj.size;
	while (obj.size > obj.max_size || obj.size < 0)
		in >> obj.size;
	if (obj.size > 0)
		cout << "Submit the ratings: " << endl;
	for (int i = 0; i < obj.size; i++)
		in >>obj. rating[i];
	return in;
}

ostream& operator<<(ostream& out, const Film& obj)
{
	out << "Name: ";
	out << obj.name << endl;
	cout << "Ratings: ";
	for (int i = 0; i < obj.size; i++)
		cout << obj.rating[i] << " ";
	cout << endl;
	return out;

}

Film operator+(double num, const Film& object)//Принципът на работа е абсолютно същият като на член фунцкията operator+
{
	Film temp;
	temp.name =object. name;
	temp.max_size = object.size + 1;
	temp.rating = new double[temp.max_size];
	for (int i = 0; i < object.max_size - 1; i++)
		temp.rating[i] = object.rating[i];
	temp.rating[object.max_size - 1] = num;
	temp.size = object.max_size;
	return temp;
}

int main()
{
	Film f;
	cin >> f;
	cout << f;
	return 0;
}
