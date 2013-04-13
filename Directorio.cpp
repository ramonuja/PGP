/*
 * Directorio.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#include "Directorio.h"

namespace PGP {

Directorio::Directorio(string nombre):
	nRecursos(0),recursos(new Recurso*[100]){
}

void Directorio::crearDirectorio(string nombre) {
}

void Directorio::crearFichero(string nombre, string extension) {
}

void Directorio::eliminarRecurso(int indice) {
}

Directorio::~Directorio() {
	for (int var = 0; var < nRecursos; ++var) delete recursos[var];
	delete[] recursos;
}

} /* namespace PGP */
