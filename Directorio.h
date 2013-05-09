/*
 * Directorio.h
 *	@brief Representa un directorio en el sistema de recursos.
 *  @date 03/05/2013
 *  @Author: Ramón Díaz Valenzuela
 */

#ifndef DIRECTORIO_H_
#define DIRECTORIO_H_

#include <string>
#include <vector>
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
	Directorio* padre;
public:
	void crearDirectorio(string nombre, Usuario* u);
	void crearFichero(string nombre, string extension, int tamanio, Usuario* u);
	void eliminarRecurso(int indice);
	Directorio(string nombre, Usuario* usuario, Directorio* padre);
	virtual ~Directorio();
	virtual string getNombre();
	virtual int getTamanio();
	virtual bool esDirectorio();
	Directorio* getPadre();
	int getNRecursos() const;
	void setRecursos(int recursos);
	Recurso** getRecursos();
	vector<Recurso*> recorrer();
	vector<Recurso*> recorrer(Directorio* d);
	virtual void setNombre(string nombre);
	Recurso* getRecursoxNombre(string nombre);
};

} /* namespace PGP */
#endif /* DIRECTORIO_H_ */
