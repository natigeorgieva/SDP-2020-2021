stack<int> fibb(int n)
{
	
	stack<int> f;
	if (n <= 0)
		return f;
	f.push(0);
	if (n == 1)
	 return f;
	int memory = 0;
	f.push(1);
	for (int i = 2; i < n; i++)
	{
		int a = f.top();
		f.push(memory + f.top());
		memory = a;
	}
	return f;
}
