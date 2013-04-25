/*
 * Recurso.h
 *
 *  Created on: 12/04/2013
 *      Author: Ramón
 */

#ifndef RECURSO_H_
#define RECURSO_H_
#include <string>
#include "Usuario.h"

using namespace std;
namespace PGP {

class Recurso {
private:
	short permisosActuales;
	Usuario *u;
protected:
	string nombre;
public:
	enum AMBITOS {OTROS = 1, GRUPO = 8, PROPIETARIO = 64};
	enum PERMISOS { EJECUCION, ESCRITURA, LECTURA};
	int asignarPermisos(bool valor, short ambito, short permiso);
	int consultarPermiso(short ambito, short permiso);
	Recurso(string nombre, Usuario* u);
	virtual ~Recurso();
	short getPermisosActuales() const;
	void setPermisosActuales(short permisosActuales);
	virtual string getNombre()=0;
	virtual int getTamanio()=0;
	virtual bool esDirectorio()=0;
	string getDescripcion();
};

} /* namespace PGP */
#endif /* RECURSO_H_ */
