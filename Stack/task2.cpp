bool ispalindrome(stack<int> s)
{
	stack<int> n;
	int l = s.size();
	int k = int(l / 2);
	for (int i = 0; i < k; i++)
	{
		n.push(s.top());
		s.pop();
	}
	if (l % 2 == 0)
		s.pop();
	for (int i = 0; i < k; i++)
	{
		if (s.top() != n.top())
		{
			return false;
		}
		s.pop();
		n.pop();
	}
	return true;
}
