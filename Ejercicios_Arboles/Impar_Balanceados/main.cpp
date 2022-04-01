/*
NOMBRE Y APELLIDOS DE LOS COMPONENTES DEL GRUPO QUE HAN
REALIZADO LA PRÁCTICA: Alejandro Barrachina Argudo, Rodrigo Sosa Saez


(si algún componente no ha realizado la práctica,
no debe aparecer)

*/

#include <iostream>
#include <string>
using namespace std;
#include "Arbin.h"

int imparBalanceadosAux(const Arbin<int>& a, int& totalBal)
{
	if (a.esVacio())
	{
		return 0;
	}
	if (a.hijoDer().esVacio() && a.hijoIz().esVacio())
	{
		totalBal++;
		return a.raiz() % 2 == 0 ? 0 : 1;
	}
	else
	{
		int balIzq = imparBalanceadosAux(a.hijoIz(), totalBal);
		int balDer = imparBalanceadosAux(a.hijoDer(), totalBal);
		if (balIzq == balDer)
		{
			totalBal++;
		}
		return a.raiz() % 2 == 0 ? balIzq + balDer : balIzq + balDer + 1;
	}
	
}

/*
   DETERMINACION JUSTIFICADA DE LA COMPLEJIDAD:

   Como sabemos que esta es la implementación eficiente del Arbin, el coste de sus operaciones es O(1).
   Teniendo en cuenta que el coste del algoritmo es el numero de veces que se ejecutan las operaciones dentro de imparBalanceadoAux
   el coste del algoritmo será de orden O(n) (siendo n el numero de nodos del arbol), ya que recorre todos los nodos del arbol  una sola vez.

*/
int num_imparBalanceados(const Arbin<int>& a) {
	// A IMPLEMENTAR
	int totalBalan = 0;
	imparBalanceadosAux(a, totalBalan);
	return totalBalan;
}


// NO MODIFICAR NADA A PARTIR DE AQUI

Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		Arbin<int> a = lee_arbol(cin);
		cout << num_imparBalanceados(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}