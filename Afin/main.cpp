#include "Afin.h"

string ingresar_mensaje()
{
	string mensaje;
	cout << "\nIngrese el mensaje: ";
	getline(cin, mensaje);
	return mensaje;
}
int pedir_clave()
{
	int key;
	cout << "\nIngrese la clave: "; cin >> key;
	return key;
}
int elegir_func()
{
	int op;
	cout << "Seleccione una opcion: \n";
	cout << "1 Cifrado" << endl;
	cout << "2 Descifrado" << endl;
	cout << "\nIngrese su respuesta: "; cin >> op;
	return op;
}
int main()
{
	int op = elegir_func();
	cin.ignore();
	
	string mensaje = ingresar_mensaje();

	if (op == 1)
	{
		Afin Emisor;
		string mensaje_cifrado = Emisor.Cifrar(mensaje);
		cout << "\nMensaje: " << mensaje_cifrado;
		Emisor.print_claves();
	}
	else if (op == 2)
	{
		int a = pedir_clave();
		int b = pedir_clave();

		Afin Receptor(a, b);
		string mensaje_descifrado = Receptor.Descifrar(mensaje);
		cout << "\nMensaje descifrado: " << mensaje_descifrado;
	}
	else
		return 0;
}