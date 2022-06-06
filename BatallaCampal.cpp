
#include "BatallaCampal.h"
#include <iostream>
using namespace std;

BatallaCampal::BatallaCampal(){
  this->jugadorActual = NULL;
  this->cantidadDeJugadores=0;
  this->tablero=NULL;
  this->ListaDeJugadores=NULL;
}

int BatallaCampal::menuPrincipal(){
  int soldadosPorJugador;
  cout << "Ingresar cantidad de jugadores";
  cin >> this->cantidadDeJugadores;
  cout << "Ingresar cantidad de soldados";
  cin >> soldadosPorJugador;
  return soldadosPorJugador;
}


void BatallaCampal::inicializar(){
	this->ListaDeJugadores = new Lista<Jugador*>();
	int soldadosPorJugador = menuPrincipal();
	for(int i = 1; i <= this->cantidadDeJugadores; i++){
		string nombreJugador;
		cout << "Ingrese el nombre del jugador " << i <<": ";
		cin >> nombreJugador;
		Jugador* jugador = new Jugador(i,nombreJugador,soldadosPorJugador,soldadosPorJugador);
		this->ListaDeJugadores->agregar(jugador);
	}
	this->jugadorActual = this->ListaDeJugadores->obtener(1);

	//CREAR TABLERO
}

void BatallaCampal::jugar(){
	inicializar();
	bool juegoActivo = true;
  while(juegoActivo){
	  cout << "TURNO DE " << this->jugadorActual->obtenerNombre() << endl;
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

  //tablero->imprimirTablero();
  }
  // Mostrar ganadores
}

bool BatallaCampal::sigueJugando(){
  return true;// devuelve si la lista de jugadores tiene al menos 2 items
}

void BatallaCampal::eliminarJugador(){
  // busco un jugador en la lista de jugadores y lo elimino por tener soldados = 0
}

bool BatallaCampal::atacar(){
  for(int i=1; i<=/*jugadorActual->getCantidadDeDisparos()*/1; i++){//falta implementar getCantidadDeDisparos()
    bool ataqueValido = false;
    do{
      Coordenada coordenadaSeleccionada = this->jugadorActual->pedirCoordenadaDeAtaque();
      if(this->tablero->existeLaCasilla(/*coordenadaSeleccionada*/1,1,1)){//Tiene que pasarle cada dato de la coordenada o el tipo coordenada entero?
        Casilla* casillaAtacada = this->tablero->getCasilla(/*coordenadaSeleccionada*/1,1,1);
        if(!casillaAtacada->tieneJugador(this->jugadorActual)){
          if(/*casillaAtacada.getEstado() == OCUPADO*/true){
            Jugador* jugadorAtacado = casillaAtacada->getJugador();
            if(/*casillaAtacada->tieneSoldado()*/true){
              jugadorAtacado->eliminarUnSoldado();
              //Repazar la lista de jugadores para eliminar jugadores sin soldados
            }
            jugadorAtacado->reducirCantidadDisparos(/*casillaAtacada->getCantidadDisparos()*/1);
            casillaAtacada->vaciar();
            casillaAtacada->inactivar();

          }else{ataqueValido = true;}
        }else{ataqueValido = false;}
      }
    }while(!ataqueValido);
  }
  return sigueJugando();
}

bool BatallaCampal::mover(){
	bool coordenadaInicialValida = false;

	do{
		Coordenada coordenadaSeleccionada = this->jugadorActual->pedirCoordenadaDeSeleccion();
		if(this->tablero->existeLaCasilla(/*coordenadaSeleccionada*/1,1,1)){//Tiene que pasarle cada dato de la coordenada o el tipo coordenada entero?
		  Casilla* casillaInicio = this->tablero->getCasilla(/*coordenadaSeleccionada*/1,1,1);
		  if(casillaInicio->tieneJugador(this->jugadorActual)){
			  bool movimientoValido = false;
			  bool sigueSeleccionando = true;

			  do{
				  Coordenada movimientoSeleccionado = this->jugadorActual->pedirCoordenadaDeMovimiento();
			  	  if(this->tablero->existeLaCasilla(/*movimientoSeleccionado*/1,1,1)){//Tiene que pasarle cada dato de la coordenada o el tipo coordenada entero?
			  		  Casilla* casillaFinal = this->tablero->getCasilla(/*coordenadaSeleccionada*/1,1,1);
			  		  if(!casillaFinal->tieneJugador(this->jugadorActual) && casillaInicio->getTipo() == casillaFinal->getTipo() && casillaFinal->getEstado() !=INACTIVA){
			  			  if(casillaFinal->getEstado() == OCUPADA){
			  				  Jugador* jugadorAtacado = casillaFinal->getJugador();
			  				  if(/*casillaFinal->tieneSoldado()*/true){ // TO VIEW: EN QUE CASOS DE COLISION SE INACTIVA UNA CASILLA, TANQUE VS SOLDADO GANA TANQUE?
			  					  this->jugadorActual->eliminarUnSoldado();
			  					  jugadorAtacado->eliminarUnSoldado();
			  					  //Repazar la lista de jugadores para eliminar jugadores sin soldados
			  				  }
			  				  this->jugadorActual->reducirCantidadDisparos(/*casillaInicio->getCantidadDisparos()*/1);
			  				  jugadorAtacado->reducirCantidadDisparos(/*casillaFinal->getCantidadDisparos()*/1);
			  				  casillaFinal->inactivar();
			  			  }/*else{
			  				  //casillaFinal->copiarCasilla(casillaInicio);
			  			  }*/
			  			  casillaInicio->vaciar();
			  		  }else{movimientoValido = false;}
			  	  }else{movimientoValido = false;}
			  	  if(!movimientoValido){
			  		  cout<< "El movimiento no es valido.";
			  		  sigueSeleccionando =consultarUsuario("Desea seleccionar otro soldado?","Seleccionar otra ficha","Mover a otra casilla");
			  	  }
			  }while(!movimientoValido && sigueSeleccionando);
		  }else{coordenadaInicialValida = false;}
		}else{coordenadaInicialValida = false;}
	}while(!coordenadaInicialValida);
  return sigueJugando();
}

bool BatallaCampal::consultarUsuario(string pregunta, string opciontrue, string opcionFalse){
	unsigned int opcionElegida;
	do{
		cout<< pregunta << endl;
		cout<< "0 -> " << opciontrue << endl;
		cout<< "1 -> " << opcionFalse << endl;
		cin >> opcionElegida;
	}while(opcionElegida != 0 && opcionElegida != 1);
	  if(opcionElegida == 0){
		return true;
	  }else{
		return false;
	  }
}


BatallaCampal::~BatallaCampal() {
  // borrar todos los datos
}
