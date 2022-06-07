
#include "Tablero.h"

/**
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
				this->tablero->obtener(x)->obtener(y)->agregar(new Casilla(x,y,z, USO_GENERAL)); //agrega casillas
			}
		}
	}
}

/**
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
		case OCUPADA: {
			salidaEstadoDeCasilla = 'O';
			numeroDeJugador = ficha->getJugador()->obtenerId();
			break;}
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
			case TANQUE: salidaTipoDeFicha = 'T'; break;
			case MINA: salidaTipoDeFicha = 'Q'; break;
		}
	} else {
		salidaTipoDeFicha = 'n';
	}
}



/**
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
				estadoDeCasilla = this->getCasilla(x,y,z)->getEstado();
				tipoDeCasilla = this->getCasilla(x,y,z)->getTipo();
				ficha = this->getCasilla(x,y,z)->getFicha();

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
 */
unsigned int Tablero::getXMaximo(){
	return this->xMaximo;

}

/**
 */
unsigned int Tablero::getYMaximo(){
	return this->yMaximo;
}

/**
 */
unsigned int Tablero::getZMaximo(){
	return this->zMaximo;
}


/**
 */
Casilla* Tablero::getCasilla(unsigned int x , unsigned int y, unsigned int z){
	validarRangoDeCoordenadas(x, y, z);
	return this->tablero->obtener(x)->obtener(y)->obtener(z);

}

/**
 */
void Tablero::colocarFicha(unsigned int x, unsigned int y, unsigned int z,
		Ficha* ficha, Jugador* jugador) {

	this->getCasilla(x,y,z)->ocupar(ficha, jugador);
}


/**
 */
void Tablero::getInfoDeCasilla(){ // NO IMPLEMENTADO. Se encarga Casilla.

}

/**
 */
void Tablero::validarRangoDeCoordenadas(unsigned int x, unsigned int y, unsigned int z){

	if((x < 1) || (x > this->xMaximo)){
		throw std::string("La dimension x debe ser mayor o igual a 1 y menor o igual que xMaximo");
	}
	if((y < 1) || (y > this->yMaximo)){
		throw std::string("La dimension y debe ser mayor o igual a 1 y menor o igual que yMaximo");
	}
	if((z < 1) || (z > this->zMaximo)){
		throw std::string("La dimension z debe ser mayor o igual a 1 y menor o igual que zMaximo");
	}
}

/**
 */
bool Tablero::existeLaCasilla(unsigned int x, unsigned int y, unsigned int z){

	try{
		validarRangoDeCoordenadas(x,y,z);
		return true; // si 'validarRangoDeCoordenadas' no arrojó excepción.
	}catch (...){} //catch no hace nada.
	return false;
}

/**
 */
Tablero::~Tablero() {

	for(unsigned int x = 1; x <= this->xMaximo; x++){
		for(unsigned int y = 1; y <= this->yMaximo; y++){
			for(unsigned int z = 1; z <= this->zMaximo; z++){
				delete this->tablero->obtener(x)->obtener(y)->obtener(z); //elimina casilla
			}
			delete this->tablero->obtener(x)->obtener(y);//elimina lista
		}
		delete this->tablero->obtener(x);//elimina lista
	}
	delete this->tablero; //elimina tablero

}

/*
 */
void Tablero::escribirEnArchivo(BMP &imagen,
		unsigned int tamanioDeCasillasSalida, BMP &imagenSalida,
		unsigned int haciaX, unsigned int haciaY) {

	Rescale( imagen, 'f' , tamanioDeCasillasSalida);
	imagen.SetBitDepth( 8 );
	imagenSalida.SetBitDepth( 8 );

	RangedPixelToPixelCopy(imagen, 0, 100, 100, 0, imagenSalida, haciaX, haciaY); //-----------------------------

}

/*
 */
void Tablero::escribirVacia(TipoDeCasilla tipoDeCasilla, unsigned int tamanioDeCasillasSalida, BMP& imagenSalida,
		unsigned int haciaX, unsigned int haciaY) {

	BMP imagenTipoDeCasilla;


	switch(tipoDeCasilla){

	case TIERRA: imagenTipoDeCasilla.ReadFromFile("tipoCasilla/tierra.bmp");
				 escribirEnArchivo(imagenTipoDeCasilla,tamanioDeCasillasSalida,imagenSalida,haciaX,haciaY);
				 break;

	case AGUA: imagenTipoDeCasilla.ReadFromFile("tipoCasilla/agua.bmp");
	 	 	   escribirEnArchivo(imagenTipoDeCasilla,tamanioDeCasillasSalida,imagenSalida,haciaX,haciaY);
	 	 	   break;

	case AIRE: imagenTipoDeCasilla.ReadFromFile("tipoCasilla/aire.bmp");
	   	   	   escribirEnArchivo(imagenTipoDeCasilla,tamanioDeCasillasSalida,imagenSalida,haciaX,haciaY);
	   	   	   break;

	case USO_GENERAL:
	default:  throw std::string("No hay imágen que mostrar");

	}
}

/*
 */
void Tablero::escribirOcupada(Ficha* ficha,
		unsigned int tamanioDeCasillasSalida, BMP& imagenSalida,
		unsigned int haciaX, unsigned int haciaY) {

	TipoDeFicha tipoDeFicha = ficha->getTipo();
//	unsigned int numeroDeJugador = ficha->getJugador()->getnumero();

	BMP imagenTipoDeFicha;
//	BMP imagenNumero; //<<---------------------------------------------------------------------------------------------ALEJANDRO

	switch(tipoDeFicha){

	case SOLDADO: imagenTipoDeFicha.ReadFromFile("fichas/soldado.bmp");
				 escribirEnArchivo(imagenTipoDeFicha,tamanioDeCasillasSalida,imagenSalida,haciaX,haciaY);
				 break;

	case AVION: imagenTipoDeFicha.ReadFromFile("fichas/avion.bmp");
	 	 	   escribirEnArchivo(imagenTipoDeFicha,tamanioDeCasillasSalida,imagenSalida,haciaX,haciaY);
	 	 	   break;

	case BARCO: imagenTipoDeFicha.ReadFromFile("fichas/barco.bmp");
	   	   	   escribirEnArchivo(imagenTipoDeFicha,tamanioDeCasillasSalida,imagenSalida,haciaX,haciaY);
	   	   	   break;

	case TANQUE: imagenTipoDeFicha.ReadFromFile("fichas/tanque.bmp");
	   	   	   escribirEnArchivo(imagenTipoDeFicha,tamanioDeCasillasSalida,imagenSalida,haciaX,haciaY);
	   	   	   break;

	case MINA: imagenTipoDeFicha.ReadFromFile("fichas/minaTerrestre.bmp");
	   	   	   escribirEnArchivo(imagenTipoDeFicha,tamanioDeCasillasSalida,imagenSalida,haciaX,haciaY);
	   	   	   break;

	}

}

/**
 */
void Tablero::exportarTableroAArchivo(unsigned int tamanioDeCasillasSalida, Jugador* jugadorActual){

		unsigned int xMaximoArchivoSalida = tamanioDeCasillasSalida * this->xMaximo;
		unsigned int yMaximoArchivoSalida = tamanioDeCasillasSalida * this->yMaximo;


//.................................................................................................


	for (unsigned int z = 1; z<= zMaximo; z++){
		BMP imagenSalida;
//		std::string numeroTurno = z;
		imagenSalida.SetSize(xMaximoArchivoSalida, yMaximoArchivoSalida);
		unsigned int haciaY = 0; //hacia qué coordenadas del tablero sera impresa la casilla
		for (unsigned int y = 1; y <= this->yMaximo; y++) {

			unsigned int haciaX = 0;
			for (unsigned int x = 1; x <= this->xMaximo; x++) {

				Casilla* casilla = this->getCasilla(x,y,z);
				EstadoDeCasilla estadoDeCasilla = casilla->getEstado();

				switch (estadoDeCasilla) {

					case INACTIVA:{
						BMP imagenInactiva;
						imagenInactiva.ReadFromFile("tipoCasilla/inactiva.bmp");
						escribirEnArchivo(imagenInactiva, tamanioDeCasillasSalida,
								imagenSalida, haciaX, haciaY);
						break;
					}

					case VACIA:{
						escribirVacia(casilla->getTipo(), tamanioDeCasillasSalida,
								imagenSalida, haciaX, haciaY);
						break;
					}

					case OCUPADA:{
						escribirOcupada(casilla->getFicha(), tamanioDeCasillasSalida,
								imagenSalida, haciaX, haciaY);
						break;
					}
				}

				haciaX += tamanioDeCasillasSalida;
			}
			haciaY += tamanioDeCasillasSalida;
		}


	std::cout<< "imprimiendo..."<<std::endl;



	std::string nombreArchivo;
	nombreArchivo += "jugador-" + std::to_string(jugadorActual->obtenerId());
	nombreArchivo += "_nivel-" + std::to_string(z) + ".bmp";

	const char* numeroTurnoSalida = nombreArchivo.c_str();

	imagenSalida.WriteToFile(numeroTurnoSalida);

	}
}
