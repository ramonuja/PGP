/*
 * ItUsuarios.cpp
 *
 *  Created on: 27/04/2013
 *      Author: druida
 */

#include "ItUsuarios.h"

namespace PGP {

ItUsuarios::ItUsuarios(UG* relacion, Grupo* g):
		Iterador<Grupo,Usuario>(relacion, g) {
}

ItUsuarios::~ItUsuarios() {}

Usuario* ItUsuarios::siguiente() {
	PGP::UG_struct** relaciones;
	relaciones = this->relacion->getRelaciones();
	for (; indice < this->relacion->getNRelaciones(); ++indice) {
		if(relaciones[indice]->g == this->objetoBuscado) return relaciones[indice++]->u;
	}//end_for
	return NULL;
}
} /* namespace PGP */
