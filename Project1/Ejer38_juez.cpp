// Luis Antonio Rojas Ramirez
// E52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int vagon;
	int suma = 0;
}tSol;


// función que resuelve el problema
void resolver(const std::vector<int> &v, int ini,int max,tSol &sol) {	

	int aux = sol.suma;
	bool fin = false;

	for (int i = 0; i < (v.size() - max); i++)
	{
		sol.suma -= v.at(i); // restamos el anterior
		sol.suma += v.at(max + i); //sumamos el siguiente

		if (sol.suma == aux) { // comprobamos si son iguales
			if (i + 1 > sol.vagon) // comprobamos cual esta mas alejado y nos quedamos con ese
				sol.vagon = i + 1;
		}

		if (sol.suma > aux) { // si encontramos una suma mayor
			aux = sol.suma;
			sol.vagon = i + 1;
		}
		
	}

	sol.suma = aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	// leer los datos de la entrada
	int tam, maxVagones,aux;
	std::vector<int> v;

	std::cin >> tam >> maxVagones;

	for (int i = 0; i < tam; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}

	tSol sol;

	for (int i = 0; i < maxVagones; i++)
	{
		sol.suma += v.at(i);
		sol.vagon = 0;
	}

	resolver(v, v.at(0),maxVagones,sol);

	
	std::cout << sol.vagon << " " << sol.suma << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos38.txt");
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