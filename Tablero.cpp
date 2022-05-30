/*
 * Tablero.cpp
 *
 *  Created on: 29/05/2022
 *      Author: algo2
 */

#include "Tablero.h"
#include "Lista.h"
#include "Casilla.h"
#include <iostream>

Tablero::Tablero(unsigned int tamaniox,unsigned int tamanioy,unsigned int tamanioz) {

	unsigned int  i,j,k;


	//Validar minimo tamaño

	(this->tamaniox)=tamaniox;
	(this->tamanioy)=tamanioy;
	(this->tamanioz)=tamanioz;

	 this->casillas = new Lista<Lista<Lista<Casilla*>*>*>;

	for(i=0;i<this->tamaniox;i++)
	{
		Lista<Lista<Casilla*>*>* casillasy = new Lista<Lista<Casilla*>*>;

		for(j=0;j<this->tamanioy;j++)
		{
			Lista<Casilla*>* casillasz = new Lista<Casilla*>;

			for(k=0;k<this->tamanioz;k++)
			{
				Casilla* casilla= new Casilla;
				casillasz->agregar(casilla);

			}
			casillasy->agregar(casillasz);
		}
		this->casillas->agregar(casillasy);
	}

}

Tablero::~Tablero() {


}

void Tablero::devolverCasilla(){

}

void Tablero::inactivarCasilla(){

}
void Tablero::colocarSoldado(){

}

void Tablero::colocarBarco(){

}
void Tablero::getInfoDeCasilla(){

}

