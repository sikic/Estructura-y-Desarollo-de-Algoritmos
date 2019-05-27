#ifndef IPUD_H
#define IPUD_H

#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<list>
#include<sstream>

using Cancion = std::string;
using Autor = std::string;
using Duracion = int;

struct InfoCancion{
	Autor autor;
	Duracion duracion;
	bool reproducida;
	bool esta_enLista;
	std::list<Cancion>::iterator pos_reproducida;
	std::list<Cancion>::iterator pos_reciente;

};

class ipud{
private:
	std::unordered_map<Cancion, InfoCancion> ipod;
	std::list<Cancion> listaReproduccion;
	std::list<Cancion> recientes;
	int tiempoTotal;
	
public:

	ipud() {
		tiempoTotal = 0;
	};

	void addSong(const Autor &a, const Cancion &c, const Duracion &d) {
		auto it = ipod.find(c);

		if (it == ipod.end())
			ipod.insert({ c,{a,d,false,false,listaReproduccion.end(),recientes.end()} });
		else
			throw std::domain_error("ERROR addSong");
	}

	void addToPlaylist(const Cancion &c) {
		auto it = ipod.find(c);

		if (it == ipod.end()) //cancion no esta en el ipod
			throw std::domain_error("ERROR addToPlaylist");
		else {//esta en el ipod

			//buscamos si se ha reproducido
			if (!it->second.esta_enLista) {//no estaba en la lista de reproduccion pues la añadimos
				listaReproduccion.push_back(c);
				it->second.esta_enLista = true;
				it->second.pos_reproducida = --listaReproduccion.end();
				tiempoTotal += it->second.duracion;
			}
		}
	}

	Cancion current() {
		if (listaReproduccion.empty())
			throw std::domain_error("ERROR current");
		else
			return listaReproduccion.front();
	}

	void play(){
		if (!listaReproduccion.empty()) {
			//primera cancion de la lista
			Cancion aux = listaReproduccion.front();

			//la buscamos en el ipod y restamos su tiempo y ponemos que se ha reproduciod
			auto it = ipod.find(aux);

			//si ya esta en la lista
			if (/*it->second*/ipod[aux].reproducida){
				//borrar(recientes, aux);
				recientes.erase(ipod[aux].pos_reciente);
			}
				tiempoTotal -= it->second.duracion;
				it->second.reproducida = true;

				//La añadimos a recientes
				recientes.push_back(aux);
				it->second.pos_reciente = --recientes.end();
				//la borramos de la lista de reproduccion
				it->second.esta_enLista = false;
				it->second.pos_reproducida = listaReproduccion.end();
				listaReproduccion.pop_front();
		}
	}

	int totalTime() {
		return tiempoTotal;
	}

	std::vector<Cancion> recent(int &n) {
		std::vector<Cancion> sol;
		if (n > (int)recientes.size())//hacemos que se reproduzca  toda la lista
			n = (int)recientes.size();

		auto it = recientes.begin();

		for (int i = 0; i < n; i++)
		{
			sol.push_back(*it);
			it++;
		}
		return sol;
	}

	void deleteSong(const Cancion &c) {
		//borramos la cancion del ipod y de la lista de reproduccion y de la de recientes
		auto it = ipod.find(c);

		if (it != ipod.end()) {
			

			if (it->second.esta_enLista){

				listaReproduccion.erase(it->second.pos_reproducida);
				tiempoTotal -= it->second.duracion;
			}
			if (it->second.reproducida)
			
				recientes.erase(it->second.pos_reciente);

		ipod.erase(c);
		}
	}

	bool esVacia() {
		return listaReproduccion.empty();
	}

};
#endif // !IPUD_H
