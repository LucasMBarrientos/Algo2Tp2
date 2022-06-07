/*
 * Carta.h
 *
 *  Created on: 5 jun. 2022
 *      Author: ale
 */


#ifndef CARTA_H_
#define CARTA_H_
#include <cstdlib>
#include<ctime>
#include<iostream>
#include "Jugador.h"
#include "Ficha.h"
#include "Tablero.h"


enum TipoDeCarta {
	CARTA_AVION,
	CARTA_BARCO,
	CARTA_MISIL,
	CARTA_TANQUE,
	CARTA_MINA,
	CARTA_SUSPENSION,
};




class Carta {

private:
	enum TipoDeCarta tipo;
	unsigned int  cantCartas;



	int generaNumeroAleatorio();
	bool checkrep(int n, int num[]);

public:
	//pre:
	//pos: El constructor setea una carta aleatoria en su creacion.
	Carta();
	//pre:
	//pos:Setea el tipo de carta por "fuerza bruta", no deberia utilizarse este metodo.
	void setTipoDeCarta(enum TipoDeCarta tipo);
	//pre:
	//pos:Nos devuelve que tipo de carta aleatoria salio(CARTA_AVION o CARTA_TANQUE etc)
	enum TipoDeCarta getTipoDeCarta();
	//pre:
	//pos:Carga en el atributo tipo de carta, una de las opciones posibles.
	enum TipoDeCarta generarCartaAleatoria();
	//pre:
	//pos: Ejecuta la carta que este indicada en el atributo (tipo de carta)
	void ejecutarCarta(Jugador* jugador,Tablero* tablero,Lista<Jugador *>* ListaDeJugadores);

	virtual ~Carta();
};

#endif /* CARTA_H_ */
