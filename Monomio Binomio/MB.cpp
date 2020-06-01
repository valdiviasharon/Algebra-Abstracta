#include "MB.h"
int modulo(int a, int b)
{
	int r = a - ((a / b) * b);
	if (r < 0)
		r = a - (((a / b) - 1) * b);
	return r;
}
MB::MB(int key_1, int key_2, string _palabra)
{
	//string de la clave
	key += to_string(key_1);
	key += to_string(key_2);

	palabra = _palabra;
	//nuevo abecedario	
	for(int i=0;i<palabra.size();i++)
	{
		int pos = abecedario.find(palabra.at(i));
		if (pos>=0)
		{
			abecedario.erase(pos, 1);
		}
	}
	//Modificamos la palabra 
	palabra.insert(key_1, "-");
	palabra.insert(key_2, "-");

	abecedario.insert(0, palabra);
}
string MB::Cifrar(string _mensaje)
{
	string mensaje_cifrado;
	int size_msj = _mensaje.size();

	for (int i = 0; i < size_msj; i++)
	{
		int pos = abecedario.find(_mensaje.at(i));
		if (pos < 10)
		{
			mensaje_cifrado += numeros.at(pos);
		}
		else
		{
			(pos < 20) ? mensaje_cifrado += key.at(0) : mensaje_cifrado += key.at(1);
			pos = modulo(pos, 10);
			mensaje_cifrado += numeros.at(pos);
		}
	}
	return mensaje_cifrado;
}
string MB::Descifrar(string _mensaje_cifrado)
{
	string mensaje_descifrado;
	int size_msj= _mensaje_cifrado.size();

	for (int i = 0; i < size_msj; i++)
	{
		int pos = 0;
		if (_mensaje_cifrado.at(i) == key.at(0))
		{
			i++;
			pos = 10;
		}
		else if (_mensaje_cifrado.at(i) == key.at(1))
		{
			i++;
			pos = 20;
		}
		pos += numeros.find(_mensaje_cifrado.at(i));
		mensaje_descifrado += abecedario.at(pos);
	}
	return mensaje_descifrado;
}

