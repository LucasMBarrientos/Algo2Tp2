<<<<<<< HEAD

#include "Jugador.h"
/**
 * pre:
 * pos:
 */
Jugador::Jugador() {
  this->cantidadDeSoldados = 0;
  this->cantidadDeDisparos = 0;
}

/**
 * pre:
 * pos:
 */
void Jugador::pedirCoordenadasDeAtaque() {

}

/**
 * pre:
 * pos:
 */
void Jugador::pedirCoordenadasDeMovimiento() {

}

/**
 * pre:
 * pos:
 */
Jugador::~Jugador() {
}

=======
#include "Jugador.h"
#include <iostream>
#include <cstdlib>

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

void Jugador::eliminarVariosSoldados(unsigned int cantidad){
	this->cantidadDeSoldados -= cantidad;
}

unsigned int Jugador::obtenerId(){
	return this->id;
}

string Jugador::obtenerNombre(){
	return  this->nombre;
}

unsigned int Jugador::obtenerCantidadDeDisparos(){
	return this->cantidadDeDisparos;
}

unsigned int Jugador::obtenerCantidadDeDisparosMisil(){
	return this->cantidadDeDisparosMisil;
}

unsigned int Jugador::obtenerCantidadDeSoldados(){
  return this->cantidadDeSoldados;
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

void Jugador::reducirCantidadDisparos(unsigned int disparosReducidos){
    if(this->cantidadDeDisparos < disparosReducidos){
      throw "No se puede Reducir ese numero a la Cantidad de Disparos";
    }
    this->cantidadDeDisparos -= cantidadDeDisparos;
}

void Jugador::aumentarCantidadDisparosMisil(unsigned int disparosAumentados){
	this->cantidadDeDisparosMisil += disparosAumentados;
}

void Jugador::reducirCantidadDisparosMisil(unsigned int disparosReducidos){
    if(this->cantidadDeDisparosMisil < disparosReducidos){
      throw "No se puede Reducir ese numero a la Cantidad de Disparos";
    }
    this->cantidadDeDisparosMisil -= cantidadDeDisparos;
}

void mostrarMensaje(string mensaje){
	cout<<mensaje<<endl;
}

bool esCadenaNumerica(string cadena){
	for(unsigned int i = 0; i<cadena.length();i++){
		if(!isdigit(cadena[i])) return false;
	}
	return true;
}

int pedirNumeroEntero(string mensaje){
	string cadena;
	mostrarMensaje(mensaje);
	cin>>cadena;
	while(!esCadenaNumerica(cadena)){
		mostrarMensaje("Invalido, ingrese un nuevo numero:");
		cin>>cadena;
	}
	return atoi(cadena.c_str());
}

Coordenada Jugador::pedirCoordenadaDeAtaque(){
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

Coordenada Jugador::obtenerCoordenada(){
	unsigned int x = pedirNumeroEntero("Ingrese una coordenada en X: ");
	unsigned int y = pedirNumeroEntero("Ingrese una coordenada en Y: ");
	unsigned int z = pedirNumeroEntero("Ingrese una coordenada en Z: ");
	return Coordenada(x,y,z);
}

Jugador::~Jugador() {

}
>>>>>>> e415c573ecd72cb9a40cda720848ce8888660f1a
