/*
 * Tests.cpp
 *
 *  Created on: 25/04/2013
 *      Author: Ramón Díaz Valenzuela
 */
#include <string>
#include <iostream>
#include "Tests.h"
#include "Directorio.h"
#include "UG.h"
#include "Grupo.h"
#include "Aplicacion.h"

using namespace std;
Tests::Tests() {
	g = new Grupo ("patatasfritas");
	u = new Usuario("Ramón");

}

Tests::~Tests() {
	delete u;
}

void Tests::testGestionPermisos() {
	Directorio r("asfdasdf", u,0);
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
		Directorio aux("asfdasdf",u,0);
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
		//ItUsuarios iu(NULL,NULL);

}

void Tests::testUG() {
	Aplicacion p;
	p.parsear("cu ramon");
	p.parsear("cu angel");
	p.parsear("cg jaen");
	p.parsear("cg granada");
	p.parsear("au ramon jaen");
	p.parsear("bg ramon");
	p.parsear("bg ramon");
	p.parsear("au angel granada");
	cout << "INFO: Desasignar ramon al grupo jaen" << endl;
	p.parsear("du ramon jaen");
	cout << "INFO: Listar grupos de Ramón" << endl;
	p.parsear("bg ramon");
	cout << "INFO: Asignar ramon a granada" << endl;
	p.parsear("au ramon granada");
	cout << "INFO: Listar usuarios de granada" << endl;
	p.parsear("bu granada");
	cout << "INFO: Asignar ramon a jaen de nuevo" << endl;
	p.parsear("au ramon jaen");
	cout << "INFO: listar grupos de ramon" << endl;
	p.parsear("bg ramon");
	cout << "INFO:Crear directorio" << endl;
	p.parsear("mkd unDirectorio");
	cout << "INFO: Crear fichero." << endl;
	p.parsear("mkf fich exe 992892");
	cout << "INFO: listar ambos." << endl;
	p.parsear("ls");
	p.parsear("ap fich.exe -p -x 1");


}
