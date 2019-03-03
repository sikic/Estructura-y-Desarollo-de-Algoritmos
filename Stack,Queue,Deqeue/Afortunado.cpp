// Luis Antonio Rojas RAmirez
// e52

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, contador;
	std::queue<int> colaP; // dos colas que usaremos
	std::queue<int> colaAux;

	std::cin >> tam >> contador;

	if (tam ==0 && contador == 0)
		return false;

	int cont = contador;

	for (int i = 1; i < tam + 1; i++)
	{
		colaP.push(i); // metemos todos los alumnos en la cola
	}
	
	std::queue<int> x; 
	std::queue<int> y;

	x = colaAux; // dos punteros a las colas de antes
	y = colaP;

	while (!(y.size() == 1 && x.empty()) && !(x.size() == 1 && y.empty())){

		if (cont != 0) { // mientras no estemos en el salto lo metemos en la otra cola
			x.push(y.front());
			cont--;
		}
		else // cuando estas en el salto no haces nada solo reinicias el contador
			cont = contador;
	
		y.pop();// vas desapilando la cola hasta que se quede vacia

		if (y.empty()) // si la cola se ha quedado vacia hacemos un cambio en la dirreccion donde apuntan esos punteros
			std::swap(x,y);
	}

	// al salir del bucle nos quedamos con el elemtno buscado
	if (x.size() == 1) 
		std::cout << x.front() << "\n";
	else
		std::cout << y.front() << "\n";

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