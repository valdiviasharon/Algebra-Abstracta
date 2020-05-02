#include <iostream>

using namespace std;

void division(int a, int& q, int n, int& r)
{
	r = a % n;

	if (r < 0)
	{
		q = a / n;
		q--;
		r = a - (q * n);
	}
	else
		q = (a - r) / n;
}

int main()
{
	int a, q, n, r;

	cout << "Ingrese 'a': "; cin >> a;
	cout << "Ingrese 'n': "; cin >> n;

	if (n <= 0)
	{
		cout << "\nError, n tiene que ser positivo";
		return 0;
	}
	division(a, q, n, r);

	cout << endl << a << "=" << "(" << q << "*" << n << ")" << "+" << r;
}