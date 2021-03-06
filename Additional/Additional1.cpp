#include "stdafx.h"
#include <iostream>

using namespace std;

class Sequence
{
private:
	int* data;
	int size;

public:
	Sequence()
	{
		data = nullptr;
		size = 0;
	}

	Sequence(unsigned int n)
	{
		data = new int[n];
		size = n;
	}

	Sequence(const Sequence& other)
	{
		data = new int[other.size];
		size = other.size;

		for (int i = 0; i < other.size; i++)
		{
			data[i] = other.data[i];
		}
	}

	Sequence& operator=(const Sequence& other)
	{
		if (this != &other)
		{
			delete[] data;
			size = other.size;
			data = new int[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
		}

		return *this;
	}

	~Sequence()
	{
		delete[] data;
	}

	void push_back(int n)
	{
		size += 1;
		int *temp = new int[size];

		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = data[i];
		}

		temp[size - 1] = n;

		delete[] data;
		data = temp;
	}

	void removeLast()
	{
		size -= 1;
		int *temp = new int[size];

		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}

		delete[] data;
		data = temp;
	}

	void removeFirst()
	{
		size -= 1;
		int *temp = new int[size];

		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i + 1];
		}

		delete[] data;
		data = temp;
	}

	int sum()
	{
		int sum = 0;

		for (int i = 0; i < size; i++)
		{
			sum += data[i];
		}

		return sum;
	}

	bool isArithmeticProgression()
	{
		int d = data[1] - data[0];

		for (int i = 1; i < size - 1; i++)
		{
			if (data[i + 1] - data[i] != d)
			{
				return false;
			}
		}

		return true;
	}

	int& operator[](unsigned int i)
	{
		return data[i];
	}

	Sequence operator+(const Sequence& other)
	{
		if (this->size != other.size)
		{
			cout << "Invalid input" << endl;
			return Sequence();
		}

		Sequence result(size);
		for (int i = 0; i < size; i++)
		{
			result[i] = this->data[i] + other.data[i];
		}

		return result;
	}

	friend ostream& operator<<(ostream& out, const Sequence& seq);
};

ostream& operator<<(ostream& out, const Sequence& seq)
{
	for (int i = 0; i < seq.size; i++)
	{
		out << seq.data[i] << " ";
	}
	out << endl;

	return out;
}


int main()
{
	Sequence seq1(3);
	seq1[0] = 3;
	seq1[1] = 11;
	seq1[2] = 17;

	Sequence seq2;
	seq2.push_back(1);
	seq2.push_back(2);
	seq2.push_back(3);

	Sequence result = seq1 + seq2;
	cout << result;

    return 0;
}