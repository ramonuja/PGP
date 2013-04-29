/*
 * Iterador.h
 *
 *  Created on: 26/04/2013
 *      Author: Ramón Díaz Valenzuela
 */

#ifndef RBUSQUEDA_H_
#define RBUSQUEDA_H_
//!!!!Cuando se usan referencias cruzadas a clases hay que "declararlas" del modo que sigue.(2 líneas siguientes.)
class UG;
#include "UG.h"

namespace PGP {
template <typename T,typename U>
class Iterador {
protected:
	UG* relacion;
	T* objetoBuscado;
	int indice;
public:
	Iterador(UG *relacion, T* tipoObjeto):
		relacion(relacion), objetoBuscado(tipoObjeto),indice(0){}
	virtual ~Iterador(){}
	virtual U* siguiente() = 0;
	void reiniciar(){indice = 0;}
};

} /* namespace PGP */

#endif /* RBUSQUEDA_H_ */
