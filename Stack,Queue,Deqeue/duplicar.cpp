// Luis Antonio Rojas Ramirez
// E52


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"



// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num,k,i=0;
	queue<int> cola;
	

	std::cin >> num;

	if (!std::cin)
		return false;

	while (num != 0) {
		cola.push(num);
		std::cin >> num;
	}

	// escribir sol
	cola.duplicar();

	cola.print();
	std::cout << std::endl;

	/*std::cin >> num;

	while (num != 0) {
		cola.push(num);
		std::cin >> num;
	}

	std::cin >> k;

	while (i < k) {
		cola.pop();
		i++;
	}
	cola.print();
	std::cout << std::endl;*/
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