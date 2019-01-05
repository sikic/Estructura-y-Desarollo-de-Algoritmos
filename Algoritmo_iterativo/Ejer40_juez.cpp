// Luis Annnotio Rojas Ramirez
// e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct tSol
{
	int ini = -1;
	int fin = -1;
	int seguidos = 0;
	int veces = 0;
	int tiempo;
};



// función que resuelve el problema
tSol resolver(const std::vector<int> &v, int tam) {
	tSol sol;
	int aux_ini = -1, aux_fin = -1, contador = 0;
	for (int i = 0; i < tam; i++)
	{
		if (v.at(i) > 0) {

			if (aux_ini == -1) {
				aux_ini = i;
				aux_fin = i;
			}
			else
				aux_fin = i;

			if (aux_fin - aux_ini == contador){ // si encontramos un intervalo igual actualizamos los indices y sumamos uno al contador de las veces
				sol.veces++;
				sol.ini = aux_ini;
				sol.fin = aux_fin;
			}
			else if (aux_fin - aux_ini > contador){ // en caso de que encontremos un intervalo mayor hay que descartar la suma de las veces que llevabamos por que ya no nos vale
				contador = aux_fin - aux_ini;
				sol.ini = aux_ini;
				sol.fin = aux_fin;
				sol.veces = 1;
			}
		}
		else {
			aux_ini = -1;
			aux_fin = -1;
		}
	}
	
	if (sol.fin == sol.ini && sol.ini == -1) // al salir del for hay que ver si hemos encontrado algun intervalo 
		sol.seguidos = 0; // en caso de no encontrarlo la racha de victorias es 0
	else
		sol.seguidos = (sol.fin - sol.ini) + 1; // si hay un intervalo hay que restar las posiciones de los indices
		
	sol.tiempo = (tam - 1) - sol.fin; // el tiempo desde la ultima victoria solo hay que restar el fin del intervalo al tamaño y nos sale

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numPartidos,aux;
	std::vector<int> v;



	std::cin >> numPartidos;

	if (!std::cin)
		return false;

	for (int i = 0; i < numPartidos; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}


	tSol sol = resolver(v,numPartidos);

	// escribir sol
	std::cout << sol.seguidos << " " << sol.veces << " " << sol.tiempo << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos40.txt");
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