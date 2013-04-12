
namespace PGP {

/*
 *
 */
class Permiso {
private:
	Grupo* g;
	Permiso* p;
	bool lectura;
	bool escritura;
	bool ejecucion;
public:
	Permiso();
	virtual ~Permiso();
};

} /* namespace PGP */
