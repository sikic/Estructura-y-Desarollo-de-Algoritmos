// Luis Antonio Rojas Ramirez
// e52

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include"bintree_eda.h"
/*se recorre el arbol hasta abajo , hasta que encontremos una hoja , una vez que la encontramos  vamos para arriba y vammos actualizando 
diametro y camino mas largo*/
void diam(const bintree<char> &arbol, int &diametro,int &max) {
	if (arbol.empty()) {
		diametro = 0;
		max = 0;
	}
	else {
		
		diam(arbol.left(), diametro,max);
		int izda = diametro;
		int izdaMax = max;
		

		diam(arbol.right(), diametro, max);
		int derecha = diametro;
		int derechaMax = max;
		
	
		int maxDiametro = std::max(izda,derecha);
		int maxCamino = izdaMax + derechaMax + 1;

		diametro = std::max(maxDiametro,maxCamino);
		max = std::max(izdaMax,derechaMax) + 1;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {
	// leer los datos de la entrada
	int sol = 0;
	int aux = 0;

	auto arbol = leerArbol('.');
	diam(arbol, sol,aux);

	std::cout << sol << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int ncasos;
	std::cin >> ncasos;
	
	for (int i = 0; i < ncasos; i++)
	{
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}