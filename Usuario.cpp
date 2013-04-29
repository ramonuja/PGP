/*
 * Usuario.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ram�n
 */

#include "Usuario.h"

namespace PGP {

Usuario::Usuario(string nombre):
	nombre(nombre){
	// TODO Auto-generated constructor stub

}

string Usuario::getNombre() {
	return nombre;
}

void Usuario::setNombre(string nombre) {
	this->nombre = nombre;
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

} /* namespace PGP */
