// Luis Antonio Rojas Ramirez
//e52

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <cctype>
#include <string>
#include <utility>
#include<sstream>
#include <vector>

using tMatriz = std::vector<std::vector<std::string>>;


void print(const std::map<std::string, std::vector<int>> &diccionario){
	for (auto it =diccionario.begin() ; it != diccionario.end(); it++)
	{
		std::cout << it->first << " ";
		for (size_t j = 0; j < it->second.size(); j++)
		{
			std::cout << it->second[j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "----\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso(){

	int nLineas;
	std::cin >> nLineas;

	if (nLineas == 0)
		return false;

	std::cin.ignore();

	//map de clave(string con las palabras) y la valor(un vector de enteros)
	std::map<std::string, std::vector<int>> diccionario;
	std::vector<int> num;
	
	for (size_t i = 1; i < nLineas + 1; i++)
	{
		//leemos la linea entera
		std::string linea,cadena;
		std::getline(std::cin, linea);
		std::stringstream ss(linea);
		
		//esa linea la parseamos y nos quedamos con aquellas palbras mayores de 2 letras
		while (ss >> cadena) {
		
			if (cadena.length() > 2){
				for (size_t i = 0; i < cadena.length(); i++)// pasamos a minusculas esas palabaras y las insertamos en el diccionario siempre y cuando no esten inertados
					cadena[i] = std::tolower(cadena[i]);

				auto it = diccionario.find(cadena);
				//si no esta insertado lo insertamos y si esta insertado metemos la linea en la que estamos actualmente al vector
				if (it == diccionario.end()){
					diccionario.insert(std::make_pair(cadena, num));
					diccionario.at(cadena).push_back(i);
				}
				else {//la palabra ya existe asi que tenemos que insertar en numero de fila siempre y cuando no sea el mismo que ya tiene
					if(it->second.empty())
						it->second.push_back(i);
					else if( it->second[it->second.size() - 1] != i)
						it->second.push_back(i);
				}
			}
			cadena = "";
		}
	}
	print(diccionario);
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