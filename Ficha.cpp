
#include "Ficha.h"

Ficha::Ficha(TipoDeFicha tipo, Jugador* jugador) {
	if(jugador == NULL){
		throw std::string("El jugador no puede estar vacio");
	}

	this->tipo = tipo;
	this->jugador = jugador;

}

Ficha::~Ficha() {
}

