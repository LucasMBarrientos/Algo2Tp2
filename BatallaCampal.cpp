

#include "BatallaCampal.h"

/**
 * pre:
 * pos:
 */
BatallaCampal::BatallaCampal() {
  this->jugadorActual = 1;
}

/**
 * pre:
 * pos:
 */
void BatallaCampal::menuPrincipal(){
  int soldadosPorJugador;
  cout << "Ingresar cantidad de jugadores";
  cin << cantidadDeJugadores; 
  cout << "Ingresar cantidad de soldados";
  cin << soldadosPorJugador;

  //for a cantidadDeJugadores
  //listaJugadores (agregar) jugador(soldadosPorJugador)

  //crear tablero
}

/**
 * pre:
 * pos:
 */
void BatallaCampal::inicializar(){
  // 
}

/**
 * pre:
 * pos:
 */
void BatallaCampal::jugar(){
  //inicalizar()
  //juegoActivo = true;
  //while(juegoActivo){
  /* TURNO */
  // if(!Carta()){
  //  return //Si carta mata al ultimo jugador termina el juego y el turno
  //  }
  // if(!Atacar()){
  //  return //Si Atacar mata al ultimo jugador termina el juego y el turno
  // }
  // Pregunta movimiento
  // true =>
  //  if(!Mover()){
  //  return //Si al mover se destruye el ultimo soldado del jugador se termina el juego y el turno
  // }
  //  tablero->imprimir()
  //}
  // Mostrar ganadores


  /* ATACAR */
  // for de jugadorActual->cantidadDeDisparos
    // bool ataqueValido
    //  do
    //    Coordenada coordenadaDeAtaque = jugadorActual->atacar();
    //    if(this->tablero->validarCoordenada(coordenadaDeAtaque)){
    //          Casilla casillaSeleccionada = this->tablero->traerCasilla()
    //          /*Validaciones de juego*/
    //          si casillaSeleccionada esta ocupada me fijo que tiene y de quien y hago la accion correspondiente
    //          si se elimino el ultimo soldado de un jugador, elimino ese jugador y llamo a seguirjugando()
    //    }else{ataqueValido = false}
    //  while(!ataqueValido)


  /* MOVER */
  // bool soldadoValido  
  //  do
  //    Coordenada soldadoSeleccionado = jugadorActual->seleccionarSoldado();
  //    if(this->tablero->validarCoordenada(soldadoSeleccionado)){
  //      Casilla casillaSeleccionada = this->tablero->traerCasilla()
  //      /*Validaciones de juego*/
          // bool movimientoValido  
          // do
          //  Coordenada movimientoSeleccionado = jugadorActual->moverSoldado();
          //  if(this->tablero->validarCoordenada(movimientoSeleccionado)){
          //    Casilla casillaSeleccionada = this->tablero->traerCasilla()
          //    /*Validaciones de juego*/
          //  }else{movimientoValido = false}

          //  if(movimientoValido == false){
          //    /* quiere mover otro soldado? */
          //    true => salgo del do while ;
          //  }
          // while(!movimientoValido)
  //    }else{soldadoValido = false}
  //  while(!soldadoValido)

  //}

  //juegoActivo = sigueJugando();
  //
}

/**
 * pre:
 * pos:
 */
bool BatallaCampal::sigueJugando(){
  // devuelve si la lista de jugadores tiene al menos 2 items
}

/**
 * pre:
 * pos:
 */
BatallaCampal::~BatallaCampal() {
  // borrar todos los datos
}

