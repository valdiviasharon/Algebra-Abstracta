#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int modulo(int a, int n)
{
	int r = a - ((a / n) * n);
	if (r < 0)
	{
		r = a - (((a / n) - 1) * n);
	}
	return r;
}
int exp_modular(int base, int exp, int n)
{	
	int x = 1; //x es el exponente aux de la base
	vector<int>mods;
	vector<int>exponentes;
	mods.push_back(modulo(base, n));//Se inicializa el array 
	int resultado=mods[0];
	int pos=0;
	int ite = 1;
	while (exp>0)
	{
		int bit = modulo(exp, 2);	
		if (ite > 1)
		{
			int mod_anterior = mods[pos];
			int aux = modulo(pow(mod_anterior, 2), n);
			mods.push_back(aux);
			pos++;
			if (bit)
			{
				int n1, n2;
				n1 = modulo(resultado, n);
				n2 = modulo(mods[pos], n);
				resultado = modulo(n1 * n2, n);
			}
		}
		exp /= 2;
		x *= 2;
		ite++;
	}
	return resultado;
}
int main()
{
	int base, exp, n;
	cout << endl << "B: "; cin >> base;
	cout << endl << "Exp: "; cin >> exp;
	cout << endl << "n: "; cin >> n;
	cout<<"\nResultado:"<<exp_modular(base, exp, n);
}