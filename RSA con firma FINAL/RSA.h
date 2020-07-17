#include "funciones.h"

class RSA
{
	private:
		ZZ N=ZZ(0);
		ZZ key = ZZ(0);
		ZZ p = ZZ(0);
		ZZ q = ZZ(0);
		ZZ key_e = ZZ(0);
		ZZ key_d = ZZ(0);
		
		ZZ N2 = ZZ(0);
		ZZ key2 = ZZ(0);
	public:		
		string abecedario;
		RSA(int tam);
		RSA(ZZ _N, ZZ _key, ZZ _N2 , ZZ _key2, ZZ _p=ZZ(0), ZZ _q=ZZ(0));
		
		ZZ mcd(ZZ a, ZZ b);
		vector<ZZ> euclides_ext(ZZ a, ZZ b);
		ZZ inversa(ZZ a, ZZ n);
		ZZ exp_modular(ZZ base, ZZ exp, ZZ n);
		bool is_prime(ZZ numero);
		ZZ Generar_Aleatorio(int t_bits, vector<ZZ> rango);
		ZZ resto_chino(vector<ZZ> a, vector<ZZ>p);

		string Cifrar(string _mensaje);
		string Descifrar(string _mensaje_cifrado);
};
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
RSA::RSA(ZZ _N, ZZ _key , ZZ _N2, ZZ _key2, ZZ _p, ZZ _q)
{
	abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	N = _N;  key = _key;
	p = _p;  q = _q;

	N2 = _N2;  key2 = _key2;
}

//Funciones
ZZ RSA::mcd(ZZ a, ZZ b)
{
	ZZ r(modulo(a, b));
	while (r != 0)
	{
		a = b;
		b = r;
		r = modulo(a, b);
	}
	return b;
}
vector<ZZ> RSA::euclides_ext(ZZ a, ZZ b)
{
	vector<ZZ> valores(3);
	ZZ r1(a), r2(b);
	ZZ x1(1), x2(0);
	ZZ y1(0), y2(1);
	ZZ x;
	ZZ y;
	while (r2 > 0)
	{
		ZZ q = r1 / r2;
		ZZ r = r1 - (q * r2);
		r1 = r2; r2 = r;

		x = x1 - (q * x2);
		x1 = x2; x2 = x;

		y = y1 - (q * y2);
		y1 = y2; y2 = y;
	};

	valores[0] = x1; //x
	valores[1] = y1; //y
	valores[2] = r1; //mcd
	return valores;
}
ZZ RSA::inversa(ZZ a, ZZ n)
{
	if (mcd(n, a) == 1)
	{
		vector<ZZ> results(3);
		results = euclides_ext(a, n);
		ZZ x = results[0];
		if (x < ZZ(0)) //Si es negativo, lo volvemos positivo
			x = modulo(x, n);
		return x;
	}
	return ZZ(0);
}
ZZ RSA::exp_modular(ZZ base, ZZ exp, ZZ n)
{
	ZZ result(1);
	base = modulo(base, n);
	while (exp > 0)
	{
		if (modulo(exp, ZZ(2)) == ZZ(1)) //Si el modulo es igual a 1
			result = modulo(result * base, n); //El resultado es igual a su valor * la base de la exp, modulo n 
		exp >>= 1; //dividimos el exp. entre 2 
		base = modulo((base * base), n);
	}
	return result;
}
bool RSA::is_prime(ZZ numero)//teorema de fermat segunda version 
{
	ZZ aux(8);
	if (exp_modular(aux, numero, numero) != aux)
		return false;
	return true;
}
ZZ RSA::Generar_Aleatorio(int bits, vector<ZZ> rango)
{
	vector<int> desplazamientos = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,2,2,2 }; //Desplazamientos segun el numero de la clave
	vector<ZZ> numero; //vector que almacenara los bits del numero aleatorio

	int enteros = bits / 48; //Cantidad de claves completas necesarias

	int pos = 0;
	for (int i = 0; i < enteros; i++)
	{
		int desp = desplazamientos[i]; //Determinamos los desplazamientos
		vector<ZZ> aux = DES(desp); //Generamos la clave
		for (int j = 0; j < 48; j++) //La agregamos al vector de bits final
			numero.push_back(aux[j]);
	}

	long long mod = ZZ_to_longlong(modulo(ZZ(bits), ZZ(48)));
	if (mod) //Si faltaran bits por completar
	{
		vector<ZZ> restante = DES(desplazamientos[enteros]); //Calculamos una clave restante
		for (int i = 0; i < mod; i++) //Y la agregamos
			numero.push_back(restante[i]);
	}

	//Verificamos que no sea par
	int size = numero.size();
	if (numero[size - 1] == ZZ(0))
		numero[size - 1] = ZZ(1);

	//Verificamos que el numero no este fuera del rango de inicio
	ZZ valor = bin_dec(numero); //Lo convertimos de bin a decimal
	if (valor < rango[0])
		valor += rango[0];

	while (is_prime(valor) == false) //Verificamos si es primo o no 
	{
		valor += 2;
	}

	return valor;
}
ZZ RSA::resto_chino(vector<ZZ>val_a, vector<ZZ>val_p)
{
	//Hallamos los valores de P;
	ZZ P(val_p[0] * val_p[1]);  //P= p*q

	vector<ZZ>val_P(2);
	val_P[0] = val_p[1]; val_P[1] = val_p[0]; //Asignamos q y p 

	//Hallamos los valores de Q
	vector<ZZ>val_q(2);
	for (int i = 0; i < val_q.size(); i++)
	{
		ZZ valor_de_p(val_P[i]);

		if (valor_de_p >= val_p[i]) //Verificamos que pertenezca a Zn
			valor_de_p = modulo(valor_de_p, val_p[i]);

		valor_de_p = inversa(valor_de_p, val_p[i]);
		val_q[i] = modulo(valor_de_p, val_p[i]);
	}

	//Hallamos x0
	ZZ x0(0);
	for (int i = 0; i < 2; i++)
	{
		ZZ aux = (modulo(val_a[i], P) * modulo(val_P[i], P) * modulo(val_q[i], P));
		x0 += modulo(aux, P);
	}

	x0 = modulo(x0, P);

	return x0;
}

//Cifrado y descifrado
string RSA::Cifrar(string _mensaje)
{
	string mensaje_cifrado_1;
	string mensaje_cifrado_2;
	string pos_alf;

	ZZ size_msj = ZZ(_mensaje.size());

	//Abecedario
	string tam_abc = to_string(abecedario.size());
	int num_dig_abc = tam_abc.size();
	//N 
	string tam_N= ZZ_to_string(N);
	int num_dig_N = tam_N.size();
	int size_bloque_N = num_dig_N - 1;
	//N del receptor
	string tam_N2 = ZZ_to_string(N2);
	int num_dig_N2 = tam_N2.size();
	int size_bloque_N2 = num_dig_N2 - 1;

	//Generamos el string con las posiciones de las letras del mensaje, agregando ceros cuando lo necesite
	for (int i=0; i < size_msj; i++)
	{
		ZZ pos( abecedario.find(_mensaje[i]) );
		string _pos = ZZ_to_string(pos);
		if (_pos.size() < num_dig_abc) //Agregamos ceros de ser necesario
			_pos = agregar_ceros(num_dig_abc, _pos);
		pos_alf += _pos;
	}

	//Agregamos la posicion de la letra menos usada si necesitaramos mas valores para crear los bloques
	if (modulo(ZZ(pos_alf.size()),ZZ(size_bloque_N)) > ZZ(0))
	{
		int pos = abecedario.find("W");
		string pos_letra = to_string(pos); //Posicion en string
		int size_letra = pos_letra.size(); //Tamaño del string 
		ZZ modu = modulo(ZZ(pos_alf.size()), ZZ(size_bloque_N)); //calculamos la cantidad que falta para rellenar el string
		ZZ diferencia = ZZ(size_bloque_N) - modu;
		if ( diferencia > size_letra) //Si esa diferencia es mayor al tamaño de la letra aumentamos los caracteres necesarios a ese string
		{
			for (int i = 0; i < diferencia - size_letra; i++)
				pos_letra += pos_letra[i];
		}
		pos_alf += pos_letra; //Agregamos las posiciones
	}
	
	//Generamos los primeros bloques y los agregamos a un vector de string que los almacenara
	vector<string>bloques=generar_bloques(pos_alf,size_bloque_N);
	//Realizamos el cifrado de cada bloque
	for (int i = 0; i < bloques.size(); i++)
	{
		ZZ bloque = string_to_ZZ(bloques[i]);
		ZZ Q = exp_modular(bloque, key, N);
		string valor= ZZ_to_string(Q); 
		if (valor.size() < num_dig_N) //Agregamos ceros de ser necesario
			valor = agregar_ceros(num_dig_N, valor);
		mensaje_cifrado_1 += valor;
	}

	//Agregamos la posicion de la letra menos usada si necesitaramos mas valores para crear los bloques
	if (modulo(ZZ(mensaje_cifrado_1.size()), ZZ(size_bloque_N2)) > ZZ(0))
	{
		int pos = abecedario.find("w");
		string pos_letra = to_string(pos); //Posicion en string
		int size_letra = pos_letra.size();
		ZZ modu = modulo(ZZ(mensaje_cifrado_1.size()), ZZ(size_bloque_N2)); //Calculamos la cantidad de espacios que se necesitan para el bloque
		ZZ diferencia = ZZ(size_bloque_N2) - modu;
		if (diferencia > size_letra) //Si esa diferencia es mayor al tamaño de la posicion, 
		{
			for (int i = 0; i < diferencia - size_letra; i++) //Aumentamos esos caracteres al string
				pos_letra += pos_letra[i];  
		}
		mensaje_cifrado_1 += pos_letra; //Agregamos las posiciones
	}
	//Volvemos a separar en bloques
	vector<string>bloques_2 = generar_bloques(mensaje_cifrado_1, size_bloque_N2);
	//Realizamos su cifrado
	for (int i = 0; i < bloques_2.size(); i++)
	{
		ZZ bloque = string_to_ZZ(bloques_2[i]);
		ZZ Q = exp_modular(bloque, key2, N2);
		string valor = ZZ_to_string(Q);
		if (valor.size() < num_dig_N2) //Agregamos ceros de ser necesarios
			valor = agregar_ceros(num_dig_N2, valor);
		mensaje_cifrado_2+= valor;
	}

	return mensaje_cifrado_2;
}
string RSA::Descifrar(string _mensaje_cifrado)
{
	string mensaje_descifrado_1;
	string mensaje_descifrado_2;
	string letras_descifradas_1;
	string letras_descifradas_2;

	ZZ size_msj = ZZ(_mensaje_cifrado.size());

	//Abecedario
	string tam_abc = to_string(abecedario.size());
	int num_dig_abc = tam_abc.size();
	//N 
	string tam_N = ZZ_to_string(N);
	int num_dig_N = tam_N.size();
	int size_bloque_N = num_dig_N - 1;
	//N del emisor
	string tam_N2 = ZZ_to_string(N2);
	int num_dig_N2 = tam_N2.size();
	int size_bloque_N2 = num_dig_N2 - 1;
	
	//Creamos los bloques del mensaje cifrado segun el size de N
	vector<string> bloques = generar_bloques(_mensaje_cifrado, num_dig_N);

	//En un string agrupamos el resultado del descifrado
	for (int i = 0; i < bloques.size(); i++)
	{
		ZZ Q = string_to_ZZ(bloques[i]);
		ZZ D; 
		if (p != ZZ(0) && q != ZZ(0))
		{
			ZZ dp(modulo(key, p - ZZ(1)));
			ZZ dq(modulo(key, q - ZZ(1)));
			ZZ ap = exp_modular(Q, dp, p);
			ZZ aq = exp_modular(Q, dq, q);
			D = resto_chino({ ap,aq }, { p,q });
		}
		else
			D = exp_modular(Q, key, N);
		string valor = ZZ_to_string(D);
		if (valor.size() < size_bloque_N)
			valor = agregar_ceros(size_bloque_N, valor);
		letras_descifradas_1 += valor;
	}
	
	//Separamos en bloques del tamaño del N del emisor
	vector<string>bloques_2 = generar_bloques(letras_descifradas_1, num_dig_N2);

	//Desciframos por 2da vez
	for (int i = 0; i < bloques_2.size(); i++)
	{
		ZZ Q = string_to_ZZ(bloques_2[i]);
		ZZ D = exp_modular(Q, key2, N2);
		string valor = ZZ_to_string(D);
		if (valor.size() < size_bloque_N2)
			valor = agregar_ceros(size_bloque_N2, valor);
		letras_descifradas_2 += valor;
	}

	//Separamos nuevamente en bloques, pero ahora del tamaño del size_abc
	vector<string> letras = generar_bloques(letras_descifradas_2,num_dig_abc);

	//Remplazamos cada bloque por su valor en el abecedario
	for (long long i = 0; i < letras.size(); i++)
	{
		long long pos = stoll(letras[i]);
		mensaje_descifrado_2 += abecedario[pos];
	}
	
	return mensaje_descifrado_2;
}