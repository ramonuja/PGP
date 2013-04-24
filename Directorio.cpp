/*
 * Directorio.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ram�n
 */

#include "Directorio.h"
#include "Fichero.h"

namespace PGP {

Directorio::Directorio(string nombre):
	recursos(new Recurso*[100]),nRecursos(0){
}

void Directorio::crearDirectorio(string nombre) {
	Directorio *d = new Directorio(nombre);
	this->recursos[nRecursos++] = d;

}

void Directorio::crearFichero(string nombre, string extension) {
	Fichero *f = new Fichero();
	this->recursos[nRecursos++] = f;
}

void Directorio::eliminarRecurso(int indice) {
}

Directorio::~Directorio() {
	for (int var = 0; var < nRecursos; ++var) delete recursos[var];
	delete[] recursos;
}

} /* namespace PGP */
