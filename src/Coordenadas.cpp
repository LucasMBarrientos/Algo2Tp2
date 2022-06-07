
#include "Coordenadas.h"

Coordenada::Coordenada(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Coordenada::Coordenada(unsigned int x,unsigned int y,unsigned int z){
    if(x<0 || y<0 || z<0){
        throw "coordenada invalida deben ser positivas";
    } 
    this->x = x;
    this->y = y;
    this->z = z;
}


void Coordenada::setX(unsigned int x){
    if(x<0){
        throw "coordenada invalida x debe ser positiva";
    } 
    this->x = x;
}

void Coordenada::setY(unsigned int y){
    if(y<0){
        throw "coordenada invalida y debe ser positiva";
    } 
    this->y = y;
}

void Coordenada::setZ(unsigned int z){
    if(z<0){
        throw "coordenada invalida y debe ser positiva";
    } 
    this->z = z;    
}

unsigned int Coordenada::getX(){
    return this->x;
}

unsigned int Coordenada::getY(){
    return this->y;
}

unsigned int Coordenada::getZ(){
    return this->z;
}
