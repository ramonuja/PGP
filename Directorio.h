/*
 * Directorio.h
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#ifndef DIRECTORIO_H_
#define DIRECTORIO_H_

#include "Recurso.h"

namespace PGP {
#include <string>
using namespace std;
/*
 *
 */
class Directorio: public PGP::Recurso {
private:
	/**
	 * La construcción y destrucción de los recursos se hace dentro de esta clase.
	 */
	Recurso** recursos;
	int nRecursos;//número de recursos contenidos en un momento determinado dentro del directorio.
public:
	void crearDirectorio(string nombre);
	void crearFichero(string nombre, string extension);
	void eliminarRecurso(int indice);
	Directorio(string nombre);
	virtual ~Directorio();
};

} /* namespace PGP */
#endif /* DIRECTORIO_H_ */
