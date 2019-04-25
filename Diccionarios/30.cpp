// Luis Antonio Rojas Ramirez
//e52

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <utility>
#include<sstream>
#include <vector>

using tMatriz = std::vector<std::vector<std::string>>;

void anadidosYCambiados(const std::map<std::string, unsigned int> &antiguo, const std::map<std::string, unsigned int> &nuevo, tMatriz &matriz) {
	// recorremos el nuevo y vamos buscando esos elementos en el antiguo, si no los encuentra es que han sido agregados nuevos, si los encuentra miramos si su valor ha cambiado
	for (auto it = nuevo.begin(); it != nuevo.end(); it++)
	{
		auto itb = antiguo.find(it->first);

		//no ha encontrado el elemento asi que añadimos a el vector se añadidos un elemento
		if (itb == antiguo.end())
			matriz[0].push_back(it->first);
		else {// en caso de encontrar el elemento en los dos diccionarios , hay que comprobar que su valor ha cambiado, en caso de ser asi lo metemos en el la matriz en la pos 2
			if (it->second != itb->second)
				matriz[2].push_back(it->first);
		}
	}
}

void quitados(const std::map<std::string, unsigned int> &antiguo, const std::map<std::string, unsigned int> &nuevo, tMatriz &matriz) {
	for (auto it = antiguo.begin(); it != antiguo.end(); it++)
	{
		auto itc = nuevo.find(it->first);

		//no ha encontrado el elemento asi que añadimos a el vector de cambiados un elemento en la posicion
		if (itc == nuevo.end())
			matriz[1].push_back(it->first);
		
	}
}

void print(const tMatriz &matriz) {

	
	if (matriz[0].size() > 0) {
		std::cout << "+ ";

		for (int i = 0; i < matriz[0].size(); i++)
		{
			std::cout << matriz[0][i] << " ";
		}
		std::cout << "\n";
	}
	

	if (matriz[1].size() > 0) {
		std::cout << "- ";

		for (int i = 0; i < matriz[1].size(); i++)
		{
			std::cout << matriz[1][i] << " ";

		}
		std::cout << "\n";
	}

	if (matriz[2].size() > 0) {
		std::cout << "* ";


		for (int i = 0; i < matriz[2].size(); i++)
		{
			std::cout << matriz[2][i] << " ";

		}
		std::cout << "\n";
	}
	if (matriz[0].empty() && matriz[1].empty() && matriz[2].empty())
		std::cout << "Sin cambios\n";

	std::cout << "----\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	/*Hacemos una matriz con 3 vectores, uno para cada operacion:
	1-suma
	2-resta
	3-cambiados*/
	tMatriz matriz(3,std::vector<std::string>());


	std::string cadena,linea,linea1;
	//std::cin.ignore();
	std::getline(std::cin, linea);
	std::stringstream ss(linea);
	int num;
	

	//diccionario formado por clave(letras minusculas) y valor(entero no negativo) 
	std::map<std::string,unsigned int> antiguo;
	std::map<std::string, unsigned int> nuevo;

	// recorremos para rellenar el antiguo 
	while (ss >> cadena) {
		ss >> num;
		antiguo.insert(make_pair(cadena,num));
	}

	// recorremos para rellenar el nuevo
	std::getline(std::cin, linea1);
	std::stringstream ssa(linea1);

	while (ssa >> cadena) {
		ssa >> num;
		nuevo.insert(make_pair(cadena, num));
	}

	anadidosYCambiados(antiguo, nuevo, matriz);
	quitados(antiguo, nuevo, matriz);
	print(matriz);


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
	std::cin.ignore();

	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}