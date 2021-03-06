/*
 * Usuario.h
 *	@brief Almacena un usuario del sistema.
 *  @date 03/05/2013
 *  @Author: Ramón Díaz Valenzuela
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include <string>
#include "Grupo.h"
#include "ICSV.h"
using namespace std;

namespace PGP{
/*
 *
 */
class Usuario : public ICSV{
private:
	string nombre;
public:
	Usuario(string nombre);
	virtual ~Usuario();
	string getNombre();
	void setNombre( string nombre);
	virtual void fromCSV(string s);
	virtual string toCSV();
};

} /* namespace PGP */
#endif /* USUARIO_H_ */
