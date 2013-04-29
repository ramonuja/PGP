/*
 * UG.h
 * Mantiene las relaciones entre los Usuarios y los Grupos.
 *  Created on: 26/04/2013
 *      Author: Ramón Díaz Valenzuela
 */

#ifndef UG_H_
#define UG_H_
#define MAX_RELACIONES 1000
#include "Usuario.h"
#include "Grupo.h"

namespace PGP {
struct UG_struct{
	Usuario* u;
	Grupo* g;
};
class UG {
private:
	UG_struct** relaciones;
	int nRelaciones;
public:
	UG();
	virtual ~UG();
	void aniadirRelacion(Usuario* u, Grupo* g) ;
	void eliminarRelacion(Usuario* u, Grupo* g) ;
	int getUsuarios(Grupo *g, Usuario** u);
	int getGrupos(Usuario *u, Grupo** g);
	UG_struct** getRelaciones() const;
	int getNRelaciones() const;
};

} /* namespace PGP */
#endif /* UG_H_ */
