// Luis Antonio Rojas Ramirez
// e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum piedrasPreciosas{diamante,rubi,esmeralda,zafiro,jade};

//sobrecarga del operador
std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
	char num;
	entrada >> num;
	switch (num) {
	case 'd': p = diamante; break;
	case 'r': p = rubi; break;
	case 'e': p = esmeralda; break;
	case 'z': p = zafiro; break;
	case 'j': p = jade; break;
	}
	return entrada;
}


// función que resuelve el problema
int resolver(const std::vector<piedrasPreciosas> &v ,int tam,int numpiedras ,const piedrasPreciosas &tipo1,const piedrasPreciosas &tipo2, int numtipo1,int numtipo2)
{
	int veces = 0 , vecestipo1 = 0,vecestipo2 = 0 ,aux = 0;


	for (int i = 0; i < tam; i++)
	{
		if (v.at(i) == tipo1)
			vecestipo1++;

		if (v.at(i) == tipo2)
			vecestipo2++;

		if (i >= numpiedras-1 && vecestipo1 == numtipo1 && vecestipo2 == numtipo2) {
			veces++;;
			vecestipo1 = 0;
			vecestipo2 = 0;
			//aux = 0;
		}

		//aux++;
	}


	return veces;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numpiedras, tam, numtipo1,numtipo2;
	piedrasPreciosas tipo1, tipo2;

	std::cin >> tam >> numpiedras >> tipo1 >> numtipo1 >> tipo2 >> numtipo2;

	std::vector<piedrasPreciosas> v(tam);

	for (piedrasPreciosas& i : v) std::cin >> i;

	int sol = resolver(v,tam,numpiedras,tipo1,tipo2,numtipo1,numtipo2);
	// escribir sol

	std::cout << sol << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos41.txt");
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