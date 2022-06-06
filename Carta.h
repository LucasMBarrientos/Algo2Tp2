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
	CARTAAVION,
	CARTABARCO,
	CARTAMISIL,
	CARTATANQUE,
	CARTADESERTOR,
	CARTAD
};




class Carta {

private:
	enum TipoDeCarta tipo;




	int generaNumeroAleatorio();
	bool checkrep(int n, int num[]);

public:

	Carta();

	void setTipoDeCarta(enum TipoDeCarta tipo);

	enum TipoDeCarta getTipoDeCarta();

	enum TipoDeCarta daUnaCartaAleatoria();

	void ejecutarCarta(Jugador* jugador,Tablero* tablero);

	virtual ~Carta();
};

#endif /* CARTA_H_ */
