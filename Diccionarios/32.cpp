// Luis Antonio Rojas Ramirez
//e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

struct Output {
	std::string nombre;
	int total;
};

bool ordenar(const Output &a, const Output &b) {
	if (a.total != b.total)
		return a.total > b.total;
	else
		return a.nombre < b.nombre;
}
void print(std::vector<Output> &v,const  std::map<std::string, int> &sol) {
	
	for (size_t i = 0; i < v.size(); i++)
	{
		auto it = sol.find(v[i].nombre);

		if (it != sol.end())
			v[i].total = it->second;
	}

	std::sort(v.begin(),v.end(),ordenar);

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i].nombre << " " << v[i].total << "\n";
	}

	std::cout << "***\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso(){
	// leer los datos de la entrada
	/*map cuya clave es el deporte en cuestion, y su valor es un map(este map tiene como clave el nombre de el alumno y como valor
	un vector con los deportes en los que se ha inscrito*/
	std::map<std::string,int> sol;
	std::unordered_map <std::string, std::unordered_map<std::string,bool> > apuntados;

	std::vector<Output> v;
	std::string deporte, nombre,linea;

	std::cin >> linea;
	
	while (linea != "_FIN_") {
		if (linea[0] >= 'A' && linea[0] <= 'Z') {
			//Guardamos el nombre del deporte:
			v.push_back({linea,0 });
			deporte = linea;
			std::cin >> linea;
			//si la linea que leo es otro deporte  guardo el anterior por que esta vacio
			if (linea[0] >= 'A' && linea[0] <= 'Z') {
				sol.insert({deporte,0});
			}
			else {
				while ((linea[0] >= 'a' && linea[0] <= 'z')) { // mientras haya alumnos los leemos
					nombre = linea;
					//busco al alumno y miro si se ha apuntado en mas de un deporte
					auto it = apuntados.find(nombre);

					if (it == apuntados.end()) { // el alumno aun no se ha apuntado a nada
						
						//le apuntamos y añadimos que el deporte al que se ha apuntado y sumamos uno a la lista de ese deporte
						apuntados[nombre].insert({deporte,true});
						sol[deporte]++;
					}
					else {//el alumno ya se ha apuntado a algo
						auto it2 = it->second.find(deporte);
						if (it2 == it->second.end()){
							auto it3 = sol.find(it->second.begin()->first);//buscamos el deporte que tenia antes y le borramos uno ademas de poner a false el campo de ese alumno
							if (it->second.begin()->second == true) {
								it3->second--;
								//ponemos a false el del alumno
								//it->second.begin()->first.(deporte);
								it->second.begin()->second = false;
							}
				
						}
						
					}
					std::cin >> linea;
				}
			}
		}

		//std::cin >> linea;
	}

	print(v, sol);
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos = 1;
	//std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}