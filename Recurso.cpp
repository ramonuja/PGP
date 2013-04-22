/*
 * Recurso.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#include "Recurso.h"

namespace PGP {
//void Recurso::garantizarPermisos(bool lectura, bool escritura, bool ejecucion,
//		Grupo& g) {
//	this->permisos[tamPermisos++] = new Permiso(lectura, escritura, ejecucion, g);
//}
//
//void Recurso::garantizarPermisos(bool lectura, bool escritura, bool ejecucion,
//		Usuario& u) {
//	this->permisos[tamPermisos++] = new Permiso(lectura, escritura, ejecucion, u);
//}
//
//bool Recurso::retirarPermisos(Grupo &g) {
//	for (int var = 0; var < tamPermisos; ++var) {
//		if( &g== (*(this->permisos[var])).grupo){
//			delete permisos[var];
//			permisos[var] = permisos[--tamPermisos];
//			return true;
//		}
//	}//end_for
//	return false;
//}
//
//bool Recurso::retirarPermisos(Usuario &u) {
//	for (int var = 0; var < tamPermisos; ++var) {
//		if( &u== (*(this->permisos[var])).usuario){
//			delete permisos[var];
//			permisos[var] = permisos[--tamPermisos];
//			return true;
//		}
//	}//end_for
//	return false;
//}

Recurso::Recurso(string nombre):
		nombre(nombre),/*permisos(new Permiso*[100]),*/tamPermisos(0) {

}


Recurso::~Recurso() {
	//LIBERAR OBJETOS DE MEMORIA
	//for (int var = 0; var < tamPermisos; ++var) delete permisos[var];
	//delete[] permisos;
}

} /* namespace PGP */
