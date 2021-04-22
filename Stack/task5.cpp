void sort(stack<int>& original)
{
	stack<int>temp;
	int len = original.size();
	for (int i = 0; i < len; i++)//С външния цикъл сортираме всяко от числата
	{
		int largest = original.top();
		for (int j = 0; j < len - i; j++)//С този цикъл прехвърляме всички len-i на брой числа в друг масив, като в процеса прверяваме кое е най-голямото от тях
		//Броят е len-i, тъй като на всяка стъпка от външния цикъл ние сме сортирали вече i елемента и се занимаваме с оставащите
		{
			if (largest < original.top())
				largest = original.top();
			temp.push(original.top());
			original.pop();
		}
		original.push(largest);
		bool flag=true;
		for (int j = 0; j < len - i; j++)//Тук връщаме числата от втория масив обратно в първия, като при първото срещане на елемента largest, гo пропускаме,
			//тъй като вече сме го записали в първия масив на правилното му място.
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
