/**
  NOMBRE Y APELLIDOS:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "centroSalud.h"

#include <iostream>
using namespace std;

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
CentroSalud::CentroSalud()
{
	// A IMPLEMENTAR
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
void CentroSalud::annadir_medico(tNumColegiado num_colegiado, tNumPacientes num_pacientes)
{
	// A IMPLEMENTAR
	if (_listadoMedicos.contiene(num_colegiado))
	{
		throw EMedicoExistente();
	}

	_listadoMedicos.inserta(num_colegiado, num_pacientes);
	_citados.inserta(num_colegiado, Lista<tCodigoPaciente>());
	_medicoPorPaciente.inserta(num_colegiado, Diccionario<tCodigoPaciente, tNombre>());
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
void CentroSalud::annadir_paciente(tCodigoPaciente codigo_id, tNombre nombre, tNumColegiado num_colegiado)
{
	// A IMPLEMENTAR
	if (!_listadoMedicos.contiene(num_colegiado) || _listadoPacientes.contiene(codigo_id))
	{
		throw EIncorporacionNoAdmitida();
	}
	else
	{
		_listadoPacientes.inserta(codigo_id, nombre);
		_pacientesPorMedico.inserta(codigo_id, num_colegiado);

		_medicoPorPaciente.busca(num_colegiado).valor().inserta(codigo_id, nombre);
	}
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
bool CentroSalud::citar(tCodigoPaciente codigo_id)
{
	// A IMPLEMENTAR
	if (!_listadoPacientes.contiene(codigo_id))
	{
		throw ECitaNoAdmitida();
	}
	tNumColegiado medico = _pacientesPorMedico.busca(codigo_id).valor();
	if (_turnos.contiene(codigo_id) || _citados.busca(medico).valor().longitud() >= _listadoMedicos.busca(medico).valor())
	{
		return false;
	}

	_citados.busca(medico).valor().pon_ppio(codigo_id);
	auto turno = _citados.busca(medico).valor().begin();

	_turnos.inserta(codigo_id, turno);

	return true;
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
const Lista<tCodigoPaciente> &CentroSalud::citados(tNumColegiado num_colegiado) const
{
	// A IMPLEMENTAR
	if (!_listadoMedicos.contiene(num_colegiado))
	{
		throw EMedicoInexistente();
	}

	return _citados.cbusca(num_colegiado).valor();
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
bool CentroSalud::cancelar_cita(tCodigoPaciente codigo_id)
{
	// A IMPLEMENTAR
	if (!_listadoPacientes.contiene(codigo_id))
	{
		throw ECancelacionNoAdmitida();
	}

	if (!_turnos.contiene(codigo_id))
	{
		return false;
	}

	auto turno = _turnos.busca(codigo_id).valor();
	tNumColegiado medico = _pacientesPorMedico.busca(codigo_id).valor();
	_citados.busca(medico).valor().eliminar(turno);
	_turnos.borra(codigo_id);

	return true;
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n

*/
Lista<Codigo_y_Nombre> CentroSalud::vinculados(tNumColegiado num_colegiado) const
{
	// A IMPLEMENTAR
	if (!_listadoMedicos.contiene(num_colegiado))
	{
		throw EMedicoInexistente();
	}
	auto listadoPacientes = _medicoPorPaciente.cbusca(num_colegiado).valor();
	Lista<Codigo_y_Nombre> aux;
	for (auto it = listadoPacientes.cbegin(); it != listadoPacientes.cend(); it.next())
	{
		Codigo_y_Nombre aux2;
		aux2.codigo = it.clave();
		aux2.nombre = it.valor();
		aux.pon_final(aux2);
	}

	return aux;
}
