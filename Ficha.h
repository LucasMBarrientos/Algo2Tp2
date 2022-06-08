
#ifndef FICHA_H_
#define FICHA_H_

#include "Jugador.h"

enum TipoDeFicha{
	SOLDADO,
	AVION,
	BARCO,
<<<<<<< HEAD

};

=======
	TANQUE,
	MINA,

};

const unsigned int cantidadDeDisparosAvion = 2;
//const unsigned int cantidadDeDisparosBarco = ??;
//const unsigned int cantidadDeDisparosTanque = ??;

>>>>>>> e415c573ecd72cb9a40cda720848ce8888660f1a
class Ficha {

	private:
		TipoDeFicha tipo;
		Jugador* jugador;

	public:
		/**
<<<<<<< HEAD
		 * pre: jugador no puede estar vacío.
=======
		 * pre: El jugador no puede estar vacío.
>>>>>>> e415c573ecd72cb9a40cda720848ce8888660f1a
		 * pos: Crea la ficha con el tipo y el jugador dado.
		 */
		Ficha(TipoDeFicha tipo, Jugador* jugador);

		/**
<<<<<<< HEAD
		 * pre: El jugador no puede estar vacío.
		 * pos:
=======
		 * pre: -
		 * pos: Devuelve el tipo de ficha.
		 */
		TipoDeFicha getTipo();

		/**
		 * pre: El jugador no puede estar vacío.
		 * pos: Establece al jugador como dueño de la ficha.
>>>>>>> e415c573ecd72cb9a40cda720848ce8888660f1a
		 */
		void setJugador(Jugador*& jugador);

		/**
		 * pre:-
<<<<<<< HEAD
		 * pos: devuelve el jugador dueño de la ficha.
		 */
		const Jugador*& getJugador() const;


		virtual ~Ficha();
=======
		 * pos: Devuelve el jugador dueño de la ficha.
		 */
		Jugador* getJugador();

>>>>>>> e415c573ecd72cb9a40cda720848ce8888660f1a
};

#endif /* FICHA_H_ */
