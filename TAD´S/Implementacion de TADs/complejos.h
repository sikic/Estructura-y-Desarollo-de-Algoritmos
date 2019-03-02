#ifndef COMPLEJOS
#define COMPLEJOS

#include <iostream>
#include <fstream>

class complejos {

private:

	float real;
	float imaginario;

public:

	complejos() {};
	complejos(float  r,float i):real(r),imaginario(i){} ;

	float get_real() const { return real; };
	float get_imaginario() const { return imaginario; };
	

	//operadores

	complejos operator+ (complejos const &complejo){

		return complejos((real + complejo.real),(imaginario + complejo.imaginario));
	}

	complejos operator* (complejos const  &complejo) {

		return complejos(((real * complejo.real-imaginario * complejo.imaginario)),(((real * complejo.imaginario + complejo.real * imaginario))));
	}
	
};

inline std::istream& operator >> (std::istream& in,complejos &complejo){
	
	float r, i;

	in >> r >> i;

	complejo = complejos(r,i);

	return in;
}

#endif // !COMPLEJOS

