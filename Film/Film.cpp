#include"Header.h"

Film::Film()
{
	name = "";
	size = max_size = 0;
	rating = nullptr;
}

Film::~Film()
{
	delete[]rating;
}

Film::Film(const Film& other)
{
	name = other.name;
	size = other.size;
	max_size = other.max_size;
	rating = new double[max_size];
	for (int i = 0; i < size; i++)
		rating[i] = other.rating[i];
}
Film& Film:: operator=(const Film& other)
{
	name = other.name;
	size = other.size;
	max_size = other.max_size;
	delete[] rating;
	rating = new double[max_size];
	for (int i = 0; i < size; i++)
		rating[i] = other.rating[i];
	return *this;
}

Film::Film(const double* arr, int MaxSize, std::string name)
{
	size = MaxSize;
	max_size = MaxSize;
	rating = new double[max_size];
	for (int i = 0; i < max_size; i++)
		rating[i] = arr[i];
	this->name = name;
}

Film Film::operator+(double num)
{
	Film temp;
	temp.name = name;
	temp.max_size = size + 1;
	temp.rating = new double[temp.max_size];
	for (int i = 0; i < max_size - 1; i++)
		temp.rating[i] = rating[i];
	temp.rating[max_size - 1] = num;
	temp.size = max_size;
	return temp;
}

bool Film::operator>=(const Film& other)
{
	double first = 0; double second = 0;
	for (int i = 0; i < size; i++)
		first += rating[i];
	for (int i = 0; i < other.size; i++)
		second += other.rating[i];
	first /= size; second /= other.size;
	return first >= second;
}

void Film::operator-(int n)
{
	if (n <= size && n >= 0)
		size -= n;
}
