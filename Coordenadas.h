#ifndef COORDENADAS_H_
#define COORDENADAS_H_

class Coordenada{

	private:

        unsigned int x;
        unsigned int y;
        unsigned int z;

	public:

        Coordenada();

        Coordenada(unsigned int x,unsigned int y,unsigned int z);

        void cambiarCoordenadaX(unsigned int x);

        void cambiarCoordenadaY(unsigned int y);

        void cambiarCoordenadaZ(unsigned int z);

        unsigned int obtenerCoordenadaX();

        unsigned int obtenerCoordenadaY();

        unsigned int obtenerCoordenadaZ();


};

#endif /* Coordenadas_H_ */
