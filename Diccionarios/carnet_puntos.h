#ifndef CARNET_PUNTOS
#define CARNET_PUNTOS

#include <iostream>
#include <array>
#include <stdexcept>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<unordered_map>

struct tListar {
	std::string dni;
	int posicion;
};
struct tPuntos {
	int puntos;
	int posicion;
};
using  DNI = std::string;//La clave del mapa es el DNI del conductor
using puntos = int;//El valor son los puntos del carnet del conductor


class carnet_puntos {

private: std::unordered_map<DNI,tPuntos> carnets;
		 std::vector<int> nPuntos;
public:
	carnet_puntos() {
		nPuntos = std::vector<int>(16);
	};

	void nuevo(const DNI &n) {
		auto it = carnets.find(n);
		if (it == carnets.end()) {
			carnets.insert({ n, {15,nPuntos[15]} });
			nPuntos.at(15)++;
		}
		else throw std::domain_error("Conductor duplicado");
	}
	void quitar(const DNI &n, const puntos &p) {
		auto it = carnets.find(n);
		if (it == carnets.end())  throw std::domain_error("Conductor inexistente");
		else {
			if (it->second.puntos < p) {
				nPuntos.at(it->second.puntos)--;
				it->second.puntos = 0;
				it->second.posicion = nPuntos[0];
				nPuntos.at(0)++;
			}
			else {
				nPuntos.at(it->second.puntos)--;
				it->second.puntos -= p;
				it->second.posicion = nPuntos[it->second.puntos];
				nPuntos.at(it->second.puntos)++;

			};

		}
	}

	void recuperar(const DNI &n,const puntos &p) {
		auto it = carnets.find(n);
		if (it == carnets.end())  throw std::domain_error("Conductor inexistente");
		else {
			if (it->second.puntos + p > 15) {
				nPuntos.at(it->second.puntos)--;
				it->second.puntos = 15;
				it->second.posicion = nPuntos[15];
				nPuntos.at(15)++;
			}
			else {
				nPuntos.at(it->second.puntos)--;
				it->second.puntos += p;
				it->second.posicion = nPuntos[it->second.puntos];
				nPuntos.at(it->second.puntos)++;

			}
		}

	}
	int consultar(const DNI &n) {
		auto it = carnets.find(n);
		if (it == carnets.end()) throw std::domain_error("Conductor inexistente");
		else return it->second.puntos;

	}
	int cuantos_con_puntos(const puntos &p) {
		if (p < 0 || p >15) throw std::domain_error("Puntos no validos");
		else {
			return nPuntos.at(p);
		}
	}

	std::vector<tListar> lista_puntos(const puntos &p){
		if (p < 0 || p >15) throw std::domain_error("Puntos no validos");

		std::vector<tListar> soli;
		
		for (auto i = carnets.begin(); i != carnets.end(); i++)
		{
			if (i->second.puntos == p)
				soli.push_back({i->first,i->second.posicion});
		}

		return soli;
	}
};
#endif // !carmet