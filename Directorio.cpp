/*
 * Directorio.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón Díaz Valenzuela
 *       */
#include "Directorio.h"
#include "Fichero.h"
#include "typeinfo"

namespace PGP {

Directorio::Directorio(string nombre, Usuario* usuario, Directorio* padre):
		Recurso(nombre,usuario),recursos(new Recurso*[100]),nRecursos(0),padre(padre){

}

void Directorio::crearDirectorio(string nombre, Usuario* u) {
	Directorio *d = new Directorio(nombre,u, this);
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

int Directorio::getNRecursos() const {
	return nRecursos;
}

void Directorio::setRecursos(int recursos) {
	nRecursos = recursos;
}

Recurso** Directorio::getRecursos() {
	return recursos;
}

Directorio* Directorio::getPadre() {
	return padre;
}

bool Directorio::esDirectorio() {
	return true;
}
vector<Recurso*> Directorio::recorrer() {
	return recorrer(this);
}
vector<Recurso*> Directorio::recorrer(Directorio* d) {
	vector<Recurso*> vct;
	for (int var = 0; var < d->getNRecursos(); ++var) {
		vct.push_back(d->getRecursos()[var]);
		if(typeid(recursos[var])==typeid(Directorio*)){
			vector<Recurso*> innv = recorrer((Directorio*)recursos[var]);
			for (unsigned int var2 = 0; var2 < innv.size(); ++var2) {
				vct.push_back(innv[var2]);
			}
		}
	}
	return vct;
}

void Directorio::setNombre(string nombre) {
	this->nombre = nombre;
}

Recurso* Directorio::getRecursoxNombre(string nombre) {
	for (int var = 0; var < nRecursos; ++var) {
		if (this->recursos[var]->getNombre() == nombre) return this->recursos[var];
	}
	return 0;
}
} /* namespace PGP */
