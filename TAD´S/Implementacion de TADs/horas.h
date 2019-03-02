#ifndef HORAS
#define HORAS

//Bibliotecas
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <limits>

class horas{
private:
	int hora, minutos, segundos;

public:

	horas() {};

	horas(int h, int m,int s): hora(h),minutos(m),segundos(s){

		if (h < 0 || h > 23) throw std::invalid_argument("ERROR");

		else if(m < 0 || m > 59) throw std::invalid_argument("ERROR");

		else if(s < 0 || s > 59) throw std::invalid_argument("ERROR");
	};

	int getHoras() const { return hora; };
	int getMinutos() const { return minutos; };
	int getSegundos() const { return segundos; };

	/*esta funcion nos dira cual es el minimo numero de segundos entre una hora y los horarios de los trenes , quedandonos con aquella
	que menos tarde, si se devuelve un -1 es que no se ha encontrado ninguna hora*/

	int horaCorrecta(const std::vector<horas> &v) { 
		
		int pos = -1;
		bool encontrado = false;

		for (int i = 0; i < v.size() && !encontrado; i++)
		{
			if (*this < v[i] || *this == v[i]) { // buscamos una mas pequeña que la actual descartando los trenes que ya se han ido
				pos = i;
				encontrado = true;
			}
		}

		return pos;
	}


// operadores de comparacion
	bool operator<(horas const &htren) const {
		if (hora < htren.hora) return true;
		else if (hora > htren.hora) return false;
		else if (hora == htren.hora && minutos < htren.minutos) return true;
		else if (hora == htren.hora && minutos > htren.minutos)  return false;
		else if (hora == htren.hora && minutos == htren.minutos && segundos < htren.segundos) return true;
		else return false;
	}

	bool operator==(horas const &htren) const{
		return ((hora == htren.hora) && (minutos == htren.minutos) && (segundos == htren.segundos));

	}

	horas operator+ (horas const &h) const {

		int hor=0, m = 0, s;

		s = segundos + h.segundos;

		if (s > 59) { // si los segundos pasan de 60 lo trasformas en minutos
			m = s / 60;
			s = s % 60;
		}

		m += minutos + h.minutos;
		
		if (m > 59) { // los minutos pasan a ser horas

			hor = m / 60;
			m = m % 60;
		}
		
		hor += hora + h.hora;

		if (hor > 23) throw std::invalid_argument("ERROR");

		return horas(hor, m, s);
	}
		
};

	inline std::ostream& operator<< (std::ostream& out, horas const& h) {
		out << std::setfill('0') << std::setw(2) << h.getHoras()
			<<":" << std::setfill('0') << std::setw(2) << h.getMinutos() << ":"
			<< std::setfill('0') << std::setw(2) << h.getSegundos();
		return out;
	};

	inline std::istream& operator >>(std::istream& in, horas & hora) {
		int h, m, s;
		char aux;
		
		in >> h >> aux  >> m >> aux >> s;
		hora = horas(h,m,s);
		return in;
	};
	


#endif // !horas
