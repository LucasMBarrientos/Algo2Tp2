/*
 * Carta.cpp
 *
 *  Created on: 5 jun. 2022
 *      Author: ale
 */

#include "Carta.h"

Carta::Carta() {
	enum TipoDeCarta tipoAleatorio;


	switch(generaNumeroAleatorio()){
					case 1: tipoAleatorio=CARTAAVION; break;
					case 2: tipoAleatorio=CARTABARCO; break;
					case 3: tipoAleatorio=CARTAMISIL; break;
					case 4: tipoAleatorio=CARTATANQUE; break;
					case 5: tipoAleatorio=CARTADESERTOR; break;
					case 6: tipoAleatorio=CARTAD; break;
	}
	this->setTipoDeCarta(tipoAleatorio);

}



enum TipoDeCarta Carta::daUnaCartaAleatoria() {
	enum TipoDeCarta tipoAleatorio;


	switch(generaNumeroAleatorio()){
					case 1: tipoAleatorio=CARTAAVION; break;
					case 2: tipoAleatorio=CARTABARCO; break;
					case 3: tipoAleatorio=CARTAMISIL; break;
					case 4: tipoAleatorio=CARTATANQUE; break;
					case 5: tipoAleatorio=CARTADESERTOR; break;
					case 6: tipoAleatorio=CARTAD; break;
	}
	this->setTipoDeCarta(tipoAleatorio);

}


void Carta::setTipoDeCarta(enum TipoDeCarta tipo){
	this->tipo=tipo;
}

enum TipoDeCarta Carta::getTipoDeCarta(){
	return(this->tipo);
}




int Carta::generaNumeroAleatorio(){
	int MAX=7;
    srand(time(NULL));
    int n;
         n = 1 + rand() % MAX;
    return (n);
}

bool Carta::checkrep(int n, int num[])
    {
        for(int i=0; i<10; i++)
            if(n == num[i])
                return true;
        return false;
    }


void Carta::ejecutarCarta(Jugador* jugador,Tablero* tablero){
	switch(this->tipo){
				case CARTAAVION:{

									//tablero->colocarAvion();//Posiciona un avion en el tablero
									jugador->aumentarCantidadDisparos(2);//Agrega 2 tiros al jugador que saco la carta

									; break;
				}
				case CARTABARCO:
							{	tablero->colocarBarco();//Posiciona un avion en el tablero
								jugador->aumentarCantidadDisparosMisil();
								 break;
				}
				case CARTAMISIL:{
									//ejecutaUnTiroMisil();

								 break;
				}
				case CARTATANQUE:{

									//Definir que hace un tanque
								 break;
		        }
				case CARTADESERTOR:{
								 //El jugador pierde 1 soldado (ojo hay que ubicar al soldado y vaciar el casillero)
								 break;
				}
				case CARTAD:{

								//Definir que hace esta carta
								break;
				}
	}
}



Carta::~Carta() {
	// TODO Auto-generated destructor stub
}

