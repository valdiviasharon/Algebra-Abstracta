#include "funciones.h"
#include <string>
class RSA
{
	private:
		int key_d=0;
	public:		
		string abecedario;
		int key_e;
		int N;
		RSA(int _key_e, int _N);
		string Cifrar(string _mensaje);
		string Descifrar(string _mensaje_cifrado);
		void set_key_d(int key);
};
RSA::RSA(int _N, int _key_e=0)
{
	abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	key_e = _key_e;
	N = _N;
}
void RSA::set_key_d(int key)
{
	key_d = key;
}
string RSA::Cifrar(string _mensaje)
{
	string mensaje_cifrado;
	int size_msj = _mensaje.size();

	for (int i = 0; i < size_msj; i++)
	{
		int pos = abecedario.find(_mensaje.at(i));
		int Q = exp_modular(pos, key_e, N);

		string valor = to_string(Q);
		mensaje_cifrado += valor;
		mensaje_cifrado += " ";
	}
	return mensaje_cifrado;
}
string RSA::Descifrar(string _mensaje_cifrado)
{
	string mensaje_descifrado;

	int size_msj = _mensaje_cifrado.size();

	for (int i = 0; i < _mensaje_cifrado.size();)
	{
		int pos_esp = _mensaje_cifrado.find(" ",i);
		string letra = _mensaje_cifrado.substr(i, pos_esp);
		_mensaje_cifrado.erase(i, letra.size()+1);
		int Q = stoi(letra);
		int D = exp_modular(Q, key_d, N);
		mensaje_descifrado += abecedario[D];
	}
	
	return mensaje_descifrado;
}

