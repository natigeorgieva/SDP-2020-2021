#pragma once
#include<iostream>
class Film
{
private:
	std::string name;
	int size;
	int max_size;
	double* rating;

public:

	Film();
	~Film();
	Film(const Film&);
	Film& operator=(const Film&);
	Film(const double*, int MaxSize, std::string name);

	Film operator+(double);
	bool operator>=(const Film&);
	void operator-(int);

	void Print()
	{
		for (int i = 0; i < size; i++)
			std::cout << rating[i] << " ";
		std::cout << std::endl;
	}
	friend Film operator+(double, const Film&);
	friend std:: istream &operator>>(std::istream &input, Film&);//Ако използваме using namespace std, няма да се налага да пишем std::
	friend std::ostream& operator<<(std::ostream& out, const Film&);

};
