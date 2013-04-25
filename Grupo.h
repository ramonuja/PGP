/*
 * Grupo.h
 *
 *  Created on: 12/04/2013
 *      Author: Ram�n
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
	Usuario** constituyentes;
	int nConstituyentes;
	string nombre;
public:
	void altaUsuario(Usuario* u);
	void bajaUsuario(Usuario* u);
	Grupo(string nombre);
	virtual ~Grupo();
};

} /* namespace PGP */
#endif /* GRUPO_H_ */
