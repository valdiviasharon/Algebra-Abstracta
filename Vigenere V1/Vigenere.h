#include<iostream>
#include <string>

using namespace std;
class Vigenere
{
	private:
		string key;
		int size_key;

	public:

		string abecedario;
		int size_abc;

		string ASCII;
		int size_ascii;

		Vigenere(string _key);

		string Cifrar(string _mensaje);
		string Descifrar(string _mensaje_cifrado);

		string Cifrar_ASCII(string _mensaje);
		string Descifrar_ASCII(string _mensaje_cifrado);

		string Cifrar_ejer_e(string _mensaje);
		string Descifrar_ejer_e(string _mensaje_cifrado);

		string Cifrar_ejer_f(string _mensaje);
		string Descifrar_ejer_f(string _mensaje_cifrado);
		

		~Vigenere() {};
};

