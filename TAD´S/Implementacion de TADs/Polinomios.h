#ifndef POLINOMIOS
#define POLINOMIOS

#include <iostream>
#include <vector>
#include<fstream>
#include <cmath>

typedef struct {
	signed int coeficiente;
	int exponente;
}monomio;

class polinomios {

private:
	std::vector<monomio> poli;

public:

	std::vector<monomio> get_poli () const { return poli; };

	int buscar_pos( monomio const &mono, int ini, int fin) {

		if (fin - ini == 0) {// hay solo un elemento
			if (poli[ini].exponente > mono.exponente)
				return ini;
			else
				return ini + 1;
		}
		else {
			int mitad = (ini + fin) / 2;

			if (poli[mitad].exponente > mono.exponente) //tiene que buscar en la izda
				buscar_pos(mono, ini, mitad);
			else
				buscar_pos( mono, mitad + 1, fin);
		}
	};
	
signed int solucion(signed int valor) {
		signed int resultado = 0;

		for (int i = 0; i < poli.size(); i++)
		{
			resultado += (pow(valor, poli[i].exponente)) * poli[i].coeficiente;
		}

		return resultado;
	}

	void insertar(monomio const &mono){
		int pos;

		if (poli.empty()) // si el polinomio esta vacio lo metemos normal
			poli.push_back(mono);

		else { // si no esta vacio hay que insertarlo ordenado
			pos = buscar_pos(mono, 0, poli.size() - 1);
			poli.insert(poli.begin() + pos, mono);
		}
	}
};


inline std::istream& operator >>(std::istream & in,polinomios &poli) {
	monomio mono;

	in >> mono.coeficiente >> mono.exponente;

	while (mono.coeficiente != 0 || mono.exponente != 0){
		
		poli.insertar(mono);

		in >> mono.coeficiente >> mono.exponente;
	}

	return in;
};


#endif // !POLINOMIOS


