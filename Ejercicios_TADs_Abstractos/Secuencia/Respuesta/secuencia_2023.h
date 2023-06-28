//LA DIFERENCIA CON EL ORIGINAL ESTA EN LOS NULLS

#ifndef _SECUENCIA_H_
#define _SECUENCIA_H_

/// Excepción de elemento inexistente
class ElementoInvalido {};


template<class T>
class Secuencia {
public:
	Secuencia() {
		// A IMPLEMENTAR
		_secuencia = new T[TAM_INICIAL];
		_tam_actual = 0;
		_tam_max = TAM_INICIAL;
	}

	Secuencia(const Secuencia& s) {
		_secuencia = new T[s._tam_actual];
		for (int i = 0; i < s._tam_actual; i++) {
			_secuencia[i] = s._secuencia[i];
		}
		_tam_actual = s._tam_actual;
		_tam_max = s._tam_max;
	}

	~Secuencia() {
		delete[] _secuencia;
		T* _secuencia;
	}

	Secuencia& operator=(const Secuencia& s) {
		while (_tam_max < s._tam_actual) {
			redimensionar();
		}
		for (int i = 0; i < s._tam_actual; i++) {
			_secuencia[i] = s._secuencia[i];
		}
		_tam_actual = s._tam_actual;
		_tam_max = s._tam_max;
		return *this;
	}

	void pon(const T& e) {
		// A IMPLEMENTAR
		if (_tam_actual == _tam_max) {
			redimensionar();
		}
		_secuencia[_tam_actual] = e;
		_tam_actual++;
	}

	const T& elem(int i) {
		// A IMPLEMENTAR
		if (i >= _tam_actual) {
			throw ElementoInvalido();
		}
		else {
			return _secuencia[i];
		}
	}

	int num_elems() const {
		// A IMPLEMENTAR
		return _tam_actual;
	}

     // DEBEN INCLUIRSE E IMPLEMENTARSE 
	 // LAS OPERACIONES ADICIONALES
	 // NECESARIAS PARA GARANTIZAR EL CORRECTO
	 // FUNCIONAMIENTO DEL TAD


private:
  // INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES
	static const int TAM_INICIAL = 2;
	T* _secuencia;
	int _tam_actual;
	int _tam_max;

	void redimensionar() {
		_tam_max = _tam_max * 2;
		T* aux = new T[_tam_max];
		for (int i = 0; i < _tam_actual; i++) {
			aux[i] = _secuencia[i];
		}
		delete[] _secuencia;
		_secuencia = aux;
	}
};


#endif


