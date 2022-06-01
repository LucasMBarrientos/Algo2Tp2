
#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
const unsigned int MAX_JUGADORES = 1000;

class Jugador {

	private:
		unsigned int id;
		std::string nombre; 
		unsigned int cantidadDeSoldados;
		unsigned int cantidadDeDisparos;

	public:
		/**
		 * pre:
		 * pos:
		 */
		Jugador(unsigned int id,std::string nombre,
		unsigned int cantidadDeSoldados,unsigned int cantidadDeDisparos);

		/**
		 * pre:
		 * pos:
		 */
        unsigned int Jugador::obtenerId();
		
		/**
		 * pre:
		 * pos:
		 */
		std::string Jugador::obtenerNombre();

		/**
		 * pre:
		 * pos:
		 */
		void Jugador::sumarUnSoldadoSoldados(unsigned int cantidadDeDisparos);

		/**
		 * pre:
		 * pos:
		 */
		void Jugador::eliminarUnSoldados();
		
		/**
		 * pre:
		 * pos:
		 */
		void Jugador::aumentarCantidadDisparos(unsigned int cantidadDeDisparos);

		/**
		 * pre:
		 * pos:
		 */
		void Jugador::reducirCantidadDisparos(int cantidadDeDisparos);

		/**
		 * pre:
		 * pos:
		 */
		void pedirCoordenadasDeAtaque();

		/**
		 * pre:
		 * pos:
		 */
		void pedirCoordenadasDeMovimiento();

		/**
		 * pre:
		 * pos:
		 */
		void eliminarSoldado();

		/**
		 * pre:
		 * pos: Libera los recursos tomados
		 */
		~Jugador();
};

#endif /* JUGADOR_H_ */

