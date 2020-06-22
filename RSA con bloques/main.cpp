#include "RSA.h"

int elegir_funcion()
{
	int op;
	cout << "Opciones: ";
	cout << endl << "1 Generar Claves";
	cout << endl << "2 Cifrar";
	cout << endl << "3 Descifrar";
	cout << endl << "Ingrese su opcion: "; cin >> op;
	return op;
}
int main()
{
	int op = elegir_funcion();
	if (op == 1)
	{
		int tam;
		cout << "\nIngrese el rango de su clave: "; cin >> tam;
		RSA Generar_clave(tam);
	}
	else if (op == 2)
	{
		long long key, N;

		cout << endl << "Ingrese la clave publica: "; cin >> key;
		cout << endl << "Ingrese N: "; cin >> N;

		string mensaje;
		cin.ignore();
		cout << endl << "Ingrese la mensaje: "; getline(cin, mensaje);

		RSA Emisor(N, key);

		string mensaje_cifrado = Emisor.Cifrar(mensaje);
		cout << endl << "Mensaje cifrado: " << mensaje_cifrado;
	}
	else if (op == 3)
	{
		long long key, N;

		cout << endl << "Ingrese la clave privada: "; cin >> key;
		cout << endl << "Ingrese N: "; cin >> N;

		string mensaje;
		cin.ignore();
		cout << endl << "Ingrese la mensaje: "; getline(cin, mensaje);

		RSA Receptor(N, key);
		string mensaje_descifrado = Receptor.Descifrar(mensaje);
		cout << endl << "Mensaje descifrado: " << mensaje_descifrado;
	}
}