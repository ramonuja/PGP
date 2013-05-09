/*
 * main.cpp
 *
 *  Created on: 13/04/2013
 *      Author: Ramón Díaz Valenzuela
 */
#include <iostream>
#include <string>
#include <math.h>
#include <exception>
#include "Tests.h"
#include "Aplicacion.h"


using namespace std;
using namespace PGP;
enum AMBITOS {OTROS = 1, GRUPO = 8, PROPIETARIO = 64};
enum PERMISOS { EJECUCION, ESCRITURA, LECTURA};

short permisosActuales = 0;


void tests(){
	Tests t;
	//t.testGestionPermisos();
	t.testUG();

}

int main(int argc, char **argv) {
	try{
	//enviar parametro debug para depurar. Método tests().
	if (argc>1){
		string s(argv[1]);
		if(s == "debug"){
			tests();
			return 0;
		}
	}
	int cod = 0;
	Aplicacion p;
	while(true){
		cout << endl << p.getPrompt() ;
		string s;
		getline(cin, s);
		cod = p.parsear(s);
		if (cod == -1) break;
	}//end_outerwhile
	}catch(exception & e){
		cout << e.what() << endl;
	}
}//end_main





