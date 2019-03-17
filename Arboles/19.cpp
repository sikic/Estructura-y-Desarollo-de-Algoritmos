// Luis Antonio Rojas Ramirez
// e52

#include <iostream>
#include <iomanip>
#include <fstream>
#include"bintree_eda.h"

template <class T>
class bintree_ext : public bintree<T>{

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	size_t altura() const {
		return altura(this->raiz);
	}

	size_t nodos() const {
		size_t num = 1;
		nodos(this->raiz,num);
		return num;
	}

	size_t hojas() const {
		size_t num = 1;
		hojas(this->raiz,num);
		return num -1;
	}

	bintree_ext<T> leerArbol_ext(T vacio) {

		T raiz;
		std::cin >> raiz;

		if (raiz == vacio) // es un ·rbol vacÌo
			return {};

		else { // leer recursivamente los hijos

			auto iz = leerArbol_ext(vacio);
			auto dr = leerArbol_ext(vacio);
			return { iz, raiz, dr };
		}

	}
private:

	static size_t altura(Link r) {

		if (r == nullptr)
			return 0;
		else
			return 1 + std::max(altura(r->left), altura(r->right));
	}

	static void nodos(Link r, size_t &num) {
		
		if (r == nullptr)
			num = 0;
		else {
			if (r->left != nullptr) {
				num++;
				nodos(r->left,num);
			}
			if (r->right != nullptr) {
				num++;
				nodos(r->right,num);
			}
		}


	}

	static size_t hojas(Link r, size_t &num) {

		if (r == nullptr)
			return 0;
		else {
			if (r->left == nullptr && r->right == nullptr)
				num++;

			if (r->left != nullptr)
				hojas(r->left, num);

			if (r->right != nullptr)
				hojas(r->right, num);

			}
		}
	

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÃÅn, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	auto arbol = bintree_ext<char>().leerArbol_ext('.');

	std::cout <<arbol.nodos()<< " " << arbol.hojas() << " "  << arbol.altura() << "\n";
	
	
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