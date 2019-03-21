//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno
//Luis Antonio Rojas Ramirez
// Usuario del juez de clase
//e52
// Usuario del juez de examen que has utilizado en la prueba de hoy
//e18
//***************************************************
/*el coste de este algoritmo es lineal en cuanto al numero de nodos del arbol, ya que hacemos una llamada por cada nodo que no sea
vacio */

#include <iostream>
#include <fstream>
#include "bintree_eda.h"


// Aqui función del alumno
void resolver(const bintree<int> &arbol, int &niveles, bool &exito) {
	if (arbol.empty()) {
		exito = true;
		niveles = 0;
	}
	else { // exploramos todos los nodos de la izda y nos guardamos su raiz en caaso de que no este vacio
		int izda = 0;
		int aux_izd = 0;
		if (!arbol.left().empty()) {
			resolver(arbol.left(), niveles, exito);
			izda = arbol.left().root();
			niveles++;
			aux_izd = niveles;

		}
		// exploramos todos los nodos de la derecha y gaurdamos su raiz en caso de que no este vacio
		int derecha = 0;
		int aux = 0;
		if (!arbol.right().empty()) {
			resolver(arbol.right(), niveles, exito);
			derecha = arbol.right().root();
			niveles++;
			aux = niveles;
		}
		// comprobamos con los nodos que hemos guardadaDO QUE SE CUMPLEN  las condiciones del enunciado
		if (izda - 2 < derecha && !arbol.right().empty() && !arbol.left().empty())
			exito = false;
		else if ((arbol.root() - 18 < izda && !arbol.left().empty()) || (arbol.root() - 18 < derecha && !arbol.right().empty()))
			exito = false;
		else if (arbol.left().empty() && !arbol.right().empty())
			exito = false;
		//nos guardamos en nivell de la izda y el de la derecha y nos quedamos con el que sea mayor
		niveles = std::max(aux, aux_izd);
	}
}





void resuelveCaso() {
	int nNivel = 0;
	bool ex = true;
	bintree<int> tree = leerArbol(-1);

	// LLamada a la funcion y escribir resultados
	// A rellenar por el alumno

	resolver(tree, nNivel, ex);

	if (ex && tree.empty())
		std::cout << "SI" << " " << nNivel << "\n";
	else if (ex && !tree.empty())
		std::cout << "SI" << " " << nNivel + 1 << "\n";
	else
		std::cout << "NO\n";

}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //redirect std::cin to casos.txt
#endif

	int numCasos; std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) { resuelveCaso(); }

	// Para restablecer entrada. 

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}