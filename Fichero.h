/*
 * Fichero.h
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#ifndef FICHERO_H_
#define FICHERO_H_

#include "Recurso.h"

namespace PGP {
#include <string>
using namespace std;
/*
 *
 */
class Fichero: public PGP::Recurso {
private:
	string extension;
	float tamanio;
public:
	Fichero();
	virtual ~Fichero();
};

} /* namespace PGP */
#endif /* FICHERO_H_ */
