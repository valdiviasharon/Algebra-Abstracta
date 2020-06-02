#include <iostream>

using namespace std;

int modulo(int a, int b) 
{
	int r = a - ((a / b) * b);
	if (r < 0)
		r = a - (((a / b) - 1) * b);
	return r;
}
int euclides_ext(int a, int b)
{
	int mcd = 0;

	int r1 = a, r2 = b;
	int s1 = 1, s2 = 0;
	int t1 = 0,	t2 = 1;
	int s;
	int t;
	while (r2 > 0)
	{
		int q = r1 / r2;

		int r = r1 - (q * r2);
		r1 = r2; r2 = r;

		s = s1 - (q * s2);
		s1 = s2; s2 = s;

		t = t1 - (q * t2);
		t1 = t2; t2 = t;
	};

	s = s1; 
	if (s < 0)
	{
		s = modulo(s, b);
	}
	return s;
}
int mcd(int a, int b)
{
	if (abs(b) > abs(a))
		return mcd(b, a);
	if (b == 0)
		return a;
	if (modulo(a, 2) == 0 && modulo(b, 2) == 0)
		return 2 * mcd(a >> 1, b >> 1);
	if (modulo(a, 2) == 0 && modulo(b, 2) == 1)
		return mcd(a >> 1, b);
	if (modulo(a, 2) == 1 && modulo(b, 2) == 0)
		return mcd(a, b >> 1);
	return mcd((abs(a) - abs(b)) >> 1, b);
}
int inversa(int a, int n)
{
	if (mcd(n, a) == 1)
	{
		int x = euclides_ext(a, n);
		if (modulo(a * x, n) == 1)
			return x;
		else
			cout << "La inversa no puede ser negativa"<<endl;
	}
	else
		cout << "El mcd es diferente de 1, no posee inversa"<<endl;
	return 0;
}
int main()
{
	int a, n;
	cout << "Ingrese a: "; cin >> a;
	cout << "\nIngrese n: "; cin >> n;

	if (inversa(a, n))
		cout << "la inversa de " << a << " es " << inversa(a,n);
}