#include "Tablero.h"

/**
 * pre:
 * pos:
 */
Tablero::Tablero(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo) {

	if(xMaximo < 1){
		throw std::string("La dimension x debe ser mayor o igual a 1");
	}
	if(yMaximo < 1){
		throw std::string("La dimension y debe ser mayor o igual a 1");
	}
	if(zMaximo < 1){
		throw std::string("La dimension z debe ser mayor o igual a 1");
	}

	this->xMaximo = xMaximo;
	this->yMaximo = yMaximo;
	this->zMaximo = zMaximo;
	this->tablero = new Lista<Lista<Lista<Casilla *> *> *> (); //crea tablero

	for(unsigned int x = 1; x <= this->xMaximo; x++){
		this->tablero->agregar(new Lista<Lista<Casilla*>*>()); //crea lista
		for(unsigned int y = 1; y <= this->yMaximo; y++){
			this->tablero->obtener(x)->agregar(new Lista<Casilla*>()); //crea lista
			for(unsigned int z = 1; z <= this->zMaximo; z++){
				this->tablero->obtener(x)->obtener(y)->agregar(new Casilla(x,y,z, USO_GENERAL)); //agrega casilleros
			}
		}
	}
}

/**
 * pre: Si ficha != NULL, el estadoDeCasilla debe estar OCUPADA
 * pos: Convierte en char los datos de estado, tipo y ficha.
 */
void Tablero::transformarDatoDeCasilla(EstadoDeCasilla& estadoDeCasilla, TipoDeCasilla& tipoDeCasilla, Ficha* ficha,
		char &salidaEstadoDeCasilla, char &salidaTipoDeCasilla, char &salidaTipoDeFicha, unsigned int &numeroDeJugador) {

	if(ficha && estadoDeCasilla != OCUPADA){
		throw std::string("No puede haber una ficha en una Casilla no ocupada");
	}

	numeroDeJugador = 0;


	switch (estadoDeCasilla) {
		case INACTIVA: salidaEstadoDeCasilla = 'I'; break;
		case VACIA: salidaEstadoDeCasilla = 'E'; break;
		case OCUPADA: numeroDeJugador = ficha->getJugador()->obtenerId; break;
	}

	switch (tipoDeCasilla){
		case TIERRA: salidaTipoDeCasilla = 'L'; break;
		case AGUA: salidaTipoDeCasilla = 'W'; break;
		case AIRE: salidaTipoDeCasilla = 'A'; break;
		case USO_GENERAL: salidaTipoDeCasilla = 'M'; break;
	}

	if(ficha){	//si no existe ficha: ficha == NULL.
		switch(ficha->getTipo()){
			case SOLDADO: salidaTipoDeFicha = 'S'; break;
			case AVION: salidaTipoDeFicha = 'V'; break;
			case BARCO: salidaTipoDeFicha = 'B'; break;
		}
	} else {
		salidaTipoDeFicha = 'n';
	}
}



/**
 * pre:-
 * pos:
 */
void Tablero::imprimirCasilla(EstadoDeCasilla &estadoDeCasilla, TipoDeCasilla &tipoDeCasilla, Ficha* ficha){

	char salidaEstadoDeCasilla = '5';//eliminar inicalizacion
	char salidaTipoDeCasilla = '6';//eliminar inicalizacion
	char salidaTipoDeFicha = '7'; //eliminar inicalizacion
	unsigned int numeroDeJugador;

	transformarDatoDeCasilla(estadoDeCasilla, tipoDeCasilla, ficha,
								salidaEstadoDeCasilla, salidaTipoDeCasilla,
								salidaTipoDeFicha, numeroDeJugador);


	std::cout << salidaEstadoDeCasilla
			  << salidaTipoDeCasilla
			  << salidaTipoDeFicha
			  << numeroDeJugador
			  << "  ";



}

/**
 *  Gestiona la impresion por consola del tablero de juego.
 */
void Tablero::imprimirTablero() {

	EstadoDeCasilla estadoDeCasilla;
	TipoDeCasilla tipoDeCasilla;
	Ficha* ficha;

	for (unsigned int z = 1; z <= this->zMaximo; z++) {
		std::cout << "nivel z = " << z << std::endl;
		for (unsigned int y = 1; y <= this->yMaximo; y++) {
			for (unsigned int x = 1; x <= this->xMaximo; x++) {
				estadoDeCasilla = this->tablero->obtener(x)->obtener(y)->obtener(z)->getEstado();
				tipoDeCasilla = this->tablero->obtener(x)->obtener(y)->obtener(z)->getTipo();
				ficha = this->tablero->obtener(x)->obtener(y)->obtener(z)->getFicha();

				imprimirCasilla(estadoDeCasilla, tipoDeCasilla, ficha);

			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
		std::cout<<std::endl;
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}


/**
 * pre:-
 * pos:
 */
unsigned int Tablero::getXMaximo(){
	return this->xMaximo;

}

/**
 * pre:
 * pos:
 */
unsigned int Tablero::getYMaximo(){
	return this->yMaximo;
}

/**
 * pre:
 * pos:
 */
unsigned int Tablero::getZMaximo(){
	return this->zMaximo;
}


/**
 * pre:
 * pos:
 */
Casilla* Tablero::getCasilla(unsigned int x , unsigned int y, unsigned int z){
	validarRangoDeCoordenadas(x, y, z);
	return this->tablero->obtener(x)->obtener(y)->obtener(z);

}

/**
 * pre:
 * pos:
 */
void Tablero::colocarSoldado(){ //----------------------------------------------------------¿¿debería encargarse Ficha??

}

/**
 * pre:
 * pos:
 */
void Tablero::colocarBarco(){ //----------------------------------------------------------¿¿debería encargarse Ficha??

}

/**
 * pre:
 * pos:
 */
void Tablero::getInfoDeCasilla(){ // NO IMPLEMENTADO. Se encarga Casilla.

}

/**
 * pre:-
 * pos:
 */
void Tablero::validarRangoDeCoordenadas(unsigned int x, unsigned int y, unsigned int z){

	if((x < 1) || (x > this->xMaximo)){
		throw std::string("La dimension x debe ser mayor o igual a 1 y menor o igual que xMaximo");
	}
	if((y < 1) || (y > this->yMaximo)){
		throw std::string("La dimension y debe ser mayor o igual a 1 y menor o igual que yMaximo");
	}
	if((z < 1) || (x > this->xMaximo)){
		throw std::string("La dimension z debe ser mayor o igual a 1 y menor o igual que zMaximo");
	}
}

/**
 * pre:-
 * pos:
 */
bool Tablero::existeLaCasilla(unsigned int x, unsigned int y, unsigned int z){

	try{
		validarRangoDeCoordenadas(x,y,z);
		return true; // si 'validarRangoDeCoordenadas' no arrojó excepción.
	}catch (...){} //catch no hace nada.
	return false;
}

/**
 * pre:-
 * pos:
 */
Tablero::~Tablero() {

	for(unsigned int x = 1; x <= this->xMaximo; x++){
		for(unsigned int y = 1; y <= this->yMaximo; y++){
			for(unsigned int z = 1; z <= this->zMaximo; z++){
				delete this->tablero->obtener(x)->obtener(y)->obtener(z); //elimina casillero
			}
			delete this->tablero->obtener(x)->obtener(y);//elimina lista
		}
		delete this->tablero->obtener(x);//elimina lista
	}
	delete this->tablero; //elimina tablero

}
