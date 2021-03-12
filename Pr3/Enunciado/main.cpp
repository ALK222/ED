/*
NUMERO DE GRUPO:

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

#include <iostream>
#include <string>
using namespace std;



bool esEquilibrada(const string& cadena) {
	// A IMPLEMENTAR
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
