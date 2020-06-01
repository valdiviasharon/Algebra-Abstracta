#include <iostream>
#include <string>

using namespace std;

class MB
{
	private:
		string key;
		string palabra;
		
	public:
		string abecedario = "abcdefghijklmnopqrstuvwxyz. ";
		string numeros = "0123456789";

		MB(int _key1, int _key2, string _palabra);
		string Cifrar(string _mensaje);
		string Descifrar(string _mensaje_cifrado);
		
};

