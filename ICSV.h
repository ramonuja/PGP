/*
 * ICSV.h
 *	@brief Interfaz para pasar los datos a o desde una cadena.
 *  @date 03/05/2013
 *  @Author: Ramón Díaz Valenzuela
 */

#ifndef ISERIALIZABLE_H_
#define ISERIALIZABLE_H_
#include <string>
using namespace std;
namespace PGP {
class ICSV {
public:
	ICSV(){}
	virtual ~ICSV(){}
	virtual void fromCSV(string s) = 0;
	virtual string toCSV() = 0;
};

} /* namespace PGP */
#endif /* ISERIALIZABLE_H_ */
