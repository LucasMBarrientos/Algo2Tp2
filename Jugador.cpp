
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

void Jugador::sumarUnSoldadoSoldados(){
  this->cantidadDeSoldados++;
}

void Jugador::eliminarUnSoldados(){
    this->cantidadDeSoldados--;
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

void Jugador::pedirCoordenadasDeAtaque(coordenada ataque) {
	std::cout<< "Ingrese las coordenadas del Ataque: " << endl;
	
	std::cout<< "Ingrese una coordenada en X: ";
	std::cin >> ataque->x;
	std::cout<< "Ingrese una coordenada en Y: ";
	std::cin >> ataque->y;
	std::cout<< "Ingrese una coordenada en Z: ";
	std::cin >> ataque->z;
}

void Jugador::pedirCoordenadasDeSeleccion(coordenada seleccion) {
	std::cout<< "Ingrese las coordenadas del Soldado a seleccionar: " << endl;
	
	std::cout<< "Ingrese una coordenada en X: ";
	std::cin >> seleccion->x;
	std::cout<< "Ingrese una coordenada en Y: ";
	std::cin >> seleccion->y;
	std::cout<< "Ingrese una coordenada en Z: ";
	std::cin >> seleccion->z;
}

void Jugador::pedirCoordenadasDeMovimiento(coordenada movimiento) {
	std::cout<< "Ingrese las coordenadas donde desea Mover al soldado: " << endl;
	
	std::cout<< "Ingrese una coordenada en X: ";
	std::cin >> movimiento->x;
	std::cout<< "Ingrese una coordenada en Y: ";
	std::cin >> movimiento->y;
	std::cout<< "Ingrese una coordenada en Z: ";
	std::cin >> movimiento->z;
}

void Jugador::eliminarSoldado(){

}

Jugador::~Jugador() {

}

