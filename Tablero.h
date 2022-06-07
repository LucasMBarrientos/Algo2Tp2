
#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casilla.h"
#include "Lista.h"

#include "EasyBMP.h"

#include <iostream>
#include <string>

class Tablero {

	private:

		Lista<Lista<Lista<Casilla *> *> *> * tablero;
		unsigned int xMaximo;
		unsigned int yMaximo;
		unsigned int zMaximo;

	public:
		/**
		 * pre: los maximos deben ser mayores o iguales a 1.
		 * pos: Crea un tablero de las dimensiones dadas con todos los
		 * 		casilleros en estado vacio y de tipo USO_GENERAL.
		 */
		Tablero(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo);

		/**
		 * pre:-
		 * pos: Imprime por consola el tablero de juego.
		 */
		void imprimirTablero();

		/**
		 * pre:-
		 * pos: guarda en un archivo *.bmp el tablero de juego.
		 */
		void exportarTableroAArchivo(unsigned int tamanioDeCasillasSalida, Jugador* jugadorActual);

		/**
		 * pre:-
		 * pos: Devuelve verdadero si x y z son mayores o iguales a 1 y menores o iguales a
		 * 		los maximos del tablero.
		 */
		bool existeLaCasilla(unsigned int x, unsigned int y, unsigned int z);

		/**
		 * pre: existeLaCasilla() es verdadero.
		 * pos: Devuelve la casilla en la posición indicada.
		 */
		Casilla* getCasilla(unsigned int x , unsigned int y, unsigned int z);

		/**
		 * pre:-
		 * pos: Devuelve la coordenada X máxima del tablero.
		 */
		unsigned int getXMaximo();

		/**
		 * pre:-
		 * pos: Devuelve la coordenada Y máxima del tablero.
		 */
		unsigned int getYMaximo();

		/**
		 * pre:-
		 * pos: Devuelve la coordenada Z máxima del tablero.
		 */
		unsigned int getZMaximo();


		/**
		 * pre: (x,y,z) debe pertenecer al tablero,
		 * 		ficha no puede ser vacío,
		 * 		jugador no puede ser vacío.
		 *
		 * pos: Setea en (x,y,z) una ficha de jugador.
		 */
		void colocarFicha(unsigned int x, unsigned int y, unsigned int z,
				Ficha* ficha, Jugador* jugador);

		/**
		 * pre:
		 * pos:
		 */
		void colocarElementoAleatorio(enum TipoDeFicha ficha,Jugador* jugador);


		/**
		 * pre:
		 * pos:
		 */
		void getInfoDeCasilla(); // NO IMPLEMENTADO. Se encarga Casilla.


		/**
		 * pre:-
		 * pos: Elimina todos los casilleros liberando los recursos utilizados.
		 */
		~Tablero();



	private:

		/**
		 * pre:-
		 * pos: Valida que x y z esten entre 1 y los maximos. Si no, lanza una excepcion 'string'.
		 */
		void validarRangoDeCoordenadas(unsigned int x, unsigned int y, unsigned int z);

		/**
		 * pre: Si ficha != NULL, el estadoDeCasilla debe estar OCUPADA
		 * pos: Convierte las Casillas (y el tipo de ficha si hubiere) en las Salidas como char que se imprimirán por pantalla.
		 */
		void transformarDatoDeCasilla(EstadoDeCasilla& estadoDeCasilla, TipoDeCasilla& tipoDeCasilla, Ficha* ficha,
				char &salidaEstadoDeCasilla, char &salidaTipoDeCasilla, char &salidaTipoDeFicha, unsigned int &numeroDeJugador);

		/**
		* pre:-
		* pos:
		*/


		bool validarCasillaYElemento(enum TipoDeFicha ficha,Casilla* casilla);
		/**
		* pre:-
		* pos:
		*/

		unsigned int devuelveNumAleatorio(unsigned int MAX);



		/**
		 * pre:-
		 * pos: Muestra por consola los datos de una casilla del tablero.
		 */
		void imprimirCasilla(EstadoDeCasilla &estadoDeCasilla, TipoDeCasilla &tipoDeCasilla, Ficha* ficha);

		/**
		 * pre:-
		 * pos: Escribe en el archivo la casilla con su estado y tipo correspodiente;
		 * 		además de la ficha y numero de jugador si hubiere.
		 */
		void escribirEnArchivo(BMP &imagen,
				unsigned int tamanioDeCasillasSalida, BMP &imagenSalida,
				unsigned int haciaX, unsigned int haciaY);

		/*
		 * pre:
		 * pos:
		 */
		void escribirInactiva(BMP &imagen,
				unsigned int tamanioDeCasillasSalida, BMP &imagenSalida,
				unsigned int haciaX, unsigned int haciaY);

		/*
		 * pre:
		 * pos:
		 */
		void escribirVacia(TipoDeCasilla tipoDeCasilla, unsigned int tamanioDeCasillasSalida, BMP& imagenSalida,
				unsigned int haciaX, unsigned int haciaY);

		/*
		 * pre:
		 * pos:
		 */
	void escribirOcupada(Ficha* ficha,
			unsigned int tamanioDeCasillasSalida, BMP& imagenSalida,
			unsigned int haciaX, unsigned int haciaY);





};

#endif /* TABLERO_H_ */
