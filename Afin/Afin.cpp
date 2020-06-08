#include "Afin.h"
#include <time.h>
#include <stdlib.h>
#include "math.h"

void generar_claves(int size,int & a, int & b)
{
	srand(time(NULL));
	b = modulo(rand(),size);
	do{
		a = rand() % size;
	} while (mcd(a, size) != 1);
}
void Afin::print_claves()
{
	cout << "\nClave a: " << key_a << endl;
	cout << "Clave b: " << key_b << endl;
}
Afin::Afin()
{
	abecedario = "abcdefghijklmnopqrstuvwxyz ";
	generar_claves(abecedario.size(),key_a,key_b);
}
Afin::Afin(int a, int b)
{
	abecedario = "abcdefghijklmnopqrstuvwxyz ";
	key_a = a;
	key_b = b;
}
string Afin::Cifrar(string _mensaje)
{
	string mensaje_cifrado;
	int size_msj = _mensaje.size();
	
	for (int i = 0; i < size_msj; i++)
	{
		int pos_msj = abecedario.find(_mensaje.at(i));
		int pos = modulo((key_a * pos_msj) + key_b, abecedario.size());
		mensaje_cifrado += abecedario.at(pos);
	}
	return mensaje_cifrado;
}
string Afin::Descifrar(string _mensaje_cifrado)
{
	string mensaje_descifrado;
	int size_msj = _mensaje_cifrado.size();
	int inv_a = inversa(key_a, abecedario.size());

	for (int i = 0; i < size_msj; i++)
	{
		int pos_msj = abecedario.find(_mensaje_cifrado.at(i));
		int pos = modulo(inv_a * (pos_msj- key_b), abecedario.size());
		mensaje_descifrado += abecedario.at(pos);
	}
	return mensaje_descifrado;
}