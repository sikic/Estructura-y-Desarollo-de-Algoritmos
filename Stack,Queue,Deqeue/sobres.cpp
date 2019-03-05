// Luis Antonio Rojas Ramirez
// E52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <stack>
#include <vector>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, k,dinero;
	std::deque<int> sobres;
	std::vector<int> v;

	std::cin >> tam >> k;

	if (tam == 0 && k == 0)
		return false;

	for (int i = 0; i < tam; i++)
	{
		std::cin >> dinero;
		v.push_back(dinero);
	}

	int i = 0;
	while (i < k) { // se queda con el max en la pos front
		while (!sobres.empty() && sobres.back() < v[i])
			sobres.pop_back();

		sobres.push_back(v[i]);
		i++;
	}

	std::cout << sobres.front() << " ";

	for (int i = k; i < tam; i++)
	{
		if (v[i - k] == sobres.front()) sobres.pop_front();

		while(!sobres.empty() && sobres.back() < v[i])
			sobres.pop_back();

		sobres.push_back(v[i]);
		std::cout << sobres.front() << " ";
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