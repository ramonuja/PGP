/*
 * Grupo.h
 *
 *  Created on: 12/04/2013
 *      Author: Ramón Díaz Valenzuela
 */

#ifndef GRUPO_H_
#define GRUPO_H_
#include <string>
#include "Usuario.h"
#include "ICSV.h"

using namespace std;

namespace PGP {
/*
 *
 */
class Grupo : public ICSV
{
private:
	string nombre;
public:
	Grupo(string nombre);
	virtual ~Grupo();
	string getNombre();
	void setNombre(string nombre);
	virtual void fromCSV(string s);
	virtual string toCSV();
};

} /* namespace PGP */
#endif /* GRUPO_H_ */
