
#ifndef CASILLA_H_
#define CASILLA_H_

#include "Ficha.h"
#include <string>


enum EstadoDeCasilla {
	INACTIVA,
	VACIA,
	OCUPADA

};

enum TipoDeCasilla{
	TIERRA,
	AGUA,
	AIRE,
	USO_GENERAL //permite reutilizar el Casillero en otro contexo

};

class Casilla {

	private:

		EstadoDeCasilla estado; // (inactiva, vacia, ocupada)   [ocupada: ¿con qué? y ¿de quien?]
		TipoDeCasilla tipo;
		unsigned int x;
		unsigned int y;
		unsigned int z;
		Ficha* ficha;

	public:

		/**
		 * pre: x y z deben ser mayores o igual a 1.
		 * pos: La casilla queda creada en la posicion (x,y,z) con ese tipo, en
		 * 		estado vacia y sin fichas.
		 */
		Casilla(unsigned int x, unsigned int y, unsigned int z, TipoDeCasilla tipo);
//-------------------------------------------------------------------------------
		/**
		 * pre: -
		 * pos: Devuelve true si la casilla esta inactiva.
		 */
		bool estaInactiva();

		/**
		 * pre: -
		 * pos: Devuelve true si la casilla esta vacia.
		 */
		bool estaVacia();

		/**
		 * pre: -
		 * pos: Devuelve true si la casilla esta ocupada.
		 */
		bool estaOcupada();
//-------------------------------------------------------------------------------
		/**
		 * pre: La casilla no puede estar inactiva.
		 * 		[estaInactiva() debe ser false].
		 * pos: Elimina la ficha e inactiva la casilla.
		 */
		void inactivar();

		/**
		 * pre: La casilla no puede estar vacía.
		 * 		[estaVacia() debe ser false].
		 * pos: Elimina la ficha y vacía la casilla.
		 */
		void vaciar();

		/**
		 * pre: La casilla no puede estar ocupada.
		 * 		[estaOcupada() debe ser false].
		 * pos: La casilla queda ocupada.
		 */
		void ocupar();

		/*
		 * pre: La ficha no puede estar vacia.
		 * 		El jugador no puede ser NULL.
		 * pos: Ocupa la casilla con una ficha del jugador.
		 */
		void ocupar(Ficha* ficha, Jugador* jugador);
//-------------------------------------------------------------------------------
		/**
		 * pre:
		 * pos: Devuelve el estado de la casilla actual.
		 */
		EstadoDeCasilla getEstado();

		/**
		 * pre:
		 * pos: Devuelve el tipo de la casilla actual.
		 */
		TipoDeCasilla getTipo();


		/*
		 * pre:-
		 * pos: Devuelve true si jugador tiene cualquier ficha en la casilla.
		 */
		bool tieneJugador(Jugador* jugador);

		/**
		 * pre:
		 * pos: Devuelve el jugador dueño de la ficha ubicada en la casilla.
		 */
		Jugador* getJugador();

		/**
		 * pre: El tipo nuevo no puede ser igual al que ya tiene la casilla.
		 * pos: Cambia el tipo de la casilla.
		 */
		void setTipo(TipoDeCasilla tipo);
		/**
		 * pre: -
		 * pos: Devuelve la coordenada X entre 1 y el maximo.
		 */
		unsigned int getX();

		/**
		 * pre: -
		 * pos: Devuelve la coordenada Y entre 1 y el maximo.
		 */
		unsigned int getY();

		/**
		 * pre: -
		 * pos: Devuelve la coordenada Z entre 1 y el maximo.
		 */
		unsigned int getZ();

		/**
		 * pre: Tiene que existir una ficha en la casilla.
		 * pos: Devuelve la ficha de la casilla o NULL si esta vacío.
		 */
		Ficha* getFicha();

		/**
		 * pre: la ficha no es vacia.
		 * pos: Cambia la ficha de la casilla.
		 */
		void setFicha( Ficha*& ficha);


	private:
		/**
		 * pre: El estado nuevo no puede ser igual al que ya tiene la casilla.
		 * pos: Cambia el estado de la casilla.
		 */
		void setEstado(EstadoDeCasilla estadoNuevo);
};

#endif /* CASILLA_H_ */
