/*
 * Grupo.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón Díaz Valenzuela
 */
#include <sstream>
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

void Grupo::fromCSV(string s) {
	stringstream ss(s);
	ss >> nombre;
}

string Grupo::toCSV() {
	stringstream ss;
	ss << nombre;
	return ss.str();
}

} /* namespace PGP */
