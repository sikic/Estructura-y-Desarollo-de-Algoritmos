// Luis Antonio Rojas Ramirez
// E52

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits.h>

using tMatriz = std::vector < std::vector<int>>;


bool esValida (int i,int presupuesto,int precioActual, const std::vector<int> &cont, int &mejorprecio) {

	bool valida = true;

	// que no se salga de mi presupuesto
	if (precioActual > presupuesto)
		valida = false;

	//no puedo ir dos veces a una misma ciudad
	if (cont.at(i) > 1)
		valida = false;


	if (precioActual > mejorprecio) // si el precio actual sobrepasa a nuestro mejor  ya no nos interesa mirar
		valida = false;

	return valida;
}



bool esSolucion(const tMatriz &matriz,const std::vector<int> &sol, int k, int presupuesto, int &precioActual){

	// miramos si una vez recorridas todas las ciudades nos da el dinero para ir a casa
	if ((precioActual + matriz[sol.at(k)][0]) > presupuesto)
		return false;
	else 
		return true;
}

// función que resuelve el problema
void vueltaAtras(const std::vector<int> &precioBaja, const std::vector<int> &precioAlta, const tMatriz &matriz, std::vector<int> &sol, int k, int nCiudades, int presupuesto, int &precioActual, int tempBaja, bool &exito, int &mejorprecio, std::vector<int> &cont,const std::vector<int> &acumulados) {

	
	for (size_t i = 1; i < nCiudades + 1; i++)
	{

		sol.at(k) = i;

		cont.at(i)++;// marcamos la ciudad a la que hemos ido

		if (k  >= tempBaja) //estoy en el dia que inicia la temp baja de hoteles
			precioActual += matriz[sol.at(k-1)][i] + precioBaja.at(i - 1);
		else  // estoy en temporada alta de hoteles
			precioActual += matriz[sol.at(k-1)][i] + precioAlta.at(i - 1);

		if (esValida(i, presupuesto, precioActual, cont, mejorprecio)) {
			if (k == nCiudades) {
				if (esSolucion(matriz, sol, k, presupuesto, precioActual)){
					precioActual += matriz[sol.at(k)][0]; //sumamos el billete de vuelta a casa

					if (precioActual < mejorprecio)
						mejorprecio = precioActual;

					exito = true;
					precioActual -= matriz[sol.at(k)][0]; // desmarcamos el billete de destino a casa para buscar más opciones
				}
				
			}
			else {
				if (((acumulados.at(nCiudades) - acumulados.at(k) + precioActual) < mejorprecio))
					vueltaAtras(precioBaja, precioAlta, matriz, sol, k + 1, nCiudades, presupuesto, precioActual, tempBaja, exito, mejorprecio, cont,acumulados);
			}

			
		}
		cont.at(i)--; // desmarcamos lo de arriba
		if (k >= tempBaja)
			precioActual -= matriz[sol.at(k-1)][i] + precioBaja.at(i - 1);
		else
			precioActual -= matriz[sol.at(k-1)][i] + precioAlta.at(i - 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCiudades, iniBaja, presupuesto,aux,precioActual = 0,mejorprecio = INT_MAX,costeminimo,costeEficiente = 0 ,anterior = 0;
	bool exito = false;

	std::cin >> numCiudades >> iniBaja >> presupuesto;

	if (numCiudades == 0 && iniBaja == 0 && presupuesto == 0)
		return false;

	std::vector<int> precioBaja(numCiudades);
	std::vector<int> precioAlta(numCiudades);
	std::vector<int> cont(numCiudades + 1);
	std::vector<int> acumulados(numCiudades + 1);

	for (int i= 0; i < numCiudades; i++)
	{
		std::cin >> aux;
		precioAlta.at(i) = aux;
	}

	for (int j = 0; j < numCiudades; j++)
	{
		std::cin >> aux;
		precioBaja.at(j) = aux;
	}

	tMatriz matriz(numCiudades + 1,std::vector<int>(numCiudades + 1));

	for (int i = 0; i < numCiudades + 1; i++)
	{
		
		std::cin >> costeEficiente;
		matriz[i][0] = costeEficiente;

		for (int j = 1; j < numCiudades + 1; j++)
		{
			std::cin >> aux;
			matriz[i][j] = aux;

			if (costeEficiente < matriz[i][j])
				costeEficiente = matriz[i][j];
		}
		acumulados.at(i) = costeEficiente + anterior;
		anterior = acumulados.at(i);
	}

	std::vector<int> sol(numCiudades + 1,-1);
	sol[0] = 0;
	
	vueltaAtras(precioBaja,precioAlta, matriz, sol,1, numCiudades, presupuesto, precioActual,iniBaja,exito,mejorprecio,cont,acumulados);

	// escribir sol

	if (exito)
		std::cout << mejorprecio << "\n";
	else
		std::cout << "No puedes ir \n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos32.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}