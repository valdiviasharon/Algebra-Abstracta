#include "Vigenere.h"

// ALUMNA: SHARON VALDIVIA BEGAZO

//Se realizo: Cifrado numérico y un intento de cifrado ASCII, ya que aun tenia dudas de como realizar el ejercicio
//El ejercicio de Kasiski no lo realice
//Todos los demás están implementados 
int choice()
{
	int op;

	cout << "Seleccione una opcion: ";
	cout << "\n1 Cifrar";
	cout << "\n2 Descifrar";
	cout << "\n Ingrese la opcion: "; cin >> op;

	return op;
}
void Cifrado_Numerico()
{
	string key;
	string mensaje;

	int op = choice();

	cin.ignore();

	cout << "Ingrese la clave: "; getline(cin, key);
	cout << "\nIngrese el mensaje: "; getline(cin, mensaje);


	if (op == 1)
	{
		Vigenere Emisor(key);
		string mensaje_cifrado = Emisor.Cifrar(mensaje);
		cout << "\nMensaje cifrado: " << mensaje_cifrado;
	}
	else if (op == 2)
	{
		Vigenere Receptor(key);
		string mensaje_descifrado = Receptor.Descifrar(mensaje);
		cout << "\nMensaje descifrado: " << mensaje_descifrado;
	}

}
void Cifrado_ASCII()
{
	string mensaje;
	string key;

	Vigenere Emisor(key);
	Vigenere Receptor(key);

	cout << "Ingrese la clave: "; getline(cin, key);
	cout << "\nIngrese el mensaje: "; getline(cin, mensaje);


	string mensaje_cifrado = Emisor.Cifrar_ASCII(mensaje);
	cout << "\nMensaje cifrado: " << mensaje_cifrado;

	string mensaje_descifrado = Receptor.Descifrar(mensaje_cifrado);
	cout << "\nMensaje descifrado: " << mensaje_descifrado;
}
void ejer_3e()
{
	string key;
	string mensaje;

	cout << "Ingrese una clave: "; getline(cin, key);
	cout << "\nIngrese el mensaje: "; getline(cin, mensaje);

	Vigenere Emisor(key);
	Vigenere Receptor(key);

	string mensaje_cifrado = Emisor.Cifrar_ejer_e(mensaje);
	cout << "\nMensaje cifrado: " << mensaje_cifrado;
	string mensaje_descifrado = Receptor.Descifrar_ejer_e(mensaje_cifrado);
	cout << "\nMensaje descifrado: " << mensaje_descifrado;
}
void ejer_3f()
{
	string key;
	string mensaje;

	cout << "Ingrese una clave: "; getline(cin, key);
	cout << "\nIngrese el mensaje: "; getline(cin, mensaje);

	Vigenere Emisor(key);
	Vigenere Receptor(key);

	string mensaje_cifrado = Emisor.Cifrar_ejer_f(mensaje);
	cout << "\nMensaje cifrado: " << mensaje_cifrado;

	string mensaje_descifrado = Receptor.Descifrar_ejer_f(mensaje_cifrado);
	cout << "\nMensaje descifrado: " << mensaje_descifrado;
}
int main()
{
	//Cifrado_Numerico();
	//Cifrado_ASCII();
	//ejer_3e();
	//ejer_3f();

}