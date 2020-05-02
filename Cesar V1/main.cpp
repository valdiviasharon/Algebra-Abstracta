
#include "Cesar.h"
string pedir_mensaje()
{
	string mensaje;
	cout << "\nMensaje a cifrar: "; getline(cin, mensaje);
	return mensaje;
}
int main()
{
	string mensaje = pedir_mensaje();
	int key;
	cout << "Ingrese la clave: "; cin >> key;

	Cesar Emisor(key);
	Cesar Receptor(key);

	string mensaje_cifrado=Emisor.cifrar(mensaje);
	cout << "\nMensaje cifrado: " << mensaje_cifrado << endl;

	string mensaje_descifrado = Receptor.descifrar(mensaje_cifrado);
	cout << "\nMensaje descifrado: " << mensaje_descifrado ;
};