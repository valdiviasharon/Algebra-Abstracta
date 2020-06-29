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
void swap_values(ZZ & a, ZZ & b)
{
	ZZ aux;
	aux = a;
	a = b;
	b = aux;
}
void print(vector<ZZ> S)
{
	for (long long i = 0; i < S.size(); i++)
		cout << S[i] << endl;
	cout << endl;
}
vector<string> Memoria()
{
	vector<string>datos;
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);

	DWORDLONG virtualMemUsed = memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
	DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

	string VMU = to_string(virtualMemUsed);
	string PMU = to_string(physMemUsed);

	datos.push_back(VMU);
	datos.push_back(PMU);

	return datos;
}
vector<ZZ> Generar_semilla(ZZ bits)
{
	vector<string>datos_memoria = Memoria();
	vector<ZZ> K;
	//inicializamos K (semilla)
	int j = 0;
	for (ZZ i(0); i < bits; i++)
	{
		ZZ tiempo(time(NULL));
		string value = datos_memoria[j];
		ZZ valor(INIT_VAL, value.c_str());
		if (modulo(modulo(valor, i), ZZ(2)) == ZZ(1)) //Primero realiza un mod con el valor de memoria obtenido y el valor de i
			valor *= tiempo + i;                      //Si ese resultado es impar valor*= tiempo + i, sino resta i
		else
			valor *= tiempo - i;
		K.push_back(valor);
		if (j + 1 == datos_memoria.size()) //Va recorriendo el array e iterando los valores que usará, entonces si se pasa del tamaño reinicia la posicion
			j = -1;
		j++;
		Sleep(30);
	}
	return K;
}
int main()
{
	ZZ bits;
	cout << "Ingrese la cantidad de valores : "; cin >> bits;
	vector<ZZ>semillas = Generar_semilla(bits);
	print(semillas);
}