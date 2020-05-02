#include "Cesar.h"
Cesar::Cesar(int _key)
{
	key = _key;
	abecedario = "abcdefghijklmnopqrstuvwxyz";
}
string Cesar::cifrar(string _mensaje)
{
	string mensaje_cifrado;

	string new_abecedario;
	new_abecedario.assign(abecedario.begin() + key, abecedario.end());
	new_abecedario.append(abecedario.begin(), abecedario.begin() + key);

	int size_mensaje = _mensaje.size();
	
	for (int i = 0; i < size_mensaje; i++)
	{
		if (_mensaje.at(i) == ' ')
		{
			mensaje_cifrado.append(" ");
		}
		else
		{
			int pos = abecedario.find(_mensaje.at(i));
			mensaje_cifrado.append(new_abecedario, pos, 1);
		}
	}
	return mensaje_cifrado;
}

string Cesar::descifrar(string _mensaje_cifrado)
{
	string mensaje_descifrado;

	string new_abecedario;
	new_abecedario.assign(abecedario.begin() + key, abecedario.end());
	new_abecedario.append(abecedario.begin(), abecedario.begin() + key);

	int size_mensaje = _mensaje_cifrado.size();

	for (int i = 0; i < size_mensaje; i++)
	{
		if (_mensaje_cifrado.at(i) == ' ')
		{
			mensaje_descifrado.append(" ");
		}
		else
		{
			int pos = new_abecedario.find(_mensaje_cifrado.at(i));
			mensaje_descifrado.append(abecedario, pos, 1);
		}
	}
	return mensaje_descifrado;
}