// Luis Antonio Rojas Ramirez
// E52

#include <iostream>
#include <iomanip>
#include <fstream>
#include "complejos.h"
#include <cmath>


float mod(complejos const &complejo){
	return sqrt(complejo.get_real() * complejo.get_real() +   complejo.get_imaginario() * complejo.get_imaginario());
}	  

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nVeces;
	bool exito = false;
	complejos c;
	complejos z(0,0);

	std::cin >> c >> nVeces;

	int i = 1;

	while (i < nVeces && !exito) {

		z = z*z + c;
	
		if (mod(z) > (float)2)
			exito = true;

		i++;
	}

	if (exito)
		std::cout << "NO \n";
	else
		std::cout << "SI \n";

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
