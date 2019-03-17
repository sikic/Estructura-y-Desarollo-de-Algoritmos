// Luis Antonio Rojas Ramirez
// e52

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include"bintree_eda.h"


void fronterizos(const bintree<int> &arbol, std::vector<int> &sol){

	if (!arbol.empty()){
	
		if (arbol.left().empty() && arbol.right().empty())
			sol.push_back(arbol.root());
		else
			fronterizos(arbol.left(), sol);


		if (arbol.empty())
			sol.push_back(arbol.right().root());
		else
			fronterizos(arbol.right(), sol);
	}

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::vector<int> sol;
	bintree<int> arbol = leerArbol(-1);

	fronterizos(arbol,sol);

	for (int i = 0; i < sol.size(); i++)
	{
		std::cout << sol[i] << " ";
	}

	std::cout << "\n";


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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