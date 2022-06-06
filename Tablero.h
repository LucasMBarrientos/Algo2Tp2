#ifndef TABLERO_H_
#define TABLERO_H_

#include <iostream>

#include "Casilla.h"
#include "Lista.h"


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
		 * pos: Devuelve verdadero si la coordenada está entre 1 y Maximos.
		 */
		bool existeLaCasilla(unsigned int x, unsigned int y, unsigned int z);

		/**
		 * pre: x y z son mayores o iguales a 1 y menores o iguales a
		 * 		los maximos del tablero.
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
		 * pre:
		 * pos:
		 */
		void colocarSoldado(); // NO IMPLEMENTADO------------------------------------------¿¿No debería encargarse Ficha??

		/**
		 * pre:
		 * pos:
		 */
		void colocarBarco(); //NO IMPLEMENTADO---------------------------------------------¿¿No debería encargarse Ficha??

		/**
		 * pre:
		 * pos:
		 */
		void getInfoDeCasilla(); // NO IMPLEMENTADO. Se encarga Casilla.


		/**
		 * pre:
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
		 * pre:
		 * pos: Muestra por consola los datos de una casilla del tablero.
		 */
		void imprimirCasilla(EstadoDeCasilla &estadoDeCasilla, TipoDeCasilla &tipoDeCasilla, Ficha* ficha);



};

#endif /* TABLERO_H_ */
