#include <iostream>
#include <string> 
#include <cstring>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <time.h> 

using namespace std;
class Practica
{
public:
	string a = "";
	string b = "";
	int size_a = 0;
	int size_b = 0;
	char* cadena;


	Practica(string _a)
	{
		a = _a; 
		size_a = a.size();
		cadena = new char[size_a+1];
		cadena[size_a] = 0;
	}
	Practica(string _a, string _b)
	{
		a = _a;				b = _b;
		size_a = a.size();	size_b = b.size();
	}

	void asignar_a_cadena();
	void cadena_a_string(string& palabra);
	
	void convertir_May_Min();
	
	void mayor_lexicograficamente();

	void reemplazar_signos_x_espacio();

	~Practica() {};

};
