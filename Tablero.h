
#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casilla.h"

class Tablero {

	private:
		Casilla casilla;

	public:
		/**
		 * pre:
		 * pos:
		 */
		Tablero();

		/**
		 * pre:
		 * pos:
		 */
		void inactivarCasilla();

		/**
		 * pre:
		 * pos:
		 */
		void colocarSoldado();

		/**
		 * pre:
		 * pos:
		 */
		void colocarBarco();

		/**
		 * pre:
		 * pos:
		 */
		void getInfoDeCasilla();


		/**
		 * pre:
		 * pos:
		 */
		~Tablero();
};

#endif /* TABLERO_H_ */
