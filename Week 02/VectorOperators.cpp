//оператор +
void Vector::operator+(float num)
{
	
	if(max_size==size)
    resize();
  ptr[size]=num;
  size++;
}

//оператор +=
void Vector::operator+=(const Vector& other)
{//събираме поелементно двата масива до по-малката дължина, след това по-краткият считаме, че има нули.
	int longer, shorter;
	if (size < other.size)
	{
		shorter = size;
		longer = other.size;
		while (max_size < longer)//уверяваме се, че има достатъчно място
			resize();
		//В единия цикъл събираме, в другия присвояваме, тъй като сме минали дължината, в която и двата имат елементи
		for (int i = 0; i < shorter; i++)
			ptr[i] += other.ptr[i];
		for (int i = shorter; i < longer; i++)
		{
			ptr[i] = other.ptr[i];
			size++;
		}

	}
	else { shorter = other.size; longer = size;
	
	for (int i = 0; i < shorter; i++)
		ptr[i] += other.ptr[i];

	}
}

//оператор =
void Vector::operator=(const Vector& other)
{
	size = other.size;
	max_size = other.max_size;
	delete [] ptr;
	ptr = new float[max_size];
	for (int i = 0; i < size; i++)
		ptr[i] = other.ptr[i];
		
}
