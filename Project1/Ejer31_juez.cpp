// Luis Antonio rojas Ramirez
// e52


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using tMatriz = std::vector<std::vector<int>>;

bool esValida( const tMatriz &matriz, int k, int presupuesto, int notaMin, int &precioAct, const std::vector<bool> &marcado,int i) {
	bool valida = true;
	
	//la nota no supera la minima
	if (matriz[k][i] < notaMin)
		valida = false;

	//el precio actual supera al presupuesto
	if (precioAct > presupuesto)
		valida = false;

	//un actor no puede hacer dos veces el mismo papel
	if (marcado.at(i))
		valida = false;

	return valida;
}


// función que resuelve el problema
void vueltaAtras(std::vector<int> &sol,const tMatriz &matriz, const std::vector<int> &sueldos,int k,int numActores,int papeles,int presupuesto,int notaMin,bool &exito,int &notaAct,int &precioAct,int &notaMejor,int &precioMejor,std::vector<bool> &marcado, std::vector<int> &aux) {

	for (int i = 0; i < numActores; i++)
	{
		aux.at(k) = i;
		precioAct += sueldos.at(i);// marcamos tanto la nota como el precio que llevamos hasta el momento
		notaAct += matriz[k][i];

		if (esValida(matriz,k,presupuesto,notaMin,precioAct,marcado,i)){
			if (k == papeles - 1) {//es solucion
				exito = true; //actualizamos las notas en caso de ser mejores y el precio y nos quedamos con la solucion nueva
				if (notaAct >= notaMejor) {
					notaMejor = notaAct;
					precioMejor = precioAct;

					for (int i = 0; i < aux.size(); i++)
					{
						sol.at(i) = aux.at(i);
					}
				}
			}
			else {
				//if
				marcado.at(i) = true;
				vueltaAtras(sol,matriz,sueldos, k + 1,numActores,papeles, presupuesto,notaMin,exito,notaAct, precioAct,notaMejor,precioMejor,marcado,aux);
				marcado.at(i) = false;
			}
		}
		precioAct -= sueldos.at(i); //desmarcamos
		notaAct -= matriz[k][i];
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int papeles, numActores, presupuesto, min,notaAct = 0, precioAct = 0,notaMejor = INT_MIN,precioMejor = INT_MAX;
	bool exito = false;

	std::cin >> papeles >> numActores >> presupuesto >> min;
	
	std::vector<int> sol(papeles, -1);
	std::vector<int> sueldo(numActores);
	tMatriz matriz(papeles,std::vector<int>(numActores));
	std::vector<bool> marcado(numActores,false);
	std::vector<int> aux(papeles);

	if (papeles == 0 && numActores == 0 && presupuesto == 0 && min == 0)
		return false;


	for (int i = 0; i < numActores; i++)
	{
		std::cin >> sueldo[i];
	}

	for (int i = 0; i < papeles; i++)
	{
		for (int j = 0; j < numActores; j++)
		{
			std::cin >> matriz[i][j];
		}
	}


	vueltaAtras(sol, matriz,sueldo,0, numActores, papeles, presupuesto, min, exito, notaAct, precioAct,notaMejor,precioMejor,marcado,aux);

	// escribir sol

	if (exito) {
		std::cout << notaMejor << " " << precioMejor << "\n";

		for (int i = 0; i < papeles; i++)
		{
			std::cout << i << " " << sol.at(i) << "\n";
		}
	}else
		std::cout << "0" << " " << "0" << "\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos31.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}