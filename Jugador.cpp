
#include "Jugador.h"

Jugador::Jugador(unsigned int id,std::string nombre,
unsigned int cantidadDeSoldados,unsigned int cantidadDeDisparos){
  if( id < 0 || id > MAX_JUGADORES){
    throw "numero de valor invalido";
  }
  this->id = id;
  this->nombre = nombre;
  this->cantidadDeSoldados = cantidadDeSoldados;
  this->cantidadDeDisparos = cantidadDeDisparos;
}

unsigned int Jugador::obtenerId(){
  return this->id;
}

std::string Jugador::obtenerNombre(){
  return  this->nombre;
}

void Jugador::sumarUnSoldadoSoldados(unsigned int cantidadDeDisparos){
  this->cantidadDeDisparos++;
}

void Jugador::eliminarUnSoldados(){
    this->cantidadDeDisparos--;
}

void Jugador::aumentarCantidadDisparos(unsigned int cantidadDeDisparos){
  this->cantidadDeDisparos+= cantidadDeDisparos;
}

void Jugador::reducirCantidadDisparos(int cantidadDeDisparos){
    if(cantidadDeDisparos > 0){
      throw "numero invalido positivo";
    }
    this->cantidadDeDisparos-= cantidadDeDisparos;
}

void Jugador::pedirCoordenadasDeAtaque() {

}

void Jugador::pedirCoordenadasDeMovimiento() {

}

void Jugador::eliminarSoldado(){

}

Jugador::~Jugador() {

}

