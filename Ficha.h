
#ifndef FICHA_H_
#define FICHA_H_

#include "Jugador.h"

enum TipoDeFicha{
	SOLDADO,
	AVION,
	BARCO,

};

class Ficha {

	private:
		TipoDeFicha tipo;
		Jugador* jugador;

	public:
		/**
		 * pre: jugador no puede estar vacío.
		 * pos: Crea la ficha con el tipo y el jugador dado.
		 */
		Ficha(TipoDeFicha tipo, Jugador* jugador);

		/**
		 * pre: El jugador no puede estar vacío.
		 * pos:
		 */
		void setJugador(Jugador*& jugador);

		/**
		 * pre:-
		 * pos: devuelve el jugador dueño de la ficha.
		 */
		const Jugador*& getJugador() const;


		virtual ~Ficha();
};

#endif /* FICHA_H_ */
