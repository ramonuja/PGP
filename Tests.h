/*
 * Tests.h
 *
 *  Created on: 25/04/2013
 *      Author: druida
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Usuario.h"
using namespace PGP;
class Tests {
private:
	Usuario *u;
public:
	Tests();
	virtual ~Tests();
	void testGestionPermisos();
};

#endif /* TESTS_H_ */
