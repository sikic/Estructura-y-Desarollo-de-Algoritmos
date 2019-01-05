// Luis Antonio Rojas Ramirez
// E52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(const std::vector<int> &v, int p) {
	//cogemos el mayor de todos hasta p y luego si ese mayor es mas grande que cualquiera a partir de p ya es false
	bool exito = true;
	int mayor = v.at(0);

	for (int i = 0; i <= p; i++)
	{
		if (v.at(i) > mayor)
			mayor = v.at(i);
	}

	for (int i = p + 1; i < v.size(); i++)
	{
		if (mayor >= v.at(i))
			exito = false;
	}
	

	return exito;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	// leer los datos de la entrada
	int n,p, aux;
	std::vector<int> v;

	std::cin >> n >> p;

	for (int i = 0; i < n; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}

	if (resolver(v, p))
		std::cout << "SI \n";
	else
		std::cout << "NO \n";
	
	
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos37.txt");
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