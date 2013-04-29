/*
 * UG.cpp
 *
 *  Created on: 26/04/2013
 *      Author: druida
 */

#include "UG.h"

namespace PGP {

UG::UG(): relaciones(new UG_struct* [MAX_RELACIONES]),nRelaciones(0) {
	// TODO Auto-generated constructor stub

}

UG::~UG() {
	// TODO Auto-generated destructor stub
}

void UG::aniadirRelacion(Usuario* u, Grupo* g)  {
	//TODO checkear que la relación no existe previamente
	UG_struct * temp = new UG_struct;
	temp->g = g;
	temp->u = u;
	this->relaciones[nRelaciones++] = temp;
}//end_method

void UG::eliminarRelacion(Usuario* u, Grupo* g) {
	for (int var = 0; var < nRelaciones; ++var) {
		if(relaciones[var]->g == g && relaciones[var]->u == u){
			relaciones[var] = relaciones[--nRelaciones];
			break;
		}//end_if
	}//end_for
}//end_method


UG_struct** UG::getRelaciones() const {
	return relaciones;
}
ItUsuarios UG::getUsuarios(Grupo* g) {
	//Usuario* us[MAX_RELACIONES];
	ItUsuarios iu(NULL,NULL);
	return iu;
}

void UG::getGrupos(Usuario* u) {
	//return NULL;
}

int UG::getNRelaciones() const{
	return nRelaciones;
}

} /* namespace PGP */
