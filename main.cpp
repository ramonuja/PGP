/*
 * main.cpp
 *
 *  Created on: 13/04/2013
 *      Author: Ram�n
 */
#include <iostream>
#include <string>
#include <math.h>
#include "Tests.h"

using namespace std;
enum AMBITOS {OTROS = 1, GRUPO = 8, PROPIETARIO = 64};
enum PERMISOS { EJECUCION, ESCRITURA, LECTURA};

short permisosActuales = 0;

int modificarPermisos(bool valor, short ambito, short permiso){
	if ((ambito != OTROS && ambito != GRUPO && ambito != PROPIETARIO)
			||(permiso != EJECUCION && permiso != ESCRITURA && permiso != LECTURA)) return 1;
	short mascara = ambito *  (0x0001 << permiso);
	if (!valor){//denegar un permiso
		mascara = 0x01FF xor mascara;//inversión de la máscara
		permisosActuales = permisosActuales & mascara;
	}else{//garantizar un permiso.
		permisosActuales = permisosActuales | mascara;
	}
	return 0;
}

int consultarPermiso(short ambito, short permiso){
	if ((ambito != OTROS && ambito != GRUPO && ambito != PROPIETARIO)
				||(permiso != EJECUCION && permiso != ESCRITURA && permiso != LECTURA)) return -1;
	short mascara = ambito *  (0x0001 << permiso);
	return ((permisosActuales & mascara) >> ((short)log2(mascara)));
}


int main(int argc, char **argv) {
	Tests t;
	t.testGestionPermisos();
}





