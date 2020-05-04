#include <iostream>
#include <string>
#include <time.h>
#include <NTL/ZZ.h>

NTL_CLIENT
using namespace std;

ZZ moduloc(ZZ a, ZZ b)
{
	if (b <= 0)
		return ZZ(0);
	ZZ r = a - ((a / b) * b);
	if (r < 0)
	{
		r = a - (((a / b) - 1) * b);
	}
	return r;
}
void print_valores(ZZ a, ZZ b)
{
	if (b == 0)
		cout << a << " = " << "0" << " * (" << b << ") + " << moduloc(a, b) << endl;
	else
		cout << a << " = " << a / b << " * (" << b << ") + " << moduloc(a, b) << endl;
}

ZZ alg_1c(ZZ a, ZZ b)
{
	ZZ r(moduloc(a, b));
	
	while (r != 0)
	{
		print_valores(a, b);
		a = b;
		b = r;
		r = moduloc(a, b);
	};
	print_valores(a, b);
	return b;
}
ZZ alg_2c(ZZ a, ZZ b)
{
	ZZ r(moduloc(a, b));
	while (r != 0)
	{
		print_valores(a, b);
		if (r > b / 2)
			r = b - r;
		a = b;
		b = r;
	}
	print_valores(a, b);
	return b;
}
ZZ alg_3c(ZZ a, ZZ b)
{
	if (a < 0 || b < 0)
	{
		cout << "error";
		return ZZ(-1);
	}
	if (b == 0)
		return a;

	cout << "\na:" << a << " b:" << b << endl;

	return alg_3c(b, moduloc(a, b));
}
ZZ alg_4c(ZZ a, ZZ b)
{
	ZZ dos(2);
	cout << "\na:" << a << " b:" << b << endl;

	if (abs(b) > abs(a))
		return alg_4c(b, a);
	if (b == 0)
		return a;
	if (moduloc(a, dos) == 0 && moduloc(b, dos) == 0)
		return 2 * alg_4c(a / 2, b / 2);
	if (moduloc(a, dos) == 0 && moduloc(b, dos) == 1)
		return alg_4c(a / 2, b);
	if (moduloc(a, dos) == 1 && moduloc(b, dos) == 0)
		return alg_4c(a, b / 2);
	return alg_4c((abs(a) - abs(b)) / 2, b);
}
ZZ alg_5c(ZZ x, ZZ y)
{
	if (x < 0 || y < 0)
	{
		cout << "error, a y b no pueden ser negativos ";
		return ZZ(-1);
	}
	if (x < y)
	{
		cout << "error, 'a' no puede ser menor a 'b'";
		return ZZ(-1);
	}

	ZZ g(1);
	ZZ dos(2);
	while (moduloc(x, dos) == 0 && moduloc(y, dos) == 0)
	{
		cout << "a=" << x << "  b=" << y << "  g= " << g << endl;
		x = x / 2;
		y = y / 2;
		g = 2 * g;
	}
	while (x != 0)
	{
		cout << "a=" << x << "  b=" << y << "  g= " << g;
		while (moduloc(x, dos) == 0)
			x = x / 2;
		while (moduloc(y, dos) == 0)
			y = y / 2;
		ZZ t = abs(x - y) / 2;
		cout << "  t=" << t << endl;
		if (x >= y)
			x = t;
		else
			y = t;
	}

	return (g * y);
}
ZZ alg_6c(ZZ a, ZZ b)
{
	do
	{
		cout << "\na:" << a << " b:" << b << endl;
		if (a > b)
			a -= b;
		else
			b -= a;
	} while (a != b);

	return a;
}
ZZ alg_7c(ZZ a, ZZ b)
{
	if (b == 0)
		return a;

	print_valores(a, b);

	return alg_7c(b, moduloc(a, b));
}

