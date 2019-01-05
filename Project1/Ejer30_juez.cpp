// Luis Antonio Rojas Ramirez
// E52
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;


void rellenar(const tMatriz &matriz, int numFunc, std::vector<int> &acumulados){

	int eficiente, anterior = 0,k = numFunc - 1;

	for (int i = 0; i < numFunc; i++)
	{
		eficiente = matriz[i][0];
		for (int j = 1; j < numFunc; j++)
		{
			if (eficiente > matriz[i][j])
				eficiente = matriz[i][j];
		}
		acumulados[i] = eficiente + anterior;
		anterior = acumulados.at(i);
	
	}
	
}
// función que resuelve el problema
void resolver(tMatriz const& matriz, int k, int sumAct,
	int & sumMin, int numFunc, std::vector<bool> & marcar, const std::vector<int> &acumulados) {

	//Con el for recorroemos las columnas:
	for (int i = 0; i < numFunc; ++i) {
		sumAct += matriz[k][i]; //sumo una tarea de un funcionario nuevo;
		
		if (!marcar[i]) { // es valida
			if (k == numFunc - 1) { //es una solucion
				if (sumAct < sumMin)  //es mejor que  la anterior
					sumMin = sumAct; //actualizo la suma minima;
			}
			else{
				if (acumulados.at(numFunc - 1) - acumulados.at(k) + sumAct < sumMin) {
					marcar[i] = true; //marcamos la columna usada;
					resolver(matriz, k + 1, sumAct, sumMin, numFunc, marcar, acumulados);
					marcar[i] = false; //desmarcamos;
				}
			}
		}

		sumAct -= matriz[k][i]; //resto lo sumado

	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numFunc, k = 0, sumAct = 0, sumMin = 0;
	std::cin >> numFunc;

	if (numFunc == 0) return false;

	tMatriz matriz(numFunc, std::vector<int>(numFunc));

	std::vector<int> acumulados(numFunc);

	for (int i = 0; i < numFunc; i++) {
		for (int j = 0; j < numFunc; j++) {
			std::cin >> matriz[i][j];
		}
	}

	for (int i = 0; i < numFunc; i++)
	{
		sumMin += matriz[i][i];
	}

	//Creamos un vector para marcar la columna usada:
	std::vector<bool> marcar(numFunc,false);
	rellenar(matriz, numFunc,acumulados);

	resolver(matriz, k, sumAct, sumMin, numFunc, marcar,acumulados);


	//escribir sol
	std::cout << sumMin << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos30.txt");
	//save old buf and redirect std::cin to datos.txt:
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}