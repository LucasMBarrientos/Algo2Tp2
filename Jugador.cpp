
#include "Jugador.h"

Jugador::Jugador(unsigned int id,std::string nombre){
  if( id < 0 || id > MAX_JUGADORES){
    throw "numero de valor invalido";
  }
  this->id = id;
  this->nombre = nombre;
  this->cantidadDeSoldados = 0;
  this->cantidadDeDisparos = 0;
}

unsigned int Jugador::obtenerId(){
  return this->id;
}

std::string Jugador::obtenerNombre(){
  return  this->nombre;
}


void Jugador::setcantidadDeSoldados(unsigned int cantidadDeSoldados){
  this->cantidadDeSoldados = cantidadDeSoldados;
}

unsigned int Jugador::getcantidadDeSoldados(){
  return this->cantidadDeSoldados;
}

void Jugador::setcantidadDeDisparos(unsigned int cantidadDeDisparos){
  this->cantidadDeDisparos = cantidadDeDisparos;
}

unsigned int Jugador::getcantidadDeDisparos(){
  return this->cantidadDeDisparos;
}

void Jugador::pedirCoordenadasDeAtaque() {

}

void Jugador::pedirCoordenadasDeMovimiento() {

}

void Jugador::eliminarSoldado(){

}

Jugador::~Jugador() {

}

