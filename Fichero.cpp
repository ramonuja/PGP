/*
 * Fichero.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ram�n
 */

#include "Fichero.h"

namespace PGP {

Fichero::Fichero(string nombre, string extension, float tamanio, Usuario* u) :
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

} /* namespace PGP */
