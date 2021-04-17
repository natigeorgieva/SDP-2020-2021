#include<iostream>
#include<stack>
using namespace std;

class Point
{
private:
	int x, y, z;
	char* ptr;
public:
	Point()
	{
		x = y = z = 0;
		ptr = nullptr;
	}
	~Point()
	{
		delete[]ptr;
	}
	Point(int x1, int y1, int z1, const char* name)
	{
		x = x1; y = y1; z = z1;
		int k = strlen(name);
		ptr = new char[k + 1];
		for (int i = 0; i < k + 1; i++)
			ptr[i] = name[i];
	}
	Point(const Point& other) 
	{
		x = other.x;
		y = other.y;
		z = other.z;
		int i = 0;
		while (other.ptr[i] != '\0')
		{
			i++;
		}
		ptr = new char[i+1];
		for (int j = 0; j < i + 1; j++)
			ptr[j] = other.ptr[j];
	}
	bool operator<(const Point& other) const
	{
		if (x < other.x)
			return true;
		else if (x == other.x && y < other.y)
			return true;
		else if (x == other.x && y == other.y && z < other.z)
			return true;
		return false;
	}



	friend ostream& operator<<(ostream& out, const Point& obj);

	Point& operator=(const Point& other)
	{
		if (this == &other)
			return *this;
		x = other.x;
		y = other.y;
		z = other.z;
		int i = 0;
		while (other.ptr[i] != '\0')
		{
			i++;
		}
		delete[] ptr;
		ptr = new char[i + 1];
		for (int j = 0; j < i + 1; j++)
			ptr[j] = other.ptr[j];
		return *this;

	}

	
};

ostream& operator<<(ostream& out, const Point& obj)
{
	out << obj.ptr << " ";
	out << "(" << obj.x << ", " << obj.y << ", " << obj.z << ")" << endl;
	return out;
}

void swap(Point& obj1, Point& obj2)
{
	Point temp;
	temp = obj1;
	obj1 = obj2;
	obj2 = temp;
}

void Sort(Point arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


int main()
{

	Point p1(1, 2, 3, "1");
	Point p2(2, 2, 3, "2");
	Point p3(2, 3, 3, "3");
	Point p4(2, 3, 4, "4");
	//Може и с cin, ако си го предефинираме, вместо цялата тази занимавка
	Point arr[4];
	arr[0] = p2;
	arr[1] = p4;
	arr[2] = p1;
	arr[3] = p3;

	Sort(arr, 4);
	for (int i = 0; i < 4; i++)
		cout << arr[i];
	


	return 0;
}
