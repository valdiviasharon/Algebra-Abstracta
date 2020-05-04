#include "funciones_cout.h"

ZZ modulo(ZZ a, ZZ b)
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

ZZ alg_1(ZZ a, ZZ b)
{
	ZZ r(modulo(a, b));
	while (r != 0)
	{
		a = b;
		b = r;
		r = modulo(a, b);
	};
	return b;
}
ZZ alg_2(ZZ a, ZZ b)
{
	ZZ r(modulo(a, b));
	while (r != 0)
	{
		if (r > b / 2)
			r = b - r;
		a = b;
		b = r;
	}
	return b;
}
ZZ alg_3(ZZ a, ZZ b)
{
	/*if (a < 0 || b < 0)
	{
		cout << "error";
		return;
	}*/
	if (b == 0)
		return a;

	return alg_3(b, modulo(a, b));
}
ZZ alg_4(ZZ a, ZZ b)
{
	ZZ dos(2);

	if (abs(b) > abs(a))
		return alg_4(b, a);
	if (b == 0)
		return a;
	if (modulo(a, dos) == 0 && modulo(b, dos) == 0)
		return 2 * alg_4(a / 2, b / 2);
	if (modulo(a, dos) == 0 && modulo(b, dos) == 1)
		return alg_4(a / 2, b);
	if (modulo(a, dos) == 1 && modulo(b, dos) == 0)
		return alg_4(a, b / 2);
	return alg_4((abs(a) - abs(b)) / 2, b);
}
ZZ alg_5(ZZ x, ZZ y)
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
	while (modulo(x, dos) == 0 && modulo(y, dos) == 0)
	{
		x = x / 2;
		y = y / 2;
		g = 2 * g;
	}
	while (x != 0)
	{
		while (modulo(x, dos) == 0)
			x = x / 2;
		while (modulo(y, dos) == 0)
			y = y / 2;
		ZZ t = abs(x - y) / 2;
		if (x >= y)
			x = t;
		else
			y = t;
	}

	return (g * y);
}
ZZ alg_6(ZZ a, ZZ b)
{
	do
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	} while (a != b);

	return a;
}
ZZ alg_7(ZZ a, ZZ b)
{
	if (b==0)
		return a;

	return alg_7(b, modulo(a, b));
}

int elegir_alg()
{
	int op;
	cout << "Seleccione un ejercicio: ";
	cout << "\n1: alg_1";
	cout << "\n2: alg_2";
	cout << "\n3: alg_3";
	cout << "\n4: alg_4";
	cout << "\n5: alg_5";
	cout << "\n6: alg_6";
	cout << "\n7: alg_7";
	cout << "\nIngrese opcion:"; cin >> op;
	return op;
}
int elegir_version()
{
	int op;
	cout << "Seleccione una version: \n";
	cout << "1 Cout\n";
	cout << "2 Time\n";
	cout << "Ingrese su respuesta: "; cin >> op;
	return op;
}
int main()
{
	ZZ a(0);
	ZZ b(0);
	double t_inicial, t_final;
	double time;

	int op1 = elegir_version();
	int op2 = elegir_alg();

	cout << "Ingresar 'a': "; cin >> a;
	cout << "Ingresar 'b': "; cin >> b;

	switch (op1)
	{
	case 1:
		switch (op2)
		{
		case 1:
			cout << "\nMCD del alg_1: " << alg_1c(a, b);
			break;
		case 2:
			cout << "\nMCD del alg_2: " << alg_2c(a, b);
			break;
		case 3:
			//if (alg_3c(a, b, time_cout, contador) == -1)
			//	break;
			cout << "\nMCD del alg_3: " << alg_3c(a, b);
			break;
		case 4:
			cout << "\nMCD del alg_4: " << alg_4c(a, b);
			break;
		case 5:
			/*if (alg_5(a, b, time_cout, contador) == -1)
				break;*/
			cout << "\nMCD del alg_5: " << alg_5c(a, b);
			break;
		case 6:
			cout << "\nMCD del alg_6: " << alg_6c(a, b);
			break;
		case 7:
			cout << "\nMCD del alg_7: " << alg_7c(a, b);
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (op2)
		{
		case 1:
			t_inicial = clock();
			cout << "\nMCD del alg_1: " << alg_1(a, b);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time;
			break;
		case 2:
			t_inicial = clock();
			cout << "\nMCD del alg_2: " << alg_2(a, b);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time;
			break;
		case 3:
			//if (alg_3(a, b, time_cout, contador) == -1)
			//	break;
			t_inicial = clock();
			cout << "\nMCD del alg_3: " << alg_3(a, b);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time;
			break;
		case 4:
			t_inicial = clock();
			cout << "\nMCD del alg_4: " << alg_4(a, b);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time;
			break;
		case 5:
			/*if (alg_5(a, b, time_cout, contador) == -1)
				break;*/
			t_inicial = clock();
			cout << "\nMCD del alg_5: " << alg_5(a, b);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time;
			break;
		case 6:
			t_inicial = clock();
			cout << "\nMCD del alg_6: " << alg_6(a, b);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time;
			break;
		case 7:
			t_inicial = clock();
			cout << "\nMCD del alg_7: " << alg_7(a, b);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}