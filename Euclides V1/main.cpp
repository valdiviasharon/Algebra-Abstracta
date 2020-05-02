#include "funciones.h"

int elegir_alg()
{
	int op;
	cout << "Seleccione un ejercicio:\n ";
	cout << "1: alg_1\n";
	cout << "2: alg_2\n";
	cout << "3: alg_3\n";
	cout << "4: alg_4\n";
	cout << "5: alg_5\n";
	cout << "6: alg_6\n";
	cout << "7: alg_7\n";
	cout << "\nIngrese opcion:"; cin >> op;
	return op;
}
int main()
{
	int a, b;
	double t_inicial, t_final;
	double time, time_cout;

	int contador = 0;

	int op = elegir_alg();
	cout << "Ingresar 'a': "; cin >> a;
	cout << "Ingresar 'b': "; cin >> b;
	switch (op)
	{
		case 1:
			t_inicial = clock();
			cout << "\nMCD del alg_1: " << alg_1(a, b, time_cout, contador);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time - (time_cout * contador);
			break;
		case 2:
			t_inicial = clock();
			cout << "\nMCD del alg_2: " << alg_2(a, b, time_cout, contador);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time - (time_cout * contador);
			break;
		case 3:
			
			//if (alg_3(a, b, time_cout, contador) == -1)
			//	break;
			t_inicial = clock();
			cout << "\nMCD del alg_3: " << alg_3(a, b, time_cout, contador);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time - (time_cout * contador);
			break;
		case 4:
			t_inicial = clock();
			cout << "\nMCD del alg_4: " << alg_4(a, b, time_cout, contador);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time - (time_cout * contador);
			break;
		case 5:
			/*if (alg_5(a, b, time_cout, contador) == -1)
				break;*/
			t_inicial = clock();
			cout << "\nMCD del alg_5: " << alg_5(a, b, time_cout, contador);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time - (time_cout * contador);
			break;
		case 6:
			t_inicial = clock();
			cout << "\nMCD del alg_6: " << alg_6(a, b, time_cout, contador);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time - (time_cout * contador);
			break;
		case 7:
			t_inicial = clock();
			cout << "\nMCD del alg_3: " << alg_3(a, b, time_cout, contador);
			t_final = clock();
			time = (double(t_final - t_inicial) / CLOCKS_PER_SEC);

			cout << "\nTiempo de demora:" << time - (time_cout * contador);
			break;
		default:
			break;
	}
}