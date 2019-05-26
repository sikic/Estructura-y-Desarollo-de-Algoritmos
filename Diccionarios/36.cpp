// Luis Antonio Rojas Ramirez
//e52

#include "consultorio.h"
#include<sstream>
#include <algorithm>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(consultorio &cp) {
	// leer los datos de la entrada
	
	std::string linea,medico,paciente,operacion;
	int d, h, m;
	
	std::getline(std::cin,linea);
	std::stringstream ss(linea);
	ss >> operacion;

	try {
		if (operacion == "nuevoMedico") {
			ss >> medico;
			cp.nuevoMedico(medico);
		}
		else if (operacion == "pideConsulta") {
			ss >> paciente >> medico >> d >> h >> m;
			fecha f(d, h, m);
			cp.pideConsulta(paciente, medico, f);
		}
		else if (operacion == "listaPacientes") {
			ss >> medico >> d;
			std::vector <InfoPaciente> sol = cp.listaPacientes(medico, d);
		
			std::cout << "Doctor " << medico << " dia " << d << "\n";

			for (int i = 0; i < sol.size(); i++)
			{
				
				std::cout << sol[i].paciente << " " << std::setfill('0') << std::setw(2) << sol[i].hora << ":" << 
					std::setfill('0') << std::setw(2) << sol[i].minuto << "\n";
			}

			std::cout << "---\n";
		}
		else if (operacion == "siguientePaciente") {
			ss >> medico;

			std::cout << "Siguiente paciente doctor " << medico << "\n" << cp.siguientePaciente(medico) << "\n---\n";
		}
		else if (operacion == "atiendeConsulta") {
			ss >> medico;
			cp.atiendeConsulta(medico);
		}
	}
	catch (std::domain_error e) {
		std::cout << e.what() << std::endl;
		std::cout << "---\n";
	}



}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


		int numCasos;
		std::cin >> numCasos;
		if (std::cin) {
			do {

				std::cin.ignore();
				consultorio cp;
				for (int i = 0; i < numCasos; ++i)
					resuelveCaso(cp);
				std::cout << "------\n";
				std::cin >> numCasos;
			} while (std::cin);
		}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}