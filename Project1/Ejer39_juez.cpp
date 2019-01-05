// Luis Antonio Rojas Ramirez
// E52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int ini;
	int fin;
}tSol;


// función que resuelve el problema
tSol resolver(const std::vector<int> &v, int altura) {
	
	tSol sol;
	int aux_ini = -1;
	int aux_fin = -1;
	int cont = -1;


	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) > altura) {
			if (aux_ini == -1) { // si el edificio es mayor que la altura lo guardamos tanto en el inicio como en el final
				aux_ini = i;
				aux_fin = i;
			}
			else // si el inicio esta relleno solo aumentamos el fin
				aux_fin = i;

			if (aux_fin - aux_ini > cont) { // aqui siempre entra la primera vez y solo guarda el intervalo si encuentra uno mayor que el , entonces cada vez que lea una secuencia la resta entre fin y ini crecera y cuando sea mas grande que el contador nos interesara guardala
				sol.ini = aux_ini;
				sol.fin = aux_fin;
				cont = aux_fin - aux_ini;
			}
		}
		else {
			aux_ini = -1;
			aux_fin = -1;
		}

			
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	// leer los datos de la entrada
	int tam, altura, aux;
	std::vector<int> v;

	std::cin >> tam >> altura;

	for (int i = 0; i < tam; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}

	
	tSol sol = resolver(v, altura);


	std::cout << sol.ini << " " << sol.fin << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos39.txt");
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