/*
 * Tests.cpp
 *
 *  Created on: 25/04/2013
 *      Author: druida
 */
#include <string>
#include <iostream>
#include "Tests.h"
#include "Directorio.h"

using namespace std;
Tests::Tests() {
	u = new Usuario();

}

Tests::~Tests() {
	delete u;
}

void Tests::testGestionPermisos() {
	Directorio r("asfdasdf", u);
	cout << "Los permisos actuales son: " << hex << r.getPermisosActuales() << endl;
		cout << "Añado permisos de ejecución al r.PROPIETARIO..." << endl;
		r.asignarPermisos(true, r.PROPIETARIO, r.EJECUCION);
		cout << "El resultado obtenido es: " << hex << r.getPermisosActuales() << endl;
		cout << "Si se los quito..." << endl;
		r.asignarPermisos(false, r.PROPIETARIO, r.EJECUCION);
		cout << "Tenemos como resultado: " << hex << r.getPermisosActuales() << endl;
		cout << "Asignamos permisos de ejecución a r.OTROS: " << endl;
		r.asignarPermisos(true, r.OTROS, r.EJECUCION);
		cout << "Como resultado obtenemos: " << hex << r.getPermisosActuales() << endl;
		cout << "Ahora reseteo los permisos y asigno escritura al r.GRUPO..." << endl;
		r.setPermisosActuales(0);
		r.asignarPermisos(true, r.GRUPO, r.LECTURA);
		cout << "El resultado es el siguiente: " << hex << r.getPermisosActuales() << endl;
		cout << "Lo desasigno y asigno ejecucion y escritura" << endl;
		r.asignarPermisos(false, r.GRUPO, r.LECTURA);
		r.asignarPermisos(true, r.GRUPO, r.EJECUCION);
		r.asignarPermisos(true, r.GRUPO, r.ESCRITURA);
		cout << "El resultado final: " << hex << r.getPermisosActuales() << endl;
		cout << "El más delicado... lectura al r.PROPIETARIO: " << endl;
		r.asignarPermisos(true, r.PROPIETARIO, r.LECTURA);
		cout << "El resultado: " << hex << r.getPermisosActuales() << endl;
		cout << "Si lo quito" << endl;
		r.asignarPermisos(false, r.PROPIETARIO, r.LECTURA);
		cout << "Finalmente tras quitarlo tenemos: " << hex << r.getPermisosActuales() << endl;
		cout << "Permiso Otros-Lectura: "  << r.consultarPermiso(r.OTROS,r.LECTURA) << endl;
		cout << "Permiso Otros-Escritura: "  << r.consultarPermiso(r.OTROS,r.ESCRITURA) << endl;
		cout << "Permiso Otros-Ejecucion: "  << r.consultarPermiso(r.OTROS,r.EJECUCION) << endl;
		cout << "Permiso GRUPO-Lectura: "  << r.consultarPermiso(r.GRUPO,r.LECTURA) << endl;
		cout << "Permiso GRUPO-Escritura: "  << r.consultarPermiso(r.GRUPO,r.ESCRITURA) << endl;
		cout << "Permiso GRUPO-Ejecucion: "  << r.consultarPermiso(r.GRUPO,r.EJECUCION) << endl;
		cout << "Permiso Prop-Lectura: "  << r.consultarPermiso(r.PROPIETARIO,r.LECTURA) << endl;
		cout << "Permiso Prop-Escritura: "  << r.consultarPermiso(r.PROPIETARIO,r.ESCRITURA) << endl;
		cout << "Permiso Prop-Ejecucion: "  << r.consultarPermiso(r.PROPIETARIO,r.EJECUCION) << endl;
		cout << "Entrada de datos prohibida: "  << r.consultarPermiso(r.PROPIETARIO,5488) << endl;


		cout << "Creando un objeto con los permisos por defecto: " << endl;
		Directorio aux("asfdasdf",u);
		r = aux;
		cout << "Permiso Otros-Lectura: "  << r.consultarPermiso(r.OTROS,r.LECTURA) << endl;
		cout << "Permiso Otros-Escritura: "  << r.consultarPermiso(r.OTROS,r.ESCRITURA) << endl;
		cout << "Permiso Otros-Ejecucion: "  << r.consultarPermiso(r.OTROS,r.EJECUCION) << endl;
		cout << "Permiso GRUPO-Lectura: "  << r.consultarPermiso(r.GRUPO,r.LECTURA) << endl;
		cout << "Permiso GRUPO-Escritura: "  << r.consultarPermiso(r.GRUPO,r.ESCRITURA) << endl;
		cout << "Permiso GRUPO-Ejecucion: "  << r.consultarPermiso(r.GRUPO,r.EJECUCION) << endl;
		cout << "Permiso Prop-Lectura: "  << r.consultarPermiso(r.PROPIETARIO,r.LECTURA) << endl;
		cout << "Permiso Prop-Escritura: "  << r.consultarPermiso(r.PROPIETARIO,r.ESCRITURA) << endl;
		cout << "Permiso Prop-Ejecucion: "  << r.consultarPermiso(r.PROPIETARIO,r.EJECUCION) << endl;
		cout << "Entrada de datos prohibida: "  << r.consultarPermiso(r.PROPIETARIO,5488) << endl;


		cout << "Probando la descripción: " << r.getDescripcion() << endl;

}
