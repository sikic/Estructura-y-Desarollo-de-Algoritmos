#ifndef PELICULAS
#define PELICULAS

#include<iostream>
#include <string>
#include "horas.h"

class peliculas {

private:

	std::string nombrePelicula;
	horas horaInicio,duracion,fin;


public:
	peliculas() {};
	peliculas(std::string p,horas ini,horas dur,horas f) :nombrePelicula(p),horaInicio(ini),duracion(dur),fin(f){};

	std::string get_Nombre() const { return nombrePelicula; };
	horas get_Inicio() const { return horaInicio; };
	horas get_Duracion() const { return duracion; };
	horas get_Fin() const { return fin; };
	
	bool operator< (peliculas const &p){

		return (fin < p.fin) || (fin == p.fin && nombrePelicula < p.nombrePelicula);
	}

};

inline std::ostream& operator<< (std::ostream& out ,peliculas const& p) {

	out << p.get_Fin() << " " << p.get_Nombre();
	return out;

}

inline std::istream& operator>> (std::istream& in, peliculas &p) {

	std::string nombre;
	horas inicio, duracion;
	
	in >> inicio >> duracion;
	in.ignore();
	std::getline(in,nombre);

	 p= peliculas(nombre,inicio,duracion,inicio+duracion);

	return in;
}
#endif // !PELICULAS

