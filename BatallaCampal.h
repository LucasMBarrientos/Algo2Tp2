
#ifndef BATALLACAMPAL_H_
#define BATALLACAMPAL_H_

class BatallaCampal {

	private:

	public:
		/**
		 * pre:
		 * pos:
		 */
		BatallaCampal();

		/**
		 * pre:
		 * pos:
		 */
		void menuPrincipal();

		/**
		 * pre:
		 * pos:
		 */
		void inicializar();

		/**
		 * pre:
		 * pos:
		 */
		void jugar();	// pide coordenadas al jugador y al tablero, y las valida.

		/**
		 * pre:
		 * pos:
		 */
		bool sigueJugando();


		/**
		 * pre:
		 * pos:
		 */
		~BatallaCampal();
};

#endif /* BATALLACAMPAL_H_ */
