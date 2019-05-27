#include "iPud.h"
#include <sstream>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string linea;
	std::getline(std::cin, linea);
	if (!std::cin) return false;

	ipud iPudTad; //Creamos nuestro tad;

	while (linea != "FIN") {
		std::stringstream ss(linea);
		std::string comando, nombreCancion, nombreArtista;
		int minutos, numSong;

		//Leemos la primera palabra de la linea:
		ss >> comando;

		//Parseamos la primera palabra y en funcion del comando
		//hacemos una cosa u otra:
		try {
			//Agrega una cancion al iPud:
			if (comando == "addSong") {
				ss >> nombreCancion >> nombreArtista >> minutos;
				iPudTad.addSong( nombreArtista,nombreCancion,minutos);
			}

			//Agrega una cancion a la playList:
			else if (comando == "addToPlaylist") {
				ss >> nombreCancion;
				iPudTad.addToPlaylist(nombreCancion);
			}

			//Muestra cuantos puntos tiene un alumno:
			else if (comando == "current") {
				iPudTad.current();


			}

			//Aumenta la cantidad de puntos de un alumno:
			else if (comando == "play") {
				//Comprueba si hay canciones en la lista y reproduce la 
				//primera canción (la elimina de la playlist):
				if (!iPudTad.esVacia()) {
					std::cout << "Sonando " << iPudTad.current() << "\n";
					iPudTad.play();
				}
				else std::cout << "No hay canciones en la lista" << "\n";
			}

			//Muestra el tiempo total de la lista de reproduccion:
			else if (comando == "totalTime") {
				std::cout << "Tiempo total " << iPudTad.totalTime() << "\n";
			}

			//Muestra las numSong canciones reproducidas:
			else if (comando == "recent") {
				ss >> numSong;
				std::vector<Cancion> aux = iPudTad.recent(numSong);

				if (!aux.empty()) { //Si hay canciones;
					std::cout << "Las " << numSong << " mas recientes" << "\n";

					//Muestra cada una de las canciones:
					for (int i = aux.size()-1; i >= 0; i--) {
						std::cout << "    " << aux[i] << "\n";
					}
				}
				else std::cout << "No hay canciones recientes" << "\n";
			}

			//Elimina una cancion del iPud:
			else if (comando == "deleteSong") {
				ss >> nombreCancion;
				iPudTad.deleteSong(nombreCancion);
			}
		}
		catch (std::domain_error & e) {
			std::cout << e.what() << "\n";
		}

		std::getline(std::cin, linea);
	}

	std::cout << "----" << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}