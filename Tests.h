/*
 * Tests.h
 *
 *  Created on: 25/04/2013
 *      Author: Ramón Díaz Valenzuela
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Usuario.h"
using namespace PGP;
class Tests {
private:
	Usuario *u;
	Grupo *g;
public:
	Tests();
	virtual ~Tests();
	void testGestionPermisos();
	void testUG();
};

#endif /* TESTS_H_ */
