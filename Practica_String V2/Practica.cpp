#include "Practica.h"

void Practica::asignar_a_cadena()
{
	for (int i = 0; i < size_a; i++)
		cadena[i] = a.at(i);
}
void Practica::cadena_a_string( string& palabra)
{
	for (int i = 0; i < size_a; i++)
		palabra.append(1,cadena[i]);
}

void Practica::convertir_May_Min()
{
	for (int i = 0; i < size_a; i++)
	{
		if (islower(a.at(i)))
			a.at(i) = toupper(a.at(i));
		else
			a.at(i) = tolower(a.at(i));
	}
}

void Practica::mayor_lexicograficamente()
{
	cout << "Mayor: ";
	if (a > b)
		cout << a;
	else
		cout << b;
}

void Practica::reemplazar_signos_x_espacio()
{
	int found;
	for (int i = 0; i < size_a; i++)
	{
		found = a.find_first_of("-.;,:");
		if (found != string::npos)
			a.replace(found, 1, " ");
	}
}

