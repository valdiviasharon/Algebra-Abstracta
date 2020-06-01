#include "Polybios.h"

int modulo(int a, int n)
{
	int r = a - ((a / n) * n);
	if (r < 0)
	{
		r = a - (((a / n) - 1) * n);
	}
	return r;
}
string Polybios::Cifrar(string _mensaje)
{
	string mensaje_cifrado;
	int size_msj = _mensaje.size();
	int pos;
	int x, y;  //COORDENADAS

	for (int i = 0; i < size_msj; i++)
	{
		if (_mensaje.at(i) == ' ')
		{
			mensaje_cifrado += ' ';
			i++;
		}	
		pos = abecedario.find(_mensaje.at(i));
		if (pos > 8)
			pos--;
		x = pos / 5;
		y = pos % 5;

		mensaje_cifrado += tabla[x];
		mensaje_cifrado += tabla[y];
	}
	return mensaje_cifrado;
}
string Polybios::Descifrar(string _mensaje_cifrado)
{
	string mensaje_descifrado;
	int size_msj = _mensaje_cifrado.size();
	int pos;
	int x, y;

	for (int i = 0; i < size_msj; i+=2)
	{
		if (_mensaje_cifrado.at(i) == ' ')
		{
			mensaje_descifrado += ' ';
			i++;
		}
		
		x = tabla.find(_mensaje_cifrado.at(i));
		y = tabla.find(_mensaje_cifrado.at(i + 1));

		pos = (5 * x) + y;

		if (pos > 8)
			pos++;

		mensaje_descifrado += abecedario[pos];
	}
	return mensaje_descifrado;
}