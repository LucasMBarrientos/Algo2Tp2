
#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>


class Jugador {

	private:

		std::string identificador; //  ID del jugador (puede ser otro tipo de dato)
		unsigned int cantidadDeSoldados;
		unsigned int cantidadDeDisparos;

	public:

		/**
		 * pre:
		 * pos:
		 */
		Jugador();

		/**
		 * pre:
		 * pos:
		 */
		void pedirCoordenadasDeAtaque();

		/**
		 * pre:
		 * pos:
		 */
		void pedirCoordenadasDeMovimiento();

		/**
		 * pre:
		 * pos:
		 */
		void eliminarSoldado();


		/**
		 * pre:
		 * pos: Libera los recursos tomados
		 */
		~Jugador();
};

#endif /* JUGADOR_H_ */
