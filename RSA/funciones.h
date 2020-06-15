#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int modulo(int a, int b)
{
	int r = a - ((a / b) * b);
	if (r < 0)
		r = a - (((a / b) - 1) * b);
	return r;
};
int random(int rango, int inicio = 0)
{
	int num = inicio + rand() % (rango - inicio);
	return num;
};
//funcion exp modular
int exp_modular(int base, int exp, int n)
{
	int x = 1; //x es el exponente aux de la base
	vector<int>mods;
	vector<int>exponentes;
	mods.push_back(modulo(base, n));//Se inicializa el array 
	int resultado = mods[0];
	int pos = 0;
	int ite = 1;
	while (exp > 0)
	{
		int bit = modulo(exp, 2);
		if (ite > 1)
		{
			int mod_anterior = mods[pos];
			int aux = modulo(pow(mod_anterior, 2), n);
			mods.push_back(aux);
			pos++;
			if (bit)
			{
				int n1, n2;
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
int euclides_ext(int a, int b)
{
	int r1 = a, r2 = b;
	int s1 = 1, s2 = 0;
	int t1 = 0, t2 = 1;
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
		s = modulo(s, b);
	return s;
}
int inversa(int a, int n)
{
	if (mcd(n, a) == 1)
	{
		int x = euclides_ext(a, n);
		if (modulo(a * x, n) == 1)
			return x;
	}
	return 0;
}
//funciones criba
void inicializar_lista(vector<int> & a, int inicio, int rango)
{
	if (inicio <= 2)
		a.push_back(2);
	if (modulo(inicio, 2) == 0)
		inicio++;
	for (int j = inicio; j <= rango; j += 2)
		a.push_back(j);
}
void delete_num(vector<int>&a,int rango)
{
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] * a[i] <= rango)
		{
			for (int j = i + 1; j < a.size();)
			{
				if (modulo(a[j], a[i]) == 0)
					a.erase(a.begin() + j);
				else j++;
			}
		}
		else i = a.size();
	}
}
void criba(int inicio, int rango, int& a, int& b)
{
	srand(time(NULL));
	vector<int> primos;
	inicializar_lista(primos, inicio, rango);
	delete_num(primos,rango);
	a = primos[random(primos.size())];
	do {
		b = primos[random(primos.size())];
	} while (a == b);
}

