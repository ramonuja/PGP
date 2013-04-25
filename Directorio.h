/*
 * Directorio.h
 *
 *  Created on: 12/04/2013
 *      Author: Ram�n
 */

#ifndef DIRECTORIO_H_
#define DIRECTORIO_H_

#include <string>
#include "Recurso.h"
#include "Usuario.h"

using namespace std;
namespace PGP 
{
/*
 *
 */
class Directorio: public PGP::Recurso {
private:
	/**
	 * La construcci�n y destrucci�n de los recursos se hace dentro de esta clase.
	 */
	Recurso** recursos;
	int nRecursos;//n�mero de recursos contenidos en un momento determinado dentro del directorio.
public:
	void crearDirectorio(string nombre, Usuario* u);
	void crearFichero(string nombre, string extension, int tamanio, Usuario* u);
	void eliminarRecurso(int indice);
	Directorio(string nombre, Usuario* usuario);
	virtual ~Directorio();
	virtual string getNombre();
	virtual int getTamanio();
	virtual bool esDirectorio();
};

} /* namespace PGP */
#endif /* DIRECTORIO_H_ */
