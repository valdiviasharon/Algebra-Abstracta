#include <iostream>
#include <string>

using namespace std;

class Polybios
{
	private:
		string tabla = "ABCDE";
	public:
		string abecedario = "abcdefghijklmnopqrstuvxyz";

		Polybios () {};

		string Cifrar(string _mensaje);
		string Descifrar(string _mensaje_cifrado);
};

