#include "GestionAdmisiones.h"


/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 coste O(1), la creación de objetos es constante
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR
	_pacientes = Diccionario<CodigoPaciente, tPaciente>();
	_cola = Lista<CodigoPaciente>();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(N), siendo n el número de pacientes totales
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas) {
	// A IMPLEMENTAR
	if (_pacientes.contiene(codigo))
	{
		throw EPacienteDuplicado();
	}
	_pacientes.inserta(codigo, { nombre, edad, sintomas });
	_cola.pon_final(codigo);
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(logN) ya que solo busca en parte del diccionario
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENTAR
	if (!_pacientes.contiene(codigo))
	{
		throw EPacienteNoExiste();
	}

	tPaciente aux = _pacientes.valorPara(codigo);

	nombre = aux.nombre;
	edad = aux.edad;
	sintomas = aux.sintomas;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(1), comprobar si es vacio y sacar el primer valor es coste constante
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo) const {
  // A IMPLEMENTAR
	if (_cola.esVacia())
	{
		throw ENoHayPacientes();
	}

	codigo = _cola.primero();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(1), comprobar si es vacio es constante
*/
bool GestionAdmisiones::hay_pacientes() const {  
  // A IMPLEMENTAR
	return !_cola.esVacia();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(N) ya que se realiza una busqueda sobre la lista
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	// A IMPLEMENTAR
	if (_pacientes.contiene(codigo))
	{
		_pacientes.borra(codigo);

		auto paciente = _cola.begin();
		bool encontrado = false;

		while (paciente != _cola.end() && !encontrado)
		{
			if (paciente.elem() == codigo)
			{
				encontrado = true;
			}
			else
			{
				paciente.next();
			}
		}

		if (encontrado)
		{
			_cola.eliminar(paciente);
		}
	}
}
   
