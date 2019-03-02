// Luis Antonio Rojas Ramirez
// E52

#include <iostream>
#include <iomanip>
#include <fstream>
#include"Polinomios.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	polinomios poli;
	signed int valor;
	int veces;

	std::cin >> poli;

	if (!std::cin)
		return false;

	std::cin >> veces;

	for (int i = 0; i < veces; i++)
	{
		std::cin >> valor;

		std::cout << poli.solucion(valor) << " ";
	}

	std::cout << std::endl;


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