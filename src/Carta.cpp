/*
 * Carta.cpp
 *
 *  Created on: 5 jun. 2022
 *      Author: ale
 */

#include "Carta.h"
using namespace std;

Carta::Carta() {

	switch(generaNumeroAleatorio()){
					case 1: this->setTipoDeCarta(CARTA_AVION); break;
					case 2: this->setTipoDeCarta(CARTA_BARCO); break;
					case 3: this->setTipoDeCarta(CARTA_MISIL); break;
					case 4: this->setTipoDeCarta(CARTA_TANQUE); break;
					case 5: this->setTipoDeCarta(CARTA_MINA); break;
					case 6: this->setTipoDeCarta(CARTA_SUSPENSION); break;
	}


}



enum TipoDeCarta Carta::generarCartaAleatoria() {

	switch(generaNumeroAleatorio()){

					case 1: this->setTipoDeCarta(CARTA_AVION); break;
					case 2: this->setTipoDeCarta(CARTA_BARCO); break;
					case 3: this->setTipoDeCarta(CARTA_MISIL); break;
					case 4: this->setTipoDeCarta(CARTA_TANQUE); break;
					case 5: this->setTipoDeCarta(CARTA_MINA); break;
					case 6: this->setTipoDeCarta(CARTA_SUSPENSION); break;
	}
	return (this->getTipoDeCarta());

}


void Carta::setTipoDeCarta(enum TipoDeCarta tipo){
	this->tipo=tipo;
}

enum TipoDeCarta Carta::getTipoDeCarta(){
	return(this->tipo);
}




int Carta::generaNumeroAleatorio(){
	int MAX=7;
    srand((unsigned)time(NULL));
    int n;
         n = 0 + rand() % MAX;
    return (n);
}

bool Carta::checkrep(int n, int num[])
    {
        for(int i=0; i<10; i++)
            if(n == num[i])
                return true;
        return false;
    }


void Carta::ejecutarCarta(Jugador* jugador,Tablero* tablero,Lista<Jugador *>* ListaDeJugadores){
	switch(this->tipo){
				case CARTA_AVION:{

									tablero->colocarElementoAleatorio(SOLDADO,jugador);//Posiciona un avion en el tablero
									jugador->aumentarCantidadDisparos(2);//Agrega 2 tiros al jugador que saco la carta

									; break;
				}
				case CARTA_BARCO:
							{	tablero->colocarElementoAleatorio(SOLDADO,jugador);//Posiciona un barco en el tablero
								jugador->aumentarCantidadDisparosMisil(1);
								 break;
				}
				case CARTA_MISIL:{
									//ejecutaUnTiroMisil();

								 break;
				}
				case CARTA_TANQUE:{
									tablero->colocarElementoAleatorio(TANQUE,jugador);
									//EjecutaUnTirotaque en el plano xy de 2x2;
								 break;
		        }
				case CARTA_MINA:{
								 //Colocar mina en posicion que deja el soldado al moverse.
								 break;
				}
				case CARTA_SUSPENSION:{

					bool flagIdValido=false;
					unsigned int id;
					do{
						cout<<"Ingrese el Id del jugador a saltear";
						cin>>id;
						ListaDeJugadores->iniciarCursor();
						while(ListaDeJugadores->avanzarCursor()){
								if((ListaDeJugadores->obtenerCursor()->obtenerId())==id){
									ListaDeJugadores->obtenerCursor()->bloquearJugador() ;
								flagIdValido=true;
								}
						}
					}while(!flagIdValido);

					break;
				}
	}
}



Carta::~Carta() {
	// TODO Auto-generated destructor stub
}

