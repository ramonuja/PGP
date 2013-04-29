/*
 * Usuario.h
 *
 *  Created on: 12/04/2013
 *      Author: Ram�n
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include <string>
#include "Grupo.h"
using namespace std;

namespace PGP {
/*
 *
 */
class Usuario {
private:
	string nombre;
public:
	Usuario(string nombre);
	virtual ~Usuario();
	string getNombre();
	void setNombre( string nombre);
};

} /* namespace PGP */
#endif /* USUARIO_H_ */
