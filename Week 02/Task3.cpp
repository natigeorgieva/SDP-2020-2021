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
	//Имайте предвид тази функция, тъй като никъде в нея не сме освободили заделената памет.
}


void SwitchArray(int*& arr1, int*& arr2, int NewLen)
{
	//Тук ключово е да подадем указателите с &, тъй като в противен случай се създава локален за фунцкията указател, който сочи същия адрес, но не е нашият указател.
	//Това може да създаде проблем при използването на оператора delele [], тъй като, ако примерно указателят arr1 (подаден без псевдоним) бъде изтрит, то ще се изтрие и масива,
	//към който сочи, но нашият първоначален указател (чието локално копие е създадено в тази функция) от функцията ShrinkArray, все още ще сочи към адреса, където е бил масива
	//Тоест все едно само сме изтрили масива, без да изтрием стойността, която arr1 пази (тоест адреса към този масив). Това после пречи на презаписването, което на свой ред
	//предизивква проблеми след това при CoutArr. Също така поради горните съобращения, arr1 може да не е нито nullptr, нито да сочи към масив, тогава няма как да прилжоим
	//оператора delete и ни дава грешка.
	
	arr2 = new int[NewLen];
	for (int i = 0; i < NewLen; i++)
		arr2[i] = arr1[i];

	delete [] arr1;//Изтриваме масива и самия указател arr1 и не забравяме да го занулим, тъй като след оператора delete, указателят не сочи към nullptr, а към друг
	//адрес (настройка на вижуъл студио)
	arr1 = nullptr;
}

void ShrinkArray(int* arr1, int n)
{
	arr1 = CreateArray(n);
	int* PtrHelp = nullptr;
	//Ще се прехвърляме от едния усказател (arr1) в другия (PtrHelp) и обратното, като идеята е, че когато едният узказател сочи към масив с дължина k (1<=k<=n-1),
	//то другият указател ще сочи към nullptr. Нека арр1 сочи към масив с дължина к, тогава нашата цел е да да прехвърлим първите к-1 елемента в нов масив (който  PtrHelp
	//ще сочи), след което "зануляваме" arr1 и вече PtrHelp е новият ни масив с един елемент по-малко. И така се прехвърляме от единия в другия, докато не стигнем дължина 0
	//Ще принтираме всеки нов по-малък масив на екрана за проверка
	for (int i = n - 1; i >= 1; i--)
	{
		if (PtrHelp == nullptr)
		{
			SwitchArray(arr1, PtrHelp, i);
			CoutArr(PtrHelp, i);
		}
		else {
			SwitchArray(PtrHelp, arr1, i);
			CoutArr(arr1, i);

		}
	}
	delete[] arr1;
	delete[] PtrHelp;
}
int main()
{
  int n;
  cin>>n;
  int* ptr=nullptr;
	ShrinkArray(ptr, n);
}
