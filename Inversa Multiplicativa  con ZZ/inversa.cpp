#include <iostream>
#include <NTL/ZZ.h>

NTL_CLIENT
using namespace std;

ZZ modulo(ZZ a, ZZ b)
{
	ZZ r = a - ((a / b) * b);
	if (r < 0)
		r = a - (((a / b) - 1) * b);
	return r;
}
ZZ euclides_ext(ZZ a, ZZ b)
{
	ZZ mcd;

	ZZ r1 = a, r2 = b;
	ZZ s1(1), s2 (0);
	ZZ t1(0), t2 (1);
	ZZ s;
	ZZ t;
	while (r2 > 0)
	{
		ZZ q = r1 / r2;

		ZZ r = r1 - (q * r2);
		r1 = r2; r2 = r;

		s = s1 - (q * s2);
		s1 = s2; s2 = s;

		t = t1 - (q * t2);
		t1 = t2; t2 = t;
	};

	s = s1;
	t = t1;
	mcd = r1;
	return s;
}
ZZ mcd(ZZ a, ZZ b)
{
	ZZ dos (2);
	if (abs(b) > abs(a))
		return mcd(b, a);
	if (b == 0)
		return a;
	if (modulo(a, dos) == 0 && modulo(b, dos) == 0)
		return 2 * mcd(a >> 1, b >> 1);
	if (modulo(a, dos) == 0 && modulo(b, dos) == 1)
		return mcd(a >> 1, b);
	if (modulo(a, dos) == 1 && modulo(b, dos) == 0)
		return mcd(a, b >> 1);
	return mcd((abs(a) - abs(b)) >> 1, b);
}
void inversa(ZZ a, ZZ n)
{
	if (mcd(n, a) == 1)
	{
		ZZ x = euclides_ext(a, n);
		if (modulo(a * x, n) == 1)
			cout << "la inversa de " << a << " es " << x;
		else
			cout << "El mod de es diferente de 1 no posee inversa" << endl;
	}
	else
		cout << "El mcd es diferente de 1, no posee inversa" << endl;
}
int main()
{
	ZZ a, n;
	cout << "Ingrese a: "; cin >> a;
	cout << "\nIngrese n: "; cin >> n;

	inversa(a, n);

}