#ifndef conjunto_h
#define conjunto_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>

template <class T>
class set {

private:
	const static size_t TAM_INICIAL = 8;
	size_t contador;
	size_t capacidad;
	T * datos;
	void amplia();
	void libera();
	void copia(set<T> const& other);

public:
	set(size_t tam = TAM_INICIAL); // constructor
	set(set<T> const& other); // constructor por copia
	set<T> & operator=(set<T> const& other); // operador de asignación
	~set(); // destructor
	void insert(T e);
	bool contains(T e) const;
	void erase(T e);

	//-----------
	T menor();
	void eraseMin();
	void print(size_t k);
	size_t pos(T e ,size_t ini,size_t fin);
	//------------

	bool empty() const;
	size_t size() const;

};

template <class T>
set<T>::set(size_t tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
	libera();
}

template <class T>
void set<T>::libera() {
	delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
	copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (size_t i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) {
	size_t poss;
	if (!contains(e)) {
		if (contador == capacidad)
			amplia();
		if (contador == 0) {
			datos[contador] = e;
			contador++;
			
		}
		else {
			poss = pos(e,0,contador -1);

			for (size_t i = contador; i > poss; i--)
			{
				datos[i] = datos[i-1];

			}
			datos[poss] = e;
			contador++;

		}
	}
}

template <class T>
bool set<T>::contains(T e) const {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	return i < contador;
}
//**********************
template<class T>
inline T set<T>::menor()
{
	return datos[contador - 1];
}
//**********************
template <class T>
void set<T>::amplia() {
	T * nuevos = new T[2 * capacidad];
	for (size_t i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	if (i < contador) {
		datos[i] = datos[contador - 1];
		--contador;
	}
	else
		throw std::domain_error("El elemento no esta");
}
/*******************************************/
template<class T>
inline void set<T>::eraseMin()
{
	contador--;
}
template<class T>
inline void set<T>::print(size_t k)
{
	for (size_t i = 0; i < k; i++)
	{
		std::cout << menor() << " ";
		eraseMin();
	}
}

template<class T>
inline size_t set<T>::pos(T e, size_t ini, size_t fin)
{
	if (fin == ini) {// hay solo un elemento
		if (datos[ini] < e)
			return ini;
		else
			return ini + 1;
	}
	else {
		int mitad = (ini + fin) / 2;

		if (datos[mitad] < e) //tiene que buscar en la izda
			return pos(e, ini, mitad);
		else
			 return pos(e, mitad + 1, fin);
	}	
}

/*****************************************/

template <class T>
bool set<T>::empty() const {
	return contador == 0;
}

template <class T>
size_t set<T>::size() const {
	return contador;
}


#endif // conjunto_h
 