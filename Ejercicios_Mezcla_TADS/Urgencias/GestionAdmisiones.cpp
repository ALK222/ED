#include "GestionAdmisiones.h"

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 coste O(1), la creación de objetos es constante
*/
GestionAdmisiones::GestionAdmisiones()
{
	// A IMPLEMENTAR
	_pacientes = Diccionario<CodigoPaciente, tPaciente>();
	_cola = Lista<CodigoPaciente>();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(N), siendo n el número de pacientes totales
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string &nombre, unsigned int edad, const string &sintomas)
{
	// A IMPLEMENTAR
	if (_pacientes.contiene(codigo))
	{
		throw EPacienteDuplicado();
	}
	_cola.pon_ppio(codigo);
	_pacientes.inserta(codigo, {nombre, edad, sintomas, _cola.begin()});
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(logN) ya que solo busca en parte del diccionario
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string &nombre, unsigned int &edad, string &sintomas) const
{
	// A IMPLEMENTAR
	if (!_pacientes.contiene(codigo))
	{
		throw EPacienteNoExiste();
	}

	auto aux = _pacientes.cbusca(codigo);

	nombre = aux.valor().nombre;
	edad = aux.valor().edad;
	sintomas = aux.valor().sintomas;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(1), comprobar si es vacio y sacar el primer valor es coste constante
*/
void GestionAdmisiones::siguiente(CodigoPaciente &codigo) const
{
	// A IMPLEMENTAR
	if (_cola.esVacia())
	{
		throw ENoHayPacientes();
	}

	codigo = _cola.ultimo();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(1), comprobar si es vacio es constante
*/
bool GestionAdmisiones::hay_pacientes() const
{
	// A IMPLEMENTAR
	return !_cola.esVacia();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
 Complejidad O(logN) ya que solo busca en parte del diccionario
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo)
{
	// A IMPLEMENTAR
	const auto it = _pacientes.busca(codigo);
	if (it != _pacientes.end())
	{
		_cola.eliminar(it.valor().pos);
		_pacientes.borra(codigo);
	}
}
