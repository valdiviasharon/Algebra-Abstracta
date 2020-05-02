#include "Practica.h"

void Practica::for_asignar(int size)
{
	for (int i = 0; i < size; i++)
		cadena[i] = a[i];
}
void Practica::for_concatenar(int size, string& palabra)
{
	for (int i = 0; i < size; i++)
		palabra += cadena[i];
}
void Practica::for_printCadena(int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << cadena[i];
	}
}

void Practica::convertir_May_Min()
{
	for (int i = 0; i < size_a; i++)
	{
		if (islower(cadena[i]))
		{
			a[i] = toupper(a[i]);
		}
		else
		{
			a[i] = tolower(a[i]);
		}
	}
}
void Practica::mayor()
{
	cout << "Mayor: ";
	if (a > b)
		cout << a;
	else
		cout << b;
}
void Practica::insertar()
{
	a.insert((size_a / 2), b);
}

void Practica::replace_char(int size)
{
	int found;

	for (int i = 0; i < size; i++)
	{
		found = a.find_first_of("-.;,:");
		if (found != string::npos)
		{
			a.replace(found, 1, " ");
		}
	}
}
void Practica::Encriptar(string& codigo)
{
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (b[i] == a[j])
				codigo += a[j + 13];
		}
	}
}