
#ifndef BATALLACAMPAL_H_
#define BATALLACAMPAL_H_

#include "Jugador.h"
#include "Tablero.h"
#include "Lista.h"
class BatallaCampal {

	private:
    LLista<Jugador *>* ListaDeJugadores;
    Jugador jugadorActual;
    Tablero tablero;
    int cantidadDeJugadores;
    /*Carta*/
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
		void menuPrincipal();

		/**
		 * pre:
		 * post: 
		 */
		void inicializar();


    /**
		 * pre:
		 * post: valida si listaJugadores tiene mas de un item => devuelve true
		 */
		bool sigueJugando();
		
};

#endif /* BATALLACAMPAL_H_ */
