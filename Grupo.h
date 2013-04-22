/*
 * Grupo.h
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#ifndef GRUPO_H_
#define GRUPO_H_
#include <string>
#include "Usuario.h"
using namespace std;

namespace PGP {
/*
 *
 */
class Grupo
{
private:
	Usuario* *constituyentes;
	string nombre;
public:
	bool altaUsuario(Usuario u);
	bool bajaUsuario(Usuario u);
	Grupo();
	virtual ~Grupo();
};

} /* namespace PGP */
#endif /* GRUPO_H_ */
