/*
 * main.cpp
 *
 *  Created on: 13/04/2013
 *      Author: Ramón
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
	string **p;
	p = new string*[2];
	p[0] = new string("Primera Cadena.");
	p[1] = new string("Segunda Cadena.");

	cout << *p[0] << endl;
	cout << *p[1] << endl;

	delete p[0];
	delete p[1];
	delete[] p;
}





