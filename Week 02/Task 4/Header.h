#pragma once
#include<iostream>

class IntArray {

private:

	int size;
	int* arr;

public:
	IntArray();
	IntArray(int);
	~IntArray();
	int Size();
	int get(int);
	void put(int, int);
};

