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

        void cambiarCoodenadaX(unsigned int x);

        void cambiarCoodenadaY(unsigned int y);

        void cambiarCoodenadaZ(unsigned int z);

        unsigned int obtenerCoodenadaX();

        unsigned int obtenerCoodenadaY();

        unsigned int obtenerCoodenadaZ();


};

#endif /* Coordenadas_H_ */
