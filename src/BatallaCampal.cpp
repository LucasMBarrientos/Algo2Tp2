
#include "BatallaCampal.h"
#include <iostream>
using namespace std;

BatallaCampal::BatallaCampal(){
  this->jugadorActual = NULL;
  this->cantidadDeJugadores=0;
  this->tablero=NULL;
  this->ListaDeJugadores=NULL;

  this->carta = new Carta;

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
		Jugador* jugador = new Jugador(i,nombreJugador,soldadosPorJugador,1);
		this->ListaDeJugadores->agregar(jugador);
	}

	this->jugadorActual = this->ListaDeJugadores->obtener(1);

	//CREAR TABLERO
	this->tablero = new Tablero(10,10,3);
	for (unsigned int x = 1; x <= this->tablero->getXMaximo(); x++){
		for (unsigned int y = 1; y <= this->tablero->getYMaximo(); y++){
			try{
				this->tablero->getCasilla(x,y,1)->setTipo(TIERRA);
			} catch (string mensajeError){
				cout << "Ocurrio un error en la ejecucion: " + mensajeError << endl;
			}
		}
	}

	for (unsigned int x = 1; x <= this->tablero->getXMaximo(); x++){
		for (unsigned int y = 1; y <= this->tablero->getYMaximo(); y++){
			for (unsigned int z = 2; z <= this->tablero->getZMaximo(); z++){
				try{
					this->tablero->getCasilla(x,y,z)->setTipo(AIRE);
				} catch (string mensajeError){
					cout << "Ocurrio un error en la ejecucion: " + mensajeError << endl;
				}
			}
		}
	}

	//LLENAR TABLERO
	for (unsigned int x = 1; x <= this->cantidadDeJugadores; x++){
			for (unsigned int y = 1; y <= soldadosPorJugador; y++){
				try{
					Ficha* ficha = new Ficha(SOLDADO,this->ListaDeJugadores->obtener(x));
					this->tablero->colocarFicha(x,y,1,ficha,this->ListaDeJugadores->obtener(x));
				} catch (string mensajeError){
					cout << "Ocurrio un error en la ejecucion: " + mensajeError << endl;
				}
			}
	}
}

void BatallaCampal::cambiarTurno(){
	this->ListaDeJugadores->iniciarCursor();
	while(this->ListaDeJugadores->avanzarCursor()){
		if(this->ListaDeJugadores->obtenerCursor() == this->jugadorActual){
			break;
		}
	}
	if(this->ListaDeJugadores->avanzarCursor()){
		this->jugadorActual = this->ListaDeJugadores->obtenerCursor();
	}else{
		this->jugadorActual = this->ListaDeJugadores->obtener(1);
	}
}


void BatallaCampal::jugar(){
	inicializar();
	bool juegoActivo = true;
	while(juegoActivo){
		cout << "TURNO DE " << this->jugadorActual->obtenerNombre() << endl;

		this->tablero->imprimirTablero();

		if(!atacar()){
			break;
		}

		if(consultarUsuario("Desea realizar un movimiento?","Si","No")){
			if(!mover()){
				break;
			}
		}


		this->carta->generarCartaAleatoria();
		this->carta->ejecutarCarta(this->jugadorActual, this->tablero, this->ListaDeJugadores);



		juegoActivo = sigueJugando();
		cambiarTurno();
  }
  if(this->ListaDeJugadores->estaVacia()){
	  cout << "EMPATE" << endl;
  }else{
	  cout << "GANADOR JUGADOR " << this->ListaDeJugadores->obtener(1)->obtenerNombre() << endl;
  }
}

bool BatallaCampal::sigueJugando(){
	this->ListaDeJugadores->iniciarCursor();
	if(this->ListaDeJugadores->contarElementos() >= 2){
		return true;
	}else{
		return false;
	}
}

void BatallaCampal::eliminarJugador(Jugador* jugador){
	this->ListaDeJugadores->iniciarCursor();
	unsigned int posicion = 0;
	while(this->ListaDeJugadores->avanzarCursor()){
		posicion++;
		if(this->ListaDeJugadores->obtenerCursor() == jugador){
			this->ListaDeJugadores->remover(posicion);
			delete jugador;
		}

	}
}

bool BatallaCampal::atacar(){

  for(int i=1; i<=jugadorActual->obtenerCantidadDisparos(); i++){

    bool ataqueValido = false;
    do{
    	Coordenada coordenadaSeleccionada = this->jugadorActual->pedirCoordenadaDeAtaque();
    	if(this->tablero->existeLaCasilla(coordenadaSeleccionada.obtenerCoordenadaX(),coordenadaSeleccionada.obtenerCoordenadaY(),coordenadaSeleccionada.obtenerCoordenadaZ())){
    		Casilla* casillaAtacada = this->tablero->getCasilla(coordenadaSeleccionada.obtenerCoordenadaX(),coordenadaSeleccionada.obtenerCoordenadaY(),coordenadaSeleccionada.obtenerCoordenadaZ());
    		if(casillaAtacada->getEstado() == OCUPADA){
				if(!casillaAtacada->tieneJugador(this->jugadorActual)){
					Jugador* jugadorAtacado = casillaAtacada->getJugador();
					switch (casillaAtacada->getFicha()->getTipo()) {
						case SOLDADO: {
							jugadorAtacado->eliminarUnSoldado();
							if(jugadorAtacado->obtenerCantidadDeSoldados() == 0){
								eliminarJugador(jugadorAtacado);
							}
							break;
						}
						case AVION: {
							jugadorAtacado->reducirCantidadDisparos(2);
							break;
						}
						case BARCO: {
							jugadorAtacado->reducirCantidadDisparosMisil(1);
							break;
						}
						/*case TANQUE: {
							jugadorAtacado->reducirCantidadDisparosTanque(1);
							break;
						}*/
						case MINA: {
							break;
						}
					}
					casillaAtacada->inactivar();
					ataqueValido = true;
				}else{cout<< "No te podes atacar a vos mismo, intente otra vez" << endl;}
			}else{ataqueValido = true;}
    	}else{cout<< "Coordenada fuera de tablero, intente otra vez" << endl;}
    }while(!ataqueValido);
  }
  return sigueJugando();
}

void BatallaCampal::elegirMovimiento(Casilla* casillaInicio) {
	bool movimientoValido = false;
	bool sigueSeleccionando = true;
	do {
		Coordenada coordenadaSeleccionada = this->jugadorActual->pedirCoordenadaDeMovimiento();
		if (this->tablero->existeLaCasilla(coordenadaSeleccionada.obtenerCoordenadaX(),coordenadaSeleccionada.obtenerCoordenadaY(),coordenadaSeleccionada.obtenerCoordenadaZ())){
			Casilla* casillaFinal = this->tablero->getCasilla(coordenadaSeleccionada.obtenerCoordenadaX(),coordenadaSeleccionada.obtenerCoordenadaY(),coordenadaSeleccionada.obtenerCoordenadaZ());
			if (casillaInicio->getTipo() == casillaFinal->getTipo()
					/*&& validarMovimiento(casillaInicio,casillaFinal)*/
					&& casillaFinal->getEstado() != INACTIVA/*
					&& !casillaFinal->tieneJugador(this->jugadorActual)*/
					) {

				if (casillaFinal->getEstado() == OCUPADA) {
					Jugador* jugadorAtacado = casillaFinal->getJugador();

					switch (casillaFinal->getFicha()->getTipo()) {
						case SOLDADO: {
					    	jugadorAtacado->eliminarUnSoldado();
					        jugadorAtacado->reducirCantidadDisparos(1);
					        if(jugadorAtacado->obtenerCantidadDeSoldados() == 0){
					        	eliminarJugador(jugadorAtacado);
					        }
					        break;
					    }
					    case AVION: {
							jugadorAtacado->reducirCantidadDisparos(2);
							break;
					    }
					    case BARCO: {
							jugadorAtacado->reducirCantidadDisparosMisil(1);
							break;
					    }
					    /*case TANQUE: {
							jugadorAtacado->reducirCantidadDisparosTanque(1);
							break;
					    }
					    case MINA: {
					    	break;
					    }*/
					}
					casillaFinal->inactivar();
				}else{
					casillaFinal = casillaInicio; /*PROBAR*/
				}
				casillaInicio->vaciar();
			} else {
				cout<< "Movimiento invalido, intente otra vez" << endl;
			}
		} else {
			cout<< "Coordenada fuera de tablero, intente otra vez" << endl;
		}
		if (!movimientoValido) {
			cout << "El movimiento no es valido.";
			sigueSeleccionando = consultarUsuario(
					"Desea seleccionar otro soldado?", "Seleccionar otra ficha",
					"Mover a otra casilla");
		}
	} while (!movimientoValido && sigueSeleccionando);
}

bool BatallaCampal::mover(){
	bool coordenadaInicialValida = false;
	do{
		Coordenada coordenadaSeleccionada = this->jugadorActual->pedirCoordenadaDeSeleccion();
		if(this->tablero->existeLaCasilla(coordenadaSeleccionada.obtenerCoordenadaX(),coordenadaSeleccionada.obtenerCoordenadaY(),coordenadaSeleccionada.obtenerCoordenadaZ())){
		  Casilla* casillaInicio = this->tablero->getCasilla(coordenadaSeleccionada.obtenerCoordenadaX(),coordenadaSeleccionada.obtenerCoordenadaY(),coordenadaSeleccionada.obtenerCoordenadaZ());
		  if(casillaInicio->tieneJugador(this->jugadorActual)){
				elegirMovimiento(casillaInicio);
		  }else{coordenadaInicialValida = false;}
		}else{coordenadaInicialValida = false;}
	}while(!coordenadaInicialValida);
  return sigueJugando();
}

bool BatallaCampal::validarMovimiento(Casilla* casillaInicio, Casilla* casillaFinal){
	int diferenciaEnX = casillaInicio->getX() - casillaFinal->getX();
	int diferenciaEnY = casillaInicio->getY() - casillaFinal->getY();
	int diferenciaEnZ = casillaInicio->getZ() - casillaFinal->getZ();

	float modulo = sqrt(pow(diferenciaEnX,2) + pow(diferenciaEnY,2) + pow(diferenciaEnZ,2));

	return (modulo == 1);
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
	delete this->tablero;
}
