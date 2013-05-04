/*
 * Parseador.h
 *
 *  Created on: 03/05/2013
 *      Author: druida
 */

#ifndef PARSEADOR_H_
#define PARSEADOR_H_
#include <string>
#include "Usuario.h"
#include "Grupo.h"
#include "UG.h"
using namespace std;
namespace PGP {

class Aplicacion {
private:
	Usuario** usuarios;
	int nUsuarios;
	Grupo** grupos;
	int nGrupos;
	UG* relaciones;

	void crearUsuario(string nombre);
	void eliminarUsuario(string nombre);
	void renombrarUsuario (string antNom, string nueNom);
	void listarUsuarios();
	void crearGrupo(string nombre);
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
public:
	int parsear(string s);
	Aplicacion();
	virtual ~Aplicacion();
};

} /* namespace PGP */
#endif /* PARSEADOR_H_ */
