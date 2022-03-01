/*
NOMBRE Y APELLIDOS DE LOS COMPONENTES DEL GRUPO QUE HAN 
REALIZADO LA PRÁCTICA:

Alejandro Barrachina Argudo

Rodrigo Sosa Saez

(si algún componente no ha realizado la práctica,
no debe aparecer)

*/
using namespace std;

#ifndef _MEMORIA_H_
#define _MEMORIA_H_

/// Excepción de direccion invalida
class DireccionInvalida {};


template<class T>
class Memoria {
public:
	/**
	 * crea una memoria
	 * @param defecto valor por defecto de las celdas
	 */
	Memoria(const T& defecto) {
		 // A IMPLEMENTAR
		_celdas = new T[TAM_INICIAL];
		for (int i = 0; i < TAM_INICIAL; ++i)
		{
			_celdas[i] = defecto;
		}
		_tamActual = TAM_INICIAL;
		_defaultValue = defecto;
	}

	Memoria(const Memoria& m)
	{
		_celdas = new T[m._tamActual];

		for (int i = 0; i < m._tamActual; ++i)
		{
			_celdas[i] = m._celdas[i];
		}

		_tamActual = m._tamActual;
		_defaultValue = m._defaultValue;
	}

	Memoria operator =(const Memoria& m)
	{
		if (_tamActual < m._tamActual)
		{
			redimensiona(m._tamActual - 1);
		}
		

		for (int i = 0; i < _tamActual; ++i)
		{
			_celdas[i] = m._celdas[i];
		}

		_defaultValue = m._defaultValue;

		return *this;
	}

	~Memoria()
	{
		delete[] _celdas;
		_celdas = nullptr;
	}

	/**
	 * Devuelve el contenido de una celda
	 * @param d dirección de la celda
	 */
	const T& fetch(int d) const {
		 // A IMPLEMENTAR
		if ( d < 0)
		{
			throw DireccionInvalida();
		}
		else if (d >= _tamActual)
		{
			return _defaultValue;
		}
		else
		{
			return _celdas[d];
		}
		
	}

	/**
	 * Almacena un valor en una celda
	 * @param d dirección de la celda
	 * @param v valor a almacenar
	 */
	void load(int d, const T& v) {
		 // A IMPLEMENTAR
		if (d < 0)
		{
			throw DireccionInvalida();
		}
		if (d >= _tamActual)
		{
			redimensiona(d);
		}

		_celdas[d] = v;
	}
	
	
     // DEBEN INCLUIRSE E IMPLEMENTARSE 
	 // LAS OPERACIONES ADICIONALES
	 // NECESARIAS PARA GARANTIZAR EL CORRECTO
	 // FUNCIONAMIENTO DEL TAD
	

private:
  // INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES

	T* _celdas = nullptr;
	const int TAM_INICIAL = 2;
	int _tamActual;
	T _defaultValue;

	void redimensiona(const int& d)
	{
		int tamAnterior = _tamActual;

		_tamActual = d + 1;

		T* aux = new T[_tamActual];

		for (int i = 0; i < tamAnterior; ++i)
		{
			aux[i] = _celdas[i];
		}
		for (int i = tamAnterior; i < _tamActual; ++i)
		{
			aux[i] = _defaultValue;
		}

		delete[] _celdas;

		_celdas = aux;
	}
};


#endif


