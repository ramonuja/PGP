/*
 * ItGrupos.h
 *
 *  Created on: 27/04/2013
 *      Author: druida
 */

#ifndef ITGRUPOS_H_
#define ITGRUPOS_H_

#include "Iterador.h"
#include "Usuario.h"
#include "Grupo.h"
#include "UG.h"

namespace PGP {

class ItGrupos: public Iterador<Usuario,Grupo> {
public:
	virtual Grupo* siguiente();
	ItGrupos(UG* relacion, Usuario* u);
	virtual ~ItGrupos();
};

} /* namespace PGP */
#endif /* ITGRUPOS_H_ */
