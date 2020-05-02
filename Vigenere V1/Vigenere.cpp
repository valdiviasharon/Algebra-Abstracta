#include "Vigenere.h"

Vigenere::Vigenere(string _key)
{
	key = _key;			
	size_key = key.size();
	
	abecedario = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
	size_abc = abecedario.size();
	ASCII = "-------------------------------- !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[|]^_'abcdefghijklmnopqrstuvwxyz";
	size_ascii = ASCII.size();
}

string Vigenere::Cifrar(string _mensaje)
{
	string mensaje_cifrado;
	int size_msj = _mensaje.size();
	int pos_mensaje;
	int pos_key;
	int pos_final;

	if (size_key < size_msj) //Se extiende la clave, al tamaño del mensaje
	{
		int diferencia = size_msj - size_key;
		for (int i = 0; i < diferencia; i++)
			key += key[i];
	}

	for (int i = 0; i < size_msj; i++)
	{	
		pos_mensaje = abecedario.find(_mensaje.at(i));
		pos_key = abecedario.find(key.at(i));
		pos_final = pos_mensaje + pos_key;
		if (pos_final >= size_abc)
			pos_final = pos_final % size_abc;
		mensaje_cifrado += abecedario[pos_final];
	}
	return mensaje_cifrado;
}
string Vigenere::Descifrar(string _mensaje_cifrado)
{
	string mensaje_descifrado;
	int size_msj = _mensaje_cifrado.size();

	int pos_mensaje;
	int pos_key;
	int pos_final;

	if (size_key < size_msj)//Se extiende la clave, al tamaño del mensaje
	{
		int diferencia = size_msj - size_key;
		for (int i = 0; i < diferencia; i++)
			key += key[i];
	}

	for (int i = 0; i < size_msj; i++)
	{
		pos_mensaje = abecedario.find(_mensaje_cifrado.at(i));
		pos_key = abecedario.find(key.at(i));

		pos_final = (pos_mensaje - pos_key);
		if (pos_final < 0)
			pos_final += size_abc;
		mensaje_descifrado += abecedario[pos_final];
	}

	return mensaje_descifrado;
}

string Vigenere::Cifrar_ASCII(string _mensaje)
{
	string mensaje_cifrado;
	int size_msj = _mensaje.size();
	int pos_mensaje;
	int pos_key;
	int pos_final;

	if (size_key < size_msj)//Se extiende la clave, al tamaño del mensaje
	{
		int diferencia = size_msj - size_key;
		for (int i = 0; i < diferencia; i++)
			key += key[i];
	}

	for (int i = 0; i < size_msj; i++)
	{
		pos_mensaje = ASCII.find(_mensaje.at(i));
		pos_key = ASCII.find(key.at(i));

		pos_final = pos_mensaje + pos_key;

		if (pos_final >= size_ascii)
			pos_final = (pos_final % size_ascii) + 32; //Toma en cuenta los caracteres a partir de la pos 32, donde se encuentra el espacio
		mensaje_cifrado += ASCII[pos_final];
	}
	return mensaje_cifrado;
}
string Vigenere::Descifrar_ASCII(string _mensaje_cifrado)
{
	string mensaje_descifrado;
	int size_msj = _mensaje_cifrado.size();

	int pos_mensaje;
	int pos_key;
	int pos_final;

	if (size_key < size_msj)//Se extiende la clave, al tamaño del mensaje
	{
		int diferencia = size_msj - size_key;
		for (int i = 0; i < diferencia; i++)
			key += key[i];
	}

	for (int i = 0; i < size_msj; i++)
	{
		pos_mensaje = ASCII.find(_mensaje_cifrado.at(i));
		pos_key = ASCII.find(key.at(i));

		pos_final = pos_mensaje + pos_key;

		pos_final = (pos_mensaje - pos_key);
		if (pos_final < 0)
		{
			pos_final += size_abc;
			pos_final += 32;//Toma en cuenta los caracteres a partir de la pos 32, donde se encuentra el espacio
		}

		mensaje_descifrado += ASCII[pos_final];
	}
	return mensaje_descifrado;
}

string Vigenere::Cifrar_ejer_e(string _mensaje)
{
	string mensaje_cifrado;
	int pos_mensaje;
	int pos_key;
	int pos_final;

	for (int i = 10; i < _mensaje.size(); i += 10) //Agregamos la palabra AQUI cada 10 caracteres
	{
		_mensaje.insert(i, "AQUI");
		i += 4; //avanzamos el iterador después de terminar la palabra aqui
	}

	while (_mensaje.size() % 4 != 0) //Agrega la letra W al final si el tamaño del mensaje no es multiplo de 4
	{
		_mensaje += "W";
	}

	if (size_key < _mensaje.size()) //Se extiende la clave, al tamaño del mensaje
	{
		int diferencia = _mensaje.size() - size_key;
		for (int i = 0; i < diferencia; i++)
			key += key[i];
	}
	for (int i = 0; i < _mensaje.size(); i++)
	{
		pos_mensaje = abecedario.find(_mensaje.at(i));
		pos_key = abecedario.find(key.at(i));
		pos_final = pos_mensaje + pos_key;
		if (pos_final >= size_abc)
			pos_final = pos_final % size_abc;
		mensaje_cifrado += abecedario[pos_final];
	}
	return mensaje_cifrado;
}
string Vigenere::Descifrar_ejer_e(string _mensaje_cifrado)
{
	string mensaje_descifrado;

	int size_msj = _mensaje_cifrado.size();

	int pos_mensaje;
	int pos_key;
	int pos_final;

	if (size_key < size_msj) //Se extiende la clave, al tamaño del mensaje
	{
		int diferencia = size_msj - size_key;
		for (int i = 0; i < diferencia; i++)
			key += key[i];
	}

	for (int i = 0; i < size_msj; i++)
	{
		pos_mensaje = abecedario.find(_mensaje_cifrado.at(i));
		pos_key = abecedario.find(key.at(i));

		pos_final = (pos_mensaje - pos_key);
		if (pos_final < 0)
			pos_final += size_abc;
		mensaje_descifrado+= abecedario[pos_final];
	}

	for (int i = size_msj-1; i > size_msj-4; i--) //Se eliminan las letras W que se encuentren en las ultimas 4 posiciones, ya que si pasa de este rango no se tomaria el cuenta si es multiplo de 4.
	{
		if (mensaje_descifrado.at(i) == 'W')
			mensaje_descifrado.pop_back();
	}
	int size = mensaje_descifrado.size();

	for (int i = 10; i < size; i += 10) //Eliminamos las palabras AQUI que se encuentren 
	{
		if(int pos=mensaje_descifrado.find("AQUI"))
		{
			mensaje_descifrado.erase(pos, 4);
			i += 4;
		}
	}
	return mensaje_descifrado;
}

string Vigenere::Cifrar_ejer_f(string _mensaje)
{
	string mensaje_cifrado;
	int size_msj = _mensaje.size();
	int pos_mensaje;
	int pos_key;
	int pos_final;

	if (size_key < size_msj) //Se extiende la clave, al tamaño del mensaje, con las letras que conforman el mensaje plano.
	{
		int diferencia = size_msj - size_key;
		for (int i = 0; i < diferencia; i++)
			key += _mensaje[i];
	}
	cout << key;
	for (int i = 0; i < size_msj; i++)
	{
		pos_mensaje = abecedario.find(_mensaje.at(i));
		pos_key = abecedario.find(key.at(i));
		pos_final = pos_mensaje + pos_key;
		if (pos_final >= size_abc)
			pos_final = pos_final % size_abc;
		mensaje_cifrado += abecedario[pos_final];
	}
	return mensaje_cifrado;
}
string Vigenere::Descifrar_ejer_f(string _mensaje_cifrado)
{
	string mensaje_descifrado;
	int size_msj = _mensaje_cifrado.size();

	int pos_mensaje;
	int pos_key;
	int pos_final;

	int size_aux = key.size();
	for (int i = 0; i < size_msj; i++)
	{
		pos_mensaje = abecedario.find(_mensaje_cifrado.at(i));
		pos_key = abecedario.find(key.at(i));

		pos_final = (pos_mensaje - pos_key);
		if (pos_final < 0)
			pos_final += size_abc;
		mensaje_descifrado += abecedario[pos_final];
		key += mensaje_descifrado[i]; //Conforme vamos decifrando las primeras letras del mensaje plano, agregamos estas "key" ya que no sabemos que letras conforman al no ser almacenada esta informacion por seguridad
	}

	return mensaje_descifrado;
}

