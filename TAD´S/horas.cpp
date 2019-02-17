#include <iostream>
#include <fstream>
#include "horas.h"
#include <vector>

bool resuelveCaso() {
	// leer los datos de la entrada
	int nhoras, nComprobar;
	horas hora,horaConsultar;
	
	std::cin >> nhoras >> nComprobar;

	if (nhoras == 0 && nComprobar == 0)
		return false;

	
		std::vector<horas> horario_trenes;

		for (int i = 0; i < nhoras; i++)
		{
			std::cin >> hora;
			horario_trenes.push_back(hora);
		}
		
		int c = 0;

		while (c < nComprobar) { // comprobamos el numero de horas que nos piden 

			try {
				std::cin >> horaConsultar;

				int x = horaConsultar.horaCorrecta(horario_trenes); // miramos si existe una hora de tren a la que podamos subir

				if (x == -1)
					std::cout << "NO \n";
				else
					std::cout << horario_trenes[x] << "\n";
			}
			catch (std::invalid_argument e) { // si la hora peta , damos error y consultamos las otras

				std::cout << e.what() << "\n";
			}

			c++;
		}
		std::cout << "--- \n";

	
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}