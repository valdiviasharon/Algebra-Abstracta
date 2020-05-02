#include "Cesar.h"
Cesar::Cesar(int _key)
{
	key = _key;
	abecedario = "abcdefghijklmnopqrstuvwxyz";
	size_abc = abecedario.size();
}
string Cesar::cifrar(string _mensaje)
{
	string mensaje_cifrado;

	int size_mensaje = _mensaje.size();
	int pos, num;
	
	for (int i = 0; i < size_mensaje; i++)
	{
		if (_mensaje.at(i) == ' ')
		{
			mensaje_cifrado.append(" ");
		}
		else
		{
			pos = abecedario.find(_mensaje.at(i)) + key;
			if (pos >= size_abc)
				num = pos % size_abc;
			else
				num = pos;
			mensaje_cifrado.append(abecedario,num,1);
		}
	}
	return mensaje_cifrado;
}

string Cesar::descifrar(string _mensaje_cifrado)
{
	string mensaje_descifrado;

	int size_mensaje = _mensaje_cifrado.size();
	int pos,num;

	for (int i = 0; i < size_mensaje; i++)
	{
		if (_mensaje_cifrado.at(i) == ' ')
		{
			mensaje_descifrado.append(" ");
		}
		else
		{
			pos = abecedario.find(_mensaje_cifrado.at(i)) - key;
			if (pos < 0)
				num = size_abc + pos;
			else
				num = pos;
			mensaje_descifrado.append(abecedario, num, 1);
		}
	}
	return mensaje_descifrado;
}
