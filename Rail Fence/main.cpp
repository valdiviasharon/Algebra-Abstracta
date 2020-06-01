#include "Rail_Fence.h"
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
	cout << "\n Ingrese su respuesta: "; cin >> op;
	return op;
}
int pedir_key()
{
	int key;
	cout << "\Ingrese la clave: "; cin >> key;
	return  key;
}
int main()
{
	int op = elegir_func();
	int key = pedir_key();
	cin.ignore();
	string mensaje = ingresar_mensaje();

	if (op == 1)
	{
		Rail_Fence Emisor(key);
		string mensaje_cifrado = Emisor.Cifrar(mensaje);
		cout << "\Mensaje cifrado: " << mensaje_cifrado;
	}
	else if (op == 2)
	{
		Rail_Fence Receptor(key);
		string mensaje_descifrado=Receptor.Descifrar(mensaje);
		cout << "\Mensaje descifrado: " << mensaje_descifrado;
	}
	else
		return 0;
}