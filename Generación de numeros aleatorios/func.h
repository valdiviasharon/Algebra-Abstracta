#include <NTL/ZZ.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <Windows.h>
#include "psapi.h"
#include <string>
#include <sstream>

NTL_CLIENT
using namespace std;

string ZZ_to_string(ZZ valor)
{
	stringstream palabra;
	palabra << valor;
	return palabra.str();
}
ZZ string_to_ZZ(string valor)
{
	return ZZ(INIT_VAL, valor.c_str());
}
long long ZZ_to_longlong(ZZ valor)
{
	string aux = ZZ_to_string(valor);
	return stoll(aux);
}
ZZ modulo(ZZ a, ZZ n)
{
	if (n <= 0)
		return ZZ(0);
	if (a < n && a >= 0)
		return a;
	ZZ q = a / n;
	if (a < 0)
		q -= 1;
	return  a - (q * n);
}
vector<ZZ> calcular_rango(ZZ bits)
{
	vector<ZZ> valores(2);
	ZZ inicio = ZZ(1);
	ZZ fin;
	for (int i = 0; i < bits - 1; i++)
		inicio <<= 1;

	fin = inicio << 1;

	valores[0] = inicio;
	valores[1] = fin - 1;
	return valores;
}
vector <ZZ> dec_bin(ZZ num, long long bits) //Conversión a bits
{
	vector<ZZ> valor(bits);
	ZZ bit;
	if (num > 0)
	{
		for (long long i = bits - 1; i >= 0; i--)
		{
			bit = modulo(num, ZZ(2));
			num >>= 1;
			valor[i] = ZZ_to_longlong(bit);
		}
	}
	else //Si es 0
	{
		for (long long i = 0; i < bits; i++)
			valor[i] = ZZ(0);
	}
	return valor;
}
ZZ bin_dec(vector<ZZ> bits)
{
	ZZ numero(0);
	ZZ valor(1);

	for (long long i = bits.size() - 1, j = 0; i >= 0; i--, j++)
	{
		if (modulo(bits[i], ZZ(2)) == ZZ(1))
			numero += valor;
		valor *= 2;
	}
	return numero;
}
void swap_values(ZZ& a, ZZ& b)
{
	ZZ aux;
	aux = a;
	a = b;
	b = aux;
}
void corr_izq(vector<ZZ>& K)
{
	K.push_back(K.front());
	K.erase(K.begin());
}
void corr_der(vector<ZZ>& K)
{
	long long aux = K.size() - 1;
	K.insert(K.begin(), K[aux]);
	K.pop_back();
}
void print(vector<ZZ> S)
{
	for (long long i = 0; i < S.size(); i++)
		cout << S[i] <<endl;
	cout << endl;
}
ZZ exp_modular(ZZ base, ZZ exp, ZZ n)
{
	ZZ x(1); //x es el exponente aux de la base
	vector<ZZ>mods; //vector que almacena los modulos calculados durante la funcion 
	mods.push_back(modulo(base, n));//Se inicializa el array 
	ZZ resultado = mods[0];
	long long pos(0);
	ZZ ite(1);
	while (exp > 0)
	{
		ZZ bit = modulo(exp, ZZ(2));
		if (ite > 1)
		{
			ZZ mod_anterior = mods[pos];
			ZZ aux = modulo((mod_anterior * mod_anterior), n);
			mods.push_back(aux);
			pos++;
			if (ZZ(bit) == ZZ(1))
			{
				ZZ n1, n2;
				n1 = modulo(resultado, n);
				n2 = modulo(mods[pos], n);
				resultado = modulo(n1 * n2, n);
			}
		}
		exp >>= 1;
		x <<= 1;
		ite++;
	}
	return resultado;
}
bool is_prime(ZZ numero)//teorema de fermat segunda version 
{
	ZZ aux(8); 
	if(exp_modular(aux,numero,numero)!=aux)
		return false;
	return true;
}
