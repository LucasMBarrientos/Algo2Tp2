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
	this->estado = HABILITADO;
	this->cantidadDeDisparosMisil = 0;
	this->cantidadDeDisparosTanque = 0;
}

void Jugador::eliminarVariosSoldados(unsigned int cantidadSoldados){
	if(this->obtenerCantidadDeSoldados() < cantidadSoldados){
      throw "No se puede Reducir ese numero a la Cantidad de Soldados";
    }
	this->cantidadDeSoldados -= cantidadSoldados;
}

unsigned int Jugador::obtenerId(){
	return this->id;
}

string Jugador::obtenerNombre(){
	return  this->nombre;
}

unsigned int Jugador::obtenerCantidadDisparos(){
	return this->cantidadDeDisparos;
}

unsigned int Jugador::obtenerCantidadDeDisparosMisil(){
	return this->cantidadDeDisparosMisil;
}

unsigned int Jugador::obtenerCantidadDeDisparosTanque(){
	return this->cantidadDeDisparosTanque;
}

unsigned int Jugador::obtenerCantidadDeSoldados(){
  return this->cantidadDeSoldados;
}

Permiso Jugador::obtenerPermiso(){
	return this->estado;
}

void Jugador::habilitarJugador(){
	if(this->obtenerPermiso() == HABILITADO){
		throw "Error: Ya se encuentra habilitado";
	}
	this->estado = HABILITADO;
}

void Jugador::bloquearJugador(){
	if(this->obtenerPermiso() == BLOQUEADO){
		throw "Error: Ya se encuentra bloqueado";
	}
	this->estado = BLOQUEADO;
}

void Jugador::sumarUnSoldado(){
	this->cantidadDeSoldados++;
}

void Jugador::eliminarUnSoldado(){
    if(this->obtenerCantidadDeSoldados() < 0){
      throw "No se puede Reducir ese numero a la Cantidad de Soldados";
    }
    this->cantidadDeSoldados--;
}

void Jugador::aumentarCantidadDisparos(unsigned int disparosAumentados){
	this->cantidadDeDisparos += disparosAumentados;
}

void Jugador::reducirCantidadDisparos(unsigned int disparosReducidos){
    if(this->obtenerCantidadDisparos() < disparosReducidos){
      throw "No se puede Reducir ese numero a la Cantidad de Disparos";
    }
    this->cantidadDeDisparos -= cantidadDeDisparos;
}

void Jugador::aumentarCantidadDisparosMisil(unsigned int disparosAumentados){
	this->cantidadDeDisparosMisil += disparosAumentados;
}

void Jugador::reducirCantidadDisparosMisil(unsigned int disparosReducidos){
    if(this->obtenerCantidadDeDisparosMisil() < disparosReducidos){
      throw "No se puede Reducir ese numero a la Cantidad de Disparos";
    }
    this->cantidadDeDisparosMisil -= cantidadDeDisparos;
}

void Jugador::aumentarCantidadDisparosTanque(unsigned int disparosAumentados){
	this->cantidadDeDisparosTanque += disparosAumentados;
}

void Jugador::reducirCantidadDisparosTanque(unsigned int disparosReducidos){
    if(this->obtenerCantidadDeDisparosTanque() < disparosReducidos){
      throw "No se puede Reducir ese numero a la Cantidad de Disparos";
    }
    this->cantidadDeDisparosTanque -= cantidadDeDisparos;
}

void Jugador::mostrarMensaje(string mensaje){
	cout<<mensaje<<endl;
}

bool Jugador::esCadenaNumerica(string cadena){
	for(unsigned int i = 0; i<cadena.length();i++){
		if(!isdigit(cadena[i])) return false;
	}
	return true;
}

int Jugador::pedirNumeroEntero(string mensaje){
	string cadena;
	mostrarMensaje(mensaje);
	cin>>cadena;
	while(!esCadenaNumerica(cadena)){
		mostrarMensaje("Invalido, ingrese un nuevo numero:");
		cin>>cadena;
	}
	return atoi(cadena.c_str());
}

void Jugador::pedirCoordenadaDeAtaque(Coordenada &coordenada){
	cout<< "Ingrese las coordenadas del Ataque: " << endl;
	obtenerCoordenada(coordenada);
}

void Jugador::pedirCoordenadaDeSeleccion(Coordenada &coordenada) {
	cout << "Ingrese las coordenadas del Soldado a seleccionar: " << endl;
	obtenerCoordenada(coordenada);
}

void Jugador::pedirCoordenadaDeMovimiento(Coordenada &coordenada) {
	cout << "Ingrese las coordenadas donde desea Mover al soldado: " << endl;
	obtenerCoordenada(coordenada);
}

void Jugador::obtenerCoordenada(Coordenada &coordenada){
	coordenada.setX(pedirNumeroEntero("Ingrese una coordenada en X: "));
	coordenada.setY(pedirNumeroEntero("Ingrese una coordenada en Y: "));
	coordenada.setZ(pedirNumeroEntero("Ingrese una coordenada en Z: "));
}

