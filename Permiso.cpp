/*
 * Permiso.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#include "Permiso.h"

namespace PGP {

Permiso::Permiso(bool lectura, bool escritura, bool ejecucion, Grupo* g):
		lectura(lectura), escritura(escritura), ejecucion(ejecucion), grupo(g), usuario(0) {
}

Permiso::Permiso(bool lectura, bool escritura, bool ejecucion, Usuario* u):
		lectura(lectura), escritura(escritura), ejecucion(ejecucion), grupo(0), usuario(u){
}

bool Permiso::isEjecucion() const {
	return ejecucion;
}

void Permiso::setEjecucion(bool ejecucion) {
	this->ejecucion = ejecucion;
}

bool Permiso::isEscritura() const {
	return escritura;
}

void Permiso::setEscritura(bool escritura) {
	this->escritura = escritura;
}

const Grupo* Permiso::getGrupo() const {
	return grupo;
}

bool Permiso::isLectura() const {
	return lectura;
}

void Permiso::setLectura(bool lectura) {
	this->lectura = lectura;
}

const Usuario* Permiso::getUsuario() const {
	return usuario;
}

Permiso::~Permiso() {
	// TODO Auto-generated destructor stub
}

} /* namespace PGP */
