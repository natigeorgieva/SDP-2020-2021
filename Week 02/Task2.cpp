
void CoutArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int* CreateArray(int n)
{

	int* ptr = new int[n];
	for (int i = 0; i < n; i++)
		ptr[i] = i;

	return ptr;
}

void CopyArray(int*& ptr1, int*& ptr2, int len)
{
  //Тук е важно да подадем указателя, който ще сочи към вече копирания масив, с &, тъй като в противен случай след презаписването в ptr2, който би бил локална порменлива,
  //нашият първоначален указател за презаписване няма да сочи вече новия масив. Така дори губим връзката към заделената памет и не можем по-късно да я освободим.
	ptr2 = new int[len];
	for (int i = 0; i < len; i++)
		ptr2[i] = ptr1[i];
	delete[] ptr1;
}


int main()
{ 
  int n;
  cin>>n;
  int* ptr = CreateArray(n);
	int* ptr2=nullptr;
	CopyArray(ptr, ptr2, n);
	CoutArr(ptr2,n);
  delete [] ptr2;
}
