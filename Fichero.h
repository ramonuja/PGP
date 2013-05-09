/*
 * Fichero.h
 *	@brief Representa un fichero en el sistema de recursos.
 *  @date 03/05/2013
 *  @Author: Ramón Díaz Valenzuela
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
	int tamanio;
public:
	Fichero(string nombre,string extension, int tamanio, Usuario* u);
	virtual ~Fichero();
	virtual string getNombre();
	virtual int getTamanio();
	virtual bool esDirectorio();
	virtual void setNombre(string nombre);
};

} /* namespace PGP */
#endif /* FICHERO_H_ */
