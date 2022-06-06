#include "Ficha.h"

Ficha::Ficha(TipoDeFicha tipo, Jugador* jugador) {
	if(jugador == NULL){
		throw std::string("El jugador no puede estar vacio");
	}

	this->tipo = tipo;
	this->jugador = jugador;

}

/**
 * pre:
 * pos:
 */
TipoDeFicha Ficha::getTipo(){
	return this->tipo;
}

/**
 * pre:
 * pos:
 */
void Ficha::setJugador(Jugador*& jugador){
	this->jugador = jugador;
}

/**
 *pre:
 *pos:
 */
Jugador* Ficha::getJugador() {
	return this->jugador;
}

/**
 * pre:
 * pos:
 */
Ficha::~Ficha() {
}
