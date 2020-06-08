#include <iostream>
#include <string>

using namespace std;

class Afin
{
	private:
		int key_a;
		int key_b;
		
	public:

		string abecedario;
		Afin();
		Afin(int a, int b);

		string Cifrar(string mensaje);
		string Descifrar(string mensaje);

		void print_claves();
};

