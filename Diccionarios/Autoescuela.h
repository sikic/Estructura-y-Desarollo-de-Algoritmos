#ifndef AUTOESCUELA_H
#define	AUTOESCUELA_H

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<sstream>
#include<fstream>

using Profesor = std::string;
using Alumno = std::string;
using Puntos = int;

struct InfoAlumno {
	Puntos puntos;
	Profesor profesor;
};

class autoescuela {
private:
	std::map<Alumno,InfoAlumno> escuela;
public:
	autoescuela() {};

	void alta(const Alumno &a,const Profesor &p) {
		auto it = escuela.find(a);//buscamos el alumno

		if (it == escuela.end()) {	//no esta dado de alta
			escuela.insert({ a,{0,p}});
		}
		else {//esta dado de alta, es un cambio de profesor
			it->second.profesor = p;
		}
	}

	bool es_alumno(const Alumno &a, const Profesor &p) {
		auto it = escuela.find(a);//buscamos el alumno

		if (it == escuela.end()) // alumno no matriculado
			return false;
		else {// alumno matriculado
			if (it->second.profesor == p)// con el mismo porfesor 
				return true;
			else
				return false; //con otro
		}
	}

	int puntuacion(const Alumno &a) {
		auto it = escuela.find(a);//buscamos el alumno

		if (it == escuela.end())//no esta dado de alta
			throw std::domain_error("ERROR");
		else
			return it->second.puntos;
	}

	void actualizar(const Alumno &a,const int &n) {
		auto it = escuela.find(a);

		if (it == escuela.end())//no matriculado
			throw std::domain_error("ERROR");
		else {//si esta 
			it->second.puntos += n;
		}
	}

	std::vector<Alumno> examen(const Profesor &p, const int &n) {

		std::vector<Alumno> sol;
		for (auto it = escuela.begin(); it != escuela.end();it++)
		{
			if (it->second.profesor == p) {
				if (it->second.puntos >= n) {
					sol.push_back(it->first);
				}
			}
		}

		return sol;
	}
	
	void aprobar(const Alumno &a ) {
		auto it = escuela.find(a);

		if (it == escuela.end())
			throw std::domain_error("ERROR");

		else{
			escuela.erase(it);
		}
	}
};

#endif // !AUTOESCUELA_H
