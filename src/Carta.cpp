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

					case 1: this->setTipoDeCarta(CARTA_AVION);
						cout<<"USTED SACO LA CARTA AVION"<<endl;
						break;
					case 2: this->setTipoDeCarta(CARTA_BARCO);
						cout<<"USTED SACO LA CARTA BARCO"<<endl;
						break;
					case 3: this->setTipoDeCarta(CARTA_MISIL);
						cout<<"USTED SACO LA CARTA MISIL"<<endl;
						break;
					case 4: this->setTipoDeCarta(CARTA_TANQUE);
						cout<<"USTED SACO LA CARTA TANQUE"<<endl;
						break;
					case 5: this->setTipoDeCarta(CARTA_MINA);
						cout<<"USTED SACO LA CARTA MINA"<<endl;
						break;
					case 6: this->setTipoDeCarta(CARTA_SUSPENSION);
						cout<<"USTED SACO LA CARTA SUSPENSION"<<endl;
						break;
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




Carta::~Carta() {
	// TODO Auto-generated destructor stub
}
