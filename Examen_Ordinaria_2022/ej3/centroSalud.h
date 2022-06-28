/**
  NOMBRE Y APELLIDOS:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#ifndef _centroSalud_H
#define _centroSalud_H

#include "lista.h"
#include "Diccionario.h"
#include <string>
using namespace std;

// clases para las excepciones
class EMedicoExistente
{
}; // excepci�n asociada a "annadir_medico"

class EIncorporacionNoAdmitida
{
}; // excepci�n asociada a "annadir_paciente"

class ECitaNoAdmitida
{
}; // excepci�n asociada a "citar"

class ECancelacionNoAdmitida
{
}; // excepci�n asociada a "cancelar_cita"

class EMedicoInexistente
{
}; // excepci�n asociada a "citados" y "vinculados"

typedef unsigned int tNumColegiado;              // tipo para el n� de colegiado del m�dico
typedef unsigned int tCodigoPaciente;            // tipo para el c�digo de identificaci�n del paciente
typedef unsigned int tNumPacientes;              // tipo para el n� m�ximo de pacientes que un m�dico puede atender
typedef string tNombre;                          // tipo para el nombre del paciente
typedef Lista<tCodigoPaciente>::Iterator tTurno; // Iterador de la posición de un paciente en la lista de citados

// clase para la operacion "vinculados"
class Codigo_y_Nombre
{
public:
  tCodigoPaciente codigo;
  tNombre nombre;
};

class CentroSalud
{
public:
  CentroSalud();
  void annadir_medico(tNumColegiado num_colegiado, tNumPacientes num_pacientes);
  void annadir_paciente(tCodigoPaciente codigo_id, tNombre nombre, tNumColegiado num_colegiado);
  bool citar(tCodigoPaciente codigo_id);
  const Lista<tCodigoPaciente> &citados(tNumColegiado num_colegiado) const;
  bool cancelar_cita(tCodigoPaciente codigo_id);
  Lista<Codigo_y_Nombre> vinculados(tNumColegiado num_colegiado) const;

private:
  Diccionario<tNumColegiado, tNumPacientes> _listadoMedicos;
  Diccionario<tCodigoPaciente, tNombre> _listadoPacientes;
  Diccionario<tCodigoPaciente, tNumColegiado> _pacientesPorMedico;
  Diccionario<tNumColegiado, Diccionario<tCodigoPaciente, tNombre>> _medicoPorPaciente;
  Diccionario<tNumColegiado, Lista<tCodigoPaciente>> _citados;
  Diccionario<tCodigoPaciente, tTurno> _turnos;
};

#endif
