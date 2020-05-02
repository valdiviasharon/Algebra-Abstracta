#include "Practica.h"
#include <cstring>
#include <string.h>
#include <fstream>


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
void ordenamiento(string cadena[4])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j <= 3; j++)
		{
			if (cadena[j] < cadena[i])
				cadena[j].swap(cadena[i]);
		}
	}
}
void PrintCadena(string cadena[4])
{
	for (int i = 0; i < 4; i++)
		cout << cadena[i] << " ";
}

//FUNCIONES AHORCADO
void generar_codigo(string& codigo, int size_palabra)
{
	for (int i = 0; i < size_palabra; i++)
		codigo += 'X';
}
void inicializar_muñeco(char vida[4][3])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			vida[i][j] = ' ';
	}
}
void print_muñeco(char v[4][3])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << v[i][j];
		}
		cout << endl;
	}
}
void refresh(int intento, char vida[4][3])
{
	switch (intento)
	{
	case 1:
		vida[0][1] = 'O';
		break;
	case 2:
		vida[1][1] = '|';
		break;
	case 3:
		vida[1][0] = '/';
		break;
	case 4:
		vida[1][2] = '-';
		break;
	case 5:
		vida[2][1] = '|';
		break;
	case 6:
		vida[3][0] = '/';
		break;
	case 7:
		vida[3][2] = '-';
		break;
	};
}
void adivinar_palabra(string codigo, string palabra, int size_palabra)
{
	char vida[4][3];
	string usuario;
	int error = 0;

	bool win = false;

	inicializar_muñeco(vida);
	cout << "\nAdivine la palabra: " << codigo;

	while (win == false)
	{
		bool acierto = false;
		cout << "\nIngrese letra: "; cin >> usuario;
		for (int j = 0; j < size_palabra; j++)
		{
			if (usuario[0] == palabra[j])
			{
				codigo.replace(j, 1, usuario);
				acierto = true;
			}

		}
		if (codigo == palabra)
		{
			cout << "ganaste\n";
			win = true;
		}
		else
		{
			if (acierto == false)
				{
					error++;
					refresh(error, vida);
				}
			cout << codigo << endl;
			if (error==7 )
				{
					cout << "\n PERDISTE\n";
					win = true;
				}
				
		}
		print_muñeco(vida);
	}
}
//Funciones Ejericicio 12 y 13
void random(int &a,int limite)
{
	srand(NULL);
	a= 1 + rand() % limite;
}
void Escribir(int N)
{
	ofstream archivo;
	archivo.open("numeros.txt", ios::app);

	int aux=0;

	while (N != 0)
	{
		if (aux == 0)
		{
			random(aux, 1000);
			archivo << aux<<endl;
			aux = 0;
		}
			
		N--;
	}

	archivo.close();
}
void Leer()
{
	ifstream archivo;
	archivo.open("numeros.txt", ios::in);

	int numero;
	int sumatoria = 0;

	while (!archivo.eof())
	{
		archivo >> numero;
		sumatoria += numero;
	}
	cout << "\nSumatoria: " << sumatoria;
	archivo.close();

}
void Ejercicio_1()
{
	cout << "Ejercicio 1: convertir un string a un array tipo char y viceversa \n";
	string a = PedirString();
	string b;

	Practica Ejer_1(a);

	Ejer_1.for_asignar(Ejer_1.size_a);//Iguala los elementos del string con el array
	cout << "A Cadena: ";
	Ejer_1.for_printCadena(Ejer_1.size_a);
	Ejer_1.for_concatenar(Ejer_1.size_a, b);//Une los elementos de un array en un string
	cout << "\nA palabra: ";
	cout << b;
}
void Ejercicio_2()
{
	cout << "\n\nEjercicio 2: Cual es la diferencia entre la funcion capacity y la funcion size de la clase string?\n" << "El tamaño o la longitud de un objeto string es el numero de caracteres actualmente almacenados en el objeto string. La capacidad de un objeto string es el número de caracteres que se pueden almacenar en el objeto string sin necesidad de asignar más memoria.\n";
}
void Ejercicio_3()
{
	cout << "\nEjercicio 3: Convertir las letras de un string de minúsculas a mayúsculas, y las mayúsculas a minúsculas.\n";

	string a =PedirString();
	Practica Ejer_3(a);
	cout << "Palabra:"<<Ejer_3.a;
	Ejer_3.convertir_May_Min();
	cout << "\nIntercambio: "<<Ejer_3.a;
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
	cout << "Convertimos y *2: " << nro1 * 2;

}
void Ejercicio_5()
{
	cout << "\nEjercicio 5: string de mil 'a' con una sola línea de codigo\n";
	string a(1000, 'a');
	cout << a;
}
void Ejercicio_6()
{
	cout << "\nEjercicio 6: Reemplazar desaprobe por aprobe\n";
	string a ("Yo desaprobe el curso de Algebra Abstracta\n");
	string b ("desaprobe");
	string c ("aprobe");

	int size_b = b.size();
	int pos;

	cout << "Antes: " << a;
	pos = a.find(b);
	a.replace(pos, size_b, c);

	cout << "\nDespues: " << a;

}
void Ejercicio_7()
{
	string frase = " " + PedirString() + " ";
	string palabra = PedirString();
	int size_palabra = palabra.size();
	int pos = 0;
	string aux;

	// for(int i=0; i< frase.size(); i++)
	//   {
	//     if(frase[i]==" ")
	//       {
	//         pos=i+1;
	//         aux=frase.substr(pos);
	//       }
	//   }


}
void Ejercicio_8()
{
	cout << "\nEjercicio 8: Iteradores\n";
	string a("Iterador");
	cout << "Palabra: "<<a<<endl;
	string::const_iterator ite= a.begin();
	
	while (ite != a.end())
	{
		cout << *ite<<endl;
		ite++;
	}
}
void Ejercicio_9()
{
	cout << "\nEjercicio 9: Insertar una string en otro\n";
	string a =PedirString();
	string b =PedirString();
	Practica Ejer_9(a, b);
	Ejer_9.insertar();
	cout << Ejer_9.a;
}
void Ejercicio_10()
{
	string frase (PedirString() + " ");
	string a (PedirString());
	string b (PedirString());
	int cdp = 0;
	int pos = 0;
	// for(int i=0; i<frase.size();i++)
	//   {
	//     if(frase[i]==' ')
	//       cdp++;
	//   }
	// int i=0;
	// while(i<cdp)
	// {
	//   if(pos)
	//     {
	//       frase.replace(pos,a.size(),b);
	//       pos=0;
	//       i++;
	//     }
	//   pos=frase.find(a);
	// }
}
void Ejercicio_11()
{
	cout << "\nEjercicio 11: Mayor lexicograficamente \n";
	string a (PedirString());
	string b (PedirString());
	
	Practica Ejer_11(a, b);
	Ejer_11.mayor(); //Compara mayor con menor
}
void Ejercicio_12y13()
{
	cout << "\nEjercicio 12: Crear una función que reciba un número N (N va de 1 a 10), y que escriba N números con valores que van de 1 a 1000 en un archivo llamado “numeros.txt”.\n";
	cout << "\nEjercicio 13: Leer los números en el archivo “numeros.txt” de la pregunta 12 e imprimir la sumatoria.\n";
	
	int N;
	random(N, 10);
	cout << "\nNumero de elementos a sumar: " << N<<endl;
	
	Escribir(N);
	Leer();
}
void Ejercicio_18_7()
{
	cout << "\nEjercicio 18.7: Encriptado\n";

	string abecedario("abcdefghijklmnopqrstuvwxyzabcdefghijklm");
	string palabra(PedirString());
	string codigo;

	cout << "Palabra: " << palabra << endl;
	Practica Ejer_18_7(abecedario, palabra);
	Ejer_18_7.Encriptar(codigo);
	cout << "Encriptado: "<<codigo;

}
void Ejercicio_18_11()
{
	cout << "\nEjercicio 18.11: Nombre y apellido\n";
	string nombre, apellido;
	cout << "Ingrese su primer nombre: "; cin >> nombre;
	cout << "Ingrese su primer apellido: "; cin >> apellido;
	cout << "Nombre completo: " << nombre + ' ' + apellido;
}
void Ejercicio_18_12()
{
	cout << "\n\nEjercicio 18.22: Ahorcado\n";
	string palabra = "gato";
	string codigo;
	
	int size_palabra = palabra.size();
	
	generar_codigo(codigo,size_palabra);
	adivinar_palabra(codigo, palabra, size_palabra);
}
void Ejercicio_18_19()
{
	cout << "\nEjercicio 18.19: Insertar **** en la palabra\n";
	string a (PedirString());
	string b ("******");
	Practica Ejer_18_19(a, b);
	Ejer_18_19.insertar();
	cout << Ejer_18_19.a;
}
void Ejercicio_18_21()
{
	cout << "\nEjercicio 18.21: Cambiar signos de puntuacion por espacio\n";
	string texto = PedirString();
	Practica Ejer_18_21(texto);
	Ejer_18_21.replace_char(Ejer_18_21.size_a);
	cout << Ejer_18_21.a << endl;
	Ejer_18_21.for_asignar(Ejer_18_21.size_a);

	/*char* a = Ejer_18_21.cadena;
	char *token = strtok(a," ");
	while (token)
	{
	     cout << token << endl;
	     token = strtok(NULL," ");
	}*/
}
void Ejercicio_18_22()
{
	cout << "Ejercicio 18.22: Mostras palabra al revez\n";
	string frase ("Buenos dias");
	cout << "Palabra: " << frase<<endl;	
	cout << "Intercambio: ";
	for (int i = frase.size() - 1; i >= 0; i--)
		cout << frase[i]; 
}
void Ejercicio_18_27()
{
	cout << "\n\nEjercicio 18.27: Ordenamiento\n";
	string familia[4] = { "mamá", "papá","hijo","hija" };
	cout << "Lista antes: ";
	PrintCadena(familia);
	ordenamiento(familia);
	cout << "\nLista después de ordenar: ";
	PrintCadena(familia);
}
int main()
{
	Ejercicio_1();
	Ejercicio_2();
	//Ejercicio_3(); //Miss no se porque se crashea
	Ejercicio_4();
	Ejercicio_5();
	Ejercicio_6();
	//Ejercicio_7(); //FALLAS
	Ejercicio_8();
	Ejercicio_9();
	//Ejercicio_10(); //FALLAS
	Ejercicio_11();
	Ejercicio_12y13(); 


	Ejercicio_18_7(); 
	Ejercicio_18_11(); 
	Ejercicio_18_12();
	Ejercicio_18_19(); 
	Ejercicio_18_21();  
	Ejercicio_18_22(); 
	Ejercicio_18_27(); 
};