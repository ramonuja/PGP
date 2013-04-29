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
int UG::getUsuarios(Grupo* g, Usuario** usuarios) {
	//primero cuento el número de usuarios del grupo
	int count = 0;
	for (int var = 0; var < nRelaciones; ++var) {
		if(this->relaciones[var]->g == g) count ++;
	}
	usuarios = new Usuario*[count];
	count = 0;
	for (int var = 0; var < nRelaciones; ++var) {
		if(this->relaciones[var]->g == g) usuarios[count++] = this->relaciones[var]->u;
	}
	return count;
}

int UG::getGrupos(Usuario* u, Grupo** grupos) {
	//primero cuento el número de grupos a los que está asociado el usuario
		int count = 0;
		for (int var = 0; var < nRelaciones; ++var) {
			if(this->relaciones[var]->u == u) count ++;
		}
		grupos = new Grupo*[count];
		count = 0;
		for (int var = 0; var < nRelaciones; ++var) {
			if(this->relaciones[var]->u == u) grupos[count++] = this->relaciones[var]->g;
		}
		return count;
}

int UG::getNRelaciones() const{
	return nRelaciones;
}

} /* namespace PGP */
