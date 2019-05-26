#ifndef Fecha_h
#define Fecha_h

//blibliotecas
#include <iostream>
#include <iomanip>
#include <fstream>

class fecha {
private:
	int dia,horas, minutos;
public:
	fecha() {};
	fecha(int d, int h, int m) {
		dia = d;
		horas = h;
		minutos = m;
	}

	int getDia() const {
		return dia;
	}

	int getHora() const {
		return horas;
	}
	int getMinutos() const {
		return minutos;
	}
	bool operator< (fecha &f) const {
		if (dia != f.dia)
			return dia < f.dia;
		else {
			if (horas != f.horas)
				return horas < f.horas;
			else 
				return minutos < f.minutos;
				
		}
	}
	
};

#endif // !Fecha_h






