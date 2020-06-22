#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
int modulo(int a, int n)
{
	if (n <= 0)
		return 0;
	if (a < n && a >= 0)
		return a;
	int q = a / n;
	if (a < 0)
		q -= 1;
	return  a - (q * n);
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
vector<int> euclides_ext(int a, int b)
{
	vector<int> valores(3);
	int r1 = a, r2 = b;
	int x1 = 1, x2 = 0;
	int y1 = 0, y2 = 1;
	int x;
	int y;
	while (r2 > 0)
	{
		int q = r1 / r2;
		int r = r1 - (q * r2);
		r1 = r2; r2 = r;

		x = x1 - (q * x2);
		x1 = x2; x2 = x;

		y = y1 - (q * y2);
		y1 = y2; y2 = y;
	};

	if (x1 < 0)
		x1 = modulo(x1, b);
	valores[0] = x1; //x
	valores[1] = y1; //y
	valores[2] = r1; //mcd
	return valores;
}
int inversa(int a, int n)
{
	if (mcd(n, a) == 1)
	{
		vector<int> results(3);
		results = euclides_ext(a, n);
		return results[0];
	}
	return 0;
}
