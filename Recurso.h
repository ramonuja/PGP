/*
 * Recurso.h
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#ifndef RECURSO_H_
#define RECURSO_H_
namespace PGP {
#include <string>
using namespace std;

/*
 *
 */
class Recurso {
	private:
	string nombre;
	Permiso* *permisos;
public:
	Recurso();
	virtual ~Recurso();
};

} /* namespace PGP */
#endif /* RECURSO_H_ */
