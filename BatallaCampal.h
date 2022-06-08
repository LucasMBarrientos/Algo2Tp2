<<<<<<< HEAD

#ifndef BATALLACAMPAL_H_
#define BATALLACAMPAL_H_

class BatallaCampal {

	private:

	public:
		/**
		 * pre:
		 * pos:
=======
#ifndef BATALLACAMPAL_H_
#define BATALLACAMPAL_H_

#include "Jugador.h"
#include "Tablero.h"
#include "Lista.h"
#include "Ficha.h"
#include "Coordenadas.h"
#include <string>
#include "Carta.h"
class BatallaCampal {

	private:
    Lista<Jugador *>* ListaDeJugadores;
    Jugador* jugadorActual;
    Tablero* tablero;
    int cantidadDeJugadores;
    Carta* carta;
	public:
		/**
		 * pre:
		 * post: crea el objeto
>>>>>>> e415c573ecd72cb9a40cda720848ce8888660f1a
		 */
		BatallaCampal();

		/**
		 * pre:
<<<<<<< HEAD
		 * pos:
		 */
		void menuPrincipal();

		/**
		 * pre:
		 * pos:
		 */
		void inicializar();

		/**
		 * pre:
		 * pos:
		 */
		void jugar();	// pide coordenadas al jugador y al tablero, y las valida.

		/**
		 * pre:
		 * pos:
		 */
		bool sigueJugando();


		/**
		 * pre:
		 * pos:
		 */
		~BatallaCampal();
=======
		 * post:
		 */
		void jugar();	// pide coordenadas al jugador y al tablero, y las valida.

		/**
		 * pre:
		 * post: destruye el objeto
		 */
		~BatallaCampal();

    private:

    /**
		 * pre:
		 * post: crea el menu principal /definir como va a ser el menu
		 */
		int menuPrincipal();

		/**
		 * pre:
		 * post:
		 */
		void inicializar();

		bool atacar();
		bool mover();
		void eliminarJugador(Jugador* jugador);
    /**
		 * pre:
		 * post: valida si listaJugadores tiene mas de un item => devuelve true
		 */
		bool sigueJugando();

		bool consultarUsuario(std::string pregunta, std::string opciontrue, std::string opcionFalse);
		void elegirMovimiento(Casilla* casillaInicio);
>>>>>>> e415c573ecd72cb9a40cda720848ce8888660f1a
};

#endif /* BATALLACAMPAL_H_ */
