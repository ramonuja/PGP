/*
 * Parseador.h
 *
 *  Created on: 03/05/2013
 *      Author: Ramón Díaz Valenzuela
 */

#ifndef PARSEADOR_H_
#define PARSEADOR_H_
#include <string>
#include "Usuario.h"
#include "Grupo.h"
#include "UG.h"
#include "Directorio.h"
using namespace std;
namespace PGP {

class Aplicacion {
private:
	Usuario** usuarios;
	int nUsuarios;
	Grupo** grupos;
	int nGrupos;
	UG* relaciones;
	Directorio* dirActual;
	Usuario* uActual;

	Usuario* crearUsuario(string nombre);
	void eliminarUsuario(string nombre);
	void renombrarUsuario (string antNom, string nueNom);
	void listarUsuarios();
	Grupo* crearGrupo(string nombre);
	void eliminarGrupo(string nombre);
	void renombrarGrupo (string antNom, string nueNom);
	void listarGrupos();
	void mostrarMensaje(string s);
	void aniadirRelacion(string nUsuario, string nGrupo);
	void eliminarRelacion(string nUsuario, string nGrupo);
	Usuario* getUsuarioPorNombre(string nombre);
	Grupo* getGrupoPorNombre(string nombre);
	void listarGrupos(string usuario);
	void listarUsuarios(string grupo);
	string getPrompt(Directorio *d);
	void listarRecursos();
	void cargarDirectorio(string dir);
	void login(string l);
	void borrarRecurso(string nombre);
	void renombrarRecurso(string antNom, string nueNom);
	void buscarRecursoxUsuario(string nomUs);
	void buscarRecursoxNombre(string cadena);
	void gestionarCambioPermisos(string nombreFichero, string ambito,
			const string& tipoPermiso, int valorPermiso);

public:
	string getPrompt();
	int parsear(string s);
	Aplicacion();
	virtual ~Aplicacion();
};

} /* namespace PGP */
#endif /* PARSEADOR_H_ */
