#include <iostream>
#include <string> 
#include <sstream>

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
		a = _a; size_a = a.size();
		cadena = new char[size_a];
	}
	Practica(string _a, string _b)
	{
		a = _a; b = _b;
		size_a = a.size(); size_b = b.size();
	}
	void for_asignar(int size);
	void for_concatenar(int size, string& palabra);
	void for_printCadena(int size);
	void convertir_May_Min();
	void insertar();
	void mayor();
	void replace_char(int size);
	void Encriptar(string& codigo);
	~Practica() {};

};
