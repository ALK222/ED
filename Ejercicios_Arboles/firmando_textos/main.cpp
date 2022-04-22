/*
NOMBRE Y APELLIDOS DE LOS COMPONENTES DEL GRUPO QUE HAN
REALIZADO LA PRÁCTICA: Alejandro Barrachina Argudo y Rodrigo Sosa Saez


(si algún componente no ha realizado la práctica,
no debe aparecer)

*/

#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;


typedef Lista<string> tTexto; // Representación del texto

typedef Lista<int> tFirma;    // Representación de la firma



void construye_firma(const tTexto& texto, tFirma& firma) {
	// A implementar: en 'firma' debe almacenarse la firma de 'texto'

	auto itTexto = texto.cbegin();
	Diccionario<string, int> sol = Diccionario<string, int>();

	while (itTexto != texto.cend())
	{
		if (sol.contiene(itTexto.elem()))
		{
			sol.inserta(itTexto.elem(), sol.valorPara(itTexto.elem())+1);
		}
		else
		{
			sol.inserta(itTexto.elem(), 1);
		}
		itTexto.next();
	}

	Diccionario<int, string> sol2 = Diccionario<int, string>();

	auto itSol = sol.cbegin();

	while (itSol != sol.cend())
	{
		if (!sol2.contiene(itSol.valor()))
		{
			sol2.inserta(itSol.valor(), itSol.clave());
		}
		itSol.next();
	}

	auto itSol2 = sol2.cbegin();
	while(itSol2 != sol2.cend())
	{
		firma.insertar(itSol2.clave(), firma.end());
		itSol2.next();
	}
}

// NO MODIFICAR
bool lee_texto(tTexto& texto) {
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
		for (int i = 0; i < n; i++) {
			string palabra;
			cin >> palabra;
			texto.pon_final(palabra);
		}
		return true;
	}
}

bool ejecuta_caso() {
	tTexto texto;
	if (lee_texto(texto)) {
		tFirma firma;
		construye_firma(texto, firma);
		for (int i = 0; i < firma.longitud(); i++) {
			cout << firma.elem(i) << " ";
		}
		cout << endl;
		return true;
	}
	else {
		return false;
	}
}


int main() {
	while (ejecuta_caso());
}