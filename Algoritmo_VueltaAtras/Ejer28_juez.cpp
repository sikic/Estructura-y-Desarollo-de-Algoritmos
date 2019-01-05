// Luis Antonio Rojas Ramirez
// E52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

void rellenar(const tMatriz &matriz, std::vector <int> &acumulados,int super,int produc) {

	int eficiente ,anterior = 0;
	int k = 0;
	for (int i = 0; i < produc ; i++)
	{
		
		eficiente = matriz[0][i];

		for (int j = 0; j < super; j++)
		{
			if (eficiente > matriz[j][i])
				eficiente = matriz[j][i];
		}
		acumulados[k] = anterior + eficiente;
		anterior = acumulados.at(k);
		k++;
	}
}

bool esValida(const std::vector<int> &sol, int &mejor,const std::vector<int> &cont, int k, int precioActual)
{
	bool valida = true;

	if (precioActual > mejor)
		valida = false;

	if (cont.at(sol.at(k)) > 3)
		valida = false;

	return valida;
}

// función que resuelve el problema
void vueltraAtras(const tMatriz &matriz,std::vector<int> &sol, int &mejor,int numSuper,int numProduc,std::vector<int> cont,int k,int precioActual,bool &exito,std::vector<int> acumulados) {
	
	for (int i = 0; i < numSuper; i++)
	{
		sol.at(k) = i; // probamos con el primer super

		cont.at(i)++; // marcamos el super
		precioActual += matriz[i][k];//marcamos el precio

		if (esValida(sol, mejor, cont, k, precioActual)) {
			if (k == numProduc - 1) {
				exito = true;
				if (precioActual < mejor)
					mejor = precioActual;

			}
			else {
				if(acumulados.at(numProduc - 1) - acumulados.at(k) + precioActual < mejor)
				vueltraAtras(matriz, sol, mejor, numSuper, numProduc, cont, k + 1, precioActual, exito, acumulados);
			}
		}

		cont.at(i)--; //desmarcamos tanto precio como el contador
		precioActual -= matriz[i][k];
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numSuper, numProduc,mejor=2456000,precioActual = 0,costeEficiente,anterior = 0;
	bool exito = false;

	std::cin >> numSuper >> numProduc;

	std::vector<int> acumulados(numProduc);

	tMatriz matriz(numSuper, std::vector<int>(numProduc));

	for (int i = 0; i < numSuper; i++)
	{
		for (int j = 0; j < numProduc; j++)
		{
			std::cin >> matriz[i][j];
		}
	}

	rellenar(matriz,acumulados,numSuper,numProduc);

	std::vector<int> sol(numProduc);

	std::vector<int> cont(numSuper,0);


	vueltraAtras(matriz, sol, mejor, numSuper, numProduc, cont,0, precioActual, exito,acumulados);

	// escribir sol

	if (exito)
		std::cout << mejor << "\n";
	else
		std::cout << "Sin solucion factible \n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos28.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}