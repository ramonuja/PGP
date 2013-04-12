/*
 * Usuario.h
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#ifndef USUARIO_H_
#define USUARIO_H_

namespace PGP {
#include <string>
using namespace std;
/*
 *
 */
class Usuario {
private:
	string nombre;
public:
	Usuario();
	virtual ~Usuario();
};

} /* namespace PGP */
#endif /* USUARIO_H_ */
