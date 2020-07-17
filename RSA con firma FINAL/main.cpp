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
		long long nbits;
		cout << "\nIngrese el numero de bits: "; cin >> nbits;
		RSA Generar_clave(nbits / 2);
	}
	else if (op == 2)
	{
		ZZ keyr, Nr;
		ZZ key, N;

		cout << endl << "Ingrese su clave privada : "; cin >> key;
		cout << endl << "Ingrese su N: "; cin >> N;

		cout << endl << "Ingrese la clave publica del receptor: "; cin >> keyr;
		cout << endl << "Ingrese N del receptor: "; cin >> Nr;

		string mensaje;
		cin.ignore();
		cout << endl << "Ingrese el mensaje: "; getline(cin, mensaje);

		RSA Emisor(N, key, Nr, keyr);
		string mensaje_cifrado = Emisor.Cifrar(mensaje);
		cout << endl << "Mensaje cifrado: " << mensaje_cifrado;
	}
	else if (op == 3)
	{
		ZZ key, N, p, q;
		ZZ keye, Ne;

		cout << endl << "Ingrese la clave del emisor: "; cin >> keye;
		cout << endl << "Ingrese N del emisor: "; cin >> Ne;
		cout << endl << "Ingrese la clave privada: "; cin >> key;
		cout << endl << "Ingrese N: "; cin >> N;
		cout << endl << "Ingrese P: "; cin >> p;
		cout << endl << "Ingrese Q: "; cin >> q;

		string mensaje;
		cin.ignore();
		cout << endl << "Ingrese el mensaje: "; getline(cin, mensaje);

		RSA Receptor(N, key, Ne, keye , p, q);
		string mensaje_descifrado = Receptor.Descifrar(mensaje);

		cout << endl << "Mensaje descifrado: " << mensaje_descifrado;
	}
	else
		return 0;
}