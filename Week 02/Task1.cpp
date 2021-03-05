int* CreateArray(int n)
{
	int* ptr = new int[n];
	for (int i = 0; i < n; i++)
		ptr[i] = i;

	return ptr;
	//Имайте предвид тази функция, тъй като никъде в нея не сме освободили заделената памет, тоест някъде другаде трябва да го направим.
}
int main()
{
  int n;
  cin>>n;
  int* ptr = CreateArray(n);
  delete [] ptr;
}
