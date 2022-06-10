#ifndef BATALLACAMPAL_H_
#define BATALLACAMPAL_H_

#include "Jugador.h"
#include "Tablero.h"
#include "Lista.h"
#include "Ficha.h"
#include "Coordenadas.h"
#include <string>
#include <cmath>

#include "Carta.h"

enum TipoDeAtaque {
	ATAQUE_SOLDADO, ATAQUE_TANQUE, ATAQUE_MISIL,
};

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

	void atacar(Casilla* casillaAtacada);
	bool mover(bool poniendoMina);
	void eliminarJugador(Jugador* jugador);
	/**
	 * pre:
	 * post: valida si listaJugadores tiene mas de un item => devuelve true
	 */
	bool sigueJugando();

	bool consultarUsuario(std::string pregunta, std::string opciontrue,
			std::string opcionFalse);
	bool elegirMovimiento(Casilla* casillaInicio);
	void cambiarTurno();
	bool validarMovimiento(Casilla* casillaInicio, Casilla* casillaFinal);
	bool ejecutarCarta(Jugador* jugador, Tablero* tablero,
			Lista<Jugador *>* ListaDeJugadores);
	bool ataqueArtilleria(Jugador* jugador, Tablero* tablero,
			Lista<Jugador *>* ListaDeJugadores, bool disparoForzado,
			bool misil);
	bool realizarAtaque(TipoDeAtaque tipoDeAtaque, unsigned int disparos);
	void recibirAtaque(Jugador* jugador, TipoDeFicha ficha);
	bool validarCoordenada(Coordenada coordenada);

};

#endif /* BATALLACAMPAL_H_ */
