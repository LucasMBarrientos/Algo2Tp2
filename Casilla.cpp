
#include "Casilla.h"


/**
 */
Casilla::Casilla(unsigned int x, unsigned int y, unsigned int z, TipoDeCasilla tipo) {
	if(x < 1){
		throw std::string("x debe ser mayor o igual a 1");
	}
	if(y < 1){
		throw std::string("y debe ser mayor o igual a 1");
	}
	if(z < 1){
		throw std::string("z debe ser mayor o igual a 1");
	}

	this->estado = VACIA;
	this->tipo = tipo;
	this->x = x;
	this->y = y;
	this->z = z;

	this->ficha = NULL;

}

/**
 */
bool Casilla::estaInactiva(){
	return (this->estado == INACTIVA);
}

/**
 */
bool Casilla::estaVacia(){
	return (this->estado == VACIA);
}

/**
 */
bool Casilla::estaOcupada(){
	return (this->estado == OCUPADA);
}


/**
 */
void Casilla::setEstado(EstadoDeCasilla estadoNuevo) {
	//esta validacion es opcional (p.ej: si quiero vaciar un casillero ya vacio)
	if (this->estado == estadoNuevo){
		throw std::string("No se puede setear la casilla en un estado identico al previo");
	}
	this->estado = estadoNuevo;
}

/**
 */
EstadoDeCasilla Casilla::getEstado() {
	return this->estado;
}

/**
 */
void Casilla::inactivar(){
	this->ficha = NULL;
	this->setEstado(INACTIVA);
}

/**
 */
void Casilla::vaciar(){
	this->ficha = NULL;
	this->setEstado(VACIA);
}

/**
 */
void Casilla::ocupar(){
	this->setEstado(OCUPADA);
}

/**
 */
TipoDeCasilla Casilla::getTipo() {
	return this->tipo;
}

/**
 */
unsigned int Casilla::getX() {
	return this->x;
}

/**
 */
unsigned int Casilla::getY() {
	return this->y;
}

/**
 */
unsigned int Casilla::getZ() {
	return this->z;
}

/**
 */
Ficha* Casilla::getFicha(){//----------------------------------------¿¿ diferencia con Ficha*& ??
	return this->ficha;
}

/**
 */
void Casilla::setFicha( Ficha*& ficha){
	if(ficha == NULL){
		throw std::string("La ficha no puede estar vacia");
	}

	this->ficha = ficha;
	this->estado = OCUPADA;
}


/**
 */
void Casilla::setTipo(TipoDeCasilla tipo){
	if (this->tipo == tipo){
		throw std::string("No se puede setear la casilla en un tipo identico al previo");
	}
	this->tipo = tipo;
}

/**
 */
bool Casilla::tieneJugador(Jugador* jugador){
	return (jugador == this->ficha->getJugador());

}
/**
 */
Jugador* Casilla::getJugador(){
	return this->ficha->getJugador();

}
