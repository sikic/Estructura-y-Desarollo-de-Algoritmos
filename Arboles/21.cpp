// Luis Antonio Rojas Ramirez
// e52

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include"bintree_eda.h"

template <class T>
void menor(const bintree<T> &arbol,T &e){



	if (!arbol.left().empty()) {
		if (arbol.left().root() < e)
			e = arbol.left().root();

		menor(arbol.left(), e);
	}

	if (!arbol.right().empty()) {
		if (arbol.right().root() < e)
			e = arbol.right().root();

		menor(arbol.right(), e);
	}
	
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta

bool resuelveCaso() {
	// leer los datos de la entrada
	char c;
	std::cin >> c;
	
	if (!std::cin)
		return false;

	if (c == 'N'){
		int e;
		bintree<int> arbol = leerArbol(-1);
		
		if (!arbol.empty()) {
			e = arbol.root();
			menor(arbol,e);
		}
		std::cout << e << "\n";

	}
	
	else {
		std::string e;
		std::string f = "#";
		bintree<std::string> arbol = leerArbol(f);

		if (!arbol.empty()) {
			e = arbol.root();
			menor(arbol, e);
		}

		std::cout << e << "\n";
	}


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}