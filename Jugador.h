
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
		 * pre: El Jugador debe estar crado.
		 * pos: Devuelve la cantidad de Disparos del Jugador.
		 */
		unsigned int Jugador::obtenerCantidadDisparos();
		
		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Devuelve la cantidad de Soldados del Jugador
		 */
		unsigned int Jugador::obtenerCantidadSoldados();

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Aumenta en uno la cantidad de Soldados.
		 */
		void Jugador::sumarUnSoldado();

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Disminuye en 1 la cantidad de Soldados.
		 */
		void Jugador::eliminarUnSoldado();
		
		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Aumenta los Disparos posibles del jugador, sumandole lo pasado por el parametro.
		 */
		void Jugador::aumentarCantidadDisparos(unsigned int disparosAumentados);

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Disminuye los Disparos posbiles del Jugador, reduciendole lo pasado por el parametro.
		 */
		void Jugador::reducirCantidadDisparos(int disparosReducidos);

		/**
		 * pre: -
		 * pos: Le pide al Jugador que ingrese las coordenadas donde desea atacar.
		 */
		void pedirCoordenadasDeAtaque(coordenada ataque);
	
		/**
		 * pre: -
		 * pos: Le pide al Jugador que ingrese las coordenadas para seleccionar un Soldado.
		 */
		void pedirCoordenadasDeSeleccion(coordenada seleccion);

		/**
		 * pre: El Soldado debe estar seleccionado.
		 * pos: Le pide al Jugador que ingrese las coordenadas donde desea mover un Soldado.
		 */
		void pedirCoordenadasDeMovimiento(coordenada movimiento);

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Libera los recursos tomados
		 */
		~Jugador();
};

#endif /* JUGADOR_H_ */

