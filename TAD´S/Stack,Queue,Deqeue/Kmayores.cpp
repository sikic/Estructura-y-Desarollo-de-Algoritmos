// Luis Antonio Rojas Ramirez	
// e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "conjunto.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	size_t k,i=0;
	int aux;
	std::string auxiliar;
	char c;
	set<int> numeros;
	set<std::string> letras;
	
	std::cin >> c >> k;
		

	if (!std::cin)
		return false;

	if (c == 'N') { // si entra una n hacemos de numero si no de string

		while (i != k) {
			std::cin >> aux;
			numeros.insert(aux);
			i++;
		}
		
		std::cin >> aux;

		while (aux != -1) {
			if (aux > numeros.menor() && !numeros.contains(aux)) {
				numeros.insert(aux);
				if (numeros.size() != k)
					numeros.eraseMin();
				i++;
			}
			std::cin >> aux;
		}

		numeros.print(k);
	}
	else {

		while (i != k) {
			std::cin >> auxiliar;
			letras.insert(auxiliar);
			i++;
		}

		std::cin >> auxiliar;

			while (auxiliar != "FIN") {
				if (auxiliar > letras.menor() && !letras.contains(auxiliar)) {
					letras.insert(auxiliar);
					if (letras.size() != k)
						letras.eraseMin();
					i++;
				}
				std::cin >> auxiliar;
			}
		letras.print(k);
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