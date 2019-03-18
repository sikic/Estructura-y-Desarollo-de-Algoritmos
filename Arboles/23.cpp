// Luis Anotnio Rojas Ramirez
// e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


// función que resuelve el problema
void rescate(const bintree<int> &arbol, int &equipos, int &excursionistas) {
	if (arbol.empty()) {
		equipos = 0;
		excursionistas = 0;
	}
	else {
		int izda = 0;
		if (!arbol.left().empty()) {
			rescate(arbol.left(), equipos, izda);
		}

		int der = 0;
		if (!arbol.right().empty()) {
			rescate(arbol.right(), equipos, der);
		}

		if (arbol.right().empty() && arbol.left().empty() && arbol.root() != 0) {
			equipos++;
			excursionistas = arbol.root();
		}

		else if (izda != 0 || der != 0)
			excursionistas = std::max(izda, der) + arbol.root();

		else if (arbol.root() != 0) {
			equipos++;
			excursionistas = arbol.root();
		}

	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	auto arbol = leerArbol(-1);
	int sol = 0, aux = 0;

	rescate(arbol, sol, aux);

	std::cout << sol << " " << aux << "\n";


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