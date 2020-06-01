#include <iostream>
#include <string>

using namespace std;

class Rail_Fence
{
	private:
		int key;
	public:
		Rail_Fence(int _key);
		string Cifrar(string _mensaje);
		string Descifrar(string _mensaje);
};

