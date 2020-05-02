
#include <iostream>
#include <string>

using namespace std;
class Cesar
{
	private:
		int key;
		string abecedario;
		
	public:
		Cesar(int _key);
		string cifrar(string _mensaje);
		string descifrar(string _mensaje_cifrado);
};