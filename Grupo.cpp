/*
 * Grupo.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ram�n
 */

#include "Grupo.h"

namespace PGP {

Grupo::Grupo(string nombre):
	constituyentes(new Usuario*[100]), nConstituyentes(0),nombre(nombre){
	// TODO Auto-generated constructor stub
}

void Grupo::bajaUsuario(Usuario* u) {
	for (int var = 0; var < this->nConstituyentes; ++var){
		if(this->constituyentes[var] == u){
			this->constituyentes[var] = this->constituyentes[--nConstituyentes];
			break;
		}
	}
}
void Grupo::altaUsuario(Usuario *u) {
	this->constituyentes[nConstituyentes++] = u;
}
Grupo::~Grupo() {
	// TODO Auto-generated destructor stub
}

} /* namespace PGP */
