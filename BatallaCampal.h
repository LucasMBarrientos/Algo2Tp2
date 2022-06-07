#ifndef BATALLACAMPAL_H_
#define BATALLACAMPAL_H_

#include "Jugador.h"
#include "Tablero.h"
#include "Lista.h"
#include "Ficha.h"
#include "Coordenadas.h"
#include <string>
class BatallaCampal {

	private:
    Lista<Jugador *>* ListaDeJugadores;
    Jugador* jugadorActual;
    Tablero* tablero;
    int cantidadDeJugadores;
    //Carta* carta;
	public:
		/**
		 * pre:
		 * post: crea el objeto
		 */
		BatallaCampal();

		/**
		 * pre:
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
};

#endif /* BATALLACAMPAL_H_ */
