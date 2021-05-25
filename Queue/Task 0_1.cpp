bool IsInteger(string str)
{
	for (int i = 0; i < str.size(); i++)
		if (str[i] < '0' || str[i]>'9')
			return false;

	return true;
}

int ToInteger(string str)
{
	int sum=0;
	int len = str.size();
	for (int i = len - 1; i >= 0; i--)
	{
		int num = int(str[i] - '0');
		sum += num* pow(10,len-1-i);
	}
	return sum;
}



void FillQueue(queue<int>& q)
{

	string S;
	while (1)
	{
		getline(cin, S);

		if (IsInteger(S))
			q.push(ToInteger(S));

		else return;
	}

}

void CoutQueue(queue<int> q)
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
}

int main()
{
  queue<int>q;
	FillQueue(q);
	CoutQueue(q);
  
  return 0;
}
