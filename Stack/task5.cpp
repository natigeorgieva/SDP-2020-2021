void sort(stack<int>& original)
{
	stack<int>temp;
	int len = original.size();
	for (int i = 0; i < len; i++)
	{
		int largest = original.top();
		for (int j = 0; j < len - i; j++)
		{
			if (largest < original.top())
				largest = original.top();
			temp.push(original.top());
			original.pop();
		}
		original.push(largest);
		bool flag=true;
		for (int j = 0; j < len - i; j++)
		{
			if (flag && temp.top() == largest)
			{
				temp.pop();
				flag=false;
			}
			else { 
				original.push(temp.top()); 
			temp.pop(); 
			}
			
		}

	}
}
