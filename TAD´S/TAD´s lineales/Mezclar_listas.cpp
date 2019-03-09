// Luis Antonio Rojas Ramirez
// E52

#include <iostream>
#include <fstream>
#include "queue_eda.h"

/*
	EL COSTE ES CONSTANTE: O(n) --> siendo n el numero de elementos
	de la lista final (lista resultado);
*/
template<typename T>
class listaAux : public queue<T> {
private:
	using Nodo = typename queue<T>::Nodo;

public:

	// Este metodo inserta una lista ordenada en otra lista 
	// ordenada dejando el resultado ordenado también:
	void insertLista(listaAux<T> & lista2) {
		Nodo *uno = this->prim;
		Nodo *dos = lista2.prim;
		Nodo *aux = nullptr;
		Nodo *tmp = nullptr;
		bool ok = false;

		//CASO 1: Si la lista principal esta vacia:
		if (this->empty()) {
			this->prim = lista2.prim; //Apunto su inicio al inicio de la lista2;
			this->ult = lista2.ult; //Apunto su final al final de la lista2;
			this->nelems = lista2.nelems; //Copio su numero de elementos;
		}

		//CASO 2: Si la lista principal no esta vacia:
		else {
			while (dos != nullptr) {
				//Iteramos la lista principal hasta encontrar un elemento 
				//mas grande que el primer elemento de la lista secundaria:
				while ((uno != nullptr) && dos->elem > uno->elem) {
					aux = uno;
					uno = uno->sig;
				}
				//if (uno == nullptr) ok = true;

				//Cuando el primer elemento de la lista secundaria es menor que
				//el primer elemento de la lista principal:
				if (this->prim == uno) { //Solo entra al principio en el caso descrito;
					uno = dos;
					dos = dos->sig;
					uno->sig = this->prim;
					this->prim = uno;
				}

				//Cuando cualquier otro elemento de la lista principal es mayor que
				//el elemento de la lista secundaria:
				else {
					aux->sig = dos;
					tmp = dos->sig;
					dos->sig = uno;
					//Si estamos en el ultimo elemento de la lista secundaria y ya
					//hemos recorrido la lista principal entera, redireccionamos
					//el puntero que apunta al ulitimo elemento de la lista principal:
					if (dos->sig == nullptr && uno == nullptr) this->ult = dos;
					dos = tmp;
					aux = aux->sig;
				}
			}
			this->nelems += lista2.nelems;
		}

		//Dejamos la lista2 vacia tras haber insertado 
		//sus elementos en la list principal:
		lista2.prim = nullptr;
		lista2.ult = nullptr;
		lista2.nelems = 0;
	}

	// Muestra todos los elementos de la lista:
	void mostrar() {
		//Apunto con un nodo auxiliar al inicio de mi lista:
		Nodo *aux = this->prim;

		while (aux != nullptr) {
			std::cout << aux->elem << " ";
			aux = aux->sig;
		}
		std::cout << "\n";
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// Leer los datos de la entrada
	listaAux<int> lista1;
	listaAux<int> lista2;

	int aux;

	// Rellena lsita1:
	std::cin >> aux;
	while (aux != 0) {
		lista1.push(aux);
		std::cin >> aux;
	}

	//rellena lista2:
	std::cin >> aux;
	while (aux != 0) {
		lista2.push(aux);
		std::cin >> aux;
	}

	//Inserta lista2 en lista1 de forma ordenada:
	lista1.insertLista(lista2);

	// Escribir sol:
	lista1.mostrar();
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
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