void InsertSorted(queue<int>& q, int num)//Вмъква число във сече сортирана опашка
{
	int len = q.size();
  //Идеята е да премахваме на-предния елемент и да го поставяме най-отзад, като всеки път ще проверяваме дали нашето число num не е по-малко от предното число
  //Това бтране на най-предния елемент най-отзад се извършва толкова пъти, колкото е дължината на опашката.
	bool flag = true;
	for (int i = 0; i < len; i++)
	{
		if (num < q.front() && flag)
		{
			q.push(num);
			flag = false;
		}
		q.push(q.front());
		q.pop();
	}
	if (flag)
		q.push(num);
}


void Sort(queue<int>& q)
{
   
	if (!q.empty())
	{
		int num = q.front();
		q.pop();//Премахваме и запазваме най-предния елемент
		Sort(q);//Сортираме останалите числа от опашката
		InsertSorted(q,num);//Вмъкваме запазения елемент по сортиран начин във вече сортирана опашка
	}
	return;
}

int main()
{
  queue<int> q;
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		q.push(n);
	}
	Sort(q);
	CoutQueue(q);
	return 0;

}
