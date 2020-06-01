#include "Rail_Fence.h"

Rail_Fence::Rail_Fence(int _key)
{
	key = _key;
}
string Rail_Fence::Cifrar(string _mensaje)
{
	string mensaje_cifrado;
	int size_msj = _mensaje.size();
	
	int avance_pos = (key-1)*2;
	int avance_1 = avance_pos;
	int avance_2 = 0;

	for (int i = 0; i < key; i++)
	{	
		if (i == 0 || i == (key - 1))
		{
			for (int j=i; j < size_msj; j += avance_pos)
				mensaje_cifrado += _mensaje.at(j);
		}
		else
		{
			for(int j=i;j<size_msj;j+=avance_2)
			{
				mensaje_cifrado += _mensaje.at(j);
				j += avance_1;	
				if (j < size_msj)
					mensaje_cifrado += _mensaje.at(j);
			}
		}
		avance_1 -= 2;
		avance_2 += 2;
	}
	return mensaje_cifrado;
}
string Rail_Fence::Descifrar(string _mensaje_cifrado)
{
	int size_msj = _mensaje_cifrado.size();
	string mensaje_descifrado(size_msj,' ');

	int avance_pos = (key - 1) * 2;
	int avance_1 = avance_pos;
	int avance_2 = 0;

	int k = 0; //Funciona como iterador del mensaje
	for (int i = 0; i < key;i++)
	{
		if (i == 0 || i == (key-1))
		{
			for (int j=i; j < size_msj; j += avance_pos)
			{
				if (k < size_msj) //Verifica que no se pase del tamaño del mensaje
				{
					mensaje_descifrado.replace(j, 1, _mensaje_cifrado, k, 1);
					k++;
				}
			}
		}
		else
		{
			for (int j=i; j < size_msj; j += avance_2)
			{
				mensaje_descifrado.replace(j, 1, _mensaje_cifrado, k, 1);
				k++;
				j += avance_1;
				if (j < size_msj) //Verifica dentro del bucle que el valor no pase del tamaño del mensaje
				{
					mensaje_descifrado.replace(j, 1, _mensaje_cifrado, k, 1);
					k++;
				}
			}
		}
		avance_1 -= 2;
		avance_2 += 2;
	}
	return mensaje_descifrado;
}