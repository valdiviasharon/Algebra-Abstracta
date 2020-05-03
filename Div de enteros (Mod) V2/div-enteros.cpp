#include <iostream>

using namespace std;

int division(int a, int n)
{
	int r = a - ((a / n) * n);
	if (r < 0)
	{
		r = a - (((a / n) - 1) * n);
	}
	return r;
}

int main()
{
	int a, n;

	cout << "Ingrese 'a': "; cin >> a;
	cout << "Ingrese 'n': "; cin >> n;

	if (n <= 0)
	{
		cout << "\nError, n tiene que ser positivo";
		return 0;
	}
	
	cout << division(a, n);
}