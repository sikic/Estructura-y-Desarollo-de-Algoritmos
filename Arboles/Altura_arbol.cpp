// Luis Antonio Rojas Ramirez	
// E52


#include <iostream>
#include <iomanip>
#include <fstream>


void altura(int &tam,int actual){
	int aux;
	std::cin >> aux;

	if (aux != 0) {
		for (int i = 0; i < aux; i++)
		{
			altura(tam, actual + 1);
		}
	}

	if (actual > tam)
		tam = actual;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int tam = 1,actual =1;
	
	altura(tam,actual);

	std::cout << tam << "\n";
	

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