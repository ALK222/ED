/*
NUMERO DE GRUPO: 

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:


SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

#include <iostream>
#include <string>
#include "pila.h"
using namespace std;

bool es_pareja(char sim1, char sim2){
	bool pareja = false;
	if(sim1=='(' && sim2==')'){
		pareja = true;
	}
	else if(sim1=='[' && sim2==']'){
		pareja = true;
	}
	else if(sim1=='{' && sim2=='}'){
		pareja = true;
	}
	return pareja;
}

bool es_simbolo_cerrado(char caracter) {
	bool simbolo_cerrado = false;
	if(caracter==')' || caracter== ']' || caracter=='}'){
		simbolo_cerrado = true;
	}
	return simbolo_cerrado;
}

bool es_simbolo_abierto(char caracter) {
	bool simbolo_abierto = false;
	if(caracter=='(' || caracter== '[' || caracter=='{'){
		simbolo_abierto = true;
	}
	return simbolo_abierto;
}

bool esEquilibrada(const string& cadena) {
	// A IMPLEMENTAR
	bool es_eq = true;
	int sim_abiertos = 0;
	int sim_cerrados = 0;
	Pila<char> simbolos;

	for(int i=0;i<cadena.length();i++){
		if(es_simbolo_abierto(cadena[i])){
			sim_abiertos+=1;
			simbolos.apila(cadena[i]);
		}
		else if(es_simbolo_cerrado(cadena[i])){
			sim_cerrados+=1;
			if(!simbolos.esVacia() && es_pareja(simbolos.cima(),cadena[i])){
				simbolos.desapila();
			}
			else{
				es_eq = false;
			}
		}
	}
	if(sim_abiertos!=sim_cerrados){
		es_eq=false;
	}

	return es_eq;
}


int main() {
	string cadena;
    while(getline(cin, cadena)) {
      if(esEquilibrada(cadena))
        cout << "EQUILIBRADA" << endl;
      else
        cout << "NO_EQUILIBRADA" << endl;
	}
	return 0;
}
