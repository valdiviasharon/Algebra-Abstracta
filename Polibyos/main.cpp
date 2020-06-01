#include "Polybios.h"

string ingresar_mensaje()
{
	string mensaje;
	cout << "Ingrese el mensaje: "; 
	getline(cin, mensaje);
	return mensaje;
}
int elegir_func()
{
	int op;
	cout << "Seleccione una opción: \n";
	cout << "1 Cifrado" << endl;
	cout << "2 Descifrado" << endl;
	cout << "\n Ingrese su respuesta: "; cin>>op;
	return op;
}
int main()
{
	int op = elegir_func();
	cin.ignore();

	string mensaje = ingresar_mensaje();
	if (op == 1)
	{
		Polybios Emisor;

		string mensaje_cifrado = Emisor.Cifrar(mensaje);
		cout << "\nMensaje: " << mensaje_cifrado;
	}
	else if (op == 2)
	{
		Polybios Receptor;

		string mensaje_descifrado = Receptor.Descifrar(mensaje);
		cout << "\nMensaje descifrado: " << mensaje_descifrado;
	}
	else
		return 0;
}