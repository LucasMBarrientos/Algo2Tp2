/*
 * Tablero.h
 *
 *  Created on: 29/05/2022
 *      Author: algo2
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Nodo.h"
#include "Casilla.h"
#include <iostream>

class Tablero {

    private:

		// Deberia contener 3 listas cuyos nodos son templates. Y los mismos seran casillas. Podrian ser directamente punteros a casillas?
		// y que el template sea la casilla?

        Lista<Lista<Lista<Casilla*>*>*>* casillas;


        unsigned int tamaniox;
        unsigned int tamanioy;
        unsigned int tamanioz;



    public:

        /*
         * post: Lista vacia.
         */
        Tablero(unsigned int tamaniox,unsigned int tamanioy,unsigned int tamanioz);

        /*
         * post: Crea tablero de XxYxZ.
         *
         */

        ~Tablero();

        void devolverCasilla();

       /**
       * pre:
       * pos:
       */

        void inactivarCasilla();

        /**
        * pre:
        * pos:
        */
        void colocarSoldado();

        /**
        * pre:
        * pos:
        */
        void colocarBarco();

        /**
        * pre:
        * pos:
        */
        void getInfoDeCasilla();


       /**
       * pre:
       * pos:
       */


};




#endif /* TABLERO_H_ */
