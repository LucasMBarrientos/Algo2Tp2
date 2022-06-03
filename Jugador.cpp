
#include "Jugador.h"
#include <iostream>
using namespace std;

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

void Jugador::sumarUnSoldado(){
  this->cantidadDeSoldados++;
}

void Jugador::eliminarUnSoldado(){
    this->cantidadDeSoldados--;
}

void Jugador::aumentarCantidadDisparos(unsigned int disparosAumentados){
  this->cantidadDeDisparos += disparosAumentados;
}

void Jugador::reducirCantidadDisparos(int disparosReducidos){
    if(this->cantidadDeDisparos < disparosReducidos){
      throw "No se puede Reducir ese numero a la Cantidad de Disparos";
    }
    this->cantidadDeDisparos -= cantidadDeDisparos;
}

Coordenada pedirCoordenadaDeAtaque(){
	cout<< "Ingrese las coordenadas del Ataque: " << endl;
	return obtenerCoordenada();
}

Coordenada Jugador::pedirCoordenadaDeSeleccion() {
	cout << "Ingrese las coordenadas del Soldado a seleccionar: " << endl;
	return obtenerCoordenada();
}

Coordenada Jugador::pedirCoordenadaDeMovimiento() {
	cout << "Ingrese las coordenadas donde desea Mover al soldado: " << endl;
	return obtenerCoordenada();
}


Jugador::~Jugador() {

}

Coordenada obtenerCoordenada(){
	unsigned int x;
	unsigned int y;
	unsigned int z;
	cout<< "Ingrese una coordenada en X: "<< endl;
	cin >> x;
	cout<< "Ingrese una coordenada en Y: "<< endl;
	cin >> y;
	cout<< "Ingrese una coordenada en Z: "<< endl;
	cin >> z;
	return Coordenada(x,y,z);
}
