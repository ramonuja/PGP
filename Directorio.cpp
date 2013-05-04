/*
 * Directorio.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón Díaz Valenzuela
 *       */
#include "Directorio.h"
#include "Fichero.h"

namespace PGP {

Directorio::Directorio(string nombre, Usuario* usuario):
		Recurso(nombre,usuario),recursos(new Recurso*[100]),nRecursos(0){

}

void Directorio::crearDirectorio(string nombre, Usuario* u) {
	Directorio *d = new Directorio(nombre,u);
	this->recursos[nRecursos++] = d;

}

void Directorio::crearFichero(string nombre, string extension, int tamanio, Usuario* u) {
	Fichero *f = new Fichero(nombre, extension, tamanio, u);
	this->recursos[nRecursos++] = f;
}

void Directorio::eliminarRecurso(int indice) {
	delete this->recursos[indice];
	this->recursos[indice] = this->recursos[--nRecursos];
}

Directorio::~Directorio() {
	for (int var = 0; var < nRecursos; ++var) delete recursos[var];
	delete[] recursos;
}


string Directorio::getNombre() {
	return this->nombre;
}

int Directorio::getTamanio() {
	return 0;
}

bool Directorio::esDirectorio() {
	return true;
}

} /* namespace PGP */
