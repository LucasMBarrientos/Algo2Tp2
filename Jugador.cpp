
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

string Jugador::obtenerNombre(){
	return  this->nombre;
}

unsigned int Jugador::obtenerCantidadDeDisparos(){
	this->cantidadDeDisparos;
}

void Jugador::eliminarVariosSoldados(unsigned int cantidad){
	this->cantidadDeSoldados -= cantidad;
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

Coordenada obtenerCoordenada(){
	unsigned int x = pedirNumeroEntero("Ingrese una coordenada en X: ");
	unsigned int y = pedirNumeroEntero("Ingrese una coordenada en Y: ");
	unsigned int z = pedirNumeroEntero("Ingrese una coordenada en Z: ");
	return Coordenada(x,y,z);
}

void mostrarMensaje(string mensaje){
	cout<<mensaje<<endl;
}

bool esCadenaNumerica(string cadena){
	for(int i = 0; i<cadena.length();i++){
		if(!isdigit(cadena[i])) return false;
	}
	return true;
}

int pedirNumeroEntero(string mensaje){
	string cadena;
	mostrarMensaje(mensaje);
	cin>>cadena;
	while(esCadenaNumerica(cadena)){
		mostrarMensaje("Invalido, ingrese un nuevo numero:");
		cin>>cadena;
	}
	return stoi(cadena);
}

