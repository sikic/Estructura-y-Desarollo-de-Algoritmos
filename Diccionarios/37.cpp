//Luis Antonio Rojas Ramirez
//E52

#include "Autoescuela.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	autoescuela cp;
	std::string linea,operacion,alumno,profesor;
	int puntos;

	std::getline(std::cin , linea);
	

	if (!std::cin)
		return false;


	while (linea != "FIN") {
		std::stringstream ss(linea);
		ss >> operacion;
		try {
			if (operacion == "alta") {
				ss >> alumno >> profesor;
				cp.alta(alumno,profesor);
			}
			else if (operacion == "es_alumno") {
				ss >> alumno >> profesor;
				bool ok=cp.es_alumno(alumno, profesor);

				if (ok)
					std::cout << alumno << " es alumno de " << profesor << "\n";
				else
					std::cout << alumno << " no es alumno de " << profesor << "\n";

			}
			else if (operacion == "actualizar") {
				ss >> alumno >> puntos;
				cp.actualizar(alumno, puntos);
			}
			else if (operacion == "puntuacion") {
				ss >> alumno;

				std::cout << "Puntuacion de " << alumno << ": " << cp.puntuacion(alumno) << "\n";
			}
			else if (operacion == "examen") {
				ss >> profesor >> puntos;

				std::cout << "Alumnos de " << profesor << " a examen:\n";
				
				std::vector<std::string>sol = cp.examen(profesor, puntos);

				for (int i = 0; i < sol.size(); i++)
				{
					std::cout << sol[i] << "\n";
				}

			}
			else if (operacion == "aprobar") {
				ss >> alumno;
				cp.aprobar(alumno);
			}
		}
		catch (std::domain_error e) {
			std::cout << e.what() << std::endl;
			
		}
		std::getline(std::cin, linea);
	
	}
	
	std::cout << "------\n";
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