/*
 * Usuario.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón Díaz Valenzuela
 */
#include <sstream>
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

void Usuario::fromCSV(string s) {
	stringstream ss(s);
	ss >> nombre;
}

string Usuario::toCSV() {
	stringstream ss;
	ss << nombre;
	return ss.str();
}

} /* namespace PGP */
