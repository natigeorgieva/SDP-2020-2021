#include<iostream>//Задължително се добавя при работа с вход и изход, ако го няма в header файла
#include "Vector.cpp" //По принцип добавяме header файла, но тъй като тук, в решените задачи, класа Vector e във файла Vector.cpp, добавяме него
using namespace std; //Ако не използвате namespace std, трябва да пиешeте std::istream и std::ostream

//cin и cout са обекти, представители на класовете съответно istream и ostream

//Особено важно е да подаваме обектите на двата класа istream и ostream като референции, 
//тъй като за тези два класа не съществува копиращ конструктор, който е нужен, ако подаваме по стойност.

//Тъй като операторите << и >> се декларират като приятелски фунцкии на класа ни Vector, дефинициите им са извън класа и 
//функциите имат пряк достъп до private елементите на класа.

istream& operator>>(istream& in, Vector& obj)
{
	cout << "Enter max_size for Vector: " << endl;
	in >> obj.max_size;
	while (obj.max_size <= 0)
		in >> obj.max_size;
	delete[] obj.ptr;
	obj.ptr = new float[obj.max_size];
	cout << "Enter size for Vector: " << endl;
	in >> obj.size;
	while (obj.size > obj.max_size || obj.size < 0)
		in >> obj.size;
	if (obj.size > 0)
		cout << "Enter elements of Vector: " << endl;
	for (int i = 0; i < obj.size; i++)
		in >> obj.ptr[i];
	return in;
}

ostream& operator<<(ostream& out, const Vector& obj) 
{
	int len = obj.size;
	for (int i = 0; i < len; i++)
		cout << obj.ptr[i] << " ";
	cout << endl;
	return out;
}


int main()
{
  Vector vec;
  cin>>vec;
  cout<<vec;
  
  return 0;
}
