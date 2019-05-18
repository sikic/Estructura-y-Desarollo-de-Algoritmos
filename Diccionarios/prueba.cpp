#include <iostream>
#include <map>
#include <string>
#include <utility>
 /**/
class cmp {
public:
	int valor;
	std::string nombre;
	
	cmp(std::string nom,int a) {
		valor = a;
		nombre = nom;
	}

};

class x {
public:
	bool operator()(cmp const &a, cmp const &b)const {
		if (a.valor != b.valor)
			return a.valor > b.valor;
		else
			return a.nombre < b.nombre;
	}
};
int main() {
	std::map<cmp,int,x> ej;

	cmp aux("aaa",3);
	ej.insert({aux,3});

	cmp aux1("ccc", 2);
	ej.insert({ aux1,2 });

	cmp aux2("bbb", 1);
	ej.insert({ aux2,1 });

	cmp aux3("ddd", 1);
	ej.insert({ aux3,1});

	for (auto i = ej.begin(); i != ej.end(); i++)
	{

		std::cout << i->first.nombre << " " << i->second << "\n";
	}
	
	return 0;
}