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
/*
 *
 */
class Directorio: public PGP::Recurso {
private:
	Recurso* *recursos;
	int nElem;//número de recursos contenidos en un momento determinado dentro del directorio.
public:
	aniadirRecurso(Recurso* r);
	eliminarRecurso(int indice);
	Directorio();
	virtual ~Directorio();
};

} /* namespace PGP */
#endif /* DIRECTORIO_H_ */
