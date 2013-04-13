/*
 * Recurso.h
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#ifndef RECURSO_H_
#define RECURSO_H_
namespace PGP {
#include <string>
using namespace std;

/*
 *
 */
class Recurso {
	private:
	string nombre;
	/**
	 * Los permisos se crean y se destruyen dentro de esta clase.
	 */
	//Permiso **permisos;
	/**
	 * Tamaño actual del array con los permisos.
	 */
	int tamPermisos;
public:
//	void garantizarPermisos(bool lectura, bool escritura, bool ejecucion, Grupo &g);
//	void garantizarPermisos(bool lectura, bool escritura, bool ejecucion, Usuario &u);
//	bool retirarPermisos(Grupo &g);
//	bool retirarPermisos(Usuario &u);
	Recurso(string nombre="desconocido");
	virtual ~Recurso();

	const string& getNombre() const {
		return nombre;
	}

	void setNombre(const string& nombre) {
		this->nombre = nombre;
	}
};

} /* namespace PGP */
#endif /* RECURSO_H_ */
