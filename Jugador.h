
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
		 * pre: -
		 * pos: Crea un jugador y establece sus atributos con los parametros recibidos.
		 */
		Jugador(unsigned int id,std::string nombre,
		unsigned int cantidadDeSoldados,unsigned int cantidadDeDisparos);

		/**
		 * pre: El Jugador debe estar crado.
		 * pos: Devuelde el ID del Jugador.
		 */
        unsigned int Jugador::obtenerId();
		
		/**
		 * pre: El Jugador debe estar crado.
		 * pos: Devuelve el Nombre del Jugador.
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
		void pedirCoordenadasDeAtaque(coordenada ataque);
	
		/**
		 * pre:
		 * pos:
		 */
		void pedirCoordenadasDeSeleccion(coordenada seleccion);

		/**
		 * pre:
		 * pos:
		 */
		void pedirCoordenadasDeMovimiento(coordenada movimiento);

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

