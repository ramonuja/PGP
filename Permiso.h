
namespace PGP {

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

	bool isEjecucion() const {
		return ejecucion;
	}

	bool isEscritura() const {
		return escritura;
	}

	const Grupo*& getGrupo() const {
		return grupo;
	}

	bool isLectura() const {
		return lectura;
	}

	const Usuario*& getUsuario() const {
		return usuario;
	}

	void setEjecucion(bool ejecucion) {
		this->ejecucion = ejecucion;
	}

	void setEscritura(bool escritura) {
		this->escritura = escritura;
	}

	void setLectura(bool lectura) {
		this->lectura = lectura;
	}
};

} /* namespace PGP */
