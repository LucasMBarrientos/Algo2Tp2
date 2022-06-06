
#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include "Coordenadas.h"

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
    unsigned int obtenerId();

    
		/**
		 * pre: El Jugador debe estar crado.
		 * pos: Devuelve el Nombre del Jugador.
		 */
		std::string obtenerNombre();

    /**
		 * pre: El Jugador debe estar crado.
		 * pos: Devuelve la cantidad de Disparos del Jugador.
		 */
		unsigned int obtenerCantidadDeDisparos();
    
    /**
		 * pre: El Jugador debe estar creado.
		 * pos: Le resta la cantidad de soldados al jugador que se paso por parametro.
		 */
		void eliminarVariosSoldados(unsigned int cantidad);

    /**
		 * pre: El Jugador debe estar creado.
		 * pos: Devuelve la cantidad de Soldados del Jugador
		 */
		unsigned int Jugador::obtenerCantidadSoldados();

    /**
		 * pre: El Jugador debe estar creado.
		 * pos: Aumenta en uno la cantidad de Soldados.
		 */
		void sumarUnSoldado();

    /**
		 * pre: El Jugador debe estar creado.
		 * pos: Disminuye en 1 la cantidad de Soldados.
		 */
		void eliminarUnSoldado();
		
		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Aumenta los Disparos posibles del jugador, sumandole lo pasado por el parametro.
		 */
		void aumentarCantidadDisparos(unsigned int disparosAumentados);

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Disminuye los Disparos posbiles del Jugador, reduciendole lo pasado por el parametro.
		 */
		void reducirCantidadDisparos(unsigned int disparosReducidos);
    
		 /**
		 * pre: -
		 * pos: Le pide al Jugador que ingrese las coordenadas donde desea atacar.
		 */
		Coordenada pedirCoordenadaDeAtaque();
	
		/**
		 * pre: -
		 * pos: Le pide al Jugador que ingrese las coordenadas para seleccionar un Soldado.
		 */
		Coordenada pedirCoordenadaDeSeleccion();

		/**
		 * pre: El Soldado debe estar seleccionado.
		 * pos: Le pide al Jugador que ingrese las coordenadas donde desea mover un Soldado.
     */
		Coordenada pedirCoordenadaDeMovimiento();

	  /**
		 * pre: El Jugador debe estar creado.
		 * pos: Libera los recursos tomados
		 */
		~Jugador();
	};

#endif /* JUGADOR_H_ */

