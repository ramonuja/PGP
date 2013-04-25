/*
 * Fichero.h
 *
 *  Created on: 12/04/2013
 *      Author: Ram�n
 */

#ifndef FICHERO_H_
#define FICHERO_H_

#include <string>
#include "Recurso.h"
using namespace std;

namespace PGP {
/*
 *
 */
class Fichero: public PGP::Recurso {
private:
	string extension;
	float tamanio;
public:
	Fichero(string nombre,string extension, float tamanio, Usuario* u);
	virtual ~Fichero();
	virtual string getNombre();
	virtual int getTamanio();
	virtual bool esDirectorio();
};

} /* namespace PGP */
#endif /* FICHERO_H_ */
