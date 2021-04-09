// BonusTask.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

class Vector
{
private:
	//declaring the member-fields
	float* arr;		//pointer, which will become a dynamic array
	int size;		//number of the elements in the array
	int max_size;	//number for how many elements we could store in the array

	//when max_size is reached (when size = max_size), resize it
	void resize()
	{
		max_size *= 2;

		float* buffer = new float[max_size];	//creating the new dynamic array
		for (int i = 0; i < size; i++)	//copying from arr into buffer
		{
			buffer[i] = arr[i];
		}

		delete[] arr;	//deallocating arr
		arr = buffer;	//redirect the pointer arr
	}

public:
	//default constructor
	Vector()
	{
		max_size = 10;
		arr = new float[max_size];	//allocating memory
		size = 0;
	}

	//constructor with parameters
	Vector(float* _arr, int _size)
	{
		max_size = 10 + _size;
		arr = new float[max_size];	//allocating memory

		for (int i = 0; i < _size; i++)	//copying from _arr to arr
		{
			arr[i] = _arr[i];
		}

		size = _size;
	}

	//copy-constructor
	Vector(const Vector& other)
	{
		//copying values from the other vector and allocating memory for arr
		max_size = other.max_size;
		size = other.size;
		arr = new float[other.max_size];

		for (int i = 0; i < other.size; i++)	//copying elements from the other vector into arr
		{
			arr[i] = other.arr[i];
		}
	}
	
	//destructor
	~Vector()
	{
		delete[] arr;	//deallocating the dynamically allocated memory
	}

	int getSize()
	{
		return size;
	}
	
	friend std::istream& operator>>(std::istream&, Vector&);
	
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	//вижте файла Input&Output.cpp за дефинициите

};



int main()
{
	
    return 0;
}

