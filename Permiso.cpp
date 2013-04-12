/*
 * Permiso.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#include "Permiso.h"

namespace PGP {

Permiso::Permiso(bool lectura, bool escritura, bool ejecucion, Grupo g):
		lectura(lectura), escritura(escritura), ejecucion(ejecucion), grupo(g), usuario(0) {
}

Permiso::Permiso(bool lectura, bool escritura, bool ejecucion, Usuario u):
		lectura(lectura), escritura(escritura), ejecucion(ejecucion), grupo(0), usuario(u){
}

Permiso::~Permiso() {
	// TODO Auto-generated destructor stub
}

} /* namespace PGP */
