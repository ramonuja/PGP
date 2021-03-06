/*
 * Parseador.cpp
 *
 *  Created on: 03/05/2013
 *      Author: Ramón Díaz Valenzuela
 */
#define N_USUARIOS 100
#define N_GRUPOS 100
  /*********************/
 /*LISTADO DE COMANDOS*/
/*********************/
//LOGIN
#define LOGIN "login"
//SALIR
#define SALIR "salir"
//USUARIOS
#define CREAR_USUARIO "cu"
#define BORRAR_USUARIO "eu"
#define RENOMBRAR_USUARIO "ru"
#define LISTAR_USUARIOS "lsu"
//GRUPOS
#define CREAR_GRUPO "cg"
#define BORRAR_GRUPO "eg"
#define RENOMBRAR_GRUPO "rg"
#define LISTAR_GRUPOS "lsg"
//ASIGNACIONES A GRUPOS
#define ASIGNAR_USUARIO "au"
#define DESASIGNAR_USUARIO "du"
//RECURSOS
#define CREAR_DIRECTORIO "mkd"
#define CREAR_FICHERO "mkf"
#define LISTAR_RECURSOS "ls"
#define BORRAR_RECURSO "br"
#define RENOMBRAR_RECURSO "rr"
//BUSQUEDAS
#define BUSCAR_USUARIOS "bu"
#define BUSCAR_GRUPOS "bg"
#define BUSCAR_RECURSOS_X_NOMBRE "brn"
#define BUSCAR_RECURSOS_X_USUARIO "bru"
//NAVEGACION
#define CARGAR_DIRECTORIO "cd"
#define VOLVER_ATRAS "cd.."
//PERMISOS
#define ASIGNAR_PERMISOS "ap"
#include "Aplicacion.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


namespace PGP {

Aplicacion::Aplicacion():
	usuarios(new Usuario*[N_USUARIOS]), nUsuarios(0),
	grupos(new Grupo*[N_GRUPOS]), nGrupos(0),
	relaciones(new UG){
	//carga de los datos de fichero de grupos y usuarios.
	//Ficheros usuarios.dat y grupos.dat respectivamente.
	ifstream f;
	string nombreArchivo = "usuarios.dat";
	f.open(nombreArchivo.c_str());
	if(f.good()){
		string s;
		while(!f.eof()){
			getline(f,s);
			if(s.empty()) continue;
			Usuario * u = crearUsuario("temporal");
			if(u!=NULL) u->fromCSV(s);
		}
	}
	f.close();
	nombreArchivo = "grupos.dat";
	f.open(nombreArchivo.c_str());
	if(f.good()){
		string s;
		while(!f.eof()){
			getline(f,s);
			if(s.empty()) continue;
			Grupo * u = crearGrupo("temporal");
			if (u!=NULL)u->fromCSV(s);
		}
	}
	f.close();
	PGP::Usuario* u;

	u = getUsuarioPorNombre("system");
	if(u == 0) u = crearUsuario("system");
	uActual = u;
	dirActual = new Directorio("base",u,NULL);
}

void Aplicacion::gestionarCambioPermisos(string nombreFichero, string ambito,
		const string& tipoPermiso, int valorPermiso) {
	Recurso* r = this->dirActual->getRecursoxNombre(nombreFichero);
	if(uActual!=r->getUsuario()){
		mostrarMensaje("No eres el propietario del recurso, por favor logéate como tal");
		return;
	}
	if (r == 0) {
		mostrarMensaje("Recurso no encontrado.");
		return;
	}
	short nAmb = 0;
	if (ambito == "-p") {
		nAmb = dirActual->PROPIETARIO;
	}else if(ambito == "-g"){
		nAmb = dirActual->GRUPO;
	}else if(ambito == "-o"){
		nAmb = dirActual->OTROS;
	}else{
		mostrarMensaje("Sintaxis incorrecta");
		return;
	}
	short nTP = 0;
	if (tipoPermiso == "-l") {
		nTP = dirActual->LECTURA;
	}else if(tipoPermiso == "-e"){
		nTP = dirActual->ESCRITURA;
	}else if(tipoPermiso == "-x"){
		nTP = dirActual->EJECUCION;
	}else{
		mostrarMensaje("Sintaxis incorrecta");
		return;
	}
	bool valPerm = false;
	if (valorPermiso == 1) {
		valPerm = true;
	}else if(valorPermiso == 0){
		valPerm = false;
	}else{
		mostrarMensaje("Sintaxis incorrecta");
		return;
	}
	r->asignarPermisos(valPerm,nAmb,nTP);
	mostrarMensaje("Permiso asignado");
}

int Aplicacion::parsear(string s) {
	stringstream ss(s);
	string comando,saux,saux2,saux3;
	int iaux = 0;
	ss >> comando;
	//LOGIN
	if (comando == LOGIN){
		ss >> saux;
		if (saux!="") login(saux);
		return 1;
	}
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
		//RECURSOS
		if (comando==CREAR_DIRECTORIO){
			ss >> saux;
			if (saux != ""){
				this->dirActual->crearDirectorio(saux,uActual);
				mostrarMensaje("Nuevo directorio creado.");
			}
			return 1;
		}
		if (comando==CREAR_FICHERO){
			ss >> saux;//nombre
			ss >> saux2;//extension
			int tam = 0;
			ss >> tam; //tamaño
			if (saux != ""){
				this->dirActual->crearFichero(saux,saux2,tam,uActual);
				mostrarMensaje("Nuevo fichero añadido.");
			}
			return 1;
		}
		if (comando==LISTAR_RECURSOS){
			listarRecursos();
			return 1;
		}
		if (comando==BORRAR_RECURSO){
			ss >> saux;
			if (saux != "") borrarRecurso(saux);
			return 1;
		}
		if (comando==RENOMBRAR_RECURSO){
				ss >> saux;
				ss >> saux2;
				if (saux!="" && saux2!="") renombrarRecurso(saux, saux2);
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
		if (comando==BUSCAR_RECURSOS_X_NOMBRE){
			ss >> saux;
			if (saux != "") buscarRecursoxNombre(saux);
			return 1;
		}
		if (comando==BUSCAR_RECURSOS_X_USUARIO){
			ss >> saux;
			if (saux != "") buscarRecursoxUsuario(saux);
			return 1;
		}
		//NAVEGACION
		if (comando==CARGAR_DIRECTORIO){
			ss >> saux;//directorio destino
			if (saux != "") cargarDirectorio(saux);
			return 1;
		}
		if (comando==VOLVER_ATRAS){
			if(this->dirActual->getPadre() != NULL){
				this->dirActual = this->dirActual->getPadre();
			}
			return 1;
		}
		//PERMISOS
		if (comando==ASIGNAR_PERMISOS){
			ss >> saux;//nombre del fichero
			ss >> saux2;//ambito
			ss >> saux3;//tipopermiso
			ss >> iaux;//valor
		gestionarCambioPermisos(saux, saux2, saux3, iaux);
		return 1;
		}
	//SALIR
	if (comando == SALIR) return -1;
	mostrarMensaje("Comando no reconocido.");
	return 0;
}//end_method

Usuario* Aplicacion::crearUsuario(string nombre){
	if (nombre == "") return 0;
	Usuario* u = new Usuario(nombre);
	usuarios[nUsuarios++] = u;
	mostrarMensaje("Usuario " + nombre + " creado.");
	return u;
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

Grupo* Aplicacion::crearGrupo(string nombre) {
	if (nombre=="")return 0;
	Grupo * g = new Grupo(nombre);
	grupos[nGrupos++] = g;
		mostrarMensaje("Grupo " + nombre + " creado.");
		return g;
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
	}
	delete [] us;

}
string Aplicacion::getPrompt(){return this->uActual->getNombre() + "@" + getPrompt(dirActual) + "::";}
string Aplicacion::getPrompt(Directorio *d){
	if(d->getPadre() == NULL)
		return "/" + d->getNombre();
	return getPrompt(d->getPadre()) + "/" + d->getNombre();
}

void Aplicacion::listarRecursos() {
	PGP::Recurso** rs;
	rs = this->dirActual->getRecursos();
	int nR = this->dirActual->getNRecursos();
	for (int var = 0; var < nR; ++var) {
		mostrarMensaje(rs[var]->getDescripcion());
	}
}

void Aplicacion::cargarDirectorio(string dir) {
	PGP::Recurso** rs;
	rs = this->dirActual->getRecursos();
	int nR = this->dirActual->getNRecursos();
	for (int var = 0; var < nR; ++var) {
		if(rs[var]->esDirectorio()){
			if(rs[var]->getNombre() == dir){
				dirActual = (Directorio*)rs[var];
			}//end_if
		}//end_if
	}//end_for
}

void Aplicacion::login(string l) {
	PGP::Usuario* u;
	u = getUsuarioPorNombre(l);
	if(u!=NULL){
		uActual = u;
		mostrarMensaje("Logeado como "+l);
	}else{
		mostrarMensaje("Usuario no encontrado.");
	}
}

void Aplicacion::borrarRecurso(string nombre) {
	for (int var = 0; var < dirActual->getNRecursos(); ++var) {
		if(dirActual->getRecursos()[var]->getNombre() == nombre){
			dirActual->eliminarRecurso(var);
			mostrarMensaje("Recurso eliminado");
			return;
		}
	}
	mostrarMensaje("Recurso no encontrado");
}

void Aplicacion::renombrarRecurso(string antNom, string nueNom) {
	for (int var = 0; var < dirActual->getNRecursos(); ++var) {
		if(dirActual->getRecursos()[var]->getNombre() == antNom){
			dirActual->getRecursos()[var]->setNombre(nueNom);
			mostrarMensaje("Recurso renombrado.");
			return;
		}
	}
	mostrarMensaje("Recurso no encontrado.");
}

void Aplicacion::buscarRecursoxUsuario(string nomUs) {
	PGP::Usuario* u;
	u = getUsuarioPorNombre(nomUs);
	if(u==NULL){
		mostrarMensaje("Usuario no encontrado.");
		return;
	}
	vector<Recurso*> vct = dirActual->recorrer();
	for (unsigned int var = 0; var < vct.size(); ++var) {
		if(vct[var]->getUsuario() == u){
			mostrarMensaje(vct[var]->getDescripcion());
		}
	}
}


void Aplicacion::buscarRecursoxNombre(string cadena) {
	vector<Recurso*> vct = dirActual->recorrer();
	for (unsigned int var = 0; var < vct.size(); ++var) {
		//DEBUG Buscar el valor de retorno de string.find(string)
		if(vct[var]->getNombre().find(cadena) != string::npos){
			mostrarMensaje(vct[var]->getDescripcion());
		}
	}

}

Aplicacion::~Aplicacion() {
	ofstream f;
	string nombreArchivo = "usuarios.dat";
	f.open(nombreArchivo.c_str());
	for (int var = 0; var < nUsuarios; ++var){
		if(f.good()){
			f << usuarios[var]->toCSV() << endl;
		}
		delete usuarios[var];
	}
	f.close();
	delete[] usuarios;
	nombreArchivo = "grupos.dat";
	f.open(nombreArchivo.c_str());
	for (int var = 0; var < nGrupos; ++var) {
				if(f.good()){
					f << grupos[var]->toCSV() << endl;
				}
		delete grupos[var];
	}
	f.close();
	delete[] grupos;
	delete relaciones;
}




} /* namespace PGP */
