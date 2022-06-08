
#include "Ficha.h"

Ficha::Ficha(TipoDeFicha tipo, Jugador* jugador) {
	if(jugador == NULL){
		throw std::string("El jugador no puede estar vacio");
	}

	this->tipo = tipo;
	this->jugador = jugador;

}

/**
 */
TipoDeFicha Ficha::getTipo(){
	return this->tipo;
}

/**
 */
void Ficha::setJugador(Jugador*& jugador){
	if(!jugador){
		throw std::string("El jugador no puede ser NULL");
	}
	this->jugador = jugador;
}

/**
 */
Jugador* Ficha::getJugador() {
	return this->jugador;
}


