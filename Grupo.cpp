/*
 * Grupo.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ram�n
 */

#include "Grupo.h"

namespace PGP {

Grupo::Grupo(string nombre):
	nombre(nombre){
	// TODO Auto-generated constructor stub
}

string Grupo::getNombre()  {
	return nombre;
}

void Grupo::setNombre( string nombre) {
	this->nombre = nombre;
}

Grupo::~Grupo() {
	// TODO Auto-generated destructor stub
}

} /* namespace PGP */
