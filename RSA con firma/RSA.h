#include "funciones.h"

class RSA
{
	private:
		ZZ key_d=ZZ(0);
		ZZ key_e=ZZ(0);
		ZZ N=ZZ(0);
		ZZ p = ZZ(0);
		ZZ q = ZZ(0);
		ZZ clave = ZZ(0);
	public:		
		string abecedario;
		RSA(int tam);
		RSA(ZZ _N, ZZ key, ZZ _p = ZZ(0), ZZ _q=ZZ(0));
		string Cifrar(string _mensaje);
		string Descifrar(string _mensaje_cifrado);
};
void agregar_ceros(long long tam_N, string & bloque)
{
	string ceros(tam_N - bloque.size(), '0');
	ceros += bloque;
	bloque = ceros;
}
RSA::RSA(int tam)
{
	ZZ p, q;
	vector<ZZ> rango = calcular_rango(ZZ(tam));

	p = Generar_Aleatorio(tam, rango);
	q = Generar_Aleatorio(tam, rango);
	
	N = p * q;
	ZZ phi_N = (p - 1) * (q - 1);

	do {
		key_e = RandomBnd(phi_N);
	} while (mcd(key_e, phi_N) != 1);

	key_d = inversa(key_e,phi_N);

	cout << "\nClaves generadas: " << endl;
	cout << "P: "<< p << endl;
	cout << "Q: " << q << endl;
	cout << "N: " << N << endl;
	cout << "E: " << key_e << endl;
	cout << "D: " << key_d << endl;
}
RSA::RSA(ZZ _N, ZZ key , ZZ _p, ZZ _q)
{
	abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	clave=key;
	N = _N;
	p = _p;
	q = _q;
}
string RSA::Cifrar(string _mensaje)
{
	string mensaje_cifrado;
	string pos_alf;
	ZZ size_msj = ZZ(_mensaje.size());
	string tam_abc = to_string(abecedario.size());
	long long num_dig_abc = tam_abc.size();
	string tam_N= ZZ_to_string(N);//to_string N 
	long long num_dig_N = tam_N.size();
	long long size_bloque = num_dig_N - 1;

	//Generamos el string con las posiciones de las letras del mensaje, incluyendo la modificacion del tamaño
	for (long long i=0; i < size_msj; i++)
	{
		ZZ pos( abecedario.find(_mensaje[i]) );
		string _pos = ZZ_to_string(pos); //To string pos;
		if (_pos.size() < num_dig_abc)
			agregar_ceros(num_dig_abc, _pos);
		pos_alf += _pos;
	}
	//Agregamos la posicion de la letra menos usada si necesitaramos mas valores para crear los bloques
	if (modulo(ZZ(pos_alf.size()),ZZ(size_bloque)) > ZZ(0))
	{
		int pos = abecedario.find("w");
		string pos_letra = to_string(pos);
		int sizepos_ = pos_letra.size();
		ZZ modu = modulo(ZZ(pos_alf.size()), ZZ(size_bloque));
		ZZ diferencia = ZZ(size_bloque) - modu;
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
	for (long long i = 0; i < pos_alf.size(); i += size_bloque)
	{
		string bloque = pos_alf.substr(i, size_bloque);
		bloques.push_back(bloque);
	}
	
	//Realizamos el cifrado de cada bloque
	for (long long i = 0; i < bloques.size(); i++)
	{
		ZZ pos_aux = string_to_ZZ(bloques[i]);
		ZZ Q = exp_modular(pos_aux, clave, N);
		string valor= ZZ_to_string(Q); //to_string Q
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
	string tam_N = ZZ_to_string(N);//to_string N
	long long num_dig_N = tam_N.size();
	long long size_bloque = num_dig_N - 1;
	string tam_abc = to_string(abecedario.size());
	long long num_dig_abc = tam_abc.size();
	
	//Creamos los bloques del mensaje descifrado segun el size de N
	vector<string> bloques;
	long long tope = _mensaje_cifrado.size() / num_dig_N;
	for (long long i = 0; i < tope; i++)
	{
		string bloque = _mensaje_cifrado.substr(0, num_dig_N);
		bloques.push_back(bloque);
		_mensaje_cifrado.erase(0, num_dig_N);
	}

	//En un string agrupamos el resultado del descifrado
	for (long long i = 0; i < bloques.size(); i++)
	{
		ZZ Q = string_to_ZZ(bloques[i]);
		ZZ D = exp_modular(Q, clave, N);
		/*if (p != ZZ(0) && q != ZZ(0))
		{
			ZZ dp(modulo(key_d, p - ZZ(1)));
			ZZ dq(modulo(key_d, q - ZZ(1)));
			ZZ Qp(modulo(Q, p));
			ZZ Qq(modulo(Q, q));
			ZZ ap(exp_modular(Qp, dp, p));
			ZZ aq(exp_modular(Qq, dq, q));
			D = resto_chino({ ZZ(1),ZZ(1) }, { ap,aq }, { p,q });
		}
		else
			D = exp_modular(Q, clave, N);*/
		string valor = ZZ_to_string(D);
		if (valor.size() < size_bloque)
			agregar_ceros(size_bloque, valor);
		letras_descifradas += valor;
	}
	
	//Separamos nuevamente en bloques, pero ahora del tamaño del size_abc
	vector<string> letras;
	long long tope2 = letras_descifradas.size() / num_dig_abc;
	for (long long i = 0; i < tope2 ;i++)
	{
		string bloque = letras_descifradas.substr(0, num_dig_abc);
		letras.push_back(bloque);
		letras_descifradas.erase(0, num_dig_abc);
	}
	//Remplazamos cada bloque por su valor en el abecedario
	for (long long i = 0; i < letras.size(); i++)
	{
		long long pos = stoll(letras[i]);
		mensaje_descifrado += abecedario[pos];
	}

	return mensaje_descifrado;
}

