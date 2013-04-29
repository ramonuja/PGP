/*
 * ItGrupos.cpp
 *
 *  Created on: 27/04/2013
 *      Author: druida
 */

#include "ItGrupos.h"

namespace PGP {

ItGrupos::ItGrupos(UG* relacion, Usuario* u):
	Iterador<Usuario,Grupo>(relacion, u){
	// TODO Auto-generated constructor stub

}

Grupo* ItGrupos::siguiente() {
	PGP::UG_struct** relaciones;
	relaciones = this->relacion->getRelaciones();
	for (; indice < this->relacion->getNRelaciones(); ++indice) {
		if(relaciones[indice]->u == this->objetoBuscado) return relaciones[indice++]->g;
	}//end_for
	return NULL;
}


ItGrupos::~ItGrupos() {
	// TODO Auto-generated destructor stub
}

} /* namespace PGP */
