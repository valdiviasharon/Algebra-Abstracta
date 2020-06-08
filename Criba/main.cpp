#include <iostream>
#include <vector>
using namespace std;

int modulo(int a, int b)
{
	int r = a - ((a / b) * b);
	if (r < 0)
		r = a - (((a / b) - 1) * b);
	return r;
}
int pedir_rango()
{
	int rango;
	cout << "\nIngrese el rango, 2-"; cin >> rango;
	return rango;
}
void inicializar_lista(vector<int> & a, int rango)
{
	a.push_back(2);
	for (int j = 3; j <= rango; j+=2)
		a.push_back(j);
}
void delete_num(vector<int> & a, int rango)
{
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i]*a[i] <= rango)
		{
			for (int j = i + 1; j < a.size();)
			{
				if (modulo(a[j], a[i]) == 0)
					a.erase(a.begin() + j);
				else j++;
			}
		}
		else i = a.size();
	}
}
void print(vector<int>a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
}

int main()
{
	int rango = pedir_rango();
	vector<int> primos;
	inicializar_lista(primos, rango);
	delete_num(primos, rango);
	//cout << "\Numeros primos entre 2-" << rango<< " :\n"; print(primos);
	cout << "\nCalculo finalizado";
}