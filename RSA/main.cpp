#include <NTL/ZZ.h>
#include "RSA.h"

NTL_CLIENT

void numeros_primos(int & a, int & b, int rango)
{
	int inicio = random(rango, 1);
	criba(inicio, rango, a, b);
}
int generar_claves()
{
	int p = 0, q = 0;
	numeros_primos(p, q, 100);

	int N = p * q;
	int phi_N = (p - 1) * (q - 1);

	int key_e, key_d;
	do {
		key_e = random(phi_N, 1);
	} while (mcd(key_e, phi_N) != 1);

	key_d= inversa(key_e, phi_N);
	
	cout << "\nClave publica es : <" << N << "," << key_e << ">" << endl;
	return key_d;
}
int main()
{
	int key_d=generar_claves();
	int key_e;
	int N;

	cout << endl << "Ingrese la clave publica: "; cin >> key_e;
	cout << endl << "Ingrese N: "; cin >> N;

	string mensaje;
	cin.ignore();
	cout << endl << "Ingrese la mensaje: "; getline(cin, mensaje);

	RSA Emisor(N, key_e);

	string mensaje_cifrado=Emisor.Cifrar(mensaje);
	cout << endl << "Mensaje cifrado: " << mensaje_cifrado;

	RSA Receptor(N);
	Receptor.set_key_d(key_d);
	cout << endl << "Ingrese N: "; cin >> N;
	string mensaje_descifrado = Receptor.Descifrar(mensaje_cifrado);
	cout << endl << "Mnesaje descifrado: " << mensaje_descifrado;
}