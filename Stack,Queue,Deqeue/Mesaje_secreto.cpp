// Luis Antonio Rojas Ramirez
// e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include<deque>




// función que resuelve el problema
void print(std::deque<char> s,int tam) {

	std::string frase;
	while(!s.empty()){
		frase += s.front();
		s.pop_front();
	}

	std::cout << frase << std::endl;
}
bool vocal(const char &c) {
	//paso todo a mayusculas y compruebo
	char ch = tolower(c);
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	else
		return false;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam=0;
	std::string frase;
	std::deque<char> x;
	std::deque<char> sol;
	std::deque<char> aux;

	char inicio;


	std::getline(std::cin,frase);

	if (!std::cin)
		return false;
	

	for (int i = 0; i < frase.length(); i++)
	{
		if (i % 2 == 0)
			x.push_back(frase[i]);
		else
			sol.push_front(frase[i]);
	}
	
	tam = sol.size();
	for (int i = 0; i < tam ; i++)
	{
		x.push_back(sol.front()); // primera parte
		sol.pop_front();
	}

	while(!x.empty()){
		if (!vocal(x.front())){ // en las pos pares tiene que haber una vocal
			
			while (!x.empty() && !vocal(x.front())){
				aux.push_back(x.front());
				x.pop_front();
			}
			while (!aux.empty())
			{
				sol.push_back(aux.back());
				aux.pop_back();
			}
		}
		else {
			if (!x.empty()) {
				sol.push_back(x.front());
				x.pop_front();
			}
		}
			
	}

	print(sol,tam);



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