#include "MB.h"
int pedir_clave()
{
	int key;
	cout << "\nIngrese una clave entre 0 y 9: "; cin >> key;
	while (key < 0 || key>9)
	{
		cout << "Error de rango en la clave";
		cout << "\nIngrese una clave: "; cin >> key;
	}
	return key;
}
string pedir_palabra()
{
	string palabra;
	cout << "\nLa palabra para el algoritmo no debe tener letras repetidas y debe tener 8 letras";
	cout << "\nIngrese la palabra: ";
	getline(cin, palabra);
	while(palabra.size() != 8)
	{
		cout << "\Palabra muy pequeña o grande";
		cout << "\nIngrese la palabra: ";
		getline(cin, palabra);
	}
	for (int i = 0; i < palabra.size(); i++)
	{
		for (int j = i + 1; j < palabra.size(); j++)
		{
			if (palabra.at(i) == palabra.at(j))
			{
				cout << "\La palabra tiene letras repetidas";
				cout << "\nIngrese la palabra: ";
				getline(cin, palabra);
				i = 0;
				j = i + 1;
			}
		}
	}
	return palabra;
}
string pedir_mensaje()
{
	string mensaje;
	cout << "\nIngrese el mensaje: ";
	getline(cin, mensaje);
	return mensaje;
}
int elegir_func()
{
	int op;
	cout << "\nSeleccione una opcion: ";
	cout << "\n1 Cifrado";
	cout << "\n2 Descifrado";
	cout << "\nIngrese opcion: "; cin >> op;
	return op;

}
int main()
{
	int op = elegir_func();

	int key_1 = pedir_clave();
	int key_2 = pedir_clave();
	while (key_2 == key_1)
	{
		cout << "\nClaves repetidas";
		key_2 = pedir_clave();
	}
	cin.ignore();
	string palabra = pedir_palabra();

	string mensaje = pedir_mensaje();

	if (op == 1)
	{
		MB Emisor(key_1, key_2, palabra);
		string mensaje_cifrado = Emisor.Cifrar(mensaje);
		cout << "\nMensaje cifrado: " << mensaje_cifrado;
	}
	if (op == 2)
	{
		MB Receptor(key_1, key_2, palabra);
		string mensaje_descifrado = Receptor.Descifrar(mensaje);
		cout << "\nMensaje descifrado: " << mensaje_descifrado;
	}
	else
	{
		return 0;
	}
}