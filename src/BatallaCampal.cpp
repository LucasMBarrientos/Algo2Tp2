#include "BatallaCampal.h"
#include <iostream>
using namespace std;

BatallaCampal::BatallaCampal() {
	this->jugadorActual = NULL;
	this->cantidadDeJugadores = 0;
	this->tablero = NULL;
	this->ListaDeJugadores = NULL;
	this->carta = new Carta;
}

int BatallaCampal::menuPrincipal() {
	int soldadosPorJugador;
	cout << "Ingresar cantidad de jugadores";
	cin >> this->cantidadDeJugadores;
	cout << "Ingresar cantidad de soldados";
	cin >> soldadosPorJugador;
	return soldadosPorJugador;
}

void BatallaCampal::inicializar() {
	this->ListaDeJugadores = new Lista<Jugador*>();
	int soldadosPorJugador = menuPrincipal();
	for (int i = 1; i <= this->cantidadDeJugadores; i++) {
		string nombreJugador;
		cout << "Ingrese el nombre del jugador " << i << ": ";
		cin >> nombreJugador;
		Jugador* jugador = new Jugador(i, nombreJugador, soldadosPorJugador, 1);
		this->ListaDeJugadores->agregar(jugador);
	}

	this->jugadorActual = this->ListaDeJugadores->obtener(1);

	//CREAR TABLERO
	this->tablero = new Tablero(10, 10, 3);
	for (unsigned int x = 1; x <= this->tablero->getXMaximo(); x++) {
		for (unsigned int y = 1; y <= this->tablero->getYMaximo(); y++) {
			try {
				this->tablero->getCasilla(x, y, 1)->setTipo(TIERRA);
			} catch (string mensajeError) {
				cout << "Ocurrio un error en la ejecucion: " + mensajeError
						<< endl;
			}
		}
	}
	this->tablero->getCasilla(10, 10, 1)->setTipo(AGUA);
	this->tablero->getCasilla(10, 9, 1)->setTipo(AGUA);
	this->tablero->getCasilla(10, 8, 1)->setTipo(AGUA);
	this->tablero->getCasilla(9, 10, 1)->setTipo(AGUA);
	this->tablero->getCasilla(9, 9, 1)->setTipo(AGUA);
	this->tablero->getCasilla(9, 8, 1)->setTipo(AGUA);
	this->tablero->getCasilla(8, 10, 1)->setTipo(AGUA);
	this->tablero->getCasilla(8, 9, 1)->setTipo(AGUA);
	this->tablero->getCasilla(8, 8, 1)->setTipo(AGUA);

	for (unsigned int x = 1; x <= this->tablero->getXMaximo(); x++) {
		for (unsigned int y = 1; y <= this->tablero->getYMaximo(); y++) {
			for (unsigned int z = 2; z <= this->tablero->getZMaximo(); z++) {
				try {
					this->tablero->getCasilla(x, y, z)->setTipo(AIRE);
				} catch (string mensajeError) {
					cout << "Ocurrio un error en la ejecucion: " + mensajeError
							<< endl;
				}
			}
		}
	}

	//LLENAR TABLERO
	for (int x = 1; x <= this->cantidadDeJugadores; x++) {
		for (int y = 1; y <= soldadosPorJugador; y++) {
			try {
				Ficha* ficha = new Ficha(SOLDADO,
						this->ListaDeJugadores->obtener(x));
				this->tablero->colocarFicha(x, y, 1, ficha,
						this->ListaDeJugadores->obtener(x));
			} catch (string mensajeError) {
				cout << "Ocurrio un error en la ejecucion: " + mensajeError
						<< endl;
			}
		}
	}
}

void BatallaCampal::cambiarTurno() {
	this->ListaDeJugadores->iniciarCursor();
	while (this->ListaDeJugadores->avanzarCursor()) {
		if (this->ListaDeJugadores->obtenerCursor() == this->jugadorActual) {
			break;
		}
	}
	if (this->ListaDeJugadores->avanzarCursor()) {
		this->jugadorActual = this->ListaDeJugadores->obtenerCursor();
	} else {
		this->jugadorActual = this->ListaDeJugadores->obtener(1);
	}
}

void BatallaCampal::jugar() {
	inicializar();
	bool juegoActivo = true;
	this->tablero->imprimirTablero();
	while (juegoActivo) {
		if (this->jugadorActual->obtenerPermiso() == HABILITADO) {
			cout << "TURNO DE " << this->jugadorActual->obtenerNombre() << endl;

			if (this->jugadorActual->obtenerCantidadDisparos() >= 1) {
				if (!realizarAtaque(ATAQUE_SOLDADO,
						this->jugadorActual->obtenerCantidadDisparos())) {
					break;
				}
			}
			if (this->jugadorActual->obtenerCantidadDeDisparosTanque() >= 1) {
				if (!realizarAtaque(ATAQUE_MISIL,
						this->jugadorActual->obtenerCantidadDeDisparosTanque())) {
					break;
				}
			}
			if (this->jugadorActual->obtenerCantidadDeDisparosMisil() >= 1) {
				if (!realizarAtaque(ATAQUE_TANQUE,
						this->jugadorActual->obtenerCantidadDeDisparosMisil())) {
					break;
				}
			}
			if (consultarUsuario("Desea realizar un movimiento?", "Si", "No")) {

				if (!mover(false)) {
					break;
				}
			}

			this->carta->generarCartaAleatoria();
			this->carta->setTipoDeCarta(CARTA_MINA);
			if (!ejecutarCarta(this->jugadorActual, this->tablero,
					this->ListaDeJugadores)) {
				break;
			}
		} else {
			cout << "El jugador " << this->jugadorActual->obtenerNombre()
					<< " pierde su turno." << endl;
			this->jugadorActual->habilitarJugador();
		}
		juegoActivo = sigueJugando();
		this->tablero->imprimirTablero();
		this->tablero->exportarTableroAArchivo(50, jugadorActual);
		cambiarTurno();
	}
	if (this->ListaDeJugadores->estaVacia()) {
		cout << "EMPATE" << endl;
	} else {
		cout << "GANADOR JUGADOR "
				<< this->ListaDeJugadores->obtener(1)->obtenerNombre() << endl;
	}
}

bool BatallaCampal::sigueJugando() {
	this->ListaDeJugadores->iniciarCursor();
	if (this->ListaDeJugadores->contarElementos() >= 2) {
		return true;
	} else {
		return false;
	}
}

void BatallaCampal::eliminarJugador(Jugador* jugador) {
	this->ListaDeJugadores->iniciarCursor();
	unsigned int posicion = 0;
	while (this->ListaDeJugadores->avanzarCursor()) {
		posicion++;
		if (this->ListaDeJugadores->obtenerCursor() == jugador) {
			this->ListaDeJugadores->remover(posicion);
			delete jugador;
		}

	}
}

bool BatallaCampal::elegirMovimiento(Casilla* casillaInicio) {
	bool movimientoValido = false;
	bool sigueSeleccionando = true;
	do {
		Coordenada coordenadaFinal =
				this->jugadorActual->pedirCoordenadaDeMovimiento();
		if (validarCoordenada(coordenadaFinal)) {
			Casilla* casillaFinal = this->tablero->getCasilla(
					coordenadaFinal.getX(), coordenadaFinal.getY(),
					coordenadaFinal.getZ());

			if (casillaInicio->getTipo() == casillaFinal->getTipo()
					&& validarMovimiento(casillaInicio, casillaFinal)
					&& casillaFinal->getEstado() != INACTIVA) {
				if (casillaFinal->getEstado() == OCUPADA) {
					if (!casillaFinal->tieneJugador(this->jugadorActual)) {

						recibirAtaque(casillaFinal->getJugador(),
								casillaFinal->getFicha()->getTipo());

						recibirAtaque(this->jugadorActual,
								casillaInicio->getFicha()->getTipo());

						casillaFinal->inactivar();
					} else {
						cout
								<< "No se puede mover a una casilla ocupada por uno mismo"
								<< endl;
					}
				} else {
					casillaFinal->ocupar(casillaInicio->getFicha(),
							this->jugadorActual);
				}
				casillaInicio->vaciar();
				movimientoValido = true;
				sigueSeleccionando = false;
			} else {
				cout << "Movimiento invalido, intente otra vez" << endl;
			}
		} else {
			cout << "Coordenada fuera de tablero, intente otra vez" << endl;
		}
		if (!movimientoValido) {
			sigueSeleccionando = consultarUsuario(
					"Desea intentar con otra casilla?", "Mover a otra casilla",
					"Seleccionar otra ficha");
		}
	} while (!movimientoValido && sigueSeleccionando);
	return movimientoValido;
}

bool BatallaCampal::mover(bool poniendoMina) {
	bool accionValida = false;
	bool sigueSeleccionando = true;
	do {
		Coordenada coordenadaInicial =
				this->jugadorActual->pedirCoordenadaDeSeleccion();
		if (validarCoordenada(coordenadaInicial)) {
			Casilla* casillaInicio = this->tablero->getCasilla(
					coordenadaInicial.getX(), coordenadaInicial.getY(),
					coordenadaInicial.getZ());
			if (casillaInicio->estaOcupada()
					&& casillaInicio->tieneJugador(this->jugadorActual)
					&& casillaInicio->getFicha()->getTipo() != MINA) {
				if (elegirMovimiento(casillaInicio)) {
					accionValida = true;
				}
			} else {
				cout << "Seleccion invalida, intente otra vez" << endl;
			}
		} else {
			cout << "Coordenada fuera de tablero, intente otra vez" << endl;
		}
		if (!accionValida) {
			sigueSeleccionando = consultarUsuario("Desea seguir moviendo?",
					"Seleccionar otra casilla", "Cancelar accion");
		}
		if (accionValida && poniendoMina) {
			Ficha* ficha = new Ficha(MINA, this->jugadorActual);
			this->tablero->colocarFicha(coordenadaInicial.getX(),
					coordenadaInicial.getY(), coordenadaInicial.getZ(), ficha,
					this->jugadorActual);
		}
	} while (!accionValida && sigueSeleccionando);

	return sigueJugando();
}

bool BatallaCampal::validarMovimiento(Casilla* casillaInicio,
		Casilla* casillaFinal) {
	int diferenciaEnX = casillaInicio->getX() - casillaFinal->getX();
	int diferenciaEnY = casillaInicio->getY() - casillaFinal->getY();
	int diferenciaEnZ = casillaInicio->getZ() - casillaFinal->getZ();

	float modulo = pow(diferenciaEnX, 2) + pow(diferenciaEnY, 2)
			+ pow(diferenciaEnZ, 2);

	return ((modulo == 1) || (modulo == 2) || (modulo == 3));
}

bool BatallaCampal::consultarUsuario(string pregunta, string opciontrue,
		string opcionFalse) {
	unsigned int opcionElegida;
	do {
		cout << pregunta << endl;
		cout << "0 -> " << opciontrue << endl;
		cout << "1 -> " << opcionFalse << endl;
		cin >> opcionElegida;
	} while (opcionElegida != 0 && opcionElegida != 1);
	if (opcionElegida == 0) {
		return true;
	} else {
		return false;
	}
}

bool BatallaCampal::ejecutarCarta(Jugador* jugador, Tablero* tablero,
		Lista<Jugador *>* ListaDeJugadores) {
	switch (carta->getTipoDeCarta()) {
	case CARTA_AVION: {

		tablero->colocarElementoAleatorio(AVION, jugador); //Posiciona un avion en el tablero
		jugador->aumentarCantidadDisparos(2); //Agrega 2 tiros al jugador que saco la carta

		;
		break;
	}
	case CARTA_BARCO: {
		tablero->colocarElementoAleatorio(BARCO, jugador); //Posiciona un barco en el tablero
		jugador->aumentarCantidadDisparosMisil(1);

		break;
	}
	case CARTA_MISIL: {
		return (realizarAtaque(ATAQUE_MISIL, 1));
		break;
	}
	case CARTA_TANQUE: {
		tablero->colocarElementoAleatorio(TANQUE, jugador);
		//EjecutaUnTirotaque   de 2x2;
		break;
	}
	case CARTA_MINA: {
		if(consultarUsuario("Desea colocar una mina?","Si","No")){
			return (mover(true));
		}
		break;
	}
	case CARTA_SUSPENSION: {

		bool flagIdValido = false;
		unsigned int id;
		do {
			cout << "Ingrese el Id del jugador a saltear";
			cin >> id;
			ListaDeJugadores->iniciarCursor();
			while (ListaDeJugadores->avanzarCursor()) {
				if ((ListaDeJugadores->obtenerCursor()->obtenerId()) == id) {
					ListaDeJugadores->obtenerCursor()->bloquearJugador();
					flagIdValido = true;
				}
			}
		} while (!flagIdValido);

		break;
	}
	}
	return true;
}

bool BatallaCampal::realizarAtaque(TipoDeAtaque tipoDeAtaque,
		unsigned int CantidadDisparos) {
	unsigned int tamanioAtaque;
	for (unsigned int disparos = 1; disparos <= CantidadDisparos; disparos++) {
		switch (tipoDeAtaque) {
		case ATAQUE_SOLDADO: {
			cout << "Cantidad de disparos disponibles: ";
			tamanioAtaque = 1;
			break;
		}
		case ATAQUE_TANQUE: {
			cout << "Cantidad de disparos tanque disponibles: ";
			tamanioAtaque = 2;
			break;
		}
		case ATAQUE_MISIL: {
			cout << "Cantidad de disparos misiles disponibles: ";
			tamanioAtaque = 3;
			break;
		}
		}
		cout << disparos << " de " << CantidadDisparos << endl;
		unsigned int retroceso = tamanioAtaque / 2;
		unsigned int x, y, z, i, j, k, m;

		bool ataqueValido = false;
		do {

			Coordenada coordenadaSeleccionada =
					this->jugadorActual->pedirCoordenadaDeAtaque();
			if (validarCoordenada(coordenadaSeleccionada)) {

				if ((coordenadaSeleccionada.getX() - retroceso) < 1) {
					x = 1;
					tamanioAtaque = 2 * retroceso + 1
							- coordenadaSeleccionada.getX();
				} else {
					x = coordenadaSeleccionada.getX() - retroceso;
				}
				if ((coordenadaSeleccionada.getY() - retroceso) < 1) {
					y = 1;
					tamanioAtaque = 2 * retroceso + 1
							- coordenadaSeleccionada.getY();
				} else {
					y = coordenadaSeleccionada.getY() - retroceso;
				}
				if ((coordenadaSeleccionada.getZ() - retroceso) < 1) {
					z = 1;
					tamanioAtaque = 2 * retroceso + 1
							- coordenadaSeleccionada.getZ();
				} else {
					z = coordenadaSeleccionada.getZ() - retroceso;
				}

				for (i = 0;
						i < tamanioAtaque && (x + i) <= tablero->getXMaximo();
						i++) {
					for (j = 0;
							j < tamanioAtaque
									&& (y + j) <= tablero->getYMaximo(); j++) {
						for (k = 0;
								k < tamanioAtaque
										&& (z + k) <= tablero->getZMaximo();
								k++) {
							if (tipoDeAtaque == ATAQUE_MISIL) {
								m = k;
							} else {
								m = 0;
								z = 1;
							}

							Casilla* casillaAtacada = tablero->getCasilla(x + i,
									y + j, z + m);

							atacar(casillaAtacada);
						}
					}
				}
				ataqueValido = true;

			} else {
				cout << "Coordenada fuera de tablero, intente otra vez" << endl;
				ataqueValido = false;
			}

		} while (!ataqueValido);
	}
	return sigueJugando();
}

bool BatallaCampal::validarCoordenada(Coordenada coordenada) {
	return (this->tablero->existeLaCasilla(coordenada.getX(), coordenada.getY(),
			coordenada.getZ()));
}

void BatallaCampal::atacar(Casilla* casillaAtacada) {

	switch (casillaAtacada->getEstado()) {

	case VACIA: {
		casillaAtacada->inactivar();
		break;
	}
	case OCUPADA: {
		recibirAtaque(casillaAtacada->getJugador(),
				casillaAtacada->getFicha()->getTipo());
		casillaAtacada->inactivar();
		break;
	}
	case INACTIVA: {
		break;
	}
	}
}

void BatallaCampal::recibirAtaque(Jugador* jugador, TipoDeFicha ficha) {
	switch (ficha) {
	case SOLDADO: {
		jugador->eliminarUnSoldado();
		if (jugador->obtenerCantidadDeSoldados() == 0) {
			eliminarJugador(jugador);
		}
		break;
	}
	case AVION: {
		jugador->reducirCantidadDisparos(2);
		break;
	}
	case BARCO: {
		jugador->reducirCantidadDisparosMisil(1);
		break;
	}
	case TANQUE: {
		jugador->reducirCantidadDisparosTanque(1);
		break;
	}
	case MINA: {
		break;
	}
	}
}

BatallaCampal::~BatallaCampal() {
	delete this->tablero;
}
