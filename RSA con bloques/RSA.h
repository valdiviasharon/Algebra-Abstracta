#include "funciones.h"
#include <string>
class RSA
{
	private:
		long long key_d=0;
		long long key_e=0;
		long long N=0;

	public:		
		string abecedario;
		long long clave=0;
		RSA(long long tam);
		RSA(long long _key, long long _N);
		string Cifrar(string _mensaje);
		string Descifrar(string _mensaje_cifrado);
};
void agregar_ceros(int tam_N, string & bloque)
{
	string ceros(tam_N - bloque.size(), '0');
	ceros += bloque;
	bloque = ceros;
}
RSA::RSA(long long tam=1000)
{
	long long p, q;
	criba(1, tam, p, q);
	N = p * q;
	
	long long phi_N = (p - 1) * (q - 1);

	do {
		key_e = random(phi_N, 1);
	} while (mcd(key_e, phi_N) != 1);

	key_d = inversa(key_e, phi_N);

	cout << "\nClaves generadas: " << endl;
	cout << "\nClave publica es : <" << N << "," << key_e << ">" << endl;
	cout << "\nClave privada es : <" << N << "," << key_d << ">" << endl;
}
RSA::RSA(long long _N, long long key)
{
	abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	clave=key;
	N = _N;
}
string RSA::Cifrar(string _mensaje)
{
	string mensaje_cifrado;
	string pos_alf;
	long long size_msj = _mensaje.size();
	string tam_abc = to_string(abecedario.size());
	int num_dig_abc = tam_abc.size();
	string tam_N = to_string(N);
	int num_dig_N = tam_N.size();
	int size_bloque = num_dig_N - 1;

	//Generamos el string con las posiciones de las letras del mensaje, incluyendo la modificacion del tamaño
	for (long long i = 0; i < size_msj; i++)
	{
		long long pos = abecedario.find(_mensaje.at(i));
		string _pos = to_string(pos);
		if (_pos.size() < num_dig_abc)
			agregar_ceros(num_dig_abc, _pos);
		pos_alf += _pos;
	}
	//Agregamos la posicion de la letra menos usada si necesitaramos mas valores para crear los bloques
	if (modulo(pos_alf.size(), size_bloque))
	{
		int pos = abecedario.find(",");
		string pos_letra = to_string(pos);
		int sizepos_ = pos_letra.size();
		int modu = modulo(pos_alf.size(), size_bloque);
		int diferencia = (size_bloque) - modu;
		if ( diferencia > sizepos_)
		{
			for (int i = 0; i < diferencia - sizepos_; i++)
				pos_letra += pos_letra[i];
		}
		
		for (int i = 0; i < diferencia; i++)
			pos_alf += pos_letra[i];
	}
	//Generamos los bloques y los agregamos a un vector de string que los almacenara
	vector<string>bloques;
	for (int i = 0; i < pos_alf.size(); i += size_bloque)
	{
		string bloque = pos_alf.substr(i, size_bloque);
		bloques.push_back(bloque);
	}
	
	//Realizamos el cifrado de cada bloque
	for (int i = 0; i < bloques.size(); i++)
	{
		int pos = stoi(bloques[i]);
		long long Q = exp_modular(pos, clave, N);
		string valor = to_string(Q);
		if (valor.size() < num_dig_N)
			agregar_ceros(num_dig_N, valor);
		mensaje_cifrado += valor;
	}	
	return mensaje_cifrado;
}
string RSA::Descifrar(string _mensaje_cifrado)
{
	string mensaje_descifrado;
	string letras_descifradas;

	string tam_N = to_string(N);
	int num_dig_N = tam_N.size();
	int size_bloque = num_dig_N - 1;

	string tam_abc = to_string(abecedario.size());
	int num_dig_abc = tam_abc.size();
	
	//Creamos los bloques del mensaje descifrado segun el size de N
	vector<string> bloques;

	for (int i = 0; i < _mensaje_cifrado.size(); i += num_dig_N)
	{
		string bloque = _mensaje_cifrado.substr(i, num_dig_N);
		bloques.push_back(bloque);
	}

	//En un string agrupamos el resultado del descifrado
	for (int i = 0; i < bloques.size(); i++)
	{
		long long Q = stoll(bloques[i]);
		long long D = exp_modular(Q, clave, N);
		string valor = to_string(D);
		if (valor.size() < size_bloque)
			agregar_ceros(size_bloque, valor);
		letras_descifradas += valor;
	}

	//Separamos nuevamente en bloques, pero ahora del tamaño del size_abc
	vector<string> letras;
	for (int i = 0; i < letras_descifradas.size() ; i+=num_dig_abc)
	{
		string bloque = letras_descifradas.substr(i, num_dig_abc);
		letras.push_back(bloque);
	}
	//Remplazamos cada bloque por su valor en el abecedario
	for (int i = 0; i < letras.size(); i++)
	{
		int pos = stoi(letras[i]);
		mensaje_descifrado += abecedario[pos];
	}
	
	return mensaje_descifrado;
}

