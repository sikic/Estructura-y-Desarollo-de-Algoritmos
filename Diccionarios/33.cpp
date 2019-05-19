// Luis Antonio Rojas Ramirez
//e52

#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct InfoProblema {
	int tiempo;
	bool resuelto;
};

struct Output {
	std::string nombre;
	int resueltos;
	int total;
};

bool ordenar(const Output&a, const Output&b) {
	if (a.resueltos != b.resueltos)
		return a.resueltos > b.resueltos;
	else {
		if (a.total != b.total)
			return a.total < b.total;
		else
			return a.nombre < b.nombre;
		
	}
}
void print(std::vector<Output> &v, const std::map<std::string, std::unordered_map<std::string, InfoProblema>> &sol) {

	int indice = 0;

	for (auto i = sol.begin(); i != sol.end() ; i++)
	{
		v[indice].nombre = i->first;

		for (auto i2 = i->second.begin(); i2 != i->second.end(); i2++)
		{
			if (i2->second.resuelto) {//si esta resuelto nos quedamos con el tiempo y sumamos uno a la cantidad de resueltos, si no nos da iguaal
				v[indice].resueltos++;
				v[indice].total += i2->second.tiempo;
			}
		}
		indice++;
	}

	std::sort(v.begin(), v.end(), ordenar);

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i].nombre << " " << v[i].resueltos << " " << v[i].total << "\n";
	}
	std::cout << "----\n";
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	
	//map formado por el nombre del equipo como clave, y como valor(otro map sin orden que tendra el nombre del problema como valor y como clave un struct con el tiempo y si ha sido resuelto)
	std::map<std::string,std::unordered_map<std::string,InfoProblema>> sol;

	std::string nombre, problema, estado;
	int tiempo;
	
	std::cin >> nombre;

	while (nombre != "FIN") {
		//leemos los datos
		std::cin >> problema >> tiempo >> estado;

		//bucamos el equipo en la sol
		auto it = sol.find(nombre);

		if(it == sol.end()){ // si el equipo no existe lo insertamos
			if (estado != "AC")
				sol[nombre].insert({ problema,{20,false} });
			else
				sol[nombre].insert({ problema,{tiempo,true} });
		}
		else { // el equipo ya exitse

			//buscamos si ya esta resolviendo el problema en cuestion
			auto it2 = it->second.find(problema);

			if (it2 == it->second.end()) {//si no ha encontrado el problema 
				//lo insertamos como un intento nuevo
				if (estado != "AC")
					it->second.insert({ problema,{20,false} });
				else
					it->second.insert({ problema,{tiempo,true} });

			}
			else {//se ha encontrado el problema
				//miramos si esta resuelto ya
				//en caso de que este resuelto no hacemos nada, y si no lo esta comprobamos
				//que el nuevo intento que le metemos esta ok o no
				if (it2->second.resuelto == false) {
					if (estado == "AC") {//el nuevo intento esta ok
						it2->second.resuelto = true;
						it2->second.tiempo += tiempo;
					}
					else {
						it2->second.tiempo += 20;
					}
				}
			}

		}
			
	
	std::cin >> nombre;
	}

	std::vector<Output> salida(sol.size());
	print(salida, sol);
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
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}