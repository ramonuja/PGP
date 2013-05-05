/*
 * Fichero.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón Díaz Valenzuela
 */

#include "Fichero.h"

namespace PGP {

Fichero::Fichero(string nombre, string extension, int tamanio, Usuario* u) :
		Recurso(nombre,u),extension(extension), tamanio(tamanio){
	// TODO Auto-generated constructor stub

}

Fichero::~Fichero() {
	// TODO Auto-generated destructor stub
}

string Fichero::getNombre() {
	return this->nombre + "." + extension;
}

int Fichero::getTamanio() {
	return this->tamanio;
}

bool Fichero::esDirectorio() {
	return false;
}

void Fichero::setNombre(string nombre) {
	long int p = nombre.find(".");
	this->nombre = nombre.substr(0,p);
	this->extension = nombre.substr(p+1,nombre.length()-1);
}

} /* namespace PGP */
