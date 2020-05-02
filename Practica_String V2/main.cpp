#include "Practica.h"
//CODIGO MODIFCADO EN GENERAL:
//EJERCICIOS RECIEN RESUELTOS: 7 Y 10 DE LA PRACTICA
//EJERCICIOS CORREGIDOS: 12 Y 13 (Implementar cambio int a string y viceversa)
//                       18.27 del libro (ordenar un arreglo de string con numeros "2" / implemente una version de ordenar palabras "delfin")
//						 18.12 del libro (Cambio de matriz char a matriz string, e implementacion de funciones de string donde se puede)
string PedirString()
{
	string a;
	cout << "Ingrese la palabra: "; getline(cin, a);
	return a;
}
int PedirInt()
{
	int a;
	cout << "Ingrese el número: "; cin >> a;
	return a;
}

//Funciones Ejer 7 y 10
int contar_palabras(string frase)
{
	int nro_palabras = 0;
	for (int i = 0; i < frase.size(); i++) //Cuenta las palabras existentes en la frase
	{
		if (frase.at(i) == ' ')
			nro_palabras++;
	}
	return nro_palabras;
}

//Funciones Ejer 18.7
string Encriptar(string mensaje, string abecedario, int key)
{
	string mensaje_cifrado;
	string new_abecedario;
	new_abecedario.assign(abecedario.begin() + key, abecedario.end());
	new_abecedario.append(abecedario.begin(), abecedario.begin() + key);

	int size_mensaje = mensaje.size();

	for (int i = 0; i < size_mensaje; i++)
	{
		if (mensaje.at(i) == ' ')
			mensaje_cifrado.append(" ");
		else
		{
			int pos = abecedario.find(mensaje.at(i));
			mensaje_cifrado.append(new_abecedario, pos, 1);
		}
	}

	return mensaje_cifrado;
}
string Desencriptar(string _mensaje_cifrado, string abecedario, int key)
{
	string mensaje_descifrado;
	string new_abecedario;
	new_abecedario.assign(abecedario.begin() + key, abecedario.end());
	new_abecedario.append(abecedario.begin(), abecedario.begin() + key);

	int size_mensaje = _mensaje_cifrado.size();

	for (int i = 0; i < size_mensaje; i++)
	{
		if (_mensaje_cifrado.at(i) == ' ')
			mensaje_descifrado.append(" ");
		else
		{
			int pos = new_abecedario.find(_mensaje_cifrado.at(i));
			mensaje_descifrado.append(abecedario, pos, 1);
		}
	}
	return mensaje_descifrado;
}

//Funciones Ejer 18.12
string generar_codigo(int size_palabra)
{
	string codigo;
	for (int i = 0; i < size_palabra; i++)
		codigo.append("*");
	return codigo;
}
void inicializar_muñeco(string vida[4][3])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			vida[i][j] = " ";
	}
}
void print_muñeco(string vida[4][3])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << vida[i][j];
		cout << endl;
	}
}
void update_muñeco(int intento, string vida[4][3])
{
	switch (intento)
	{
	case 1:
		vida[0][1] = "O";
		break;
	case 2:
		vida[1][1] = "|";
		break;
	case 3:
		vida[1][0] = "/";
		break;
	case 4:
		vida[1][2] = "\\";
		break;
	case 5:
		vida[2][1] = "|";
		break;
	case 6:
		vida[3][0] = "/";
		break;
	case 7:
		vida[3][2] = "\\";
		break;
	};
}
void adivinar_palabra(string codigo, string palabra, int size_palabra)
{
	string vida[4][3];

	int error = 0;

	bool win = false;

	inicializar_muñeco(vida);

	cout << "\nAdivine la palabra: " << codigo;

	while (win == false)
	{
		bool acierto = false;
		string usuario;
		cout << "\nIngrese letra: "; cin >> usuario;
		//usuario = tolower(usuario);
		for (int i = 0; i < usuario.size(); i++)
		{
			if (isupper(usuario.at(i)))
				usuario.at(i) = tolower(usuario.at(i));
		}
		if (usuario.compare(palabra) == 0)
		{
			cout << "ganaste\n";
			win = true;
		}
		else
		{
			for (int i = 0; i < size_palabra; i++)
			{
				if ((palabra.compare(i, 1, usuario)) == 0)
				{
					acierto = true;
					codigo.replace(i, 1, usuario);
				}
			}
			if (codigo.compare(palabra) == 0)
			{
				cout << "ganaste\n";
				win = true;
			}
			else
			{
				if (acierto == false)
				{
					error++;
					update_muñeco(error, vida);
				}
				cout << codigo << endl;
				if (error == 7)
				{
					cout << "\n PERDISTE\n";
					cout << "\n Palabra a decifrar: " << palabra << endl;
					win = true;
				}
			}
			print_muñeco(vida);
		}
	}
}
void replay(int &i)
{
	int op;
	cout << "\nDesea jugar nuevamente?";
	cout << "\n1 : Si ";
	cout << "\n2 : No ";
	cout << "\nIngrese su respuesta: "; cin >> op;
	if (op == 1)
		i++;
	else
		i = 5;
}

//Funciones Ejer 18.27 Palabras
void PrintCadena(string array[], int size_array)
{
	for (int i = 0; i < size_array; i++)
		cout << array[i] << " ";
}
void ordenamiento_seleccion(string array[], int size_array, int op)
{
		for (int i = 0; i <=size_array ; i++)
		{
			for (int j = i+1; j < size_array ; j++)
			{
				if (op == 1)
				{
					if (array[j] < array[i])
						array[j].swap(array[i]);
				}
				else
				{
					if (array[j] > array[i])
						array[j].swap(array[i]);
				}
			}
		}
}

//Funciones Ejer 18.27 Numeros
void crear_subcadenas(string array[], int size_array)
{
	string digito_1[10];
	string digito_2[10];

	int n_1_digito = 0;
	int n_2_digitos = 0;

	int ite_aux_1 = 0;
	int ite_aux_2 = 0;

	for (int i = 0; i < size_array; i++)
	{
		if (array[i].size() == 1)
		{
			n_1_digito++;
			digito_1[ite_aux_1].assign(array[i]);
			ite_aux_1++;
		}
		if (array[i].size() == 2)
		{
			n_2_digitos++;
			digito_2[ite_aux_2].assign(array[i]);
			ite_aux_2++;
		}
	}
	int op;
	cout << "\nOrdenamiento: \n";
	cout << " Ingrese 1 para ascendente\n";
	cout << " Ingrese 2 para descendente\n";
	cout << " \nIngrese opcion: "; cin >> op;
	ordenamiento_seleccion(digito_1, n_1_digito, op);
	ordenamiento_seleccion(digito_2, n_2_digitos, op);
	
	cout << "Despues de ordenar: ";

	if (op == 1)
	{
		PrintCadena(digito_1, n_1_digito);
		PrintCadena(digito_2, n_2_digitos);
	}
	else
	{
		PrintCadena(digito_2, n_2_digitos);
		PrintCadena(digito_1, n_1_digito);
	}
	cout << endl;
}

//EJERCICIOS FICHA
void Ejercicio_1()
{
	cout << "Ejercicio 1: convertir un string a un array tipo char y viceversa \n";
	string a = PedirString();
	string b;

	Practica Ejer_1(a);

	Ejer_1.asignar_a_cadena();
	cout << "A Cadena: ";
	cout << Ejer_1.cadena;
	Ejer_1.cadena_a_string(b);  
	cout << "\nA palabra: ";
	cout << b;
}
void Ejercicio_2()
{
	cout << "\n\nEjercicio 2: Cual es la diferencia entre la funcion capacity y la funcion size de la clase string?\n" << "La longitud de un objeto string es el numero de caracteres actualmente almacenados en el objeto string. La capacidad de un objeto string es el número de caracteres que se pueden almacenar en el objeto string sin necesidad de asignar más memoria.\n";
}
void Ejercicio_3()
{
	cout << "\nEjercicio 3: Convertir las letras de un string de minúsculas a mayúsculas, y las mayúsculas a minúsculas.\n";

	string a = PedirString();
	Practica Ejer_3(a);
	cout << "Palabra:" << a;
	Ejer_3.convertir_May_Min();
	cout << "\nIntercambio: " << Ejer_3.a;
}
void Ejercicio_4()
{
	cout << "\nEjercicio 4:  int a string, y viceversa\n";
	int nro1 = PedirInt();
	int nro2 = PedirInt();

	string palabra1, palabra2, conjunto;

	palabra1 = to_string(nro1);
	palabra2 = to_string(nro2);

	conjunto = palabra1 + palabra2;
	cout << "\nLuego de unir: " << conjunto << endl;

	nro1 = stoi(conjunto);
	cout << "Convertimos y *2: " << nro1 * 2 << endl;
}
void Ejercicio_5()
{
	cout << "\nEjercicio 5: string de 1000 'a' con una sola linea de codigo\n";
	string a(1000, 'a');
	cout << a;
}
void Ejercicio_6()
{
	cout << "\nEjercicio 6: Reemplazar desaprobe por aprobe\n";
	string a("Yo desaprobe el curso de Algebra Abstracta\n");
	string b("desaprobe");
	string c("aprobe");

	int size_b = b.size();

	cout << "Antes: " << a;
	int pos = a.find(b);
	a.replace(pos, size_b, c);

	cout << "\nDespues de reemplazar: " << a;
}
void Ejercicio_7()
{
	cout << "\nEjercicio 7: Contar la cantidad de veces que sale una palabra en una frase\n";
	string frase = PedirString() + " ";
	string palabra = PedirString();
	int size_palabra = palabra.size();
	
	int nro_palabras = contar_palabras(frase);;
	int contador = 0;
	
	int pos = 0; //posicion para iniciar a buscar la palabra
	int found; //indica si se encontro la palabra o no

	
	for (int i = 0; i < nro_palabras; i++)
	{
		found = frase.find(palabra,pos);
		if (found >= 0)
		{
			contador++;
			pos = found + size_palabra; // actualiza la posicion para iniciar la busqueda de la palabra
		}
	}
	cout << "\n Veces: " << contador;
}
void Ejercicio_8()
{
	cout << "\nEjercicio 8: Iteradores\n";

	string a = PedirString();
	cout << "Palabra: " << a << endl;
	
	string::iterator ite = a.begin();

	while (ite != a.end())
	{
		cout << *ite << endl;
		ite++;
	}
}
void Ejercicio_9()
{
	cout << "\nEjercicio 9: Insertar una string en otro\n";
	string a = PedirString();
	string b = PedirString();

	a.insert((a.size()/2), b);
	cout << "Insertamos una palabra en otra: " << a <<endl;
}
void Ejercicio_10()
{
	cout << "\nEjercicio 10: Recibir tres strings por consola, buscar todas las apariciones del segundo string en el primero y reemplazarlas por el tercer string recibido.\n";
	string frase = PedirString() + " ";
	string palabra = PedirString();
	string palabra2 = PedirString();

	int size_palabra = palabra.size();
	int nro_palabras = contar_palabras(frase);

	int pos = 0; //posicion para iniciar a buscar la palabra
	int found; //indica si se encontro la palabra o no


	for (int i = 0; i < nro_palabras; i++)
	{
		found = frase.find(palabra, pos);
		if (found >= 0)
		{
			frase.replace(found, size_palabra, palabra2);
			pos = found + size_palabra; // actualiza la posicion para iniciar la busqueda de la palabra
		}
	}
	cout << "\nDespues de reemplazar\n"<< frase << endl;
}
void Ejercicio_11()
{
	cout << "\nEjercicio 11: Mayor lexicograficamente \n";
	string a = PedirString();
	string b = PedirString();

	Practica Ejer_11(a, b);
	Ejer_11.mayor_lexicograficamente(); //Compara mayor con menor
}
void Ejercicio_12()
{
	string numeros[10];
	int N = PedirInt();
	if (N < 0 || N>10)
		cout << "\nError";
	else
	{
		srand(time(NULL));
		ofstream archivo;
		archivo.open("numeros.txt", ios::out);

		for (int i = 0; i < N; i++)
		{
			int aux = 1 + rand() % 1000 ;
			
			//archivo << aux;
			
			numeros[i] = to_string(aux);
			archivo << numeros[i];
			
			if(i!=N-1)
				archivo<<endl;
			
		}		
		archivo.close();
	}
}
void Ejercicio_13()
{
	ifstream archivo;
	archivo.open("numeros.txt", ios::in);

	string dato;
	int numero;
	int sumatoria = 0;

	while(!archivo.eof())
	{
		//archivo >> numero;
		
		archivo >> dato;
		numero= stoi(dato);

		cout << numero<<endl;
		sumatoria += numero;
	}
	cout << "\nSumatoria: " << sumatoria;
	archivo.close();
}

//EJERCICIOS LIBRO
void Ejercicio_18_7()
{
	cout << "\nEjercicio 18.7: Rot13\n";

	string abecedario("abcdefghijklmnopqrstuvwxyz");
	string mensaje = PedirString();

	cout << "\nMensaje a encriptar: " << mensaje << endl << endl;
	string mensaje_cifrado = Encriptar(mensaje,abecedario,13);
	cout << "Encriptado: " << mensaje_cifrado<< endl << endl;

	cout << "Mensaje a desencriptar: " << mensaje_cifrado<< endl;
	string mensaje_descifrado = Desencriptar(mensaje_cifrado,abecedario,13);
	cout << "\nDesencriptado: " << mensaje_descifrado << endl;

	/*cout << "Si desconociera la forma de encriptado ¿que tan dificil cree usted que seria quebrantar el código? ¿Que pasaría si tuviera acceso a un poder de cómputo considerable(por ejemplo, supercomputadoras) ? \n";
	cout << "Si se tuviera un conocimiento sobre encriptado, o quizas de los más conocidos, se podría intentar con estos y asi posiblemente descifrar el codigo. \n Si tuviera acceso a una super computadora, la programaría para que probara con todas las posibles formas de encriptar conocidad, y si no coincidiera, crearía algunas para comprobar si con esas funcionan\n";*/
}
void Ejercicio_18_11()
{
	cout << "\nEjercicio 18.11: Nombre y apellido\n";
	string nombre, apellido;
	cout << "Ingrese su nombre: "; getline(cin,nombre);
	cout << "Ingrese su apellido: "; getline(cin,apellido);
	nombre.append(" ");
	nombre.append(apellido);
	cout << "Nombre completo: " << nombre;
}
void Ejercicio_18_12()
{
	cout << "\n\nEjercicio 18.22: Ahorcado\n";
	string palabras[5] = { "amistad","fiesta","escritura","mascota","celular" };

	int i = 0;
	while (i < 5)
	{
		string palabra = palabras[i];
		int size_palabra = palabra.size();
		string codigo = generar_codigo(size_palabra);
		adivinar_palabra(codigo, palabra, size_palabra);
		replay(i);
	}
}
void Ejercicio_18_19()
{
	cout << "\nEjercicio 18.19: Insertar ****** en la palabra\n";
	string a(PedirString());
	string b("******");
	a.insert(a.size() / 2, b);
	cout << a;
}
void Ejercicio_18_21()
{
	cout << "\nEjercicio 18.21: Cambiar signos de puntuacion por espacio\n";
	string texto = PedirString();
	Practica Ejer_18_21(texto);
	Ejer_18_21.reemplazar_signos_x_espacio();
	
	cout << Ejer_18_21.a << endl;
	Ejer_18_21.asignar_a_cadena();
	
	char *token = strtok(Ejer_18_21.cadena," ");

	while (token)
	{
		 cout << token << endl;
		 token = strtok(NULL," ");
	}
}
void Ejercicio_18_22()
{
	cout << "Ejercicio 18.22: Mostras palabra al revez con iteradores\n";
	string frase("Buenos dias");
	string::reverse_iterator ite;
	
	cout << "Palabra: " << frase << endl;
	cout << "Intercambio: ";
	
	for (ite = frase.rbegin(); ite != frase.rend(); ite++)
		cout << *ite;
}
void Ejercicio_18_27()
{
	cout << "\n\nEjercicio 18.27: Ordenamiento de string\n";
	const int size_array = 10;
	int arreglo_de_nros[size_array] = { 2,6,4,8,10,12,89,68,45,37 }; //Arreglo Fig. 8.28 del libro;
	string arreglo_de_str[size_array];

	for (int i = 0; i < 10; i++) //Convertimos int to string
		arreglo_de_str[i]=to_string(arreglo_de_nros[i]);

	cout << "\nOrden original: ";
	PrintCadena(arreglo_de_str,size_array);
	cout << endl << endl;
	crear_subcadenas(arreglo_de_str, size_array);
	
}
void Ejercicio_18_27_2()
{
	cout << "\n\nEjercicio 18.27: Ordenamiento de string\n";
	string arreglo_de_str[10] = { "hola","dias","buenos","amanecer","total","amigo","delfin","conejo","dormir","zapato" };
	int size_array = 10;
	int op;

	cout << "\nOrden original: ";
	PrintCadena(arreglo_de_str,size_array);

	cout << "\nOrdenamiento: \n";
	cout << " Ingrese 1 para ascendente\n";
	cout << " Ingrese 2 para descendente\n";
	cout << " \nIngrese opcion: "; cin >> op;

	ordenamiento_seleccion(arreglo_de_str, size_array, op);

	cout << "Despues de ordenar: ";
	PrintCadena(arreglo_de_str,size_array);
	cout << endl;
}

int main()
{
	//Ejercicio_1();
	//Ejercicio_2();
	//Ejercicio_3(); 
	//Ejercicio_4();
	//Ejercicio_5();
	//Ejercicio_6();
	//Ejercicio_7(); 
	//Ejercicio_8();
	//Ejercicio_9();
	//Ejercicio_10(); 
	//Ejercicio_11();
	//Ejercicio_12(); 
	//Ejercicio_13(); 

	//Ejercicio_18_7(); 
	//Ejercicio_18_11();  
	//Ejercicio_18_12(); 
	//Ejercicio_18_19(); 
	//Ejercicio_18_21(); 
	//Ejercicio_18_22(); 
	//Ejercicio_18_27(); //Version array numeros
	//Ejercicio_18_27_2(); //Version array palabras
};