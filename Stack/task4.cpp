int sum_stack(stack<int> st)
{
	int sum = 0;
	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	return sum;
}

stack<stack<int>> interval(stack<stack<int>> st, int a, int b)
{
	stack<stack<int>> result;
	int s;
	while (!st.empty())
	{
		s = sum_stack(st.top());
		if (s >= a && s <= b)
		{
			result.push(st.top());
		}
		st.pop();
	}
	return result;
}
