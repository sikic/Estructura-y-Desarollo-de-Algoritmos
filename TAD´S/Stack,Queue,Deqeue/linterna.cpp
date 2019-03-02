// Luis Antonio Rojas Ramirez
//e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include<stack>
#include<vector>

bool resolver(std::vector<int> const& fila, int numSobrinos) {
	std::stack<int> pila;
	int medio = -1;

	//Insertamos el ultimo elemento en la fila:
	pila.push(fila[fila.size() - 1]);

	for (int i = numSobrinos - 2; i >= 0; --i) {
		if (medio > fila[i] && medio < pila.top()) return false;
		else {
			while (!pila.empty() && fila[i] > pila.top()) {
				medio = pila.top();
				pila.pop();
			}
			pila.push(fila[i]);
		}
	}

	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;

	std::cin >> tam;

	if (!std::cin)
		return false;

	std::vector<int> num(tam);

	for (int i = 0; i < tam; i++)
	{
		std::cin >> num[i];
	}
	bool exito = resolver(num,tam);
	/*meto el ultimo a saco , y voy buscando uno mayor , si lo encuentro , cambio el minimo al anterior de ese mayor y lo saco de la pila y despues meto 
	ese mayor en la pila y asi sucesivamente hasta que encuentre uno menos que sea mas pequeño que los dos entonces fin del ejercicio*/
	//meto el primero en la pila

	
	if (!exito)
		std::cout << "ELEGIR OTRA \n";
	else
		std::cout << "SIEMPRE PREMIO \n";


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