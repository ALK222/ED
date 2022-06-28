/**
  NOMBRE Y APELLIDOS:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include <iostream>
#include <string>
using namespace std;
#include "Arbin.h"

void esJugableAux(const Arbin<int> &juego, int energia_inicial, bool &ganado, bool &perdido)
{
	if (energia_inicial <= 0)
	{
		perdido = true; // se pierde la partida
	}
	else if (juego.hijoDer().esVacio() && juego.hijoIz().esVacio())
	{
		ganado = true; // Llegamos al final
	}
	else if (juego.hijoIz().esVacio())
	{
		esJugableAux(juego.hijoDer(), energia_inicial - juego.raiz(), ganado, perdido); // Se supera el obstaculo
	}
	else if (juego.hijoDer().esVacio())
	{
		esJugableAux(juego.hijoIz(), energia_inicial + juego.raiz(), ganado, perdido); // Se encuentra alimento
	}
	else
	{
		bool ganadoDerecha = false;
		bool perdidoDerecha = false;
		esJugableAux(juego.hijoDer(), energia_inicial - juego.raiz(), ganadoDerecha, perdidoDerecha); // Perdemos la pelea
		bool ganadoIzquierda = false;
		bool perdidoIzquierda = false;
		esJugableAux(juego.hijoIz(), energia_inicial, ganadoIzquierda, perdidoIzquierda); // Ganamos la pelea
		ganado = ganadoDerecha || ganadoIzquierda;										  // comprobamos si se gana en alguna de las dos ramas
		perdido = perdidoDerecha || perdidoIzquierda;									  // comprobamos si perdemos en alguna de las dos ramas
	}
}
/*
 COMPLEJIDAD: Determinar justificadamente la complejidad del algoritmo



*/
bool es_jugable(const Arbin<int> &juego, int energia_inicial)
{
	/* A IMPLEMENTAR*/

	bool ganado = false;
	bool perdido = false;
	esJugableAux(juego, energia_inicial, ganado, perdido);

	return ganado && perdido;
}

Arbin<int> lee_arbol(istream &in)
{
	char c;
	in >> c;
	switch (c)
	{
	case '#':
		return Arbin<int>();
	case '[':
	{
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(':
	{
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default:
		return Arbin<int>();
	}
}
/*
El formato de la entrada es como sigue:
- Cada línea contiene la descripción del árbol del juego, seguida de la energía inicial.
- Para describir los árboles se sigue el siguiente convenio:
* Los árboles vacíos se escriben como #
* Los árboles simples se escriben como [c], con c el contenido del nodo.
* Los árboles compuestos se escriben como (IcD), donde:  (i) I es el hijo izquierdo; (ii) c es el contenido de la raíz; (iii) D es el hijo derecho.
El programa imprime SI si el juego es jugable, NO en otro caso.
La entrada termina con una línea que contiene únicamente #.
Ejemplo de entrada / salida:
Entrada:
((#4[0])5([0]4#)) 5
((#4[0])5([0]4#)) 4
((#4[0])5([0]4#)) 6
([0]5[0]) 5
([0]5[0]) 4
([0]5[0]) 6
#
Salida:
SI
NO
NO
SI
SI
NO
*/

bool ejecuta_caso()
{
	Arbin<int> a = lee_arbol(cin);
	if (a.esVacio())
		return false;
	else
	{
		int e;
		cin >> e;
		if (es_jugable(a, e))
			cout << "SI";
		else
			cout << "NO";
		cout << endl;
		return true;
	}
}

int main()
{
	Arbin<int> arbol;
	while (ejecuta_caso())
		;
	return 0;
}
