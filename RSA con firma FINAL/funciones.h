#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <NTL/ZZ.h>
#include <sstream>
#include <string>
#include <Windows.h>
#include "psapi.h"

NTL_CLIENT
using namespace std;

//Conversiones
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

//generales
string agregar_ceros(long long tam_N, string bloque)
{
	string ceros(tam_N - bloque.size(), '0'); //Calculamos cuantos ceros necesitamos y generamos un string con esa cantidad
	ceros += bloque; //Adjuntamos la parte el bloque
	return ceros;
}
vector <string> generar_bloques(string mensaje, int size_bloque)
{
	vector<string>bloques;
	int cant = mensaje.size() / size_bloque; //Cantidad de bloques
	for (long long i = 0; i < cant; i++)
	{
		string bloque = mensaje.substr(0, size_bloque); //Extramos un bloque
		bloques.push_back(bloque); //Lo agregamos
		mensaje.erase(0, size_bloque); //Lo eliminamos del mensaje
	}
	return bloques;
}
ZZ modulo(ZZ a, ZZ n)
{
	if (n <= 0)
		return ZZ(0);
	if (a < n && a >= 0)
		return a;
	ZZ q (a / n);
	if (a < 0)
		q -= 1;
	return  a - (q * n);
};
void swap_values(ZZ& a, ZZ& b)
{
	ZZ aux;
	aux = a;
	a = b;
	b = aux;
}

//RC4 
vector<ZZ> calcular_rango(ZZ bits)
{
	vector<ZZ> valores(2);
	ZZ inicio = ZZ(1);
	ZZ fin;
	for (int i = 0; i < bits - 1; i++)
		inicio <<= 1; //Inicio *=2

	fin = inicio << 1; //Inicio * 2

	valores[0] = inicio;
	valores[1] = fin - 1; 
	return valores;
}
vector <ZZ> dec_bin(ZZ num, int bits) //Conversión a bits
{
	vector<ZZ> valor(bits); //vector que almacenara los bits
	ZZ bit;
	if (num > 0)
	{
		for (int i = bits - 1; i >= 0; i--)
		{
			bit = modulo(num, ZZ(2)); 
			num >>= 1; //num /=2
			valor[i] = ZZ_to_longlong(bit); //Asignamos valor en la posicion
		}
	}
	else //Si es 0
	{
		for (int i = 0; i < bits; i++) //Todo el vector contendrá ceros
			valor[i] = ZZ(0);
	}
	return valor;
}
ZZ bin_dec(vector<ZZ> bits)
{
	ZZ numero(0);
	ZZ valor(1);

	for (int i = bits.size() - 1, j = 0; i >= 0; i--, j++)
	{
		if (modulo(bits[i], ZZ(2)) == ZZ(1)) //Si es uno, agregamos el valor acumulado
			numero += valor;
		valor <<= 1; //Valor*=2
	}
	return numero;
}
void corr_izq(vector<ZZ>& K)
{
	K.push_back(K.front()); //Tomamos el primer bit, y lo mandamos al final
	K.erase(K.begin()); //Eliminamos ese bit
}
void corr_der(vector<ZZ>& K)
{
	long long aux = K.size() - 1;
	K.insert(K.begin(), K[aux]); //Insertamos al inicio el ultimo bit
	K.pop_back(); //Y lo borramos
}

//Aleatorio
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
vector<ZZ> Generar_semilla()
{
	vector<string>datos_memoria = Memoria();
	vector<ZZ> seed;
	//inicializamos K (semilla)
	int j = 0;
	for (ZZ i(0); i < 5; i++)
	{
		ZZ tiempo(time(NULL));
		string value = datos_memoria[j];
		ZZ valor(INIT_VAL, value.c_str());
		if (modulo(modulo(valor, i), ZZ(2)) == ZZ(1)) //Primero realiza un mod con el valor de memoria obtenido y el valor de i
			valor = tiempo + i;                      //Si ese resultado es impar valor= tiempo + i, sino resta i
		else
			valor *= tiempo - i;
		valor = modulo(valor, ZZ(255));//Hallamos el valor a 1 byte con la clase de equivalencia
		seed.push_back(valor);
		if (j + 1 == datos_memoria.size()) //Va recorriendo el array e iterando los valores que usará, entonces si se pasa del tamaño reinicia la posicion
			j = -1;
		j++;
		Sleep(30);
	}
	return seed;
}
vector<ZZ> RC4()
{
	vector<ZZ> seed = Generar_semilla();
	vector<ZZ> S;

	//agregamos a S los numeros de 0 a 256
	for (ZZ i(0); i < 256; i++)
		S.push_back(i);

	ZZ f(0);

	//Inicializacion
	for (long long i = 0, j = 0; i < 256; i++, j++)
	{
		f = modulo((f + S[i] + seed[j]), ZZ(256));
		long long aux = ZZ_to_longlong(f);
		swap_values(S[i], S[aux]);
		if (j + 1 == seed.size())
			j = -1;
	}

	f = 0;
	ZZ i(0);
	ZZ t;
	vector<ZZ>K;

	//Generacion de secuencia cifrante
	for (long long j = 0; j < 8; j++) //64 bits 
	{
		i = modulo(i + 1, ZZ(256));
		long long aux_i = ZZ_to_longlong(i);

		f = modulo(f + S[aux_i], ZZ(256));
		long long aux_f = ZZ_to_longlong(f);

		swap(S[aux_i], S[aux_f]);

		t = modulo(S[aux_i] + S[aux_f], ZZ(256));
		vector<ZZ>valor_en_bits = dec_bin(S[ZZ_to_longlong(t)], 8); //Convertimos el valor de S[t] a 8 bits

		for (long long i = 0; i < valor_en_bits.size(); i++)//Agregamos esos bits al vector final
			K.push_back(valor_en_bits[i]);
	}
	return K;
}
vector<ZZ> DES(int desplazamiento)
{
	vector<ZZ> K = RC4();
	vector<int> PC1, PC2;
	PC1 = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	PC2 = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };

	//Permutacion con tabla PC1
	vector<ZZ> K_1;
	for (int i = 0; i < PC1.size(); i++)
		K_1.push_back(K[PC1[i] - 1]);

	//Separacion en bloques de 28 elementos
	vector<ZZ> C0, D0;
	for (int i = 0; i < K_1.size() / 2; i++)
	{
		C0.push_back(K_1[i]); //Primeros 28
		D0.push_back(K_1[i + K_1.size() / 2]); //Ultimos 28 
	}

	//Corrimientos
	for (int i = 0; i < desplazamiento; i++) //Corrimientos segun los desplazamientos
	{
		corr_izq(C0);    corr_der(D0);
	}

	//Unimos C0 Y D0
	vector<ZZ> C0D0;
	C0D0 = C0;
	for (int i = 0; i < D0.size(); i++)
		C0D0.push_back(D0[i]);

	//Permutacion con tabla PC2
	vector<ZZ> K_2;
	for (int i = 0; i < PC2.size(); i++)
		K_2.push_back(C0D0[PC2[i] - 1]);

	return K_2;
}
