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


class Tablero {

    private:

		// Deberia contener 3 listas cuyos nodos son templates. Y los mismos seran casillas. Podrian ser directamente punteros a casillas?
		// y que el template sea la casilla?

        Lista filasx;


        unsigned int tamaniox;
        unsigned int tamanioy;
        unsigned int tamanioz;

        Nodo<T>* cursorx;
        Nodo<T>* cursory;
        Nodo<T>* cursorz;

    public:

        /*
         * post: Lista vac�a.
         */
        Lista();

        /*
         * post: Lista que tiene los mismos elementos que otraLista.
         *       La instancia resulta en una copia de otraLista.
         */
        Lista(Lista<T>& otraLista);

        /*
         * post: indica si la Lista tiene alg�n elemento.
         */
        bool estaVacia();

        /*
         * post: devuelve la cantidad de elementos que tiene la Lista.
         */
        unsigned int contarElementos();

        /*
         * post: agrega el elemento al final de la Lista, en la posici�n:
         *       contarElementos() + 1.
         */
        void agregar(T elemento);

        /*
         * pre : posici�n pertenece al intervalo: [1, contarElementos() + 1]
         * post: agrega el elemento en la posici�n indicada.
         *
         */
        void agregar(T elemento, unsigned int posicion);

        /*
         * post: agrega todos los elementos de otraLista
         *       a partir de la posici�n contarElementos() + 1.
         */
        void agregar(Lista<T> &otraLista);

        /*
         * pre : posici�n pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el elemento en la posici�n indicada.
         */
        T obtener(unsigned int posicion);

        /*
         * pre : posicio� pertenece al intervalo: [1, contarElementos()]
         * post: cambia el elemento en la posici�n indicada por el
         *       elemento dado.
         */
        void asignar(T elemento, unsigned int posicion);

        /*
         * pre : posici�n pertenece al intervalo: [1, contarElementos()]
         * post: remueve de la Lista el elemento en la posici�n indicada.
         */
        void remover(unsigned int posicion);

        /*
         * post: deja el cursor de la Lista preparado para hacer un nuevo
         *       recorrido sobre sus elementos.
         */
        void iniciarCursor();

        /*
         * pre : se ha iniciado un recorrido (invocando el m�todo
         *       iniciarCursor()) y desde entonces no se han agregado o
         *       removido elementos de la Lista.
         * post: mueve el cursor y lo posiciona en el siguiente elemento
         *       del recorrido.
         *       El valor de retorno indica si el cursor qued� posicionado
         *       sobre un elemento o no (en caso de que la Lista est� vac�a o
         *       no existan m�s elementos por recorrer.)
         */
        bool avanzarCursor();

        /*
         * pre : el cursor est� posicionado sobre un elemento de la Lista,
         *       (fue invocado el m�todo avanzarCursor() y devolvi� true)
         * post: devuelve el elemento en la posici�n del cursor.
         *
         */
        T obtenerCursor();

        /*
         * post: libera los recursos asociados a la Lista.
         */
        ~Lista();

    private:

        /*
         * pre : posici�n pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el nodo en la posici�n indicada.
         */
        Nodo<T>* obtenerNodo(unsigned int posicion); // NOTA: primitiva PRIVADA
};




#endif /* TABLERO_H_ */
