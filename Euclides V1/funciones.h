#include <iostream>
#include <string>
#include <time.h>


using namespace std;

int modulo(int a, int b)
{
	if (b <= 0)
		return 0;
	int r = a - ((a / b) * b);
	if (r < 0)
	{
		r = a - (((a / b) - 1) * b);
	}
	return r;
}
void print_valores(int a, int b)
{
	if (b == 0)
		cout << a << " = " << "0" << " * (" << b << ") + " << modulo(a, b) << endl;
	else
		cout << a << " = " << a / b << " * (" << b << ") + " << modulo(a, b) << endl;
}

int alg_1(int a, int b, double& time_cout, int& contador)
{
	int r;
	double t_inicial, t_final;
	while (r = modulo(a, b))
	{
		print_valores(a, b);
		a = b;
		b = r;
		contador++;
	};
	t_inicial = clock();
	print_valores(a, b);
	t_final = clock();
	time_cout = (double(t_final - t_inicial) / CLOCKS_PER_SEC);
	return b;
}
int alg_2(int a, int b, double& time_cout, int& contador)
{
	int r;
	double t_inicial, t_final;
	while (r = modulo(a, b))
	{
		print_valores(a, b);
		if (r > b / 2)
			r = b - r;
		a = b;
		b = r;
		contador++;
	}
	t_inicial = clock();
	print_valores(a, b);
	t_final = clock();
	time_cout = (double(t_final - t_inicial) / CLOCKS_PER_SEC);
	return b;
}
int alg_3(int a, int b, double& time_cout, int& contador)
{
	if (a < 0 || b < 0)
	{
		cout << "error";
		return -1;
	}
	double t_inicial, t_final;
	if (b == 0)
		return a;

	contador++;
	t_inicial = clock();
	print_valores(a, b);
	t_final = clock();
	time_cout = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

	return alg_3(b, modulo(a, b), time_cout,contador);
}
int alg_4(int a, int b, double& time_cout, int& contador)
{
	double t_inicial, t_final;

	t_inicial = clock();
	print_valores(a, b);
	t_final = clock();
	time_cout = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

	contador++;

	if (abs(b) > abs(a))
		return alg_4(b, a,time_cout,contador);
	if (b == 0)
		return a;
	if (modulo(a, 2) == 0 && modulo(b, 2) == 0)
		return 2 * alg_4(a / 2, b / 2,time_cout, contador);
	if (modulo(a, 2) == 0 && modulo(b, 2) == 1)
		return alg_4(a / 2, b, time_cout, contador);
	if (modulo(a, 2) == 1 && modulo(b, 2) == 0)
		return alg_4(a, b / 2, time_cout, contador);
	return alg_4((abs(a) - abs(b)) / 2, b, time_cout, contador);
}
int alg_5(int x, int y, double& time_cout, int& contador)
{
	if (x < 0 || y < 0)
	{
		cout << "error, a y b no pueden ser negativos ";
		return -1;
	}
	if (x < y)
	{
		cout << "error, 'a' no puede ser menor a 'b'";
		return -1;
	}

	double t_inicial, t_final;
	int g = 1;
	while (modulo(x, 2) == 0 && modulo(y, 2) == 0)
	{
		t_inicial = clock();
		cout << "a=" << x << "  b=" << y << "  g= " << g << endl;
		t_final = clock();
		x = x / 2;
		y = y / 2;
		g = 2 * g;
		contador++;
	}
	while (x != 0)
	{
		cout << "a=" << x << "  b=" << y << "  g= " << g;
		while (modulo(x, 2) == 0)
			x = x / 2;
		while (modulo(y, 2) == 0)
			y = y / 2;
		int t = abs(x - y) / 2;
		cout << "  t=" << t << endl;
		if (x >= y)
			x = t;
		else
			y = t;
		contador++;
	}
	time_cout = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

	return (g * y);
}
int alg_6(int a, int b, double& time_cout, int& contador)
{
	double t_inicial, t_final;
	do
	{
		t_inicial = clock();
		print_valores(a, b);
		t_final = clock();
		if (a > b)
			a -= b;
		else
			b -= a;
		contador++;
	} while (a != b);
	time_cout = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

	return a;
}
int alg_7(int a, int b, double& time_cout, int& contador)
{
	if (b == 0)
		return a;
	double t_inicial, t_final;
	t_inicial = clock();
	print_valores(a, b);
	t_final = clock();
	contador++;
	time_cout = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

	alg_7(b, modulo(a, b),time_cout,contador);
}
