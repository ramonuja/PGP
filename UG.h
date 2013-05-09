/*
 * UG.h
 *	@brief Sirve para mantener las relaciones entre ususarios y grupos.
 *  @date 03/05/2013
 *  @Author: Ramón Díaz Valenzuela
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
	Usuario** getUsuarios(Grupo *g);
	Grupo** getGrupos(Usuario *u);
	UG_struct** getRelaciones() const;
	int getNRelaciones() const;
};

} /* namespace PGP */
#endif /* UG_H_ */
