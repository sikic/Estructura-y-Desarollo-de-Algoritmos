// Luis Antonio Rojas Ramirez
// E52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void print(const std::map<std::string, signed int> &alumno){
	for (auto it = alumno.begin(); it != alumno.end(); it++)
	{
		if (it->second != 0)
			std::cout << it->first << ", " << it->second << "\n";
	}
	std::cout << "---\n";
}
bool resuelveCaso() {
	// leer los datos de la entrada
	int nAlumnos;
	signed int nota;
	std::string nombre,correccion;

	// creamos la el par con el nombre del alumno y un signed int
	std::map<std::string, signed int> alumno;

	std::cin >> nAlumnos;

	if (nAlumnos == 0)
		return false;


	for (size_t i = 0; i < nAlumnos; i++)
	{
		std::cin.ignore();
		std::getline(std::cin, nombre);
		std::cin >> correccion;
		
		if (correccion != "INCORRECTO")
			nota = 1;
		else
			nota = -1;

		auto it = alumno.find(nombre); // buscamos al alumno, en caso de existir modificamos su nota, en caso de no existir lo metemos en el mapa
		
		if (it == alumno.end()){ // no ha encontrado al alumno
			alumno.insert(make_pair(nombre,nota));//hace falta crear un par de valores para poder meterlos en el map o hacer el make pair
		}
		else {
			it->second += nota;
		}
	}

	print(alumno);
	
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