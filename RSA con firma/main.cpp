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
		RSA Generar_clave(nbits/2);
	}
	else if (op == 2)
	{
		ZZ keyr, Nr;

		cout << endl << "Ingrese la clave publica del receptor: "; cin >> keyr;
		cout << endl << "Ingrese N del receptor: "; cin >> Nr;

		string mensaje;
		cin.ignore();
		cout << endl << "Ingrese el mensaje: "; getline(cin, mensaje);

		ZZ key, N;

		cout << endl << "Ingrese su clave privada : "; cin >> key;
		cout << endl << "Ingrese su N: "; cin >> N;

		RSA Firma(N, key);
		string rubrica=Firma.Cifrar(mensaje);
		RSA Emisor(Nr, keyr);
		string mensaje_cifrado = Emisor.Cifrar(rubrica);
		cout << endl << "Mensaje cifrado: " << mensaje_cifrado;
	}
	else if (op == 3)
	{
		ZZ key, N, p, q;

		cout << endl << "Ingrese la clave privada: "; cin >> key;
		cout << endl << "Ingrese N: "; cin >> N;
		/*cout << endl << "Ingrese P: "; cin >> p;
		cout << endl << "Ingrese Q: "; cin >> q;*/

		string mensaje;
		cin.ignore();
		cout << endl << "Ingrese el mensaje: "; getline(cin, mensaje);

		ZZ keye, Ne;
		cout << endl << "Ingrese la clave del emisor: "; cin >> keye;
		cout << endl << "Ingrese N del emisor: "; cin >> Ne;

		RSA Sin_firma(N, key);//, p, q);
		string mensaje_sin_firma = Sin_firma.Descifrar(mensaje);

		RSA Receptor(Ne, keye);
		string mensaje_descifrado = Receptor.Descifrar(mensaje_sin_firma);

		cout << endl << "Mensaje descifrado: " << mensaje_descifrado;
	}

}