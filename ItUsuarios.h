/*
 * ItUsuarios.h
 *
 *  Created on: 27/04/2013
 *      Author: druida
 */

#ifndef ITUSUARIOS_H_
#define ITUSUARIOS_H_
#include "Iterador.h"
#include "Grupo.h"
#include "Usuario.h"
#include "UG.h"

namespace PGP {
class ItUsuarios: public Iterador<Grupo,Usuario> {
public:
	virtual Usuario* siguiente();
	ItUsuarios(UG* relacion, Grupo* g);
	virtual ~ItUsuarios();
};

} /* namespace PGP */

#endif /* ITUSUARIOS_H_ */
