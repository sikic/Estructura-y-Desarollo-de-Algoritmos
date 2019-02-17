// Luis Antonio Rojas Ramirez
// E52

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "Peliculas.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	peliculas peli;
	

	std::cin >> n;

	if (n == 0)
		return false;

	std::vector<peliculas> v;

	for (int i = 0; i < n; i++)
	{
		std::cin >> peli;
		v.push_back(peli);

	}

	std::sort(v.begin(),v.end());

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << "\n";

	}
	std::cout << "--- \n";

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