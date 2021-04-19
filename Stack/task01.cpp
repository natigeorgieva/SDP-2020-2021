#include <iostream>
#include <stack>
using namespace std;


void print_stack(stack<int> st)
{
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
int main()
{
  int el;
	cin >> el;
	while (el != 0)
	{
		st.push(el);
		cin >> el;
	}

	stack<int> even, odd;

	while (!st.empty())
	{
		if (st.top() % 2 == 0)
		{
			even.push(st.top());
		}
		else
			odd.push(st.top());
		st.pop();
	}
	print_stack(even);
	print_stack(odd);
	
	return 0;
}
