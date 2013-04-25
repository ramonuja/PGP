/*
 * Recurso.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#include "Recurso.h"
#include "math.h"

namespace PGP {

int Recurso::asignarPermisos(bool valor, short ambito, short permiso){
	if ((ambito != OTROS && ambito != GRUPO && ambito != PROPIETARIO)
			||(permiso != EJECUCION && permiso != ESCRITURA && permiso != LECTURA)) return -1;
	short mascara = ambito *  (0x0001 << permiso);
	if (!valor){//denegar un permiso
		mascara = 0x01FF xor mascara;//inversión de la máscara
		permisosActuales = permisosActuales & mascara;
	}else{//garantizar un permiso.
		permisosActuales = permisosActuales | mascara;
	}
	return 0;
}

int Recurso::consultarPermiso(short ambito, short permiso){
	if ((ambito != OTROS && ambito != GRUPO && ambito != PROPIETARIO)
				||(permiso != EJECUCION && permiso != ESCRITURA && permiso != LECTURA)) return -1;
	short mascara = ambito *  (0x0001 << permiso);
	return ((permisosActuales & mascara) >> ((short)log2(mascara)));
}
/*
 * @brief Los permisos garantizados por defecto son (0x01A0 = 0640):
 * 	- Propietario: Lectura y escritura.
 * 	- Grupo: Lectura.
 */
Recurso::Recurso(string nombre, Usuario* u):
		permisosActuales(0640),u(u),nombre(nombre) {}


void Recurso::setPermisosActuales(short permisosActuales) {
	this->permisosActuales = permisosActuales;
}

short Recurso::getPermisosActuales() const {
	return permisosActuales;
}

Recurso::~Recurso() {
}

string Recurso::getDescripcion() {
	char perm[10];
	int aux = 0;
	for (int var = PROPIETARIO; var >= OTROS; var/=8, aux += 3) {
		if(consultarPermiso(var,LECTURA)) perm[aux] = 'l'; else perm[aux] = '-';
		if(consultarPermiso(var,ESCRITURA)) perm[aux+1] = 'e'; else perm[aux+1] = '-';
		if(consultarPermiso(var,EJECUCION)) perm[aux+2] = 'x'; else perm[aux+2] = '-';
	}

	perm[9] = 0;
	return perm;
}

} /* namespace PGP */
