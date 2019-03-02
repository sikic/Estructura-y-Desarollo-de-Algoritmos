// Luis Antonio Rojas Ramirez
// e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "parentesis.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string frase;
	parentesis p;

	std::getline(std::cin, frase);

	if (!std::cin)
		return false;

	if (p.contar(frase))
		std::cout << "SI \n";
	else
		std::cout << "NO \n";


	return true;

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