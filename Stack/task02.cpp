#include <iostream>
#include <stack>
using namespace std;

stack<int> summ(stack<int> st1, stack<int> st2)
{
	stack<int> result;
	while (!st1.empty() && !st2.empty())
	{
		result.push(st1.top() + st2.top());
		st1.pop();
		st2.pop();
	}
	if (st1.empty() && st2.empty())
	{
		return result;
	}
	int sum = 0;
	if (st1.empty())
	{
		while (!st2.empty())
		{
			sum += st2.top();
			st2.pop();
		}
	}
	else
	{
		while (!st1.empty())
		{
			sum += st1.top();
			st1.pop();
		}
	}
	result.push(sum);
	return result;
}
