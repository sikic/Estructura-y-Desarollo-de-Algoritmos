// Luis Antonio Rojas Ramirez
// e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "carnet_puntos.h"

void resolver(std::string lineaB) {
	int puntos;
	std::string dni;
	carnet_puntos cp;
	std::string operacion;
	std::string linea(lineaB);

	do {

		std::stringstream ss(linea);

		ss >> operacion;

		try {

			if (operacion.compare("nuevo") == 0) {

				ss >> dni;
				cp.nuevo(dni);

			}
			else if (operacion.compare("quitar") == 0) {

				ss >> dni;
				ss >> puntos;
				cp.quitar(dni, puntos);

			}
			else if (operacion.compare("consultar") == 0) {

				ss >> dni;
				int n = cp.consultar(dni);
				std::cout << "Puntos de " << dni << ": " << n << "\n";

			}
			else if (operacion.compare("cuantos_con_puntos") == 0) {

				ss >> puntos;
				int n = cp.cuantos_con_puntos(puntos);
				std::cout << "Con " << puntos << " puntos hay " << n << "\n";

			}
			else if (operacion.compare("recuperar") == 0) {
				ss >> dni;
				ss >> puntos;
				cp.recuperar(dni, puntos);
			}
			else if (operacion.compare("lista_por_puntos") == 0) {

				ss >> puntos;
				std::cout << "Tienen " << puntos << " puntos: ";

				std::vector<tListar> sol = cp.lista_puntos(puntos);
				for (int i = sol.size() - 1; i > -1 ; i--)
				{
						std::cout << sol[i].dni << " ";
				}
					std::cout << "\n";
			}

		}
		catch (const std::domain_error& e) {

			std::cout << "ERROR: " << e.what() << std::endl;

		}

		getline(std::cin, linea);

	} while (linea.compare("FIN") != 0);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso(){

	std::string linea;

	getline(std::cin, linea);

	if (!std::cin)

		return false;

	if (linea.compare("FIN") != 0)
		resolver(linea);

	std::cout << "---" << std::endl;

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