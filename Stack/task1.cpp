stack<int> rev(stack<int> a)
{
	stack<int> b;
	while (!a.empty())
	{
		b.push(a.top());
		a.pop();
	}
	return b;
}
