#include "funciones.h"

void llenar_vectores(vector<int>& val_x, vector<int> & val_a,vector<int> & val_p)
{
	cout << "\nEjemplo de ecuacion: \n\tx = a mod p \n";
	for (int i = 0; i < val_x.size(); i++)
	{
		cout << endl << "Ecuacion nro: " << i + 1 << endl;
		cout << "\tIngrese el coeficiente de x: "; cin >> val_x[i];
		cout << "\tIngrese el coeficiente de a: "; cin >> val_a[i];
		cout << "\tIngrese el coeficiente de n: "; cin >> val_p[i];
	}
	cout << "\nEcuaciones";
	for (int i = 0; i < val_x.size(); i++)
		cout << endl << "\t"<<val_x[i] << "x = " << val_a[i] << " mod " << val_p[i];
}
bool valores_correctos(vector<int>& val_x, vector<int>& val_a, vector<int>& val_p)
{
	for (int i = 0; i < val_p.size(); i++)
	{
		for (int j = i + 1; j < val_p.size(); j++)
		{
			if (mcd(val_p[i], val_p[j]) != 1)
			{
				cout << "\nNo todos los valores de p son coprimos";
				return false;
			}
		}
	}
	
	for (int i = 0; i < val_a.size(); i++)
	{
		if (val_a[i]<0)
			val_a[i] = modulo(val_a[i], val_p[i]);
	}

	for (int i = 0; i < val_x.size(); i++)
	{
		if (val_x[i] != 1)
		{
			int inv_x = inversa(val_x[i], val_p[i]);
			if (inv_x)
			{
				val_a[i] = val_a[i] * (inv_x);
				val_x[i] = 1;
			}
			else
			{
				cout << "\nNo hay inversa del coeficiente de x en mod "<<val_p[i];
				return false;
			}
		}
	}
	return true;
}
int resto_chino(int tam)
{
	vector<int>val_x(tam), val_a(tam), val_p(tam);
	llenar_vectores(val_x, val_a, val_p);
	if (valores_correctos(val_x,val_a,val_p)==false)
	{
		cout << "\No se puede resolver";
		return {0};
	}
	//Hallamos los valores de P;
	int P=1;
	for (int i = 0; i < val_p.size(); i++)
		P *= val_p[i];
	vector<int>val_P(tam);
	for (int i = 0; i < val_P.size(); i++)
		val_P[i] = P / val_p[i];

	//Hallamos los valores de Q
	vector<int>val_q(tam);
	for (int i = 0; i < val_q.size(); i++)
	{
		int valor_de_p=val_P[i];
		
		if (valor_de_p >= val_p[i])
			valor_de_p = modulo(valor_de_p, val_p[i]);

		valor_de_p = inversa(valor_de_p, val_p[i]);

		val_q[i] = modulo(valor_de_p, val_p[i]);
	}

	//Hallamos x0
	int x0 = 0;
	for (int i = 0; i < tam; i++)
	{
		int aux = (modulo(val_a[i], P) * modulo(val_P[i], P) * modulo(val_q[i], P));
		x0 += modulo(aux, P);
	}
		
	x0 = modulo(x0, P);

	vector<int>ecuacion_general(2);
	ecuacion_general[0] = x0;    ecuacion_general[1] = P;

	cout << endl << "\nEcuacion general: " << endl;
	cout << "\tx = " << ecuacion_general[0] << " + " << ecuacion_general[1] << "k";
	cout << "\nPara k=0" << endl;
	cout << "\tx = " << ecuacion_general[0] << " + " << ecuacion_general[1] << "(0)";
	cout << "\nEntonces" << endl;
	ecuacion_general[1] *= 0;
	cout << "\tx = " << ecuacion_general[0] << " + " << "0" << endl;

	return ecuacion_general[0] + ecuacion_general[1];
}
int main()
{
	int num;
	cout << "\Cuantas ecuaciones ingresara? : "; cin >> num;
	cout << endl << "Respuesta: "<<resto_chino(num);
}