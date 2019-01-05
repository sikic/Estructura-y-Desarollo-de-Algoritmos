// Luis Antonio Rojas Ramirez
// E52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int> &v,int size) {

	//recorres el vector y los elmentos pares los echas una posici�n a la izda , dejando los impares a la derecha , y luego borrar hasta el ultimo elemnto de los pares
	int k = 0;

	for (int i = 0; i < size ; i++)
	{
		if (v.at(i) % 2 == 0) {
			std::swap(v.at(k), v.at(i));
			k++;
		}
	}

	v.resize(k);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	// leer los datos de la entrada
	int n,aux;
	std::vector<int> v;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}
	
	resolver(v,v.size());
	
	// escribir sol

	for (int i = 0; i < v.size()  ; i++)
	{
		std::cout << v.at(i) << " ";
	}

	std::cout << std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos36.txt");
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