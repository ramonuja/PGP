/*
 * Parseador.cpp
 *
 *  Created on: 03/05/2013
 *      Author: druida
 */
#define N_USUARIOS 100
#define N_GRUPOS 100

#define SALIR "salir"
#define CREAR_USUARIO "cu"
#define BORRAR_USUARIO "eu"
#define RENOMBRAR_USUARIO "ru"
#define LISTAR_USUARIOS "lsu"

#define CREAR_GRUPO "cg"
#define BORRAR_GRUPO "eg"
#define RENOMBRAR_GRUPO "rg"
#define LISTAR_GRUPOS "lsg"

#define ASIGNAR_USUARIO "au"
#define DESASIGNAR_USUARIO "du"

#define BUSCAR_USUARIOS "bu"
#define BUSCAR_GRUPOS "bg"

#include "Aplicacion.h"
#include <fstream>
#include <sstream>
#include <iostream>


namespace PGP {

Aplicacion::Aplicacion():
	usuarios(new Usuario*[N_USUARIOS]), nUsuarios(0),
	grupos(new Grupo*[N_GRUPOS]), nGrupos(0),
	relaciones(new UG){
	// TODO Auto-generated constructor stub

}

int Aplicacion::parsear(string s) {
	stringstream ss(s);
	string comando,saux,saux2;
	ss >> comando;
	//USUARIOS
		if (comando==CREAR_USUARIO){
			ss >> saux;
			if (saux!="") crearUsuario(saux);
			return 1;
		}
		if (comando==BORRAR_USUARIO){
			ss >> saux;
			if (saux != "") eliminarUsuario(saux);
			return 1;
		}
		if (comando==RENOMBRAR_USUARIO){
				ss >> saux;
				ss >> saux2;
				if (saux!="" && saux2!="") renombrarUsuario(saux, saux2);
				return 1;
		}
		if (comando==LISTAR_USUARIOS){
			listarUsuarios();
			return 1;
		}
		//GRUPOS
		if (comando==CREAR_GRUPO){
			ss >> saux;
			if (saux!="") crearGrupo(saux);
			return 1;
		}
		if (comando==BORRAR_GRUPO){
			ss >> saux;
			if (saux != "") eliminarGrupo(saux);
			return 1;
		}
		if (comando==RENOMBRAR_GRUPO){
			ss >> saux;
			ss >> saux2;
			if (saux!="" && saux2!="") renombrarGrupo(saux, saux2);
			return 1;
		}
		if (comando == LISTAR_GRUPOS){
			listarGrupos();
			return 1;
		}
		//RELACIONES ENTRE GRUPOS Y USUARIOS
		if (comando==ASIGNAR_USUARIO){
			ss >> saux;
			ss >> saux2;
			if (saux!="" && saux2!="") aniadirRelacion(saux, saux2);
			return 1;
		}
		if (comando == DESASIGNAR_USUARIO){
			ss >> saux;
			ss >> saux2;
			if (saux!="" && saux2!="") eliminarRelacion(saux,saux2);
			return 1;
		}

		//BUSQUEDAS
		if (comando==BUSCAR_USUARIOS){
			ss >> saux;
			if (saux != "") listarUsuarios(saux);
			return 1;
		}
		if (comando==BUSCAR_GRUPOS){
			ss >> saux;
			if (saux != "") listarGrupos(saux);
			return 1;
		}
	//SALIR
	if (comando == SALIR) return -1;
	mostrarMensaje("Comando no reconocido.");
	return 0;
}//end_method

void Aplicacion::crearUsuario(string nombre){
	usuarios[nUsuarios++] = new Usuario(nombre);
	mostrarMensaje("Usuario " + nombre + " creado.");
}

void Aplicacion::eliminarUsuario(string nombre) {
	for (int var = 0; var < nUsuarios; ++var) {
		if(usuarios[var]->getNombre() == nombre){
			delete usuarios[var];
			usuarios[var] = usuarios[--nUsuarios];
		}
	}
	mostrarMensaje("Usuario " + nombre + " eliminado.");
}

void Aplicacion::renombrarUsuario(string antNom, string nueNom) {
	for (int var = 0; var < nUsuarios; ++var) {
			if(usuarios[var]->getNombre() == antNom) usuarios[var]->setNombre(nueNom);
		}
	mostrarMensaje("Usuario renombrado.");
}

void Aplicacion::listarUsuarios() {
	for (int var = 0; var < nUsuarios; ++var) {
		mostrarMensaje(usuarios[var]->getNombre());
	}
}

void Aplicacion::mostrarMensaje(string s) {
	cout << s << endl;
}

void Aplicacion::crearGrupo(string nombre) {
	grupos[nGrupos++] = new Grupo(nombre);
		mostrarMensaje("Grupo " + nombre + " creado.");
}

void Aplicacion::eliminarGrupo(string nombre) {
	for (int var = 0; var < nGrupos; ++var) {
			if(grupos[var]->getNombre() == nombre){
				delete grupos[var];
				grupos[var] = grupos[--nGrupos];
			}
		}
		mostrarMensaje("Grupo " + nombre + " eliminado.");
}

void Aplicacion::renombrarGrupo(string antNom, string nueNom) {
	for (int var = 0; var < nGrupos; ++var) {
				if(grupos[var]->getNombre() == antNom) grupos[var]->setNombre(nueNom);
			}
		mostrarMensaje("Grupo renombrado.");
}

void Aplicacion::listarGrupos() {
	for (int var = 0; var < nGrupos; ++var) {
			mostrarMensaje(grupos[var]->getNombre());
		}
}

void Aplicacion::aniadirRelacion(string nUsuario, string nGrupo) {
	Usuario* u = getUsuarioPorNombre(nUsuario);
	Grupo* g = getGrupoPorNombre(nGrupo);
	if(g==0 || u == 0){
		mostrarMensaje("Valores no encontrados.");
		return;
	}
	relaciones->aniadirRelacion(u,g);
	mostrarMensaje("Relación añadida");
}

void Aplicacion::eliminarRelacion(string nUsuario, string nGrupo) {
	Usuario* u = getUsuarioPorNombre(nUsuario);
		Grupo* g = getGrupoPorNombre(nGrupo);
		if(g==0 || u == 0){
			mostrarMensaje("Valores no encontrados.");
			return;
		}
		relaciones->eliminarRelacion(u,g);
		mostrarMensaje("Relación eliminada");
}
Usuario* Aplicacion::getUsuarioPorNombre(string nombre){
	for (int var = 0; var < nUsuarios; ++var) {
		if(usuarios[var]->getNombre() == nombre) return usuarios[var];
	}
	return 0;
}
Grupo* Aplicacion::getGrupoPorNombre(string nombre){
	for (int var = 0; var < nGrupos; ++var) {
		if(grupos[var]->getNombre() == nombre) return grupos[var];
	}
	return 0;
}

void Aplicacion::listarGrupos(string usuario) {
	Grupo** gs = 0;
	Usuario* u = getUsuarioPorNombre(usuario);
	if(u==0){
		mostrarMensaje("Usuario no encontrado.");
		return;
	}
	gs =  relaciones->getGrupos(u);
	for (int var = 0; gs[var] != 0; ++var) {
		mostrarMensaje(gs[var]->getNombre());
		delete gs[var];
	}
	delete [] gs;

}
void Aplicacion::listarUsuarios(string grupo) {
	Usuario** us = 0;
	Grupo* g = getGrupoPorNombre(grupo);
	if(g==0){
		mostrarMensaje("Grupo no encontrado.");
		return;
	}
	us = relaciones->getUsuarios(g);
	for (int var = 0; us[var]!=0; ++var) {
		mostrarMensaje(us[var]->getNombre());
		delete us[var];
	}
	delete [] us;

}
Aplicacion::~Aplicacion() {
	for (int var = 0; var < nUsuarios; ++var) delete usuarios[var];
		delete[] usuarios;
	for (int var = 0; var < nGrupos; ++var) delete grupos[var];
		delete[] grupos;

	delete relaciones;
}




} /* namespace PGP */
