
#include "BatallaCampal.h"
#include <iostream>
using namespace std;

BatallaCampal::BatallaCampal() {
  this->jugadorActual = 1;
}

void BatallaCampal::menuPrincipal(){
  int soldadosPorJugador;
  cout << "Ingresar cantidad de jugadores";
  cin << this->cantidadDeJugadores; 
  cout << "Ingresar cantidad de soldados";
  cin << soldadosPorJugador;

  for(int i=1; i<=jugadorActual->getCantidadDeDisparos(); i++){
    this->ListaDeJugadores = new Lista<Jugador *> ();
  //for a cantidadDeJugadores
  //listaJugadores (agregar) jugador(soldadosPorJugador)

  //crear tablero
}


void BatallaCampal::inicializar(){
  menuPrincipal();
}

void BatallaCampal::jugar(){
  inicalizar(); //TODO: crear la funcion
  bool juegoActivo = true;
  while(juegoActivo){
    // if(!Carta()){
    //  return //Si carta mata al ultimo jugador termina el juego y el turno
    //  }
    if(!atacar()){
      break;
    }
    if(consultarUsuario("Desea realizar un movimiento?","Si","No")){
      if(!mover()){
        break;
      }
    }
    tablero->imprimirTablero();
  }
  // Mostrar ganadores
}

bool BatallaCampal::sigueJugando(){
  // devuelve si la lista de jugadores tiene al menos 2 items
}

void BatallaCampal::eliminarJugador(){
  // busco un jugador en la lista de jugadores y lo elimino por tener soldados = 0
}

bool BatallaCampal::atacar(){
  for(int i=1; i<=jugadorActual->getCantidadDeDisparos(); i++){//falta implementar getCantidadDeDisparos()
    bool ataqueValido = false;
    do 
      Coordenada coordenadaSeleccionada = this->jugadorActual->pedirCoordenadaDeAtaque();
      if(this->tablero->existeLaCasilla(coordenadaSeleccionada)){//Tiene que pasarle cada dato de la coordenada o el tipo coordenada entero?
        Casilla* casillaAtacada = this->tablero->getCasilla(coordenadaSeleccionada);
        if(!casillaAtacada->tieneJugador(this->jugadorActual)){
          if(casillaAtacada.getEstado() == OCUPADO){
            Jugador* jugadorAtacado = casillaAtacada->getJugador();
            if(casillaAtacada->tieneSoldado()){
              jugadorAtacado->eliminarUnSoldado();
              //Repazar la lista de jugadores para eliminar jugadores sin soldados
            }
            jugadorAtacado->reducirCantidadDisparos(casillaFinal->getCantidadDisparos());
            casillaAtacada->vaciar();
            casillaAtacada->inactivar();
            
          }else{ataqueValido = true}
        }else{ataqueValido = false}
      }
    while(!ataqueValido)
  }
  return sigueJugando();
} 

bool BatallaCampal::mover(){
  bool coordenadaInicialValida = false;
  do 
    Coordenada coordenadaSeleccionada = this->jugadorActual->pedirCoordenadaDeSeleccion();
    if(this->tablero->existeLaCasilla(coordenadaSeleccionada)){//Tiene que pasarle cada dato de la coordenada o el tipo coordenada entero?
      Casilla* casillaInicio = this->tablero->getCasilla(coordenadaSeleccionada);
      if(casillaInicio->tieneJugador(this->jugadorActual)){ 
        bool movimientoValido = false;
        do
          Coordenada movimientoSeleccionado = this->jugadorActual->pedirCoordenadaDeMovimiento();
          if(this->tablero->existeLaCasilla(movimientoSeleccionado)){//Tiene que pasarle cada dato de la coordenada o el tipo coordenada entero?
            Casilla* casillaFinal = this->tablero->getCasilla(coordenadaSeleccionada);
            if(!casillaFinal->tieneJugador(this->jugadorActual) && casillaInicio->getTipo() == casillaFinal->getTipo() && casillaFinal.getEstado() !=INACTIVA){
              if(casillaFinal.getEstado() == OCUPADO){
                Jugador* jugadorAtacado = casillaFinal->getJugador();
                if(casillaFinal->tieneSoldado()){
                  this->jugadorActual->eliminarUnSoldado();
                  jugadorAtacado->eliminarUnSoldado();

                }
                this->jugadorActual->reducirCantidadDisparos(casillaInicio->getCantidadDisparos());
                jugadorAtacado->reducirCantidadDisparos(casillaFinal->getCantidadDisparos());
                casillaFinal->inactivar();
              }else{
                casillaFinal->copiarCasilla(casillaInicio);
              }
              casillaInicio->vaciar();
              movimientoValido = true;
            }else{movimientoValido = false}
          }else{movimientoValido = false}

          if(!movimientoValido){
            cout<< "El movimiento no es valido."
            if(consultarUsuario("Desea seleccionar otro soldado?","Seleccionar otra ficha","Mover a otra casilla")){
              break;
            }
          }
        while(!movimientoValido)
      }else{coordenadaInicialValida = false}
    }else{coordenadaInicialValida = false}
  while(!coordenadaInicialValida)

  return sigueJugando();
} 

bool BatallaCampal::consultarUsuario(string pregunta, string opciontrue, string opcionFalse){
  do
    cout<< pregunta << endl;
    cout<< "0 -> " << opciontrue << endl;
    cout<< "1 -> " << opcionFalse << endl;
    cin >> opcionElegida;
  while(opcionElegida != 0 && opcionElegida != 1)
  if(opcionElegida == 0){
    return true
  }else{
    return false
  }
}


BatallaCampal::~BatallaCampal() {
  // borrar todos los datos
}
