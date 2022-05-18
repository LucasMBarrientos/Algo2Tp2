
#ifndef CASILLA_H_
#define CASILLA_H_

#include "Parametros.h"

class Casilla {

	private:

		EstadoDeCasilla estado; // (inactiva, vacia, ocupada)   [ocupada: ¿con qué? y ¿de quien?]

	public:

		/**
		 * pre:
		 * pos:
		 */
		Casilla();

		/**
		 * pre:
		 * pos:
		 */
		~Casilla();
};

#endif /* CASILLA_H_ */
