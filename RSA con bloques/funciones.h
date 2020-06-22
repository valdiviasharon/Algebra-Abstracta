#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

long long modulo(long long a, long long n)
{
	if (n <= 0)
		return 0;
	if (a < n && a >= 0)
		return a;
	int q = a / n;
	if (a < 0)
		q -= 1;
	return  a - (q * n);
};
long long random(long long rango, long long inicio=0)
{
	long long num = inicio + rand() % (rango - inicio);
	return num;
};
//funcion exp modular
long long exp_modular(long long base, long long exp, long long n)
{
	long long x(1); //x es el exponente aux de la base
	vector<long long>mods;
	vector<long long>exponentes;
	mods.push_back(modulo(base, n));//Se inicializa el array 
	long long resultado = mods[0];
	long long pos(0);
	long long ite(1);
	while (exp > 0)
	{
		long long bit = modulo(exp, long long(2));
		if (ite > 1)
		{
			long long mod_anterior = mods[pos];
			long long aux = modulo(pow(mod_anterior, 2), n);
			mods.push_back(aux);
			pos++;
			if (bit)
			{
				long long n1, n2;
				n1 = modulo(resultado, n);
				n2 = modulo(mods[pos], n);
				resultado = modulo(n1 * n2, n);
			}
		}
		exp /= 2;
		x *= 2;
		ite++;
	}
	return resultado;
}
//funciones inversa
long long mcd(long long a, long long b)
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
vector<long long> euclides_ext(long long a, long long b)
{
	vector<long long> valores(3);
	long long r1 = a, r2 = b;
	long long x1 = 1, x2 = 0;
	long long y1 = 0, y2 = 1;
	long long x;
	long long y;
	while (r2 > 0)
	{
		long long q = r1 / r2;
		long long r = r1 - (q * r2);
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
long long inversa(long long a, long long n)
{
	if (mcd(n, a) == 1)
	{
		vector<long long> results(3);
		results = euclides_ext(a, n);
		long long x = results[0];
		return x;
	}
	return 0;
}
//funciones criba
void inicializar_lista(vector<long long>& a, long long inicio, long long fin)
{
	if (inicio <= 2)
		a.push_back(2);
	if (modulo(inicio, 2) == 0)
		inicio++;
	for (long long j = inicio; j <= fin;)
	{
		a.push_back(j);
		if (j > 5 && modulo(j, 5) == 3)
			j += 4;
		else j += 2;
	}
}
void delete_num(vector<long long>& a, long long fin)
{
	for (long long i = 3; i < fin; i += 2)
	{
		if (i == 5)
			i += 2;
		if (i * i <= fin)
		{

			for (long long j = 0; j < a.size();)
			{
				if (modulo(a[j], i) == 0)
					a.erase(a.begin() + j);
				else j++;
			}
		}
		else i = fin;
	}
}
void criba(long long inicio, long long rango, long long& a, long long& b)
{
	srand(time(NULL));
	vector<long long> primos;
	inicializar_lista(primos, inicio, rango);
	delete_num(primos,rango);
	a = primos[random(primos.size())];
	do {
		b = primos[random(primos.size())];
	} while (a == b);
}

