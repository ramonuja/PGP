/*
 * Usuario.h
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include <string>
using namespace std;

namespace PGP {
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
