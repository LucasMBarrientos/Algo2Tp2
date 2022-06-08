#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include "Coordenadas.h"

const unsigned int MAX_JUGADORES = 1000;

enum Permiso{
	BLOQUEADO,
	HABILITADO,
};

class Jugador {

	private:
		unsigned int id;
		std::string nombre; 
		Permiso estado;
		unsigned int cantidadDeSoldados;
		unsigned int cantidadDeDisparos;
		unsigned int cantidadDeDisparosMisil;
		unsigned int cantidadDeDisparosTanque;
	public:

		/**
		 * pre: -
		 * pos: Crea un jugador y establece sus atributos con los parametros recibidos.
		 */
		Jugador(unsigned int id,std::string nombre,
		unsigned int cantidadDeSoldados,unsigned int cantidadDeDisparos);

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Devuelde el ID del Jugador.
		 */
        unsigned int obtenerId();
		
		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Devuelve el Nombre del Jugador.
		 */
		std::string obtenerNombre();


    /**
		 * pre: El Jugador debe estar creado.
		 * pos: Devuelve la cantidad de Disparos del Jugador.
		 */
		unsigned int obtenerCantidadDisparos();
    
		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Devuelve la catidad de disparos misil que posee el jugador.
		 */
		unsigned int obtenerCantidadDeDisparosMisil();

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Devuelve la catidad de disparos tanque que posee el jugador.
		 */
		unsigned int obtenerCantidadDeDisparosTanque();
		
		/**
		 * pre: -
		 * pos: Devuelve si esta habilitado o bloqueado para jugar en su turno.
		 */
		Permiso obtenerPermiso();
		
		/**
		 * pre: El Jugador no debe estar bloqueado.
		 * pos: Bloquea al jugador a usar su turno.
		 */
		void bloquearJugador();

		/**
		 * pre: El Jugador no debe estar habilitado.
		 * pos: Habilita al jugador a usar su turno.
		 */
		void habilitarJugador();

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Le resta al jugador la cantidad de soldados que se paso por parametro.
		 */
		void eliminarVariosSoldados(unsigned int cantidadSoldados);

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Devuelve la cantidad de Soldados del Jugador
		 */
		unsigned int obtenerCantidadDeSoldados();

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
		 * pos: Disminuye los Disparos posbiles del Jugador, reduciendole lo pasado por el parametro.
		 */
		void reducirCantidadDisparos(unsigned int disparosReducidos);

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Aumenta los Disparos posibles del jugador, sumandole lo pasado por el parametro.
		 */
		void aumentarCantidadDisparos(unsigned int disparosAumentados);

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Aumenta los Disparos misil posibles del jugador, sumandole lo pasado por el parametro.
		 */
		void aumentarCantidadDisparosMisil(unsigned int disparosAumentados);

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Disminuye los Disparos misil posbiles del Jugador, reduciendole lo pasado por el parametro.
		 */
		void reducirCantidadDisparosMisil(unsigned int disparosReducidos);
		
		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Aumenta los Disparos tanque posibles del jugador, sumandole lo pasado por el parametro.
		 */
		void aumentarCantidadDisparosTanque(unsigned int disparosAumentados);

		/**
		 * pre: El Jugador debe estar creado.
		 * pos: Disminuye los Disparos tanque posbiles del Jugador, reduciendole lo pasado por el parametro.
		 */
		void reducirCantidadDisparosTanque(unsigned int disparosReducidos);
		
		/**
		 * pre: Pasar unas coordenadas validas.
		 * pos: Actualiza las coordenadas donde desea atacar.
		 */
		void pedirCoordenadaDeAtaque(Coordenada &coordenada);
	
		/**
		 * pre: Pasar unas coordenadas validas.
		 * pos: Actualiza las coordenadas para seleccionar un Soldado.
		 */
		void pedirCoordenadaDeSeleccion(Coordenada &coordenada);

		/**
		 * pre: El Soldado debe estar seleccionado y pasar unas coordenadas validas.
		 * pos: Actualiza las coordenadas donde desea mover un Soldado.
		 */
		void pedirCoordenadaDeMovimiento(Coordenada &coordenada);

		private:

		/**
         * pre: Recibir unas coordenadas validas.
		 * pos: Actualiza las coordenadas pasadas por referencia.
		 */
		void obtenerCoordenada(Coordenada &coordenada);

		/**
         * pre: Recibe un mesaje valido.
		 * pos: Muestra por pantalla el mensaje.
		 */
		void Jugador::mostrarMensaje(string mensaje);

		/**
         * pre: Recibe una cadena de carateres.
		 * pos: Valida si esta compuesta por solo digitos
		 */
		bool Jugador::esCadenaNumerica(string cadena);

		/**
         * pre: Recibe un mesaje valido que aparece cuando se pida el numero entero.
		 * pos: Retorna un numero Entero.
		 */
		int Jugador::pedirNumeroEntero(string mensaje);
	};

#endif /* JUGADOR_H_ */

