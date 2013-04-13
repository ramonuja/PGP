
namespace PGP {
#include <string>
using namespace std;
/*
 *
 */
class Permiso {
private:
	Grupo* grupo;
	Usuario* usuario;
	bool lectura;
	bool escritura;
	bool ejecucion;
public:
	Permiso(bool lectura, bool escritura, bool ejecucion, Grupo g);
	Permiso(bool lectura, bool escritura, bool ejecucion, Usuario u);
	virtual ~Permiso();
	bool isEjecucion() const;
	void setEjecucion(bool ejecucion);
	bool isEscritura() const;
	void setEscritura(bool escritura);
	const Grupo*& getGrupo() const;
	bool isLectura() const;
	void setLectura(bool lectura);
	const Usuario*& getUsuario() const;
};



} /* namespace PGP */
