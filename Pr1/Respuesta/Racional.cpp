/*
NUMERO DE GRUPO: **

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:

Bad Bunny
C. Tangana

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

#include "Racional.h"
#include <cmath>

  //Metodos publicos

  	//**** COMPLETAR
	//  Deben implementarse los metodos publicos de la clase
	//****

// constructores

Racional::Racional(){
	_numer = 0;
	_denom = 1;
}
Racional::Racional(long numer, long denom){
	if(denom==0){
		throw EDenominadorCero();
	}else{
		_numer = numer;
		_denom = denom;
		reduce();
	}
}

//operaciones

Racional Racional::suma(const Racional& r) const {
	long a = (_numer*(mcm(_denom,r._denom)/_denom)) + ( r._numer * (mcm(_denom,r._denom)/r._denom));
	long b = mcm(_denom,r._denom);
	return Racional(a,b);
}

Racional Racional::operator -(const Racional& r) const {
	long a = (_numer*(mcm(_denom,r._denom)/_denom)) - ( r._numer * (mcm(_denom,r._denom)/r._denom));
	long b = mcm(_denom,r._denom);
	return Racional(a,b);
}

Racional& Racional::operator *=(const Racional& r)  {
	long a = _numer * r._numer;
	long b = _denom * r._denom;
	_numer = a;
	_denom = b;
	reduce();
	return *this;
}

Racional& Racional::divideYActualiza(const Racional& r) {
	if(r._numer==0 && r._denom==1){
		throw EDivisionPorCero();
	}
	else{
		long a = _numer * r._denom;
		long b = _denom * r._numer;
		_numer = a;
		_denom = b;
		reduce();
	}
	return *this;
}

bool Racional::operator==(const Racional& r) {
	return (_numer == r._numer) && (_denom == r._denom);
}
 
  
  // Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

