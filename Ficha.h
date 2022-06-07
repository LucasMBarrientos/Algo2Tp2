
#ifndef FICHA_H_
#define FICHA_H_

#include "Jugador.h"

enum TipoDeFicha{
	SOLDADO,
	AVION,
	BARCO,
	TANQUE,

};

const unsigned int cantidadDeDisparosAvion = 2;
//const unsigned int cantidadDeDisparosBarco = ??;
//const unsigned int cantidadDeDisparosTanque = ??;

class Ficha {

	private:
		TipoDeFicha tipo;
		Jugador* jugador;

	public:
		/**
		 * pre: El jugador no puede estar vacío.
		 * pos: Crea la ficha con el tipo y el jugador dado.
		 */
		Ficha(TipoDeFicha tipo, Jugador* jugador);

		/**
		 * pre: -
		 * pos: Devuelve el tipo de ficha.
		 */
		TipoDeFicha getTipo();

		/**
		 * pre: El jugador no puede estar vacío.
		 * pos: Establece al jugador como dueño de la ficha.
		 */
		void setJugador(Jugador*& jugador);

		/**
		 * pre:-
		 * pos: Devuelve el jugador dueño de la ficha.
		 */
		Jugador* getJugador();

};

#endif /* FICHA_H_ */
