#include <iostream>
#include <string>

using namespace std;
class Cesar
{
	private:
		int key;
		
	public:

		string abecedario;
		int size_abc;

		Cesar(int _key);
		string cifrar(string _mensaje);
		string descifrar(string _mensaje_cifrado);

};

